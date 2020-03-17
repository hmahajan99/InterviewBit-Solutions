// Approach 1: Brute force, Time - O(n^3)
// A simple solution is to one by one consider every pair as first two elements of AP and check for the remaining elements

int Solution::solve(const vector<int> &A) {

    int n = A.size();
    if(n==0) return 0;

    int ans=1; 
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int d = A[j]-A[i];
            int a = A[j] + d;
            int len=2;
            ans = max(len,ans);
            for(int k=j+1;k<n;k++){
                if(A[k]==a){
                    len++;
                    ans=max(ans,len);
                    a+=d;
                }
            }
        }
    }
    
    return ans;
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up DP, O(n^2 logn)

int Solution::solve(const vector<int> &A) {
    int n=A.size();
    if(n<=2) return n;
    unordered_map<int,vector<int>> indices; // Reverse HashMap
    for(int i=0;i<n;i++){
        indices[A[i]].push_back(i);
    }
    
    // dp[i][j] => Max len of AP such that first 2 elements are A[i]&A[j]
    // dp[i][j] = 1 + dp[j][k] such that A[i],A[j],A[k] in A.P (if this is true for many k find k such that k>j and is closest to j)
    vector<vector<int>> dp(n,vector<int>(n,2));
    int maxLen=2;
    // for(int i=0;i<n;i++) dp[i][n-1]=2; First fill last col with 2
    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>i;j--){
            int Ak=2*A[j]-A[i]; // A[i]+A[k]=2*A[j]
            auto it=upper_bound(indices[Ak].begin(),indices[Ak].end(),j);
            if(it!=indices[Ak].end()){
                int k=*it;
                dp[i][j]=1+dp[j][k];
            } 
            maxLen=max(maxLen,dp[i][j]);
        }
    }
    return maxLen;
}

