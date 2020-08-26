// Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.
// A : [  1 1 1
//        0 1 1
//        1 0 0 ]
// Output : 4 

// Approach 1: Brute Force
// The bruteforce approach is to look at all pairs of (i,j) to (k,l) and check if its filled with 1s. 
// This approach however is O(N^6) , N^4 ways to choose i,j,k,l and then N^2 elements in the square

/***************************************************************************************************************************/

// Approach 2: Can improve brute force to O(n^4) using PREFIX SUM
// Can calculate sum of a submatrix in O(1)
// Let dp[i][j] = Sum of all elements in submatrix (0,0) to (i,j)
// Precompute dp[i][j] => O(n^2) , dp[i][j] = A[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]
// For each pair (i,j) & (k,l) 
// Sum of all elements in submatrix = dp[k][l]-dp[i-1][l]-dp[k][j-1]+dp[i-1][j-1]

// Alternatively,
// We can improve from N^6 by storing in dp[i][j][k][l] if (i,j) to (k,l) is all filled with 1.
// dp[i][j][k][l] = 1 iff dp[i][j][k][l-1] = 1 && dp[i][j][k-1][l] = 1 and matrix[k][l] = 1.

/***************************************************************************************************************************/

// Approach 3: O(n^2)
// Using largest rectangle under histogram (using stack => O(n)) as a subroutine
// After creating the auxiliary matrix the largest rectangle will be the largest rectangle under histogram for a particular row

int largestRectangleArea(const vector<int> &A) {
    stack<int> s;
    int maxArea=INT_MIN;
    int i;
    for(i=0;i<A.size();){
        if(s.empty()||A[s.top()]<=A[i]){
            s.push(i);
            i++;
        }else{
            int h = A[s.top()];
            s.pop();
            if(s.empty()){
                maxArea=max(maxArea,h*i);
            }else{
                maxArea=max(maxArea,h*(i-s.top()-1));
            }            
        }
    }
    
    while(!s.empty()){
        int h = A[s.top()];
        s.pop();
        if(s.empty()){
            maxArea=max(maxArea,h*i);
        }else{
            maxArea=max(maxArea,h*(i-s.top()-1));
        }            
    }
   
    return maxArea;
    
}


int Solution::maximalRectangle(vector<vector<int> > &A) {
    
    int n = A.size();
    if(n==0) return 0;
    int m = A[0].size();
    if(m==0) return 0;
    
    vector<int> row = A[0];
    int maxArea = largestRectangleArea(row);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]==0){
                row[j]=0;
            }else{
                row[j]++;
            }
        }
        maxArea = max(maxArea,largestRectangleArea(row));
    }
    
    return maxArea;
}
