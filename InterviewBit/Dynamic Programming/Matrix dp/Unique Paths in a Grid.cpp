// An obstacle and empty space is marked as 1 and 0 respectively in the grid.

// Approach 1: Top Down

bool isValid(int i,int j,int n,int m,vector<vector<int>> &A){
    // handle blocked cell also
    if(i<0||i>=n||j<0||j>=m||A[i][j]==1) return false;
    return true;
}

int helper(int i,int j,vector<vector<int> > &A,vector<vector<int> > &dp){
    int n = A.size();
    int m = A[0].size();

    if(!isValid(i,j,n,m,A)) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==n-1&&j==m-1) return dp[i][j]=1;

    int ways = helper(i,j+1,A,dp) + helper(i+1,j,A,dp);
    return dp[i][j] = ways;
}

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    vector<vector<int>> dp(A.size(),vector<int>(A[0].size(),-1));
    return helper(0,0,A,dp);
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int n=A.size(),m=A[0].size();
    vector<vector<int>> dp(n,vector<int>(m));
    // dp[i][j] => num of unique paths from (0,0) to (i,j)
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==1){
                dp[i][j]=0;
                continue;
            }

            if(i==0&&j==0){
                dp[0][0]=1;
            }else if(i==0){
                dp[0][j]=dp[0][j-1];
            }else if(j==0){
                dp[i][0]=dp[i-1][0];
            }else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
            
        }
    }
    
    return dp[n-1][m-1];
    
}