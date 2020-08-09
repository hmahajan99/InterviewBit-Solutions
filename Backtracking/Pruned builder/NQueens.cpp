// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle.
// Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

// Approach 1: canPlace in O(N) 

bool canPlace(vector<string> &board,int N,int row,int col){
    // Col
    for(int i=0;i<=row;i++) if(board[i][col]=='Q') return false;
    // Left Diagonal
    for(int i=0;i<=min(row,col);i++) if(board[row-i][col-i]=='Q') return false;
    // Right Diagonal
    for(int i=0;i<=min(row,N-col);i++) if(board[row-i][col+i]=='Q') return false;
    
    return true;
}

void generate(int N,vector<string> &board,vector<vector<string>> &ans,int row){
    if(row==N){
        ans.push_back(board);
        return;
    }
    
    for(int j=0;j<N;j++){
        if(canPlace(board,N,row,j)){
            board[row][j]='Q';
            generate(N,board,ans,row+1);
            board[row][j]='.';
        }
    }
    
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<string> board(A,string(A,'.')); // string constructor
    vector<vector<string>> ans;
    generate(A,board,ans,0);
    return ans;
    
}

/***************************************************************************************************************************/

// Approach 2: canPlace in O(1) using boolean vectors

bool canPlace(int N,int x,int y,vector<bool> &col,vector<bool> &rd,vector<bool> &ld){
    if(col[y]||rd[x+y]||ld[x-y+N-1]) return false;
    return true;
}

void generate(int N,vector<string> &board,vector<vector<string>> &ans,int row,vector<bool> &col,vector<bool> &rd,vector<bool> &ld){
    if(row==N){
        ans.push_back(board);
        return;
    }
    
    for(int j=0;j<N;j++){
        if(canPlace(N,row,j,col,rd,ld)){
            board[row][j]='Q';
            col[j]=rd[row+j]=ld[row-j+N-1]=true;
            generate(N,board,ans,row+1,col,rd,ld);
            col[j]=rd[row+j]=ld[row-j+N-1]=false;
            board[row][j]='.';
        }
    }
    
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<bool> col(A,false);
    vector<bool> rd(2*A-1,false);
    vector<bool> ld(2*A-1,false);
    
    vector<string> board(A,string(A,'.')); // string constructor
    vector<vector<string>> ans;
    generate(A,board,ans,0,col,rd,ld);
    return ans;
    
}