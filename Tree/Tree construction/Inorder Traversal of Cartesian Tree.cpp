// Approach 1 : T => O(nlogn)
// T(n) = 2T(n/2)+c*n

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* helper(vector<int>const &A,int si,int ei){
    if(si>ei) return NULL;
    if(si==ei) return new TreeNode(A[si]);
    
    int maxIndex=si;
    for(int i=si+1;i<=ei;i++){
        if(A[i]>A[maxIndex]){
            maxIndex=i;
        }
    }
    
    TreeNode *root = new TreeNode(A[maxIndex]);
    root->left = helper(A,si,maxIndex-1);
    root->right = helper(A,maxIndex+1,ei);
    return root;
    
} 
 
TreeNode* Solution::buildTree(vector<int> &inorderTraversal) {
    return helper(inorderTraversal,0,inorderTraversal.size()-1);
}

/***************************************************************************************************************************/

// Approach 2 : TODO Use segment tree to find max 
// [Build Time= O(n)] + [T(n) = 2T(n/2)+c*logn]  O(nloglogn) ?
