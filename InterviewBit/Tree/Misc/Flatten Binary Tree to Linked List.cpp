// Bucket - Linkedlist tree

// Approach 1 : Using constant space

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
If you notice carefully in the flattened tree, each node’s right child points to the next node of a pre-order traversal.
Now, if a node does not have left node, then our problem reduces to solving it for the node->right.
If it does, then the next element in the preorder traversal is the immediate left child. 
But if we make the immediate left child as the right child of the node, then the right subtree will be lost. 
So we figure out where the right subtree should go. In the preorder traversal, the right subtree comes right after the rightmost element in the left subtree.
So we figure out the rightmost element in the left subtree, and attach the right subtree as its right child. 
We make the left child as the right child now and move on to the next node.
          1
        /   \
       2     5
      / \     \
     3   4     6
        
          1
           \
            2     
           / \     
          3   4
               \
                5
                 \
                  6
*/

TreeNode* rightMost(TreeNode* node){
    while(node->right){
        node=node->right;
    }
    return node;
}

TreeNode* Solution::flatten(TreeNode* root) {

    TreeNode* current = root;
    while(current!=NULL){
        if(!current->left){
            current=current->right;
        }else{
            TreeNode* LrightMost = rightMost(current->left);
            LrightMost->right=current->right;
            current->right=current->left;
            current->left=NULL;
            current=current->right;
        }
    }
    
    return root;

}

/***************************************************************************************************************************/

// Approach 2: Recursive solution

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

pair<TreeNode*,TreeNode*> flattenUtil(TreeNode* root){
    if(!root) return {NULL,NULL};
    auto p1 = flattenUtil(root->left);
    auto p2 = flattenUtil(root->right);
    root->left=NULL;
    TreeNode *head=root,*tail=root;
    if(p1.first){
        tail->right=p1.first;
        tail=p1.second;
    } 
    if(p2.first){
        tail->right=p2.first;
        tail=p2.second;
    }
    //tail->right=NULL;
    return {head,tail};
} 
 
TreeNode* Solution::flatten(TreeNode* A) {
    return flattenUtil(A).first;
}
