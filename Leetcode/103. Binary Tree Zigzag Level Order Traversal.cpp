// APPROACH 1 : Using 2 stacks (Can also use deque for implementing the 2 stacks using null as a seperator)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> generateLevel(stack<TreeNode*> &s1,stack<TreeNode*> &s2,bool rev){
        vector<int> currentLevel;
        while(!s1.empty()){
            TreeNode *top=s1.top();
            s1.pop();
            currentLevel.push_back(top->val);
            if(rev){
                if(top->right) s2.push(top->right);                
                if(top->left) s2.push(top->left);
            }else{
                if(top->left) s2.push(top->left);
                if(top->right) s2.push(top->right);                
            }
        }
        return currentLevel;
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        stack<TreeNode*> s1,s2;
        if(root) s1.push(root);
        while(!s1.empty()||!s2.empty()){
            if(s2.empty()){
                ans.push_back(generateLevel(s1,s2,false));
            }else{
                ans.push_back(generateLevel(s2,s1,true));
            }
        }
        return ans;
    }    
};

/***************************************************************************************************************************/

// APPROACH 2 : Using DFS

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode *root,int level,vector<list<int>> &ans){
        if(!root) return;
        if(ans.size()<level+1){
            // First time reached this level
            ans.push_back(list<int>({root->val}));
        }else{
            if(level%2==0){
                ans[level].push_back(root->val);                
            }else{
                ans[level].push_front(root->val);                                
            }
        }
        dfs(root->left,level+1,ans);
        dfs(root->right,level+1,ans);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<list<int>> ans;
        dfs(root,0,ans);
        
        vector<vector<int>>ret;
        for(list<int> l:ans){
            ret.push_back(vector<int>(l.begin(),l.end()));
        }
        return ret;
    }
};