// Approach 1: Brute force, O(n^2)
// Try to find the max sequence start at every i 

/***************************************************************************************************************************/

// Approach 2: 2 pointer like sliding window, O(n)

// pointer i and j 
// i = j = 0
// iterate till i < N:
//         if(Number_of_Zeros_in_Current_range >= M) :
//                 reduce range
//         else :
//                 add element in range and update all variables

vector<int> Solution::maxone(vector<int> &A, int M) {
    int n=A.size();
    int ansIndex=-1,ansLength=0;
    int i=0,j=0;
    int zeroCount=0;
    while(i<n&&j<n){
        
        if(A[j]==1||zeroCount<M){
            // Add A[j] to window
            zeroCount+=(A[j]==0);
            j++;
            if(j-i>ansLength){
                ansLength=j-i;
                ansIndex=i;
            }
        }else{
            // Shrink window
            while(A[i]==1) i++;
            i++;
            if(zeroCount) zeroCount--; // if statement For edge case, when M=0
            if(i>j) j=i; // For edge case, when M=0
        }

    }
    
    vector<int> ans;
    while(ansLength--) ans.push_back(ansIndex++);
    return ans;
    
}
