// Approach 1 : Single Loop

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> currentLevel;
        queue<TreeNode*> q;
        if(root!=NULL){
            q.push(root);      
            q.push(NULL);  
        } 
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node){
                if(!q.empty()) q.push(NULL);
                ans.push_back(currentLevel);
                currentLevel.clear();
            }else{
                currentLevel.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }        
        return ans;
    }
};

/***************************************************************************************************************************/

// Approach 2 : Nested Loop (Generate complete level in inner loop)

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
    vector<int> generateLevel(queue<TreeNode*> &q){
        queue<TreeNode*> q2;
        vector<int> currentLevel;
        while(!q.empty()){
            TreeNode *front = q.front();
            q.pop();
            currentLevel.push_back(front->val);
            if(front->left) q2.push(front->left);
            if(front->right) q2.push(front->right);
        }
        q=q2;
        return currentLevel;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root)  q.push(root);      
        while(!q.empty()){
            ans.push_back(generateLevel(q));
        }        
        return ans;
    }
};