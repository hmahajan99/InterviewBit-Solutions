// Bucket - Simple Tree Ops

// Recursive Solution

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


pair<int,bool> util(TreeNode* A){
    if(A==NULL) return make_pair(0,true);
    pair<int,bool> l = util(A->left);
    pair<int,bool> r = util(A->right);
    return make_pair(1+max(l.first,r.first),l.second && r.second && abs(l.first-r.first)<=1);
}  
 
int Solution::isBalanced(TreeNode* A) {
    return util(A).second;
}
