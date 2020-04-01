// Approach 1: Bottom Up

int Solution::minPathSum(vector<vector<int> > &A) {

    // n*m
    int n = A.size(),m=A[0].size();

    // dp[i][j] - min cost from (i,j) to (m-1,n-1)
    vector<vector<int>> dp(A);
    
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int x = INT_MAX;
            if(j<m-1) x=min(x,dp[i][j+1]);
            if(i<n-1) x=min(x,dp[i+1][j]);
            if(x!=INT_MAX) dp[i][j] += x;
        }
    }
    return dp[0][0];
    
}

// Alternatively,
// Let DP[i][j] store the minimum sum of numbers along the path from top left (0,0) to (i,j).
// Basically, DP[i][j] = A[i][j] + min(DP[i-1][j],DP[i][j-1]).
// Return DP[n-1][m-1] at end

/***************************************************************************************************************************/

// Approach 2: Top Down

vector<vector<int>> dp;

int minPath(int i,int j,vector<vector<int> > &A){
    int n = A.size(),m=A[0].size();
    if(i<0||i>=n||j<0||j>=m) return INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    int x = min(minPath(i,j+1,A),minPath(i+1,j,A));
    if(x==INT_MAX) x=0;
    return dp[i][j]=A[i][j]+x;
}

int Solution::minPathSum(vector<vector<int> > &A) {
    int n = A.size(),m=A[0].size();
    dp = vector<vector<int>>(n,vector<int>(m,-1));
    return minPath(0,0,A);
}