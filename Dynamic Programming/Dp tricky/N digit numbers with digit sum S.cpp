// Approach 1: Top Down
// rec_Count(numDigits, sum) = ∑ rec_Count(numDigits-1,sum-x) where 0 <= x <= 9 && sum-x >= 0. 

#define mod (int)(1e9+7)
#define lli long long
lli count(int N,int S,bool zero,vector<vector<int>> &memo){
    
    if(N==0) return S==0;    
    if(S<0) return 0;
    
    if(memo[N][S]!=-1) return memo[N][S];
    
    lli ans=0;
    if(zero){
      ans+= count(N-1,S,true,memo);
      ans%=mod;
    } 
    for(int d=1;d<10;d++){
        ans+=count(N-1,S-d,true,memo);
        ans%=mod;
    }
    
    return memo[N][S]=ans;
}

int Solution::solve(int N, int S) {
    if(N==0) return 0;
    vector<vector<int>> memo(N+1,vector<int>(S+1,-1));
    return count(N,S,false,memo); 
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up

#define mod (int)(1e9+7)

int Solution::solve(int N, int S) {
    if(N==0) return 0;
    vector<vector<int>> dp(N+1,vector<int>(S+1,0));
    
    dp[0][0]=1; // Base case dp[0][s]=1 if s=0 else dp[0][s]=0
    
    for(int n=1;n<=N;n++){
        for(int s=0;s<=S;s++){
            if(n<N){
                dp[n][s]+=dp[n-1][s]; // digit 0;
                dp[n][s]%=mod;
            } 
            for(int d=1;d<=9;d++){
                if(s-d<0) break;
                dp[n][s]+=dp[n-1][s-d];
                dp[n][s]%=mod;
            }
        }
    }
    
    return dp[N][S]; 
}