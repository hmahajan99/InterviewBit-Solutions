// Given a binary tree, find its maximum depth OR height.
// The maximum depth of a binary tree is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
int Solution::maxDepth(TreeNode* A) {
    if(!A) return 0;
    return 1+max(maxDepth(A->left),maxDepth(A->right));
}

/***************************************************************************************************************************/

// Approach 2: Iterative, we can use level order traversal to find height without recursion