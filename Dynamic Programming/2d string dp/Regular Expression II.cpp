// Implement regular expression matching with support for '.' and '*'.
// Note:- Different from wildcard matching

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.

// The matching should cover the entire input string (not partial).

// Some examples:
// isMatch("aa","a") → 0
// isMatch("aa","aa") → 1
// isMatch("aaa","aa") → 0
// isMatch("aa", "a*") → 1
// isMatch("aa", ".*") → 1 
// isMatch("ab", ".*") → 1  => .* means "zero or more (*) of any character (.)
// isMatch("aab", "c*a*b") → 1

// Approach 1: Top Down DP
// The recursion mainly breaks down into the following two cases:
// If the next character of p is NOT ‘*’, then it must match the current character of s. Continue pattern matching with the next character of both s and p.
// If the next character of p is ‘*’, then we do a brute force exhaustive matching of 0, 1, or more repeats of current character of p… Until we could not match any more characters.


int dp[10000][200];

bool f(const string &s1,int i,const string &s2,int j){
    int n1=s1.size(), n2=s2.size();
    if(i==n1){
        while(j<n2){
            if(!(j<n2-1&&s2[j+1]=='*')) return false;
            j+=2;
        }
        return true;
    }
    
    if(j>=n2) return false;
    
    if(dp[i][j]!=-1) return dp[i][j];

    if(j<n2-1&&s2[j+1]=='*'){
        dp[i][j] = f(s1,i,s2,j+2); // 0 occurences
        if(s1[i]==s2[j]||s2[j]=='.') dp[i][j] |= f(s1,i+1,s2,j);
        return dp[i][j];
    }
    
    if(s1[i]==s2[j] || s2[j]=='.'){
        return dp[i][j]=f(s1,i+1,s2,j+1);
    }

    return dp[i][j]=false;
}

int Solution::isMatch(const string A, const string B) {
    int a=A.size(),b=B.size();
    if(b==0) return a==0;

    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            dp[i][j]=-1;
        }
    }

    return f(A,0,B,0);
}
