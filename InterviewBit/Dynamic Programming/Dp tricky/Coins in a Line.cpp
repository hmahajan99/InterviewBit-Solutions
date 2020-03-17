// There are A coins (Assume A is even) in a line.
// Two players take turns to take a coin from one of the ends of the line until there are no more coins left.
// The player with the larger amount of money wins.
// Assume that you go first.
// Return the maximum amount of money you can win.

// Approach 1: Top Down

vector<vector<int>> memo; // Dont have to pass to function like this

int f(vector<int> &coins,int i,int j){
    
    if(i>j) return 0; 

    if(memo[i][j]!=-1) return memo[i][j];
    
    // you choose i , other choose i+1/j
    int op1 = coins[i] + min(f(coins,i+2,j),f(coins,i+1,j-1));
    // you choose j , other choose i/j-1
    int op2 = coins[j] + min(f(coins,i+1,j-1),f(coins,i,j-2));

    return memo[i][j]=max(op1,op2);    
}

int Solution::maxcoin(vector<int> &coins) {
    int n = coins.size();
    memo = vector<vector<int>>(n+1,vector<int>(n+1,-1)); // Initialise dp
    return f(coins,0,n-1);
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up

int Solution::maxcoin(vector<int> &coins) {
    int n = coins.size();
    vector<vector<int>> dp; 
    // dp[i][j] - Max player score for this range
    dp = vector<vector<int>>(n,vector<int>(n,0)); // Initialise dp
    // Filling dp diagonally
    for(int len=1;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1;
            if(len==1){
                // Base case
                dp[i][i]=0; // players score is 0 here
            }
            else if(len%2==1){
                // Opponents turn - Minimizes players score
                // int op1=(i+1<n)?(coins[i]+dp[i+1][j]):(INT_MAX); WRONG, Dont add coins[i] in opponents turn
                int op1=(i+1<n)?(dp[i+1][j]):(INT_MAX);
                int op2=(j-1>=0)?(dp[i][j-1]):(INT_MAX);
                dp[i][j] = min(op1,op2);
            }else{
                // Players turn
                int op1=(i+1<n)?(coins[i]+dp[i+1][j]):(INT_MIN);
                int op2=(j-1>=0)?(coins[j]+dp[i][j-1]):(INT_MIN);
                dp[i][j] = max(op1,op2);
            }
        }
    }
    
    return dp[0][n-1];
}

