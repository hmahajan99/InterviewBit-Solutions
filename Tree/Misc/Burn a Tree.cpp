// Given a binary tree denoted by root node A and a leaf node B from this tree.
// It is known that all nodes connected to a given node (left child, right child and parent) get burned in 1 second. 
// Then all the nodes which are connected through one intermediate get burned in 2 seconds, and so on.
// You need to find the minimum time required to burn the complete binary tree.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int ans;

pair<int,bool> f(TreeNode* A, int B){
    if(!A->left&&!A->right){
        if(A->val==B) return {0,true};
        return {0,false};
    }
    
    if(!A->left||!A->right){
        TreeNode *node = A->left ? A->left : A->right;
        pair<int,bool> p = f(node,B);
        if(p.second) ans = max(ans,p.first+1);
        return {p.first+1,p.second};
    }

    pair<int,bool> r = f(A->right,B);
    pair<int,bool> l = f(A->left,B);
    
    if(!l.second&&!r.second) return {1+max(l.first,r.first),false};

    ans=max({ans,r.first+l.first+2});
    if(r.second) return {r.first+1,true};
    else return {l.first+1,true};
} 
 
int Solution::solve(TreeNode* A, int B) {
    ans = 0;
    f(A,B);
    return ans;
}
