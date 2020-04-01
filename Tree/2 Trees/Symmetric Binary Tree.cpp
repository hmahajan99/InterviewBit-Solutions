/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool helper(TreeNode* A,TreeNode* B){
    if(!A && !B ) return true;
    if(!A || !B ) return false;
    return (A->val==B->val)&&helper(A->left,B->right)&&helper(A->right,B->left);
}
 
int Solution::isSymmetric(TreeNode* A) {
    return A==NULL||helper(A->left,A->right);
}