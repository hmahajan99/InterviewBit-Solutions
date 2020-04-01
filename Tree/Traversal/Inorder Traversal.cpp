// Approach 1 : Stack and Map based solution

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    if(A) s.push(A);
    unordered_map<TreeNode*,bool> visited;
    vector<int> ans;
    while(!s.empty()){
        TreeNode* top = s.top();
        if(top->left!=NULL&&!visited[top->left]){
            s.push(top->left);
        }else{
            visited[top] = true;
            ans.push_back(top->val);
            s.pop();
            if(top->right)  s.push(top->right);
        }
        
    }
    return ans;
}

/***************************************************************************************************************************/

// Approach 2 : Using Iterator

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class InorderIterator {
    public:
        stack<TreeNode *> myStack;

        InorderIterator(TreeNode *root) {
            pushAll(root);
        }

        bool hasNext() {
            return !myStack.empty();
        }

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
 
 
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    InorderIterator i(A);
    while(i.hasNext()){
        ans.push_back(i.next());
    }
    return ans;
}

/***************************************************************************************************************************/

// Approach 3 : Using Morris Traversal
// Inorder Tree Traversal without recursion and without stack!
// Time Complexity : O(n) If we take a closer look, we can notice that every edge of the tree is traversed at most two times. 
// And in the worst case, the same number of extra edges (as input tree) are created and removed.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* findPred(TreeNode* current){
    TreeNode* temp=current;
    temp=temp->left;
    while(temp->right!=NULL&&temp->right!=current){
        temp=temp->right;
    }
    return temp;
} 
 
vector<int> MorrisTraversal(TreeNode* root){
    vector<int> ans;
    TreeNode* current = root;
    while(current!=NULL){
        if(!current->left){
            // Visit current
            ans.push_back(current->val);
            current = current->right;
        }else{
            TreeNode* predecessor = findPred(current);
            if(!predecessor->right){
                predecessor->right = current;
                current = current ->left;
            }else{
                predecessor->right = NULL;
                // Visit current
                ans.push_back(current->val);
                current=current->right;;
            }
        }
    }
    return ans;
} 

vector<int> Solution::inorderTraversal(TreeNode* A) {
    return MorrisTraversal(A);
}

