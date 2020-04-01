// Approach 1: Bottom Up

int Solution::calculateMinimumHP(vector<vector<int> > &A) {

    int n=A.size(),m=A[0].size(); // n*m
    
    // dp[i][j] - knight’s minimum initial health required to reach from (i,j) to (n-1,m-1) 
    vector<vector<int>> dp(n,vector<int>(m));
    
    // Start from bottom right
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1&&j==m-1){
                dp[i][j] = (A[i][j]<0)?(-A[i][j]+1):1;
                continue;
            }
            int x = INT_MAX;
            if(i<n-1) x = min(x,dp[i+1][j]);
            if(j<m-1) x = min(x,dp[i][j+1]);
            dp[i][j] = -A[i][j] + x;
            if(dp[i][j]<=0) dp[i][j] = 1;
        }
    }
    
    return dp[0][0];
}

/***************************************************************************************************************************/

// Approach 2: Top Down


vector<vector<int>> dp;

int calculateMin(int i,int j,const vector<vector<int>> &A){
    int n = A.size(),m=A[0].size();
    if(i<0||i>=n||j<0||j>=m) return INT_MAX;
    if(i==n-1&&j==m-1) return (A[i][j]<0)?(-A[i][j]+1):1;
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j] = -A[i][j] + min(calculateMin(i,j+1,A),calculateMin(i+1,j,A));
    if(dp[i][j]<=0) dp[i][j] = 1;
    return dp[i][j];
}

int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int n=A.size(),m=A[0].size(); // n*m
    // dp[i][j] - knight’s minimum initial health required to reach from (i,j) to (n-1,m-1) 
    dp = vector<vector<int>>(n,vector<int>(m,-1));
    return calculateMin(0,0,A);
}