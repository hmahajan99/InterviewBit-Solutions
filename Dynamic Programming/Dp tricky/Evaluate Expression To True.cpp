// Given an expression, A, with operands and operators (OR , AND , XOR), 
// in how many ways can you evaluate the expression to true, by grouping in different ways?
// Operands are only true and false.
// Eg:- The only way to evaluate the expression is:
//  => (T|F) = T
// T|F
// The operator here is 'or'. So, we need to find the number of ways sub-expression left of `|` operator, or the sub-expression to the right of the operator, evaluates to true. 
// In other words,
// ways = (ways_T_left * ways_T_right) + (ways_F_left * ways_T_right) + (ways_T_left * ways_F_right)

// Approach 1: Top Down

typedef pair<int,int> pii;
vector<vector<pii>> memo;

pii count(char op,pii a,pii b){
    int lT = a.first, lF = a.second;
    int rT = b.first, rF = b.second;
    int ansT,ansF;
    if(op=='|'){
        ansT = lT*rT + lF*rT + lT*rF;
        ansF = lF*rF;
    }else if(op=='&'){
        ansT = lT*rT;
        ansF = lF*rF + lF*rT + lT*rF;
    }else if(op=='^'){
        ansT = lT*rF + lF*rT;
        ansF = lT*rT + lF*rF;
    }
    return {ansT,ansF};
}

pii countTF(string &A,int i,int j){

    if(i==j){
        if(A[i]=='T') return {1,0};
        return {0,1};
    }
    
    if(memo[i][j]!=make_pair(-1,-1)) return memo[i][j];
    
    pii ans(0,0);
    for(int k=i;k<=j;k++){
        if(A[k]=='|'||A[k]=='&'||A[k]=='^'){
            pii small = count(A[k],countTF(A,i,k-1),countTF(A,k+1,j));
            ans = {ans.first + small.first, ans.second + small.second};
            ans = {ans.first%1003,ans.second%1003};
        }
    }
    
    return memo[i][j]=ans;
}

int Solution::cnttrue(string A) {
    int n = A.size();
    memo = vector<vector<pii>>(n+1,vector<pii>(n+1,{-1,-1}));
    return countTF(A,0,n-1).first;
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up

typedef pair<int,int> pii;

pii count(char op,pii a,pii b){
    int lT = a.first, lF = a.second;
    int rT = b.first, rF = b.second;
    int ansT,ansF;
    if(op=='|'){
        ansT = lT*rT + lF*rT + lT*rF;
        ansF = lF*rF;
    }else if(op=='&'){
        ansT = lT*rT;
        ansF = lF*rF + lF*rT + lT*rF;
    }else if(op=='^'){
        ansT = lT*rF + lF*rT;
        ansF = lT*rT + lF*rF;
    }
    return {ansT,ansF};
}

int Solution::cnttrue(string A) {
    int n = A.size();
    vector<vector<pii>> dp;
    // dp[i][j] - Ways A[i..j] evaluates to true & false
    dp = vector<vector<pii>>(n,vector<pii>(n,{0,0}));
    // Filling dp diagonally
    for(int len=1;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1;
            if(len==1){
                // Base case
                if(A[i]=='T') dp[i][i]={1,0};
                else if(A[i]=='F') dp[i][i]={0,1};
                else dp[i][i]={0,0};
                continue;
            }
            pii ans={0,0};
            for(int k=i;k<=j;k++){
                if(A[k]=='|'||A[k]=='&'||A[k]=='^'){
                    pii small = count(A[k],dp[i][k-1],dp[k+1][j]);
                    ans = {ans.first + small.first, ans.second + small.second};
                    ans = {ans.first%1003,ans.second%1003};
                }
            }
            dp[i][j]=ans;
        }
    }
    return dp[0][n-1].first;
}