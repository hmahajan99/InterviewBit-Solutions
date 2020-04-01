// Approach 1: 1 Deque and counter technique

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {

    vector<vector<int>> ans;

    deque<TreeNode*> q;
    q.push_front(A);

    int levelCount=1;
    int nextLevelCount=0;
    bool lr = true;
    
    while(!q.empty()){
        vector<int> level;
        if(lr){
            while(levelCount!=0){
                TreeNode* front =q.front();
                q.pop_front();
                level.push_back(front->val);
                if(front->left){
                  q.push_back(front->left);
                  nextLevelCount++;
                } 
                if(front->right){
                  q.push_back(front->right);
                  nextLevelCount++;
                } 
                levelCount--;
            }

        }else{
            while(levelCount!=0){
                TreeNode* back =q.back();
                q.pop_back();
                level.push_back(back->val);
                if(back->right){
                  q.push_front(back->right);
                  nextLevelCount++;
                } 
                if(back->left){
                  q.push_front(back->left);
                  nextLevelCount++;
                } 
                levelCount--;
            }
        }
        ans.push_back(level);
        levelCount=nextLevelCount;
        nextLevelCount=0;
        lr = !lr;
    }
    
    return ans;    
    
}

/***************************************************************************************************************************/

// Approach 2: Reversing alternate levels of level order traversal

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {

    vector<vector<int>> ans;
    vector<int> level;
    queue<TreeNode*> q;
    if(A){
      q.push(A);
      q.push(NULL);
    } 
    while(!q.empty()){
        TreeNode *front = q.front();
        q.pop();
        if(front==NULL){
            if(!q.empty()) q.push(NULL);
            if(ans.size()%2==1){
                reverse(level.begin(),level.end());
            }
            ans.push_back(level);
            level.clear();
        }else{
            level.push_back(front->val);
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }

    return ans;    
    
}
