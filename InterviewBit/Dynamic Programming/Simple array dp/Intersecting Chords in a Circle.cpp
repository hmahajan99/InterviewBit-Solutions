// Given a number N, return number of ways you can draw N chords in a circle with 2 x N points such that no 2 chords intersect.

// Approach 1: Top Down

#define lli long long

lli count(int n,int* dp){

    if(n==0) return 1;
    if(n==1) return 1;

    if(dp[n]!=-1) return dp[n];

    lli ans=0;
    
    // f(n) = sigma [i=0 to n-1] f(i)*f(n-1-i)
    // since every point is assigned one chord , fix point 1 and see in figure
    
    for(int i=0;i<=n-1;i++){
        ans += count(i,dp)*count(n-i-1,dp);
        ans %= (int)(1e9+7);
    }
    
    return dp[n] = ans;

}

int Solution::chordCnt(int n) {
    int* dp = new int[n+1];
    fill(dp,dp+n+1,-1);
    return count(n,dp);
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up

int Solution::chordCnt(int n) {
    if(n<=1) return 1;
    int* dp = new int[n+1];
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        long long count=0;
        for(int j=0;j<=i-1;j++){
            count+=(long long)dp[j]*dp[i-1-j];
            count%=(int)(1e9+7);
        }
        dp[i]=count;
    }
    return dp[n];
}
