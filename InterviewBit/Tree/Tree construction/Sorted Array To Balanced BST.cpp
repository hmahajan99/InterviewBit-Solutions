/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* helper(const vector<int> &A,int si,int ei){
    if(si>ei) return NULL;
    
    int mid = (si+ei)/2;
    
    TreeNode* root = new TreeNode(A[mid]);
    root->left = helper(A,si,mid-1);    
    root->right = helper(A,mid+1,ei);    
    return root;
    
} 
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return helper(A,0,A.size()-1);
}
