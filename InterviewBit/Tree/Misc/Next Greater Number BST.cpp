// Ques == Inorder Successor in Binary Search Tree

// Approach 1 : Inorder traversal using Stack & Unordered_set - Time O(n)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::getSuccessor(TreeNode* root, int B) {
    TreeNode *successor=NULL;
    bool foundNode=false;
    stack<TreeNode*> s;
    unordered_set<TreeNode*> vis;
    if(root) s.push(root);
    while(!s.empty()){
        TreeNode *top=s.top();
        if(top->left&&vis.count(top->left)==0){
            s.push(top->left);
        }else{
            vis.insert(top);
            if(foundNode) return top;
            if(top->val==B) foundNode=true;
            s.pop();
            if(top->right) s.push(top->right);
        }
    }
    return NULL;
}

/***************************************************************************************************************************/

// Approach 2 : 2 cases, Time - O(h)

/* The Algorithm is divided into two cases on the basis of right subtree of the input node being empty or not.
1) If right subtree of node is not NULL, then succ lies in right subtree. Do following.
Go to right subtree and return the node with minimum key value in right subtree.
2) If right sbtree of node is NULL, then start from root and us search like technique. Do following.
Travel down the tree, if a node’s data is greater than root’s data then go right side, otherwise go to left side. */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* findNodeBSTRecursive(TreeNode* root, int val){
    if(!root) return NULL;
    if(val==root->val) return root;
    else if(val<root->val) return findNodeBSTRecursive(root->left,val);
    else return findNodeBSTRecursive(root->right,val);
} 

TreeNode* findNodeBST(TreeNode* root, int val){
    // Iterative
    TreeNode *temp=root;
    while(temp&&temp->val!=val){
        if(val<temp->val) temp=temp->left;
        else temp=temp->right;
    }
    if(temp&&temp->val==val) return temp;
    return NULL;
} 

TreeNode* findMinBST(TreeNode* root){
    while(root&&root->left){
        root=root->left;
    }
    return root;
}

TreeNode* nextGreaterAncestor(TreeNode* root, TreeNode* node){
    TreeNode *temp=root,*successor=NULL;
    while(temp!=node){
        if(node->val<temp->val){
            successor=temp;
            temp=temp->left;
        }else{
            temp=temp->right;
        }
    }
    return successor;
}
 
TreeNode* Solution::getSuccessor(TreeNode* root, int B) {
    //TreeNode *node = findNodeBSTRecursive(root,B);
    TreeNode *node = findNodeBST(root,B);
    if(node->right) return findMinBST(node->right);
    return nextGreaterAncestor(root,node);
}
