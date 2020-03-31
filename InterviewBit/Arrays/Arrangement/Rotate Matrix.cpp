// You are given an n x n 2D matrix representing an image.
// Rotate the image by 90 degrees (clockwise).
// You need to do this in place.
// A :
// [
//   [1, 2, 3]
//   [4, 5, 6]
//   [7, 8, 9]
// ]
// The expected returned value :
// [7 4 1 ] 
// [8 5 2 ] 
// [9 6 3 ]

// Approach: In Place

// The idea is simple. Transform each row of source matrix into required column of final matrix.
// We can observe that
// first row of source ------> last column of destination
// second row of source ------> last but-one column of destination
// so ... on
// last row of source ------> first column of destination
// Thus, if we were allowed extra memory, the solution should be easy.
//     result[j][matrix.size() - i - 1] = matrix[i][j];

void Solution::rotate(vector<vector<int> > &A) {
    
    int n = A.size();
    for(int i=0;i<n/2;i++){
        // Top should go from (i,i) to (i,n-2-i)
        // top row = left column = i 
        // bottom row = right column = n-1-i 
        for(int j=i;j<n-1-i;j++){
            // int top = A[i][j];
            // int right = A[j][n-1-i];
            // int bottom = A[n-1-i][n-1-j];
            // int left = A[n-1-j][i];
            
            int temp = A[i][j];
            A[i][j] = A[n-1-j][i]; // top <- left
            A[n-1-j][i] = A[n-1-i][n-1-j]; // left <- bottom
            A[n-1-i][n-1-j] = A[j][n-1-i]; // bottom <- right
            A[j][n-1-i] = temp; // right <- top
            
        }
    }
    
}
