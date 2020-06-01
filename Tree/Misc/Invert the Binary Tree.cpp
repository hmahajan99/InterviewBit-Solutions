// Bucket - Inplace change

// Given a binary tree, invert the binary tree and return it.
// OR Given a Binary Tree, convert it into its mirror.

// Given binary tree
//      1
//    /   \
//   2     3
//  / \   / \
// 4   5 6   7
// invert and return
//      1
//    /   \
//   3     2
//  / \   / \
// 7   6 5   4


// Approach 1: Recursive

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* Solution::invertTree(TreeNode* A) {
    if(A==NULL) return NULL;
    invertTree(A->left);
    invertTree(A->right);
    swap(A->left,A->right);
    return A;
}

// Alternative, swap before

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* Solution::invertTree(TreeNode* A) {
    if(A==NULL) return NULL;
    swap(A->left,A->right);
    invertTree(A->left);
    invertTree(A->right);
    return A;
}

/***************************************************************************************************************************/

// Approach 2: Iterative, level order traversal
// The idea is to do queue based level order traversal. While doing traversal, swap left and right children of every node.


