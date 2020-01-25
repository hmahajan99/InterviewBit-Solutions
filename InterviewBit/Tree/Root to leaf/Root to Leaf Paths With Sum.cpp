/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void findPaths(TreeNode* A, int B,vector<vector<int>>& output,vector<int>& current){
    
    if(!A) return;
    
    if(!A->left && !A->right){
        if(B==A->val){
            current.push_back(A->val);
            output.push_back(current);
            current.pop_back();
        }
        return;
    }
    
    current.push_back(A->val);

    findPaths(A->left,B-A->val,output,current);
    findPaths(A->right,B-A->val,output,current);

    current.pop_back();

} 
 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>> output;
    vector<int> currentPath;
    findPaths(A,B,output,currentPath);
    return output;
}