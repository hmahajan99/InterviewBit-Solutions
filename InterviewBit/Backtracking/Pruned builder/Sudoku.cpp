// Approach 1: canPlace in O(N) 

bool canPlace(vector<vector<char>> &board,int row,int col,char num){
    int n = board.size();
    
    for(int i=0;i<n;i++){
        if(board[row][i]==num || board[i][col]==num) return false;
    }
    
    int rn = sqrt(n);
    int sx = (row/rn)*rn , sy = (col/rn)*rn;
    for(int i=sx;i<sx+rn;i++){
        for(int j=sy;j<sy+rn;j++){
            if(board[i][j]==num) return false;
        }
    }
    
    return true;
}

bool generate(vector<vector<char>> &board,int row,int col){

    int n = board.size();
    if(row==n) return true;
    if(col==n) return generate(board,row+1,0);
    if(board[row][col]!='.') return generate(board,row,col+1);

    for(int number=1;number<=n;number++){
        if(canPlace(board,row,col,'0'+number)){
            board[row][col] = '0'+number;
            if(generate(board,row,col+1)) return true;
            board[row][col] = '.';
        }
    }
    return false;

}

void Solution::solveSudoku(vector<vector<char> > &board) {
    generate(board,0,0);
}

/***************************************************************************************************************************/

// Approach 2: canPlace in O(1) using boolean vectors

bool canPlace(int row,int col,int num,int rowHash[9][10],int colHash[9][10],int blockHash[3][3][10]){
    if(rowHash[row][num]||colHash[col][num]||blockHash[row/3][col/3][num]) return false;
    return true;
}


bool generate(vector<vector<char>> &board,int row,int col,int rowHash[9][10],int colHash[9][10],int blockHash[3][3][10]){

    if(row==9) return true;
    if(col==9) return generate(board,row+1,0,rowHash,colHash,blockHash);
    if(board[row][col]!='.') return generate(board,row,col+1,rowHash,colHash,blockHash);

    for(int num=1;num<=9;num++){
        if(canPlace(row,col,num,rowHash,colHash,blockHash)){
            board[row][col] = '0'+num;
            rowHash[row][num]=colHash[col][num]=blockHash[row/3][col/3][num]=1;
            if(generate(board,row,col+1,rowHash,colHash,blockHash)) return true;
            rowHash[row][num]=colHash[col][num]=blockHash[row/3][col/3][num]=0;
            board[row][col] = '.';
        }
    }
    return false;

}

void Solution::solveSudoku(vector<vector<char>> &board){
    int rowHash[9][10]={0}; 
    int colHash[9][10]={0}; 
    int blockHash[3][3][10]={0};
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            if(board[row][col]!='.'){
                int num=board[row][col]-'0';
                rowHash[row][num]=colHash[col][num]=blockHash[row/3][col/3][num]=1;
            }
        }
    }    
    generate(board,0,0,rowHash,colHash,blockHash);
}