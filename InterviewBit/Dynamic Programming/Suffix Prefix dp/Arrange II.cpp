// You are given a sequence of black and white horses, and a set of K stables numbered 1 to K.
// Take the product (number of white horses * number of black horses) for each stable and take the sum of all these products. This value should be the minimum among all possible accommodation arrangements

// Approach 1: Top Down
// You can have a state around [first X number of horses, first Y number of stables].
// Rec(Current_Horse, Current_Stable) = [i = Current_Horse to Number_of_Horses] min [Rec(i + 1, Next_Stable) + (White_Horses * Black Horses in Current_Stable)]

long long placeHorses(int i,string &horses,int k,int K,vector<vector<int>> &memo){
    // k: current stable number

    if(i==horses.size()){
        if(k==K+1) return 0;
        return INT_MAX;
    }
    
    if(k>K) return INT_MAX;
    
    if(memo[i][k]!=-1) return memo[i][k];
    
    long long ans = INT_MAX;
    int w=0,b=0;
    for(int j=i+1;j<=horses.size();j++){
        // j - start of next stable
        if(horses[j-1]=='W') w++;
        else b++;
        ans = min(ans,placeHorses(j,horses,k+1,K,memo)+w*b);
    }
    
    return memo[i][k]=ans;
    
    
}

int Solution::arrange(string horses, int K) {
    vector<vector<int>> memo(horses.size(),vector<int>(K+1,-1));
    int ans = placeHorses(0,horses,1,K,memo);
    return (ans==INT_MAX)?(-1):(ans);
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up

#define ll long long 

int Solution::arrange(string horses, int K) {
    int N = horses.size();
    if(K>N) return -1;
    vector<vector<ll>> dp(N+1,vector<ll>(K+1));
    // dp[n][k] = min value for horses[0...n-1] and k stables
    
    for(int k=1;k<=K;k++){
        for(int n=k;n<=N;n++){
            int w=0,b=0;
            dp[n][k]=INT_MAX;
            for(int i=n-1;i>=0;i--){
                if(horses[i]=='W') w++;
                else b++;
                
                if(k==1){
                    if(i==0) dp[n][k]=w*b; // Base case only 1 stable
                    else continue;
                }else{
                    dp[n][k]=min(dp[n][k],w*b+dp[i][k-1]);
                }
            }
        }
    }

    return (dp[N][K]==INT_MAX)?(-1):(dp[N][K]);    

}
