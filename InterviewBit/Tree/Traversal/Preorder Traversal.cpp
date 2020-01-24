// Approach 1 : Using stack

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> s;
    s.push(A);
    while (!s.empty()) {
        TreeNode* top = s.top();
        s.pop();
        ans.push_back(top->val);
        if(top->right) s.push(top->right);
        if(top->left) s.push(top->left);
    }
    return ans;
}

/***************************************************************************************************************************/

// Approach 2 : Using Morris Traversal

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* findPred(TreeNode* current){
    TreeNode *temp=current;
    temp=temp->left;
    while(temp->right!=NULL&&temp->right!=current){
        temp=temp->right;
    }
    return temp;
} 
 
vector<int> MorrisTraversal(TreeNode* root){
    vector<int> ans;
    TreeNode *current = root;
    while(current!=NULL){
        if(!current->left){
            // Visit current
            ans.push_back(current->val);
            current = current->right;
        }else{
            TreeNode* predecessor = findPred(current);
            if(!predecessor->right){
                // Visit current
                ans.push_back(current->val);
                predecessor->right = current;
                current = current ->left;
            }else{
                predecessor->right = NULL;
                current=current->right;;
            }
        }
    }
    return ans;
} 
 
vector<int> Solution::preorderTraversal(TreeNode* A) {
    return MorrisTraversal(A);
}