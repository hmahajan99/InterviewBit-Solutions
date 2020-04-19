// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
// Find the total sum of all root-to-leaf numbers % 1003.
// Example :
//     1
//    / \
//   2   3
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void dfs(TreeNode* A,int& ans,int& currSum){
    // Corner case
    if(A==NULL) return;
    // Base case
    if(A->left == NULL && A->right == NULL){
        ans = (ans+(currSum*10+A->val)%1003)%1003;
        return; 
    }
    
    // Store value as we have to backtrack
    int temp = currSum;

    currSum = (currSum*10+A->val)%1003;
    dfs(A->left,ans,currSum);
    dfs(A->right,ans,currSum);

    currSum =  temp;
} 
 
int Solution::sumNumbers(TreeNode* A) {
    int ans = 0,currentPathSum = 0;
    dfs(A,ans,currentPathSum);
    return ans;
}

/***************************************************************************************************************************/

// Approach 2 : Without passing by reference

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int sumNumbers(TreeNode *root, int curSum) {
    if (root == NULL) return curSum;
    curSum = (curSum * 10 + root->val) % 1003;
    if (root->left == NULL && root->right == NULL) return curSum;
    if (!root->left) return sumNumbers(root->right, curSum);
    if (!root->right) return sumNumbers(root->left, curSum);
    return (sumNumbers(root->left, curSum) + sumNumbers(root->right, curSum)) % 1003;
}
 
int Solution::sumNumbers(TreeNode* A) {
    return sumNumbers(A,0);
}
