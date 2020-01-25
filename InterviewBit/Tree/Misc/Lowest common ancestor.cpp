// NOTE: TODO Question: See LCA in BST - O(h)

// Bucket - Tree search

// Approach 1 : Recursive solution, bottom up - O(n)

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
