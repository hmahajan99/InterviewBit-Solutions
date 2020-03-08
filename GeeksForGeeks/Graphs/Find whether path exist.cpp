// Appraoch 1: Using DFS

using namespace std;

bool isValid(int i,int j,int n){
    if(i<0||j<0||i>=n||j>=n) return false;
    return true;    
}

bool hasPathDFS(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &vis,int n){
    if(grid[i][j]==0) return false;
    if(grid[i][j]==2) return true;
    vis[i][j]=true;
    int dx[]={1,0,-1,0};    
    int dy[]={0,-1,0,1};
    for(int k=0;k<4;k++){
        int x=i+dx[k],y=j+dy[k];
        if(isValid(x,y,n)&&!vis[x][y]){
           if(hasPathDFS(x,y,grid,vis,n)) return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sx,sy;
        vector<vector<int>> grid(n,vector<int>(n));
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
                if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
            }
        }
        cout<<hasPathDFS(sx,sy,grid,vis,n)<<"\n";
    }
	return 0;
}

/***************************************************************************************************************************/

// Approach 2 : Using BFS, Better => No STACK OVERFLOW

using namespace std;

bool isValid(int i,int j,int n){
    if(i<0||j<0||i>=n||j>=n) return false;
    return true;    
}

bool hasPathBFS(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &vis,int n){
    int dx[]={1,0,-1,0};    
    int dy[]={0,-1,0,1};
    queue<pair<int,int>> q;
    vis[i][j]=true;
    q.push({i,j});
    while(!q.empty()){
        pair<int,int> node=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int x=node.first+dx[k],y=node.second+dy[k];
            if(isValid(x,y,n)&&!vis[x][y]){
               if(grid[x][y]==2) return true;
               if(grid[x][y]==0) continue;
               vis[x][y]=true;
               q.push({x,y});
            }
        }
        
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sx,sy;
        vector<vector<int>> grid(n,vector<int>(n));
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
                if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
            }
        }
        cout<<hasPathBFS(sx,sy,grid,vis,n)<<"\n";
    }
	return 0;
}

// Alternate BFS: Using only queue<int> instead of pair

using namespace std;

bool isValid(int i,int j,int n){
    if(i<0||j<0||i>=n||j>=n) return false;
    return true;    
}

bool hasPathBFS(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &vis,int n){
    int dx[]={1,0,-1,0};    
    int dy[]={0,-1,0,1};
    queue<int> q;
    vis[i][j]=true;
    q.push(i*n+j);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int x=(node/n)+dx[k],y=(node%n)+dy[k];
            if(isValid(x,y,n)&&!vis[x][y]){
               if(grid[x][y]==2) return true;
               if(grid[x][y]==0) continue;
               vis[x][y]=true;
               q.push(x*n+y);
            }
        }
        
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sx,sy;
        vector<vector<int>> grid(n,vector<int>(n));
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
                if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
            }
        }
        cout<<hasPathBFS(sx,sy,grid,vis,n)<<"\n";
    }
	return 0;
}