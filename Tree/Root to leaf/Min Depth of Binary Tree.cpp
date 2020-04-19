// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

// NOTE : TRICKY QUESTION 

/*
THIS IS WRONG
int Solution::minDepth(TreeNode* A) {
    if(!A) return 0; OR if(!A) return INT_MAX;
    return 1+min(minDepth(A->left),minDepth(A->right));
}
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    if(A==NULL) return INT_MAX;
    int d = min(minDepth(A->left),minDepth(A->right));
    if(d == INT_MAX) return 1;
    return 1 + d;
}

/***************************************************************************************************************************/

// Approach 2 : BETTER, using LEAF NODE as BASE CASE

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode *root) {
    // Corner case. Should never be hit unless the code is called on root = NULL
    if (root == NULL) return 0;
    // Base case : Leaf node. This accounts for height = 1.
    if (root->left == NULL && root->right == NULL) return 1;

    if (!root->left) return minDepth(root->right) + 1;
    if (!root->right) return minDepth(root->left) + 1;

    return min(minDepth(root->left), minDepth(root->right)) + 1; 
}
