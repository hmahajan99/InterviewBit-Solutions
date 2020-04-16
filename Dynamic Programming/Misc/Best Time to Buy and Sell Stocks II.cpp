// Bucket - Adhoc

// Say you have an array, A, for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit.
// You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
// You must sell the stock before you buy again

// Approach 1:  Observation based solution
// I will never buy a stock and sell it in loss.
// If A[i] < A[i+1], I will always buy a stock on i and sell it on i+1.
// Can sell and buy the same stock on same day

//               /       Do transaction when graph is rising
//    \        /
//     \   /\/
//      \/

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

