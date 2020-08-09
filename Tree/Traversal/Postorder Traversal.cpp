// Given a binary tree, return the postorder traversal of its nodes’ values.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) {
    if(!A) return vector<int>();
    vector<int> ans;
    stack<TreeNode*> s;
    unordered_map<TreeNode*,bool> visited;
    s.push(A);
    while(!s.empty()){
        TreeNode* top=s.top();
        bool push = false;
        if(top->right&&!visited.count(top->right)){
            s.push(top->right);
            push=true;
        };
        if(top->left&&!visited.count(top->left)){ 
            s.push(top->left);
            push=true;
        }
        if(!push){
            visited[top]=true;
            ans.push_back(top->val);
            s.pop();
        }
    }
    return ans;
}
