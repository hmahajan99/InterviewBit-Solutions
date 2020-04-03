// You are given a set of coins S. In how many ways can you make sum N assuming you have infinite amount of each coin in the set.
// Note : Coins in set S will be unique. Expected space complexity of this problem is O(N).

// Example :
// Input : 
// 	S = [1, 2, 3] 
// 	N = 4
// Return : 4

// Explanation : The 4 possible ways are
// {1, 1, 1, 1}
// {1, 1, 2}
// {2, 2}
// {1, 3}	
// Note that the answer can overflow. So, give us the answer % 1000007

// Approach 1: Top Down DP
// Time & Space Complexity - O(N*coins.size())

// We can break this into 2 parts for a particular coin:
// 1) Include - we use this coin.
// 2) Exclude - we do not use this coin.

vector<vector<int>> cache;

int numWays(int i,int N,vector<int> &S){

    if(i==S.size()) return N==0; 
    if(N==0) return 1;
    if(N<S[i]) return 0;
    
    if(cache[i][N]!=-1) return cache[i][N];
    
    int include = numWays(i,N-S[i],S);
    int exclude = numWays(i+1,N,S);
    return cache[i][N] = (include+exclude)%(1000007);
}

int Solution::coinchange2(vector<int> &S, int N) {
    sort(S.begin(),S.end());
    cache = vector<vector<int>>(S.size(),vector<int>(N+1,-1));
    return numWays(0,N,S);
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up DP
// Time & Space Complexity - O(N*coins.size())

int Solution::coinchange2(vector<int> &S, int N) {
    sort(S.begin(),S.end());
    vector<vector<int>> dp = vector<vector<int>>(S.size(),vector<int>(N+1));
    // dp[i][n] = Have coins S[0...i] & want to make change for n
    for(int i=0;i<S.size();i++){
        for(int n=0;n<=N;n++){
            if(n==0) dp[i][0]=1;
            else{
                int include = 0;
                if(n-S[i]>=0) include = dp[i][n-S[i]];
                int exclude = 0;
                if(i>0) exclude = dp[i-1][n];
                dp[i][n] = (include+exclude)%(1000007);
            }
        }
    }

    return dp[S.size()-1][N];    
}

/***************************************************************************************************************************/

// Approach 3: Optimising above approach for space
// Time Complexity - O(N*coins.size())
// Space Complexity - O(N)

// dp[i][j] = dp[i-1][n] (Prev row, same column) + dp[i][n-S[i]] (Same row)
// dp[i][j] only depends on current and previous row

int Solution::coinchange2(vector<int> &S, int N) {
    sort(S.begin(),S.end());
    vector<int> dp = vector<int>(N+1,0);
    dp[0]=1;
    for(int i=0;i<S.size();i++){
        for(int n=0;n<=N;n++){
            int include = (n-S[i]>=0)?(dp[n-S[i]]):(0);
            dp[n] += include;
            dp[n] %= 1000007;
        }
    }
    return dp[N];    
}


