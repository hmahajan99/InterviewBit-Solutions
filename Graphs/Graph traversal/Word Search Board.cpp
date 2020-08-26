// Given a 2D board and a word, find if the word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
// The cell itself does not count as an adjacent cell.
// The same letter cell may be used more than once.

// Given board =
// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]
// word = "ABCCED", -> returns 1,
// word = "SEE", -> returns 1,
// word = "ABCB", -> returns 1,
// word = "ABFSAB" -> returns 1
// word = "ABCD" -> returns 0

// Approach 1: Using DFS, BFS gives MLE 

// Lets look at the bruteforce approach.
// You iterate over every cell of the matrix to explore if it could be the starting point. 
// Then for every neighboring character which has the same character as the next character in the string, we explore if rest of the string can be formed using that neighbor cell as the starting point.
// To sum it up,
// exist(board, word, i , j) is true if for any neighbor (k,l) of (i,j) exist(board, word[1:], k, l) is true
// Now note that we could memoize the answer for exist(board, word suffix length, i, j).

class QueueNode{
public:
    int i,j,len;
};

bool isValid(int i,int j,int n,int m){
    if(i<0||i>=n||j<0||j>=m) return false;
    return true;
}

bool bfs(vector<string> &A, string B){
    // bfs gives MLE
    int n=A.size(),m=A[0].size();
    int len = B.size();
    int dx[]={1,0,-1,0};
    int dy[]={0,-1,0,1};
    queue<QueueNode> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==B.front()) q.push({i,j,1});
        }
    }
    while(!q.empty()){
        QueueNode node = q.front();
        q.pop();
        if(node.len==len) return true;
        for(int k=0;k<4;k++){
            int x=node.i+dx[k],y=node.j+dy[k];
            if(isValid(x,y,n,m)&&A[x][y]==B[node.len]){
                q.push({x,y,node.len+1});
            }
        }
    }
    return false;
}

bool dfsUtil(int x,int y,vector<string> &A, int i, string B){
    int n=A.size(),m=A[0].size();
    if(i==B.length()) return true;
    if(!isValid(x,y,n,m)) return false;
    if(A[x][y]!=B[i]) return false;
    int dx[]={1,0,-1,0};
    int dy[]={0,-1,0,1};    
    for(int k=0;k<4;k++){
        int x1=x+dx[k],y1=y+dy[k];
        if(dfsUtil(x1,y1,A,i+1,B)) return true;
    }
    return false;
}

bool dfs(vector<string> &A,string B){
    int n=A.size(),m=A[0].size();
    int len = B.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==B.front()){
              if(dfsUtil(i,j,A,0,B)) return true;   
            } 
        }
    }
    return false;
}

int Solution::exist(vector<string> &A, string B) {
    //return bfs(A,B); IMP NOTE!!=> IMP: BFS gives MLE
    return dfs(A,B); // NOTE: DFS works fine 
}
