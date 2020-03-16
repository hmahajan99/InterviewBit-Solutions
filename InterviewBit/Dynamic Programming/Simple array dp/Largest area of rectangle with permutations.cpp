// Find the largest rectangle of 1’s with swapping of columns allowed
// The idea is to use an auxiliary matrix to store count of consecutive 1’s in every column. 
// Once we have these counts, we sort all rows of auxiliary matrix in non-increasing order of counts. 
// Finally traverse the sorted rows to find the maximum area.
// Note : After forming the auxiliary matrix each row becomes independent, hence we can swap or sort each row independently.
// It is because we can only swap columns, so we have made each row independent and find the max area of rectangle possible with row and column.
    // Input
    // 0 1 0 1 0  
    // 0 1 0 1 1
    // 1 1 0 1 0
    // Auxilaiary Matrix
    // 0 1 0 1 0 
    // 0 2 0 2 1
    // 1 3 0 3 0
    // After sorting
    // 1 1 0 0 0 
    // 2 2 1 0 0
    // 3 3 1 0 0 => There are 2 columns that can form a rectangle of height 3. That makes an area of 3*2=6

int Solution::solve(vector<vector<int> > &A) {

    // n*m
    int n=A.size(),m=A[0].size();

    vector<vector<int>> hist(n,vector<int>(m,0));
    for(int col=0;col<m;col++){
        hist[0][col] = A[0][col];
        for(int row=1;row<n;row++){
            if(A[row][col]==1){
                hist[row][col] = hist[row-1][col] + 1;
            }
        }
    }
    
    int maxArea = 0;
    for(int i=0;i<n;i++){
        sort(hist[i].begin(),hist[i].end(),greater<int>()); // Sort in descending order
        for(int j=0;j<m;j++){
            maxArea = max(maxArea,hist[i][j]*(j+1));
        }
    }
    
    return maxArea;
    
    
    
}
