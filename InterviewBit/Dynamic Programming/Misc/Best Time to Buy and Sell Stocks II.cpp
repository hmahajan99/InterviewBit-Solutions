// Bucket - Adhoc

// Approach 1:  Observation based solution
// I will never buy a stock and sell it in loss.
// If A[i] < A[i+1], I will always buy a stock on i and sell it on i+1.
// Can sell and buy the same stock on same day

int Solution::maxProfit(const vector<int> &A) {

    int n = A.size();
    int p=0;
    
    for(int i=0;i<n-1;i++){
        if(A[i]<A[i+1]) p+=A[i+1]-A[i];
    }
    
    return p;
}

/***************************************************************************************************************************/

// Approach 2: DP based solution
// Let Dp[i] = max profit you can gain in region (i,i+1,….,n).
// Then Dp[i] = max(Dp[i+1],-A[i] + max( A[j]+Dp[j] st j > i ) )

