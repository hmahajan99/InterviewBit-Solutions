// Given an array of non-negative integers, A, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index.

// Approach 1: DP, O(n^2)

int Solution::canJump(vector<int> &A) {

    int n = A.size();
    if(n<=1) return true;
    
    vector<bool> dp(n);
    
    dp[0]=true;
    for(int i=1;i<n;i++){
        dp[i]=false;        
        for(int j=i-1;j>=0;j--){
            if(dp[j]&&i-j<=A[j]){
                dp[i]=true;
                break;
            }
        }
    }
    
    return dp[n-1];
}

/***************************************************************************************************************************/

// Approach 2: Greedy will work here, O(n)

int Solution::canJump(vector<int> &A) {

    int n = A.size();
    if(n<=1) return true;
    
    int jump=A[0];
    for(int i=1;i<n;i++){
        if(jump==0){
            return false;
        }else{
            jump--;
            jump=max(jump,A[i]);
        }
    }
    return true;
    
}