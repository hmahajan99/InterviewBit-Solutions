// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
// Example : Input : [1, 10, 5]
// Output : 5 
// You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
// You may also assume that the difference will not overflow.

// Approach 1: Sorting O(nlogn)

int Solution::maximumGap(const vector<int> &A) {
    if(A.size()==1) return 0;
    vector<int> B(A);
    sort(B.begin(),B.end());
    int diff=INT_MIN;
    for(int i=0;i<B.size()-1;i++){
        diff=max(diff,B[i+1]-B[i]);
    }
    return diff;
}

/***************************************************************************************************************************/

// Approach 2: TODO 
// O(n) solution using bucketing 
