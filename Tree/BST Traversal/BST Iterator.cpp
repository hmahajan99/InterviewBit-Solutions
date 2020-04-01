/*
Approach 1 : Do an inorder traversal of the tree and store the entries in an array with the current pointer set to the start of the array. 
hasNext checks if the pointer is less than the size of the array. 
next() would return the element at the current position incrementing the position by 1.
However, this has an additional space complexity of O(N) where N = number of nodes in the tree.
*/

/***************************************************************************************************************************/

// NOTE: ITERATOR CAN BE USED TO DO INORDER TRAVERSAL OF ANY BINARY TREE

// Approach 2 : Use stack to keep track of the path from root to the current node, so we can move to the parent when needed.
// Space = O(h)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

stack<TreeNode*> s;

void pushAll(TreeNode *node) {
    while(node) {
        s.push(node);
        node = node->left;
    }
}

BSTIterator::BSTIterator(TreeNode *root) {
    pushAll(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !s.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* top = s.top();
    s.pop();
    pushAll(top->right);
    return top->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
