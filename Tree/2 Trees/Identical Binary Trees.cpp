// Given two binary trees, write a function to check if they are equal or not.
// Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

// Approach 1: Recursive

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(!A&&!B) return 1;
    if(!A||!B) return 0;
    return (A->val==B->val)&&isSameTree(A->left,B->left)&&isSameTree(A->right,B->right);
}

/***************************************************************************************************************************/

// Approach 2 : Iterative, Level Order

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(!A&&!B) return true;
    if(!A||!B) return false;
    queue<TreeNode*> q1;
    queue<TreeNode*> q2;
    q1.push(A);
    q2.push(B);
    while(!q1.empty()&&!q2.empty()){
        TreeNode *front1=q1.front(),*front2=q2.front();
        q1.pop();
        q2.pop();

        if(front1->val!=front2->val) return false;
        
        if(front1->left&&front2->left){
            q1.push(front1->left);
            q2.push(front2->left);
        }else if(front1->left||front1->left){
            return false;
        }
        
        if(front1->right&&front2->right){
            q1.push(front1->right);
            q2.push(front2->right);
        }else if(front1->right||front1->right){
            return false;
        }

    }

    return true;

}
