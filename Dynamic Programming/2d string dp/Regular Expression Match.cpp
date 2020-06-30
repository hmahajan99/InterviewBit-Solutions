// Wildcard Matching
// Implement wildcard pattern matching with support for ‘?’ and ‘*’ for strings A and B.
//   ’?’ : Matches any single character.
//   ‘*’ : Matches any sequence of characters (including the empty sequence).

// Approach 1: Top Down DP

int dp[10000][200];

bool f(const string &s1,int i,const string &s2,int j){
    
    if(i==s1.size()){
        while(j!=s2.size()){
            if(s2[j]!='*') return false;
            j++;
        }
        return true;
    }
    
    if(j==s2.size()) return false;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    if(s1[i]==s2[j] || s2[j]=='?'){
        return dp[i][j]=f(s1,i+1,s2,j+1);
    }
    
    if(s2[j]=='*'){
        return dp[i][j]=f(s1,i+1,s2,j) || f(s1,i,s2,j+1);
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

/***************************************************************************************************************************/

// Approach 2: Bottom Up DP, Space O(A*B)

int Solution::isMatch(const string A, const string B) {
    int a=A.size(),b=B.size();
    bool dp[a+1][b+1];
    // dp[i][j] = answer when len(A)=i & len(B)=j i.e A[0...i-1] & B[0...j-1]
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(i==0&j==0) dp[0][0]=1;
            else if(i==0){
                int k;
                for(k=0;k<j;k++){
                    if(B[k]!='*'){
                        dp[i][j]=false;
                        break;
                    } 
                }   
                if(k==j) dp[i][j]=true;
            } 
            else if(j==0){
              dp[i][0]=0;  
            } 
            else{
                if(A[i-1]==B[j-1]||B[j-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if(B[j-1]=='*') dp[i][j]=dp[i-1][j]||dp[i][j-1];
                else dp[i][j]=false;
            }
        }
    }

    return dp[a][b];
}

/***************************************************************************************************************************/

// IMP APPROACH TO REDUCE SPACE OF BOTTOM UP DP IF dp[i][j] only depends on current and previous row
// Approach 3: Bottom Up DP, Can reduce space to O(min(A,B))
// Can reduce space complexity
// Since dp[i][j] only depends on current and previous row, having only 2 rows will suffice instead having entire dp matrix

int Solution::isMatch(const string A, const string B) {
    int a=A.size(),b=B.size();
    vector<bool> dp(b+1); // dp[j] => len(A)=0 & len(B)=j;
    dp[0]=1;
    for(int j=1;j<=b;j++){
        int k;
        for(k=0;k<j;k++){
            if(B[k]!='*'){
                dp[j]=false;
                break;
            } 
        }   
        if(k==j) dp[j]=true;
    }
    

    for(int i=1;i<=a;i++){
        // dp - represents row i-1
        vector<bool> newDp(b+1); // represents row i
        for(int j=0;j<=b;j++){
            if(j==0){
              newDp[0]=0;  
            } 
            else{
                if(A[i-1]==B[j-1]||B[j-1]=='?') newDp[j]=dp[j-1];
                else if(B[j-1]=='*') newDp[j]=dp[j]||newDp[j-1];
                else newDp[j]=false;
            }
        }
        dp=newDp;
    }

    return dp[b];
}
