// Given a matrix of integers A of size N x M and an integer B.
// Write an efficient algorithm that searches for integar B in matrix A.
// This matrix A has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than or equal to the last integer of the previous row.
// Return 1 if B is present in A, else return 0.

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int m = A.size(),n = A[0].size();
    int l=0,r=m*n-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(A[mid/n][mid%n]==B) return true;
        else if(A[mid/n][mid%n]<B) l=mid+1;
        else r=mid-1;
    }
    return false;
}
