// Approach 1: Bottom Up DP ,O(n^2)

int Solution::lis(const vector<int> &A) {

    int n = A.size();
    vector<int> dp(n); // dp[i] - Length of longest increasing subsequence ending at A[i]
    dp[0]=1;
    for(int i=1;i<n;i++){
        dp[i]=1;
        for(int j=i-1;j>=0;j--){
            if(A[j]<A[i]) dp[i] = max(dp[i],dp[j]+1);
        }
    }

    return *max_element(dp.begin(),dp.end());
    
}

/***************************************************************************************************************************/

// Approach 2: Top Down DP, O(n^2)

int lisRecursive(int i,const vector<int> &A,vector<int> &dp){
    if(dp[i]!=-1) return dp[i];
    dp[i]=1;
    for(int j=i-1;j>=0;j--){
        if(A[j]<A[i]) dp[i] = max(dp[i],lisRecursive(j,A,dp)+1);
    }
    return dp[i];    
}


int Solution::lis(const vector<int> &A) {
    int n = A.size();
    vector<int> dp(n,-1);
    for(int i=0;i<n;i++) dp[i]=lisRecursive(i,A,dp);
    return *max_element(dp.begin(),dp.end());
}

/***************************************************************************************************************************/

// Approach 3: Using Binary Search, O(NlogN)
// If want sequence also can make a parent array


int Solution::lis(const vector<int> &A) {
    int n = A.size();
    vector<int> t(n,-1); // t[i] = minimum last element of all LIS of len i+1
    int lenLongestLIS = 0;
    for(int i=0;i<n;i++){
        int pos=lower_bound(t.begin(),t.begin()+lenLongestLIS,A[i])-t.begin();
        t[pos]=A[i];
        if(pos==lenLongestLIS) lenLongestLIS++;
    }
    return lenLongestLIS;
}