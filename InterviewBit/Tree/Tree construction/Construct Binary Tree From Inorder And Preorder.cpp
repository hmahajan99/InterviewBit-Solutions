/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* helper(unordered_map<int,int> &m,vector<int> &A, vector<int> &B,int is,int ie,int ps,int pe){
    // A-> inorder B -> is preorder
    if(is>ie) return NULL;
    if(is==ie) return new TreeNode(A[is]);
    int rootValue = B[ps];
    int rootIndex = m[rootValue];
    TreeNode* root= new TreeNode(rootValue); 
    root->left = helper(m,A,B,is,rootIndex-1,ps+1,ps+rootIndex-is);
    root->right = helper(m,A,B,rootIndex+1,ie,ps+rootIndex-is+1,pe);
    return root;
} 
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    // A-> preorder B -> is inorder
    unordered_map<int,int> m;
    for(int i=0;i<=B.size()-1;i++){
        m[B[i]]=i;
    }
    return helper(m,B,A,0,B.size()-1,0,A.size()-1);
}