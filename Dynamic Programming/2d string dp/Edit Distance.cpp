// Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)
// You have the following 3 operations permitted on a word:
// Insert a character
// Delete a character
// Replace a character

// Approach 1: Top Down

typedef vector<int> vi;
typedef vector<vi> vvi; 

int editDistance(int i,int j,string &A,string &B,vvi &dp){
    if(i==A.length()) return B.length()-j;
    if(j==B.length()) return A.length()-i;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    if(A[i]==B[j]){
        dp[i][j] = editDistance(i+1,j+1,A,B,dp);
    }else{
        // convert A to B
        dp[i][j] = 1+min({editDistance(i+1,j,A,B,dp),editDistance(i,j+1,A,B,dp),editDistance(i+1,j+1,A,B,dp)});
    } 
    
    return dp[i][j];
    
}

int Solution::minDistance(string A, string B) {
    vvi dp(A.length(),vi(B.length(),-1));
    return editDistance(0,0,A,B,dp);
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up

typedef vector<int> vi;
typedef vector<vi> vvi; 

int Solution::minDistance(string A, string B) {
    int n=A.length(),m=B.length();
    vvi dp(n+1,vi(m+1));
    // dp[i][j] = edit distance when len(A)=i & len(B)=j i.e A[0...i-1] & B[0...j-1]
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0) dp[0][j]=j; // Base Case, A==""
            else if(j==0) dp[i][0]=i; // Base Case, B==""
            else if(A[i-1]==B[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
        }
    }
    return dp[n][m];
}
