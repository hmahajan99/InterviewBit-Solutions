// APPROACH 1 : Recursive

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

    bool isSymmetricRec(TreeNode* node1,TreeNode* node2){
        if(!node1&&!node2) return true;
        if(!node1||!node2) return false;
        return node1->val==node2->val && isSymmetricRec(node1->left,node2->right) && isSymmetricRec(node1->right,node2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetricRec(root->left,root->right);
    }
};

/***************************************************************************************************************************/

// APPROACH 2 : Iterative

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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q1,q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty()&&!q2.empty()){
            TreeNode *n1=q1.front(), *n2=q2.front();
            q1.pop();
            q2.pop();
            if(n1&&n2){
                if(n1->val!=n2->val) return false;
                q1.push(n1->left);
                q1.push(n1->right);
                q2.push(n2->right);
                q2.push(n2->left);
            }else if(n1||n2){
              return false;  
            } 
                       
        }
        return true;
    }
};
