// A simple observation is to notice that the strength on each row is larger or equal to the row above 
// and the strength on each column is also larger or equal to the column on its left.
// This means, we don’t really need to check every single sub-array.
// Note 1: Using Kadane’s 2D Max Sub-Matrix Sum O(N^3) will lead to TLE
// Note 2: Maximum answer might be negative.

// Based on the observation , we can assume that the largest sub-array strength may start from any point, but will definitely end on bottom-right cell (N,M).
// Therefore, we can use dynamic programming to find the sum of sub-matrix starting from the bottom-right cell (N,M) going up and left.
// DP[i][j] = A[i][j] + DP[i+1][j] + DP[i][j+1] - DP[i+1][j+1]

// Approach 1: Bottom Up

int get(int i,int j,const vector<vector<int>> &dp){
    int n = dp.size(),m=dp[0].size();
    if(i<0||i>=n||j<0||j>=m) return 0;
    return dp[i][j];
}

int Solution::solve(vector<vector<int> > &A) {

    // n*m
    int n = A.size(),m=A[0].size();
    vector<vector<int>> dp(n,vector<int>(m));
    // dp[i][j] stores sum of sub matrix from (m-1,n-1) to (i,j)
    // (m-1,n-1) <-- fixed(since in kind of a sorted order dont have to use kadane 2d )

    int ans=INT_MIN;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            dp[i][j] = A[i][j] + get(i+1,j,dp) + get(i,j+1,dp) - get(i+1,j+1,dp);
            ans = max(ans,dp[i][j]);
        }
    }
    
    return ans;
}

/***************************************************************************************************************************/

// Approach 2: Top Down

vector<vector<int>> dp;  // dp[i][j] stores sum of sub matrix from (m-1,n-1) to (i,j)
int ans;

int maxSubgrid(int i,int j,const vector<vector<int>> &A){
    int n = dp.size(),m=dp[0].size();
    if(i<0||i>=n||j<0||j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=A[i][j]+maxSubgrid(i,j+1,A)+maxSubgrid(i+1,j,A)-maxSubgrid(i+1,j+1,A);
    ans=max(ans,dp[i][j]);
    return dp[i][j];
}

int Solution::solve(vector<vector<int> > &A) {

    // n*m
    int n = A.size(),m=A[0].size();
    dp=vector<vector<int>>(n,vector<int>(m,-1));
    ans=INT_MIN;
    maxSubgrid(0,0,A);
    return ans;
}