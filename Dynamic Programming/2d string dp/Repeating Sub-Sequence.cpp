// Given a string, find if there is any subsequence of length 2 or more that repeats itself 
// such that the two subsequences doesn’t have the same character at the same position, 
// i.e., any 0’th or 1st character in the two subsequences shouldn’t have the same index in the original string.

// This problem is just the modification of Longest Common Subsequence problem

// Approach 1: Top Down DP
// The idea is to find the LCS(str, str) where str is the input string with the restriction that when both the characters are same, 
// they shouldn’t be on the same index in the two strings.
// In other words, if S1 and S2 are the subsequences, S1[i] != S2[i] for all index i.
// Dynamic programming solution takes O(n^2) time and space

int lcs(string &A,int i,string&B,int j,vector<vector<int>> &memo){
    
    if(i==A.size()||j==B.size()) return 0;
    
    if(memo[i][j]!=-1) return memo[i][j];
    
    if(A[i]==B[j]&&i!=j) return 1 + lcs(A,i+1,B,j+1,memo);
    return memo[i][j]=max(lcs(A,i+1,B,j,memo),lcs(A,i,B,j+1,memo));
    
}

int Solution::anytwo(string A) {
    vector<vector<int>> memo(A.size(),vector<int>(A.size(),-1));
    int ans = lcs(A,0,A,0,memo);
    return ans>=2;
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up DP O(n^2) time and space

int Solution::anytwo(string A) {
    int n=A.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    // dp[i][j] = modified lcs when len(A1)=i & len(A2)=j i.e A[0...i-1] & A[0...j-1]
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0) dp[i][j]=0;
            else{
                if(A[i-1]==A[j-1]&&i!=j) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n]>=2;
}

/***************************************************************************************************************************/

// Approach 3: O(n) time 

bool isPalindrome(string s){
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int Solution::anytwo(string A) {
    unordered_map<char,int> freq;
    for(char ch:A){
        freq[ch]++;
        if(freq[ch]>2) return true; // Always possible in this case eg: [cc]c ,  c[cc]
    } 
    string t="";
    // Remove all the non-repeated character(i.e freq[ch]=1) from the string
    for(int i=0;i<A.size();i++){
        if(freq[A[i]]==2) t+=A[i];
    }
    
    if(isPalindrome(t)) return false;  // eg: t=abc|cba ,not possible here
    else return true; // eg: t=[ab]ccab,abcc[ab]  t=[ab]bcac,[a]b[b]cac
}



