// Given a binary search tree, write a function to find the kth smallest element in the tree.

// Approach 1 : Inorder Traversal => T = O(h+k)

// If question is Kth Largest Element in BST => Do REVERSE INORDER traversal

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* inorderTraversal(TreeNode* node, int K,int &i){
    if(node==NULL) return NULL;
    
    TreeNode *left = inorderTraversal(node->left,K,i);
    if(left) return left;
    
    i++;
    if(i==K) return node;
    
    TreeNode *right = inorderTraversal(node->right,K,i);
    if(right) return right;
    
    return NULL;
}  
 
int Solution::kthsmallest(TreeNode* root, int K) {
    int i=0;
    TreeNode *ans = inorderTraversal(root,K,i);
    if(!ans) return -1;
    return ans->val;
}

/***************************************************************************************************************************/

// Approach 2 : Using O(1) Extra Space => Morris Traversal

/***************************************************************************************************************************/

// Approach 3 : If modification in BST structure allowed,then 
// augment the BST (storing count of nodes in left subtree with every node).
