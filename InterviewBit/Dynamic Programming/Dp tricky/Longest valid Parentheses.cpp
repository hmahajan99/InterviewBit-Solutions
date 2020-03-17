// Approach 1: Brute Force
// A Simple Approach is to find all the substrings of given string. 
// For every string, check if it is a valid string or not. 
// If valid and length is more than maximum length so far, then update maximum length. 
// We can check whether a substring is valid or not in linear time using a stack (See this for details) 
// Time complexity of this solution is O(n^2)

/***************************************************************************************************************************/

// Approach 2: DP, Like LIS longest increasing subsequence
// Time O(N) Space O(N)
// Lets construct longest[i] where longest[i] denotes the longest set of parenthesis ending at index i.
// If s[i] is ‘(‘, set longest[i] to 0, because any string end with ‘(‘ cannot be a valid one.
// Else if s[i] is ‘)’
//   If s[i-1] is ‘(‘, longest[i] = longest[i-2] + 2
//   Else if s[i-1] is ‘)’ and s[i-longest[i-1]-1] == ‘(‘, longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]

int get(vector<int> &dp,int i){
    if(i<0) return 0;
    return dp[i];
}

int Solution::longestValidParentheses(string A) {
    if(A.size()<1) return 0;
    // dp[i] - denotes the longest set of parenthesis ending at index i
    vector<int> dp(A.size());
    int res=0;
    dp[0]=0;
    for(int i=1;i<A.size();i++){
        if(A[i]=='(') dp[i]=0;
        else if(A[i]==')'){
            int p = i-1-dp[i-1]; // Index of '(' bracket corresponding to A[i]
            if(p>=0&&A[p]=='('){
                dp[i] = dp[i-1] + 2 + get(dp,p-1);
            }
        }
        res=max(res,dp[i]);
    }
    return res;
}

