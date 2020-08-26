// Determine if a Sudoku is valid.
// The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.
// Note: A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

bool Row(const vector<string> A){
    for(string s:A){
        unordered_map<char,int> m;
        for(char c:s){
            if(c!='.'&&m[c]>0) return false;
            m[c]++;
        }
    }
    return true;
}

bool Col(const vector<string> A){
    for(int i=0;i<9;i++){
        unordered_map<char,int> m;
        for(int j=0;j<9;j++){
            if(A[j][i]!='.'&&m[A[j][i]]>0) return false;
            m[A[j][i]]++;
        }
    }
    return true;
}

bool Box(const vector<string> A){
    int i=0,j=0;
    while(i!=9){
        unordered_map<char,int> m;
        for(int row=i;row<=i+2;row++){
            for(int col=j;col<=j+2;col++){
                if(A[row][col]!='.'&&m[A[row][col]]>0) return false;
                m[A[row][col]]++;
            }
        }
        j+=3;
        if(j==9){
            j=0;
            i+=3;
        }
    }
    return true;
}

int Solution::isValidSudoku(const vector<string> &A) {
    if(Row(A)&&Col(A)&&Box(A)) return 1;
    return 0;
}
