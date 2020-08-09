// Given a binary search tree T, where each node contains a positive integer, and an integer K, 
// you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTForwardIterator {
    public:
        stack<TreeNode *> myStack;

        BSTForwardIterator(TreeNode *root) {
            pushAll(root);
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            return !myStack.empty();
        }

        /** @return the next smallest number */
        int next() {
            TreeNode *tmpNode = myStack.top();
            myStack.pop();
            pushAll(tmpNode->right);
            return tmpNode->val;
        }

    private:
        void pushAll(TreeNode *node) {
            while (node != NULL) {
                myStack.push(node);
                node = node->left;
            }
        }
}; 

class BSTReverseIterator {
    public:
        stack<TreeNode *> myStack;

        BSTReverseIterator(TreeNode *root) {
            pushAll(root);
        }

        /** @return whether we have a next largest number */
        bool hasPrev() {
            return !myStack.empty();
        }

        /** @return the next largest number */
        int prev() {
            TreeNode *tmpNode = myStack.top();
            myStack.pop();
            pushAll(tmpNode->left);
            return tmpNode->val;
        }

    private:
        void pushAll(TreeNode *node) {
            while (node != NULL) {
                myStack.push(node);
                node = node->right;
            }
        }
}; 
 
 
 
int Solution::t2Sum(TreeNode* root, int K) {
    BSTForwardIterator i(root);
    BSTReverseIterator j  = BSTReverseIterator (root);
    
    int a = i.next();
    int b = j.prev();
    while(a<b){
        if(a+b==K) return 1;
        if(a+b<K) a = i.next();
        if(a+b>K) b = j.prev();
    }
    return 0;

}

// Approach 2 : More modular

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator {
    public:
        stack<TreeNode *> s;
        bool rev;
        BSTIterator(TreeNode *root,bool rev=false) {
            this->rev=rev;
            pushAll(root);
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            return !s.empty();
        }

        /** @return the next smallest number */
        int next() {
            TreeNode *tmpNode = s.top();
            s.pop();
            if(!rev) pushAll(tmpNode->right);
            else pushAll(tmpNode->left);
            return tmpNode->val;
        }

    private:
        void pushAll(TreeNode *node) {
            while (node) {
                s.push(node);
                if(!rev) node = node->left;
                else node = node->right;
            }
        }
}; 

int Solution::t2Sum(TreeNode* root, int K) {
    BSTIterator i(root);
    BSTIterator j  = BSTIterator (root,true);
    
    int a = i.next();
    int b = j.next();
    while(a<b){
        if(a+b==K) return 1;
        if(a+b<K) a = i.next();
        if(a+b>K) b = j.next();
    }
    return 0;

}