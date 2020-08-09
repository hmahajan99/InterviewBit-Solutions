// Given two Binary Trees A and B, you need to merge them in a single binary tree.
// The merge rule is that if two nodes overlap, then sum of node values is the new value of the merged node.
// Otherwise, the non-null node will be used as the node of new tree.

// Example Input
//       2         3               5
//      / \       / \             /  \ 
//     1   4     6   1    =>     7    5
//    /          \    \         / \     \ 
//   5            2    7       5   2     7

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    if(!A&&!B) return NULL;
    int val = (A?A->val:0) + (B?B->val:0);
    TreeNode *root = new TreeNode(val);
    root->left = solve(A?A->left:NULL,B?B->left:NULL);
    root->right = solve(A?A->right:NULL,B?B->right:NULL);
    return root;
}

// Alternative: In Place Merge

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    if(!A) return B;
    if(!B) return A;
    A->val += B->val;
    A->left = solve(A->left,B->left);
    A->right = solve(A->right,B->right);
    return A;
}
