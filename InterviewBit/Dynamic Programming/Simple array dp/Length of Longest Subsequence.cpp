// Given an array of integers, A of length N, find the length of longest subsequence which is first increasing then decreasing.
// Longest Bitonic Subsequence
// A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. Similarly, decreasing order sequence is considered Bitonic with the increasing part as empty.
// This problem is a variation of standard Longest Increasing Subsequence (LIS) problem
// NOTE: There exists a O(nLogn) solution for the LIS problem also. (TODO)

// Approach: DP
// Time Complexity: O(n^2)
// Auxiliary Space: O(n)

int Solution::longestSubsequenceLength(const vector<int> &A) {

    int n = A.size();

    // NOTE:  Pre defining size decreases time
    vector<int> dp1(n,1),dp2(n,1);

    // dp1[i] - Length of longest increasing subsequence ending at A[i]
    // O(n^2) DP
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(A[j]<A[i]){
                dp1[i] = max(dp1[i],dp1[j]+1);
            }
        }
    }
    
    // dp2[i] - Length of longest decreasing subsequence starting at A[i]
    // O(n^2) DP
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(A[j]<A[i]){
                dp2[i] = max(dp2[i],dp2[j]+1);
            }
        }
    }

    int maxLen=0;
    for(int i=0;i<n;i++){
        maxLen = max(maxLen,dp1[i]+dp2[i]-1);
    }
    return maxLen;
    
}
