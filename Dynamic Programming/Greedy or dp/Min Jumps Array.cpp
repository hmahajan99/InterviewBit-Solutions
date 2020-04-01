// Given an array of non-negative integers, A, of length N, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Return the minimum number of jumps required to reach the last index.
// If it is not possible to reach the last index, return -1.

// Approach: DP, Time & Space O(N) ,using 2 pointers

int Solution::jump(vector<int> &A) {
    int n = A.size();
    if(n==0) return 0;
    vector<int> minJumps(n,-1);
    minJumps[0]=0;
    int i=0,j=1; 
    for(;i<n;i++){
        if(minJumps[i]==-1) return -1;
        while(j<n&&j-i<=A[i]){
            minJumps[j]=minJumps[i]+1;
            j++;
        }
    }
    return minJumps[n-1];
}