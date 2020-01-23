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
    if(is>ie) return NULL;
    int root1 = B[pe];
    // Using m, dont have to scan inorder traversal for index now
    // O(n^2) without m in worst case (skewed tree)
    // O(n) using m
    int rootIndex = m[root1];
    TreeNode* root= new TreeNode(root1); 
    root->left = helper(m,A,B,is,rootIndex-1,ps,ps+rootIndex-is-1);
    root->right = helper(m,A,B,rootIndex+1,ie,ps+rootIndex-is,pe-1);
    return root;
} 
 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    unordered_map<int,int> m;
    // m stores reverse mapping i.e element to index in inorder traversal
    for(int i=0;i<A.size();i++){
        m[A[i]]=i;
    }
    return helper(m,A,B,0,A.size()-1,0,B.size()-1);
    
}