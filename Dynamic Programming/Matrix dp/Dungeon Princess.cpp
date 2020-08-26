// The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. 
// The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.
// The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
// Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0’s) or contain magic orbs that increase the knight’s health (positive integers).
// In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
// Write a function to determine the knight’s minimum initial health so that he is able to rescue the princess.
// For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path
// RIGHT-> RIGHT -> DOWN -> DOWN.
// -2 -3  3
// -5 -10 1
// 10 30 -5


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