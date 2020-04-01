// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

// Brute force : Try traversing each possible path from top to the leaves. Not an acceptable solution in this case.
// The triangle has a tree-like structure, which would lead people to think about traversal algorithms such as DFS. 
// However, if you look closely, you would notice that the adjacent nodes always share a ‘branch’. 
// In other word, there are overlapping subproblems. Also, suppose x and y are ‘children’ of k. 
// Once minimum paths from x and y to the bottom are known, the minimum path starting from k can be decided in O(1), that is optimal substructure. 
// Therefore, dynamic programming would be the best solution to this problem in terms of time complexity.

// Approach 1: Bottom Up
// Dont need O(n^2) space. Can solve with O(n) space.

int Solution::minimumTotal(vector<vector<int> > &A) {
    int n = A.size();
    vector<int> dp = A.back();
    // Move backward from the last row
    for(int i=n-2;i>=0;i--){
        vector<int> newdp(i+1);
        for(int j=0;j<=i;j++){
            newdp[j]=A[i][j]+min(dp[j],dp[j+1]);
        }
        dp=newdp;
    }
    return dp.front();
}

/***************************************************************************************************************************/

// Approach 2: Top Down, O(N^2) space

int minPath(int i,int j,const vector<vector<int>> &A,vector<vector<int>> &dp){
    int n = A.size();
    if(i==n-1) return A[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=A[i][j]+min(minPath(i+1,j,A,dp),minPath(i+1,j+1,A,dp));
}

int Solution::minimumTotal(vector<vector<int> > &A) {
    int n = A.size();
    vector<vector<int>> dp(n);
    for(int i=0;i<n;i++){
        dp[i]=vector<int>(i+1,-1);
    }
    return minPath(0,0,A,dp);
}