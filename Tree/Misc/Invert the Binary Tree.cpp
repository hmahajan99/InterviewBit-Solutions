// Bucket - Inplace change

// Approach 1

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

/***************************************************************************************************************************/

// Approach 2

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
