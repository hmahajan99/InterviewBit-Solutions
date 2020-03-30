// Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.
// Example:
// Input: 	
// 1 2 3
// 4 5 6
// 7 8 9
// Return the following :
// [ 
//   [1],
//   [2, 4],
//   [3, 5, 7],
//   [6, 8],
//   [9]
// ]

// Approach 1
// With every movement, row increases by one, and the column decreases by one

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n=A.size();
    vector<vector<int>> ans;
    pair<int,int> startPoint(0,0); // row,col 
    while(startPoint.first<n&&startPoint.second<n){
        int i=startPoint.first,j=startPoint.second;
        vector<int> currentDiagonal;
        while(i<n&&j>=0){
            currentDiagonal.push_back(A[i][j]);
            i++;
            j--;
        }
        ans.push_back(currentDiagonal);
        if(startPoint.second<n-1) startPoint.second++;
        else startPoint.first++;
    }
    return ans;
}

/***************************************************************************************************************************/

// Approach 2

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n=A.size();
    vector<vector<int>> ans(2*n-1); // number of vectors in ans = 2*n-1
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i+j].push_back(A[i][j]); //sum of index values in 2d array gives the index in ans
        }
    }
    return ans;
}
