// Bucket - String tricks

// Given a string S, find the longest palindromic substring in S.
// Incase of conflict, return the substring which occurs first ( with the least starting index ).
// Example :
// Input : "aaaabaaa"
// Output : "aaabaaa"

// Approach 1: Brute Force
// The simple approach is to check each substring whether the substring is a palindrome or not.
// Time complexity: O ( n^3 )
// Space complexity: O ( 1 )

/***************************************************************************************************************************/

// Approach 2: Dynamic Programming, Top Down
// Time complexity: O ( n^2 )
// Auxiliary Space: O ( n^2 )

string Solution::longestPalindrome(string A) {

    int n = A.size();
    bool dp[n][n]; // dp[i][j] = is A[i....j] palindrome
    
    int maxLen=0,si=0;
    
    for(int len=1;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1;
            if(len==1){
                dp[i][j] = true; // Base case
            }else if(len==2){
                dp[i][j] = (A[i]==A[j]); // Base case
            }else{
                dp[i][j] = (A[i]==A[j]) && (dp[i+1][j-1]);
            }
            
            if(dp[i][j]&&len>maxLen){
                maxLen=len;
                si=i;
            }
        }
    }
    
    return A.substr(si,maxLen);

}

/***************************************************************************************************************************/

// Approach 3: Expand palindromes from center
// O(N^2) time and O(1) space
// We observe that a palindrome mirrors around its center. Therefore, a palindrome can be expanded from its center, and there are only 2N-1 such centers.
// 2N-1 as the center of a palindrome can be in between two letters
// Generate all even length and odd length palindromes and keep track of the longest palindrome seen so far.

string expand(string A,int c1,int c2){
    int n = A.size();
    int i=c1,j=c2;
    int si=0,maxLen=0;
    while(i>=0&&j<n){
        int len = j-i+1;
        if(A[i]!=A[j]) break;
        if(len>maxLen){
            maxLen=len;
            si=i;
        }
        i--; 
        j++;
    }
    return A.substr(si,maxLen);
}

string Solution::longestPalindrome(string A) {

    int n = A.size();
    string ans="";
    
    for(int i=0;i<n;i++){
        string s1 = expand(A,i,i); // odd len palindromes
        if(s1.length()>ans.length()) ans=s1;
        if(i<n-1){
            s1 = expand(A,i,i+1); // even len palindromes
            if(s1.length()>ans.length()) ans=s1;
        }
    }

    return ans;


}

/***************************************************************************************************************************/

// Approach 4: O(n) time using Manacher’s Algorithm
// TODO