// Given an integer A, how many structurally unique BST’s (binary search trees) exist that can store values 1…A?

// Approach 1: Top Down DP 2 states 
// Lets consider the number [1, n]
// We have n options of choosing the root.
// If we choose the number j as the root, j - 1 numbers fall in the left subtree, n - j numbers fall in the right subtree. We already know how many ways there are to forming j - 1 trees using j - 1 numbers and n -j numbers.
// So we add number(j - 1) * number(n - j) to our solution.

int countUnique(int s,int e,int** memo){
    if(s>e) return 1;
    if(s==e) return memo[s][e] = 1;
    
    if(memo[s][e]!=-1) return memo[s][e];
    
    int ans=0;
    for(int root=s;root<=e;root++){
        ans += countUnique(s,root-1,memo)*countUnique(root+1,e,memo);
    }
    
    return memo[s][e] = ans;    
    
}


int Solution::numTrees(int N) {

    int** memo;
    memo = new int*[N+1];
    for(int i=1;i<=N;i++){
        memo[i] = new int[N+1];
        for(int j=1;j<=N;j++){
            memo[i][j] = -1;
        }
    }
    
    return countUnique(1,N,memo);
    
}

/***************************************************************************************************************************/

// Approach 2: Top Down DP 1 state, Efficient
// Instead of using (s,e) as state use n as state
// Since ans for (1,3) and (5,7) will be same

int countUnique(int N,int *memo){
    if(N<=0) return 1;
    if(N==1) return memo[N] = 1;
    
    if(memo[N]!=-1) return memo[N];
    
    int ans=0;
    for(int root=1;root<=N;root++){
        ans += countUnique(root-1,memo)*countUnique(N-root,memo);
    }
    
    return memo[N] = ans;    
    
}

int Solution::numTrees(int N) {
    int* memo = new int[N+1];
    fill(memo,memo+N+1,-1);
    return countUnique(N,memo);
    
}

/***************************************************************************************************************************/

// Approach 3: Bottom Up DP 1 state

int Solution::numTrees(int N) {
    if(N<=1) return 1;
    int *dp = new int[N+1]{0};
    dp[0]=dp[1]=1;
    for(int n=2;n<=N;n++){
        for(int root=1;root<=n;root++){
            dp[n]+=dp[root-1]*dp[n-root];
        }
    }
    return dp[N];
}
