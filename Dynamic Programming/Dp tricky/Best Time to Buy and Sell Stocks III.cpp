// Say you have an array, A, for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete at most 2 transactions.
// Return the maximum possible profit.
// Note: You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

// Approach 1: Bottom Up DP
// Time complexity is O(k * number of days ^ 2)
// dp[i][j] = max profit using at most i transactions up to day j (including day j) 
// dp[i][j] = max(dp[i][j-1], max(prices[j] - prices[m] + dp[i-1][m])) where m is 0...j-1

int maxProfitDP(const vector<int> &prices, int K){
    int n = prices.size();
    if (K==0||n==0) return 0;
    
    vector<vector<int>> dp(K+1,vector<int>(n,0));
    // dp[i][j] = max profit using at most i transactions up to day j (including day j) 
    for (int i=1;i<=K;i++) {
        for(int j=1;j<n; j++) {
            int maxVal=0;
            for (int m=0;m<j;m++) {
                maxVal = max(maxVal, prices[j] - prices[m] + dp[i-1][m]);
            }
            dp[i][j] = max(dp[i][j-1], maxVal);
        }
    }
    return dp[K][n-1];    
}

int Solution::maxProfit(const vector<int> &prices) {
    return maxProfitDP(prices,2);
}

/***************************************************************************************************************************/

// Approach 2: Optimizing approach 1
// Time complexity here is O(K * number of days)
// dp[i][j] = max(dp[i][j-1], prices[j] + maxDiff)
// maxDiff = max(maxDiff, dp[i-1][j] - prices[j])

int maxProfitDPFast(const vector<int> &prices, int K){
    int n = prices.size();
    if (K==0||n==0) return 0;
    
    vector<vector<int>> dp(K+1,vector<int>(n,0));
    for (int i=1;i<=K;i++) {
        int maxDiff = -prices[0];
        for (int j=1;j<n;j++) {
            dp[i][j] = max(dp[i][j-1], prices[j] + maxDiff);
            maxDiff = max(maxDiff, dp[i-1][j] - prices[j]);
        }
    }
    return dp[K][n-1];    
}

int Solution::maxProfit(const vector<int> &prices) {
    return maxProfitDPFast(prices,2);
}

/***************************************************************************************************************************/

// Approach 3: O(n) solution to find maximum profit by buying and selling a share at most twice
// A Simple Solution is to consider every index ‘i’ and do following
// Max profit with at most two transactions =
//        MAX {max profit with one transaction and subarray price[0..i] +
//             max profit with one transaction and aubarray price[i+1..n-1]  }
// i varies from 0 to n-1. 
// Maximum possible using one transaction can be calculated using the following O(n) algorithm
// Time complexity of above simple solution is O(n^2).

// We can do this O(n) using following Efficient Solution. The idea is to store the maximum possible profit of every subarray and solve the problem in the following two phases.
// 1) Create a table profit[0..n-1] and initialize all values in it 0.
// 2) Traverse price[] from right to left and update profit[i] such that profit[i] stores maximum profit achievable from one transaction in subarray price[i..n-1]
// 3) Traverse price[] from left to right and update profit[i] such that profit[i] stores maximum profit such that profit[i] contains maximum achievable profit from two transactions in subarray price[0..i].
// 4) Return profit[n-1]

// To do step 2, we need to keep track of the maximum price from right to left side and to do step 3, we need to keep track of the minimum price from left to right. 
