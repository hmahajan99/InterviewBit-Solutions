// Given N x M character matrix A of O's and X's, where O = white, X = black.
// Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)

// Input 1:
//     A = [ OOOXOOO
//           OOXXOXO
//           OXOOOXO  ]
// Output 1:
//     3
// Explanation:
//     3 shapes are  :
//     (i)    X
//          X X
//     (ii)
//           X
//     (iii)
//           X
//           X

bool isValid(int i,int j,int n,int m){
    if(i<0||i>=n||j<0||j>=m) return false;
    return true;
}

void bfsConnected(int i,int j,vector<string> &A,vector<vector<bool>> &vis){
    int n=A.size(), m=A[0].size();    
    int dx[]={1,0,-1,0};
    int dy[]={0,-1,0,1};
    queue<pair<int,int>> q;
    vis[i][j]=true;
    q.push({i,j});
    while(!q.empty()){
        pair<int,int> cell = q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int x = cell.first+dx[k] , y = cell.second+dy[k];
            if(isValid(x,y,n,m)&&A[x][y]=='X'&&!vis[x][y]){
                vis[x][y]=true;
                q.push({x,y});
            }
        }
    }
}

int Solution::black(vector<string> &A) {
    int n = A.size();
    if(n==0) return 0;
    int m = A[0].size();
    if(m==0) return 0;
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    int components=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]=='X'&&!vis[i][j]){
                bfsConnected(i,j,A,vis);
                components++;
            }
        }
    }
    return components;
}