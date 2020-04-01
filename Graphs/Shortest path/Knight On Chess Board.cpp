// Minimum number of steps for the knight to move to the said point

// Approach: BFS, finding the shortest path in an unweighted graph

bool isValid(int i,int j,int n,int m){
    // board is (1,1) to (N,M)
    if(i<1||i>n||j<1||j>m) return false;
    return true;
}

int Solution::knight(int N, int M, int x1, int y1, int x2, int y2) {
    int dx[]={2,2,1,1,-1,-1,-2,-2};
    int dy[]={1,-1,2,-2,2,-2,1,-1};
    typedef pair<int,int> pt;
    queue<pair<pt,int>> q;
    vector<vector<bool>> vis(N+1,vector<bool>(M+1,false));
    vis[x1][y1]=true;
    q.push({{x1,y1},0});
    while(!q.empty()){
        pair<pt,int> front=q.front();
        q.pop();
        int fX=front.first.first,fY=front.first.second;
        if(fX==x2&&fY==y2) return front.second;
        for(int k=0;k<8;k++){
            int x = fX+dx[k], y = fY+dy[k];
            if(isValid(x,y,N,M)&&!vis[x][y]){
                vis[x][y]=true;
                q.push({{x,y},front.second+1});
            }
        }
    }
    return -1;
    
    
}
