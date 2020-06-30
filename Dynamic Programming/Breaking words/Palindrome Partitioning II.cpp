// Given a string A, partition A such that every substring of the partition is a palindrome.
// Return the minimum cuts needed for a palindrome partitioning of A.

// Input 1: A = "aba" Output 1: 0
// Explanation 1: "aba" is already a palindrome, so no cuts are needed.

// Input 2: A = "aab"  Output 2: 1
// Explanation 2: Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

// Approach: This problem is a variation of Matrix Chain Multiplication problem
// If the string is a palindrome, then we simply return 0. 
// Else, like the Matrix Chain Multiplication problem, we try making cuts at all possible places, 
// recursively calculate the cost for each cut and return the minimum value.

// Top Down DP, O(n^3)
// Can optimize to O(n^2) by precomputing if s[i...j] is a palindrome in O(n^2)
// Firstly, we should be able to answer if substring [i,i+1,….j] is palindrome or not in O(1) with pre-computation of O(n^2).
 
vector<vector<int>> dp;

bool isPalindrome(const string &s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int minCuts(int i,int j,string &s){
    if(j==i) return 0;
    if(j==i+1) return s[i]!=s[j];

    if(dp[i][j]!=-1) return dp[i][j];
    
    if(isPalindrome(s,i,j)) return dp[i][j]=0;
    
    int ans = INT_MAX;
    for(int k=i;k<=j-1;k++){
        ans=min(ans,1+minCuts(i,k,s)+minCuts(k+1,j,s));
    }
    
    return dp[i][j]=ans;

}

int Solution::minCut(string A) {
    int n = A.size();
    dp = vector<vector<int>>(n,vector<int>(n,-1));
    return minCuts(0,n-1,A);
}
