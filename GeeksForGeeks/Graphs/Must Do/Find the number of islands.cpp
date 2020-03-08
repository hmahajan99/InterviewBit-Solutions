// Problem => Counting number of components in an undirected graph

// Approach 1 : DFS, Time O(NM)

/*you are required to complete this method*/
/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/

bool isValid(int i,int j,int N,int M){
    if(i<0||i>=N||j<0||j>=M) return false;
    return true;
}

void dfs(int i,int j,int N,int M,vector<int> A[],vector<vector<bool>> &vis){
    vis[i][j]=true;
    int dx[]={1,1,0,-1,-1,-1,0,1};
    int dy[]={0,-1,-1,-1,0,1,1,1};
    for(int k=0;k<8;k++){
        int x = i+dx[k], y = j+dy[k]; 
        if(isValid(x,y,N,M)&&A[x][y]==1&&!vis[x][y]){
            dfs(x,y,N,M,A,vis);
        }
    }
}

int findIslands(vector<int> A[], int N, int M){
    vector<vector<bool>> vis(N,vector<bool>(M,false));
    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!vis[i][j]&&A[i][j]==1){
                dfs(i,j,N,M,A,vis);
                ans++;
            }
        }
    }
    return ans;
}

/***************************************************************************************************************************/

// Approach 2 : Using BFS, Better => No STACK OVERFLOW

/*you are required to complete this method*/
/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/

bool isValid(int i,int j,int N,int M){
    if(i<0||i>=N||j<0||j>=M) return false;
    return true;
}

void bfs(int i,int j,int N,int M,vector<int> A[],vector<vector<bool>> &vis){
    int dx[]={1,1,0,-1,-1,-1,0,1};
    int dy[]={0,-1,-1,-1,0,1,1,1};
    queue<pair<int,int>> q;
    vis[i][j]=true;
    q.push({i,j});
    while(!q.empty()){
        pair<int,int> node=q.front();
        q.pop();
        int nodeX=node.first,nodeY=node.second;
        for(int k=0;k<8;k++){
            int x = nodeX+dx[k], y = nodeY+dy[k]; 
            if(isValid(x,y,N,M)&&A[x][y]==1&&!vis[x][y]){
                vis[x][y]=true;
                q.push({x,y});
            }
        }
    }
}

int findIslands(vector<int> A[], int N, int M){
    vector<vector<bool>> vis(N,vector<bool>(M,false));
    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!vis[i][j]&&A[i][j]==1){
                bfs(i,j,N,M,A,vis);
                ans++;
            }
        }
    }
    return ans;
}

