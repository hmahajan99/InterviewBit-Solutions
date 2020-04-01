// Approach 1: Using NULL markers

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int> > Solution::levelOrder(TreeNode* A) {

    vector<vector<int>> ans;
    if(!A) return ans;
    queue<TreeNode*> q;
    q.push(A);
    q.push(NULL);
    vector<int> level;
    while(!q.empty()){
        TreeNode* front=q.front();
        q.pop();
        if(front){
            level.push_back(front->val);
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }else{
            ans.push_back(level);
            level.clear();
            if(!q.empty()) q.push(NULL);
        }
    }
    
    return ans;
    
}

/***************************************************************************************************************************/

// Approach 2: Using levelcount counter, single loop

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int> > Solution::levelOrder(TreeNode* A) {

     // Using levelcount counter
    vector<vector<int>> ans;
    if(!A) return ans;
    queue<TreeNode*> q;
    q.push(A);
    int levelCount = 1;
    int nextLevelCount = 0;
    vector<int> level;
    while(!q.empty()){
        TreeNode* front=q.front();
        q.pop();
        level.push_back(front->val);
        if(front->left){
            q.push(front->left);
            nextLevelCount++;
        }
        if(front->right){
            q.push(front->right);
            nextLevelCount++;
        }
        levelCount--;
        if(levelCount==0){
            ans.push_back(level);
            level.clear();
            levelCount=nextLevelCount;
            nextLevelCount=0;
        }
        
    }
    
    return ans;
    
}

// Alternate: Use nested loop

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<vector<int> > Solution::levelOrder(TreeNode* A) {

     // Using levelcount counter, nested loop
    vector<vector<int>> ans;
    if(!A) return ans;
    queue<TreeNode*> q;
    q.push(A);
    vector<int> level;
    while(!q.empty()){
        int levelCount = q.size();
        while(levelCount--){
            TreeNode* front=q.front();
            q.pop();
            level.push_back(front->val);
            if(front->left)  q.push(front->left);
            if(front->right) q.push(front->right);
        }
        ans.push_back(level);
        level.clear();
    }
    
    return ans;
    
}
