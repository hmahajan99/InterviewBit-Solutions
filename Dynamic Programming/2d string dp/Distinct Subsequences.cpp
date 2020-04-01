// Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

// Approach 1: Top Down

vector<vector<int>> cache;

int count(string &S,int i,string &T,int j){
    if(j==T.size()) return 1;
    if(i==S.size()) return 0;
    
    if(cache[i][j]!=-1) return cache[i][j];
    
    int ans=0;
    if(S[i]==T[j]) ans += count(S,i+1,T,j+1); // Include S[i] , i++ & j++
    ans += count(S,i+1,T,j); // Exclude S[i] , i++
    return cache[i][j]=ans;
    
}

int Solution::numDistinct(string S, string T) {
    cache = vector<vector<int>>(S.size(),vector<int>(T.size(),-1));
    return count(S,0,T,0);
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up

// Solve the problem for some prefix of first string and some prefix of second string and use it to compute the final answer
// Try to think of DP on prefixes of both strings.

// Rule 1). dp[0][j] = 1, since aligning T = “” with any substring of S would have only ONE solution which is to delete all characters in S.
// Rule 2). dp[i][j] can be derived by two cases:
//   case 1). if T[i] != S[j], then the solution would be to ignore the character S[j] and align substring T[0..i] with S[0..(j-1)]. Therefore, dp[i][j] = dp[i][j-1].
//   case 2). if T[i] == S[j], then first we could adopt the solution in case 1), but also we could match the characters T[i] and S[j] and align the rest of them (i.e. T[0..(i-1)] and S[0..(j-1)]. As a result, dp[i][j] = dp[i][j-1] + d[i-1][j-1]

int Solution::numDistinct(string S, string T) {
    int n=S.size(),m=T.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    // dp[i][j] = count when len(S)=i & len(T)=j i.e S[0...i-1] & T[0...j-1]

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j==0) dp[i][0]=1; // Base case, T=""
            else if(j>i) dp[i][j]=0; // len(T)>len(S) 
            else{
                dp[i][j]=0;
                if(S[i-1]==T[j-1]) dp[i][j]+=dp[i-1][j-1]; // Include S[i-1]
                dp[i][j]+=dp[i-1][j]; // Exclude S[i-1]
            }
        }
    }
    
    return dp[n][m];
}
