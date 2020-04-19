// Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::hasPathSum(TreeNode* A, int B) {
    if(A==NULL) return 0;
    if(A->left==NULL && A->right==NULL) {
      return (B==A->val);
    }
    return hasPathSum(A->left,B-A->val) || hasPathSum(A->right,B-A->val);
}
