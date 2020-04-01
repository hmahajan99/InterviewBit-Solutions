// Bucket - Derived dp

// Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers
// is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.
// Note: You can choose more than 2 numbers.
// 1 <= A[i] <= 2000

// Approach 1: Bottom Up DP
// In other words, if we are on (x, y), then if we choose (x, y), we can't choose (x + 1, y), (x, y + 1) and (x + 1, y + 1). 
// We know that within a column, we can choose at max 1 element. 
// And choosing either of those elements is going to rule out choosing anything from the previous or next column. 
// This means that choosing V[0][i] or V[1][i] has identical bearing on the elements which are ruled out. 
// So, instead we replace each column with a single element which is the max of V[0][i], V[1][i].
// Here we can see that we have reduced our problem into another simpler problem.
// Now we want to find maximum sum of values where no 2 values are adjacent. 

int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    vector<int> dp(n,0); // dp[i] = Ans till ith column of A i.e A[0][i] and A[1][i]
    dp[0] = max(A[0][0],A[1][0]); 
    if(n>1) dp[1] = max(dp[0],max(A[0][1],A[1][1]));
    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-1],dp[i-2]+max(A[0][i],A[1][i]));
    }
    return dp.back();
}

/***************************************************************************************************************************/

// Approach 2: Top Down DP

int maxSum(int i,vector<vector<int>> &A,vector<int> &dp){
    int n = A[0].size();
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    return dp[i]=max(maxSum(i+1,A,dp),max(A[0][i],A[1][i])+maxSum(i+2,A,dp));
}

int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    vector<int> dp(n,-1);
    return maxSum(0,A,dp);
}