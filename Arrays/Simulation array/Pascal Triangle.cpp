// Given numRows, generate the first numRows of Pascal’s triangle.
// Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
// Example: Given numRows = 5, Return
// [
//      [1],
//      [1,1],
//      [1,2,1],
//      [1,3,3,1],
//      [1,4,6,4,1]
// ]

// Approach
// Base cases numRows = 0, numRows = 1
// Notice that the first and last numbers in each row ( for row >= 2 ) are 1 and 1.

vector<vector<int>> Solution::solve(int numRows) {

    vector<vector<int>> triangle;
    if(numRows<=0) return triangle;
    
    for(int i=0;i<numRows;i++){
        vector<int> row(i+1);
        for(int j=0;j<row.size();j++){
            if(j==0||j==row.size()-1) row[j]=1;
            else row[j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
        triangle.push_back(row);
    }
    
    return triangle;
    
}
