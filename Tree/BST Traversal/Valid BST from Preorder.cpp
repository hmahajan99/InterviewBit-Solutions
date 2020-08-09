// You are given a preorder traversal A, of a Binary Search Tree.
// Find if it is a valid preorder traversal of a BST.

// Approach 1: O(n^2)
// Find the first greater value on right side of current node.
// All values after the above found greater value should be greater than current node.

bool isBST(vector<int> &A,int s,int e){
    if(s>e) return true;
    if(s==e) return true;

    int root = A[s];
    int r = s+1;
    while(r<=e){
        if(A[r]>root) break;        
        r++;
    }
 
    int temp = r;    
    while(temp<=e){
        if(A[temp]<root) return false;   
        temp++;
    }
    
    return isBST(A,s+1,r-1) && isBST(A,r,e);
 
}
 
int Solution::solve(vector<int> &A) {
    int n = A.size();
    return isBST(A,0,n-1);
}

/***************************************************************************************************************************/

// Approach 2:  Similar to Next (or closest) Greater Element problem, O(N)