// Bucket - Tree dp

// Given a binary tree, find the maximum path sum. The path may start and end at any node in the tree.

// Approach
// For each node there can be four ways that the max path goes through the node:
// 1. Node only
// 2. Max path through Left Child + Node
// 3. Max path through Right Child + Node
// 4. Max path through Left Child + Node + Max path through Right Child

// The idea is to keep trace of four paths and pick up the max one in the end. 
// An important thing to note is, root of every subtree need to return maximum path sum such that at most one child of root is involved.

// Time Complexity: O(n) where n is number of nodes in Binary Tree.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int maxPath;

int maxPathUtil(TreeNode* node){
    // returns max path sum going through node
    if(!node) return 0;
    
    int left=maxPathUtil(node->left);
    int right=maxPathUtil(node->right);
    
    int maxPathThroughThisNode = left + node->val + right;
    maxPath = max(maxPath,maxPathThroughThisNode);

    int straightLinePath = node->val + max(left,right);
    return max(straightLinePath,0);
    
} 
 
int Solution::maxPathSum(TreeNode* root) {
    maxPath = INT_MIN;
    maxPathUtil(root);
    return maxPath;
}