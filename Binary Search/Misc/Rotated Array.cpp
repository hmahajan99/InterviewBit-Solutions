// Suppose a sorted array A is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// Find the minimum element.
// The array will not contain duplicates.

// NOTE: If the number of rotation is x, then minimum element is A[x].
// QUES can also be find how many times is a sorted array rotated?

// Approach 1: Linear search

/***************************************************************************************************************************/

// Approach 2: Binary search
// NOTE: Also think about the case when there are duplicates. Does your current solution work? How does the time complexity change?


int Solution::findMin(const vector<int> &A) {
    int n=A.size();
    
    if(n==1) return A[0]; // Edge case

    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;

        if(mid>s&&A[mid]<A[mid-1]) return A[mid];
        if(mid<e&&A[mid]>A[mid+1]) return A[mid+1];
        
        if(A[s]<=A[mid]) s=mid+1; // Left part is sorted
        else e=mid-1; // Right part is sorted
    }
    
    return A[0]; // No pivot found => Array is sorted => minimum is A[0]
}
