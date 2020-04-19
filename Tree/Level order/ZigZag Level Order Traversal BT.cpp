// Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).
// OR Write a function to print spiral order traversal of a tree. 
// Example : Given binary tree
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return
// [
//          [3],
//          [20, 9],
//          [15, 7]
// ]

// Approach 1: Using 2 stacks (Can also use deque for implementing the 2 stacks using null as a seperator/delimiter)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
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

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
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

/***************************************************************************************************************************/

// Approach 2: 1 Deque and counter technique
// Using deque for implementing the 2 stacks using null as a seperator/delimiter

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

// Approach 3: Reversing alternate levels of level order traversal

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

/***************************************************************************************************************************/

// Approach 4 : Using DFS/Preorder Traversal

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<list> 
 
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

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
    vector<list<int>> ans;
    dfs(root,0,ans);
    
    vector<vector<int>>ret;
    for(list<int> l:ans){
        ret.push_back(vector<int>(l.begin(),l.end()));
    }
    return ret;
}

