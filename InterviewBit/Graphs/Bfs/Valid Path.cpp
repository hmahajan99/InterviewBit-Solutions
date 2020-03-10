// Check if (i,j) is a valid point for all 0<=i<=x, 0<=j<=y. By valid point we mean that none of the circle should contain it.
// Now you know all the valid point in rectangle. You need to figure out if you can go from (0,0) to (x,y) through valid points. This can be done with any graph traversal algorithms like BFS/DFS.

// Approach 1: Using BFS

bool isSafe(int x1, int y1, int x2, int y2, int r){
    int d = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
    int r2 = r * r;
    return (d > r2);
}

bool isValid(int i,int j,int x,int y){
    if(i<0||j<0||i>x||j>y) return false;
    return true;    
}

bool hasPathBFS(int i,int j,int x,int y,vector<vector<bool>> &canPass){

    int dx[]={1,1,0,-1,-1,-1,0,1};
    int dy[]={0,-1,-1,-1,0,1,1,1};

    vector<vector<bool>> vis(x+1,vector<bool>(y+1,false)); 
    queue<pair<int,int>> q;
    if(canPass[i][j]){
        vis[i][j]=true;
        q.push({i,j});
    }
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        if(p.first==x&&p.second==y) return true;
        for(int k=0;k<8;k++){
            int i1=p.first+dx[k],j1=p.second+dy[k];
            if(isValid(i1,j1,x,y)&&!vis[i1][j1]&&canPass[i1][j1]){
                vis[i1][j1]=true;
                q.push({i1,j1});
            }
        }
    }
    
    return false;
}



string Solution::solve(int x, int y, int N, int R, vector<int> &Xc, vector<int> &Yc) {


    vector<vector<bool>> canPass(x+1,vector<bool>(y+1,true)); 
    
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            for(int k=0;k<N;k++){
                canPass[i][j] = isSafe(i,j,Xc[k],Yc[k],R);
                if(!canPass[i][j]) break;
            }
        }
    }
    
    if(hasPathBFS(0,0,x,y,canPass)) return "YES";
    return "NO";
}

/***************************************************************************************************************************/

// Approach 2: Using DFS

bool isSafe(int x1, int y1, int x2, int y2, int r){
    int d = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
    int r2 = r * r;
    return (d > r2);
}

bool isValid(int i,int j,int x,int y){
    if(i<0||j<0||i>x||j>y) return false;
    return true;    
}

int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,-1,-1,-1,0,1,1,1};

bool hasPathDFS(int i,int j,int x,int y,vector<vector<bool>> &vis,vector<vector<bool>> &canPass){

    if(!canPass[i][j]) return false;
    if(i==x&&j==y) return true;

    vis[i][j]=true;

    for(int k=0;k<8;k++){
        int i1=i+dx[k],j1=j+dy[k];
        if(isValid(i1,j1,x,y)&&!vis[i1][j1]){
            vis[i1][j1]=true;
            if(hasPathDFS(i1,j1,x,y,vis,canPass)) return true;
        }
    }

    return false;
}



string Solution::solve(int x, int y, int N, int R, vector<int> &Xc, vector<int> &Yc) {

    vector<vector<bool>> canPass(x+1,vector<bool>(y+1,true)); 
    
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            for(int k=0;k<N;k++){
                canPass[i][j] = isSafe(i,j,Xc[k],Yc[k],R);
                if(!canPass[i][j]) break;
            }
        }
    }
 
    vector<vector<bool>> vis(x+1,vector<bool>(y+1,false)); 
    if(hasPathDFS(0,0,x,y,vis,canPass)) return "YES";
    return "NO";
}
