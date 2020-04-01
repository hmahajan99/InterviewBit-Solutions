// Given a matrix M of size nxm and an integer K, find the maximum element in the K manhattan distance neighbourhood for all elements in nxm matrix.
// In other words, for every element M[i][j] find the maximum element M[p][q] such that abs(i-p)+abs(j-q) <= K.

// dp[k][i][j] = ans. for kth manhattan distance for element (i,j)
// dp[k+1][i][j] = max(dp[k][i-1][j], dp[k][i+1][j], dp[k][i][j-1], dp[k][i][j+1], dp[k][i][j] )

vector<vector<int> > Solution::solve(int K, vector<vector<int> > &M) {
    int n = M.size();
    if(n==0) return M;
    int m = M[0].size();
    if(m==0) return M;
    
    int dx[] = {1,0,-1,0};
    int dy[] = {0,-1,0,1};
    
    for(int k=1;k<=K;k++){
        vector<vector<int>> newM(M);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int p=0;p<5;p++){
                    int x=i+dx[p],y=j+dy[p];
                    if(x>=0&&x<n&&y>=0&&y<m){
                        newM[i][j]=max(newM[i][j],M[x][y]);
                    }
                }
            }
        }
        M = newM;
    }
    
    return M;
    
    
}
