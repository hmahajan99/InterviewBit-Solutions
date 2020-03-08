using namespace std;

bool isValid(int i,int j,int n,int m){
    if(i<0||i>=n||j<0||j>=m) return false;
    return true;
}

int bfs(int x,int y,int n,int m,vector<vector<int>> &grid){
    if(grid[0][0]==0||grid[x][y]==0) return -1;
    int dx[]={1,0,-1,0};
    int dy[]={0,-1,0,1};
    vector<vector<bool>> vis(n,vector<bool>(m));
    vector<vector<int>> dist(n,vector<int>(m,-1));
    queue<pair<int,int>> q;
    vis[0][0]=true;
    dist[0][0]=0;
    q.push({0,0});
    while(!q.empty()){
        pair<int,int> node=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int x1=node.first+dx[k],y1=node.second+dy[k];
            if(isValid(x1,y1,n,m)&&!vis[x1][y1]&&grid[x1][y1]==1){
                vis[x1][y1]=true;
                dist[x1][y1]=dist[node.first][node.second]+1;
                if(x1==x&&y1==y) return dist[x][y];
                q.push({x1,y1});
            }
        }
    }
    return dist[x][y];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> grid(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        int x,y;
        cin>>x>>y;
        cout<<bfs(x,y,n,m,grid)<<"\n";
    }
	return 0;
}

// Alternate: More modular approach, Better

using namespace std;

class QueueNode{
    public:
    int x,y,dist;
    QueueNode(int x,int y,int dist){
        this->x=x;
        this->y=y;
        this->dist=dist;
    }
};

bool isValid(int i,int j,int n,int m){
    if(i<0||i>=n||j<0||j>=m) return false;
    return true;
}

int bfs(int x,int y,int n,int m,vector<vector<int>> &grid){
    // SOLUTION USING BFS(CANNOT USE DP)
    if(grid[0][0]==0||grid[x][y]==0) return -1;
    int dx[]={1,0,-1,0};
    int dy[]={0,-1,0,1};
    vector<vector<bool>> vis(n,vector<bool>(m));
    queue<QueueNode> q;
    vis[0][0]=true;
    q.push({0,0,0});
    while(!q.empty()){
        QueueNode node=q.front();
        q.pop();
        if(node.x==x&&node.y==y) return node.dist;
        for(int k=0;k<4;k++){
            int x1=node.x+dx[k],y1=node.y+dy[k];
            if(isValid(x1,y1,n,m)&&!vis[x1][y1]&&grid[x1][y1]==1){
                vis[x1][y1]=true;
                // IMP NOTE!!!!=> [SYNTAX] CAN USE INITIALIZER LIST FOR OWN CLASS ALSO
                q.push({x1,y1,node.dist+1});
            }
        }
    }
    return -1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> grid(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        int x,y;
        cin>>x>>y;
        cout<<bfs(x,y,n,m,grid)<<"\n";
    }
	return 0;
}