// Bucket - Tree search

// NOTE: See LCA in BST also => O(h) solution

// Find the lowest common ancestor in an unordered binary tree given two values in the tree.
// Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) 
//                          is the lowest (i.e. deepest) node that has both v and w as descendants. 

// 1) You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
// 2) No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
// 3) There are no duplicate values.


// Approach 1 : Recursive solution, bottom up - O(n)

// The approach 2 finds LCA in O(n) time, but requires three tree traversals plus extra spaces for path arrays. 
// If we assume that the keys n1 and n2 are present in Binary Tree, we can find LCA using single traversal of Binary Tree and without extra storage for path arrays.
// The idea is to traverse the tree starting from root. 
// If any of the given keys (n1 and n2) matches with root, then root is LCA (assuming that both keys are present). 
// If root doesn’t match with any of the keys, we recur for left and right subtree. 
// The node which has one key present in its left subtree and the other key present in right subtree is the LCA. 
// If both keys lie in left subtree, then left subtree has LCA also, otherwise LCA lies in right subtree.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool find(TreeNode* root,int value){
    if(!root) return false;
    return root->val==value || find(root->left,value) || find(root->right,value); 
}

TreeNode* LCA(TreeNode* root, int B, int C) {
    if(!root) return NULL;
    if(root->val==B||root->val==C) return root;

    TreeNode* l = LCA(root->left,B,C);
    TreeNode* r = LCA(root->right,B,C);
    
    if(l&&r) return root;
    if(l) return l;
    if(r) return r;
    return NULL;    
}

 
int Solution::lca(TreeNode* root, int B, int C) {
    if(!find(root,B)||!find(root,C)) return -1;
    return LCA(root,B,C)->val;
}

/***************************************************************************************************************************/

// Approach 2: Recursive solution, top down. Storing the root to leaf paths

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool findPath(TreeNode* root, int data, vector<int> &currentPath){
    
    if(!root) return false;
    
    currentPath.push_back(root->val);
    if(root->val==data) return true;

    if(findPath(root->left,data,currentPath)) return true;
    if(findPath(root->right,data,currentPath)) return true;

    currentPath.pop_back();
    return false;
}  
 
int Solution::lca(TreeNode* root, int B, int C) {
    vector<int> path1,path2;
    bool b = findPath(root,B,path1);
    bool c = findPath(root,C,path2);
    if(!b||!c) return -1;
    int n = min(path1.size(),path2.size());
    for(int i=0;i<=n;i++){
        if(i==n||path1[i]!=path2[i]) return path1[i-1];
    }
}

/***************************************************************************************************************************/

// Approach 3: Using Parent pointer

// Store height for every node (unordered_map<TreeNode*,int>) & parent for every node (unordered_map<TreeNode*,TreeNode*>)
// First move nodes to same height
// Move up by 1 till they become same
// This approach takes too much memory - O(n)

// The idea is to find depths of given nodes and move up the deeper node pointer by the difference between depths. 
// Once both nodes reach same level, traverse them up and return the first common node.
