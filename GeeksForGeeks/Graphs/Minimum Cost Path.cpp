// Minimum Cost Path with Left, Right, Bottom and Up moves allowed
// It is not possible to solve this problem using dynamic programming because here current state depends not only on right and bottom cells but also on left and upper cells.
// Approach: Dijkstra on 2D Grid (Using set)
// Note : It is assumed that negative cost cycles do not exist in input matrix.

using namespace std;
typedef pair<int,int> point; // NOTE IMP!!!=> using typedef

bool isValid(int i,int j,int n){
    if(i<0||i>=n||j<0||j>=n) return false;
    return true;
}

int dijkstra(int n,vector<vector<int>> &grid){
    int dx[]={1,0,-1,0};
    int dy[]={0,-1,0,1};
    vector<vector<int>> cost(n,vector<int>(n,INT_MAX));
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    set<pair<int,point>> s; // cost (x,y)
    cost[0][0]=grid[0][0];
    vis[0][0]=true;
    s.insert({cost[0][0],{0,0}}); // IMP: SYNTAX
    while(!s.empty()){
        point pt = (*s.begin()).second;
        int dist = (*s.begin()).first;
        s.erase(s.begin()); 
        for(int k=0;k<4;k++){
            int x=pt.first+dx[k],y=pt.second+dy[k];
            if(isValid(x,y,n)){
                if(cost[pt.first][pt.second]+grid[x][y]<cost[x][y]){
                    auto it=s.find({cost[x][y],{x,y}});
                    if(it!=s.end()) s.erase(it);
                    cost[x][y]=cost[pt.first][pt.second]+grid[x][y];
                    s.insert({cost[x][y],{x,y}}); // IMP: SYNTAX
                }
            }
        }
    }
    return cost[n-1][n-1];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> grid(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>grid[i][j];
            }
        }
        cout<<dijkstra(n,grid)<<"\n";
    }
	return 0;
}