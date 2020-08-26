// Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// Example Input
//  A = [  [X, X, X, X],
//         [X, O, O, X],
//         [X, X, O, X],
//         [X, O, X, X] ]
// Example Output
//  A = [  [X, X, X, X],
//         [X, X, X, X],
//         [X, X, X, X],
//         [X, O, X, X] ]
// Example Explanation: 'O' in (4,2) is not surrounded by X from below.

// Note that all the chunks of O which remain as O are the ones which have at least one O connected to them which is on the boundary. Otherwise they will turn into X.
// Use BFS starting from ‘O’s on the boundary and mark them as ‘B’, then iterate over the whole board and mark ‘O’ as ‘X’ and ‘B’ as ‘O’.

void floodFill(vector<vector<char>> &A,int i,int j,char old,char newCh){
    int n=A.size(),m=A[0].size();
    if(i<0||i>=n||j<0||j>=m) return;
    if(A[i][j]!=old) return;
    A[i][j]=newCh;
    int dx[]={1,0,-1,0};
    int dy[]={0,-1,0,1};
    for(int k=0;k<4;k++){
        floodFill(A,i+dx[k],j+dy[k],old,newCh);
    }
}

void Solution::solve(vector<vector<char> > &A) {
    
    // TRY BFS TOO
    
    int n = A.size(),m=A[0].size(); // n*m
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]=='O') A[i][j]='-';
        }
    }
    for(int i=0;i<n;i++){
        if(A[i][0]=='-') floodFill(A,i,0,'-','O');
        if(A[i][m-1]=='-') floodFill(A,i,m-1,'-','O');
    }
    for(int i=0;i<m;i++){
        if(A[0][i]=='-') floodFill(A,0,i,'-','O');
        if(A[n-1][i]=='-') floodFill(A,n-1,i,'-','O');
    }
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(A[i][j]=='-') floodFill(A,i,j,'-','X');
        }
    }
    
    
}