// Say you have an array, A, for which the ith element is the price of a given stock on day i.
// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
// Return the maximum possible profit.

// Approach 1: O(N) Space
// Basically you need to find the maximum value of A[j]-A[i] where j>i.
// If you buy your stock on day i, you’d obviously want to sell it on the day its price is maximum after that day.
// So essentially at every index i, you need to find the maximum in the array in the suffix.

int Solution::maxProfit(const vector<int> &A) {

    int n = A.size();
    if(n==0) return 0;
    
    vector<int> dp(n); 
    // dp[i] = largest element from i to n-1
    dp[n-1] = A[n-1];
    for(int i=n-2;i>=0;i--){
        dp[i] = max(A[i],dp[i+1]);
    }
    
    int ans=0;
    for(int i=0;i<n-1;i++){
        // buy on day i
        ans=max(ans,-A[i]+dp[i+1]);
    }
    return ans;
}

/***************************************************************************************************************************/

// Approach 2: O(1) Space

int Solution::maxProfit(const vector<int> &A) {

    int n = A.size();
    if(n==0) return 0;
    
    int largest=A[n-1];
    int ans=0;
    for(int i=n-2;i>=0;i--){
        ans=max(ans,-A[i]+largest);
        largest=max(A[i],largest);
    }
    
    return ans;
}

// ALternatively,

int Solution::maxProfit(const vector<int> &A) {
    int ans = 0 ;
    int smallest =  INT_MAX; // min uptil now, buy here
    for(auto price:A){
        // Sell on this price
        ans = max(ans,price-smallest);
        smallest = min(price,smallest);
    }
    return ans;
}
