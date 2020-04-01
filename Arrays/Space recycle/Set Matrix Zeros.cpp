// Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.
// Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.
// Input:
//     [   [1, 0, 1],
//         [1, 1, 1],
//         [1, 0, 1]   ]
// Output:
//     [   [0, 0, 0],
//         [1, 0, 1],
//         [0, 0, 0]   ]

// Approach 1: Brute Force
// IMP NOTE: Cannot do IN PLACE since will cause OVERWRTING
// A simplistic solution is creating a copy of the matrix and working on top of it. 
// Additional space complexity will be O(M * N).

/***************************************************************************************************************************/

// Approach 2: The next better solution uses additional space complexity of O(M+N). 
// It works on the phenomenon that for every row, you only need to find if there is any element in the row which is 0.
// Similarly so for every column. Once that is known, all the rows with 0 can be set completely as 0 (and the same for columns).

/***************************************************************************************************************************/

// Approach 3: Constant additional space, re-using the space in first row and first column
// Then we need to know whether or not to set the first row and column to zeroes. 
// So, we use two booleans to store that information.

void Solution::setZeroes(vector<vector<int> > &A) {
    // m*n
    int m = A.size(),n=A[0].size();

    bool firstRow=false,firstCol=false;
    if(A[0][0]==0){
        firstRow=firstCol=true;        
    }else{
        // Does first row have zero?
        for(int i=1;i<m;i++){
            if(A[i][0]==0){
              firstCol = true;
              break;
            } 
        }
        // Does first column have zero?
        for(int i=1;i<n;i++){
            if(A[0][i]==0){
              firstRow = true;
              break;
            } 
        }
    }
    
    // find zeroes and store the info in first row and column
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(A[i][j]==0){
                A[i][0]=A[0][j]=0;
            }
        }
    }
    
    // set zeroes except the first row and column
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(A[i][0]==0||A[0][j]==0){
                A[i][j]=0;
            }
        }
    }
    
    // set zeroes for first row and column if needed
    if(firstRow){
        for(int j=0;j<n;j++) A[0][j]=0;
    }
    
    if(firstCol){
        for(int i=0;i<m;i++) A[i][0]=0;
    }
    
}