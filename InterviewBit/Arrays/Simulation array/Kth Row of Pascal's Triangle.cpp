// Given an index k, return the kth row of the Pascal’s triangle.
// Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.
// Example: Input : k = 3
// Return : [1,3,3,1]

// Approach 1: Generating rows one by one
// Time Complexity=O(k^2) , Space Complexity=O(k) as we only need to keep 2 rows

vector<int> Solution::getRow(int k) {

    vector<int> row;
    if(k<0) return row;
    
    for(int i=0;i<=k;i++){
        vector<int> newRow(i+1);
        for(int j=0;j<newRow.size();j++){
            if(j==0||j==newRow.size()-1) newRow[j]=1;
            else{
                newRow[j] = row[j] + row[j-1]; 
            }
        }
        row = newRow;
    }
    
    return row;
}

/***************************************************************************************************************************/

// Approach 2: Using nCr+1 / nCr = (n-r) / (r+1) 
// Time Complexity=O(k) , Space Complexity=O(k) 

vector<int> Solution::getRow(int k) {

    vector<int> row;
    if(k<0) return row;

    // nCr+1 / nCr = (n-r) / (r+1) 

    int kCr=1;
    for(int r=0;r<=k;r++){
        row.push_back(kCr);
        kCr = ( kCr*(k-r) ) / (r+1);
    }
    
    return row;
}
