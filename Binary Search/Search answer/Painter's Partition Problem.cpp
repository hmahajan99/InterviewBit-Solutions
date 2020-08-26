// Given 2 integers A and B and an array of integars C of size N.
// Element C[i] represents length of ith board.
// You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each of them takes B units of time to paint 1 unit of board.
// Calculate and return minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of board.
// 2 painters cannot share a board to paint. That is to say, a board cannot be painted partially by one painter, and partially by another.
// A painter will only paint contiguous boards. Which means a configuration where painter 1 paints board 1 and 3 but not 2 is invalid.
// Return the ans % 10000003

// Input 1:
//     A = 2
//     B = 5
//     C = [1, 10]
// Output 1:
//     50
// Explanation 1:
//     Possibility 1:- same painter paints both blocks, time taken = 55units
//     Possibility 2:- Painter 1 paints block 1, painter 2 paints block 2, time take = max(5, 50) = 50
//     There are no other distinct ways to paint boards.
//     ans = 50%10000003

// Input 2:
//     A = 10
//     B = 1
//     C = [1, 8, 11, 3]
// Output 2:
//     11

// Approach 1: Brute Force
// We can observe that the problem can be broken down into: 
// Given an array A of non-negative integers and a positive integer k, we have to divide A into k or fewer partitions 
// such that the maximum sum of the elements in a partition, overall partitions is minimized.

// A brute force solution is to consider all possible set of contiguous partitions 
// and calculate the maximum sum partition in each case and return the minimum of all these cases.
// Can do using recursion, we have to put k-1 dividers to get k partitions.

/***************************************************************************************************************************/

// Approach 2: DP
// time complexity is O(k*N^2)
// O(k * N) extra space.

#define lli long long
typedef vector<int> vi;
typedef vector<vi> vvi;

lli sum(int i,int j,lli prefixSum[]){
    if(i>j) return 0;
    return prefixSum[j]-((i==0)?(0):(prefixSum[i-1]));
}

int Solution::paint(int K, int T, vi &L) {

    int n = L.size();

    lli prefixSum[n+1];
    prefixSum[0] = L[0];
    for(int i=1;i<n;i++) prefixSum[i] = L[i] + prefixSum[i-1];

    lli dp[K+1][n+1];

    for(int i=1;i<=K;i++){
        dp[i][1]=L[0];
    }
    
    for(int i=1;i<=n;i++){
        dp[1][i]=sum(0,i-1,prefixSum);
    }
    
    for(int i=2;i<=K;i++){
        for(int j=2;j<=n;j++){
            lli ans=LLONG_MAX;
            for(int p=1;p<=j;p++){
                lli maxPartition=max(dp[i-1][p],sum(p,j-1,prefixSum));
                ans=min(ans,maxPartition);
            }
            dp[i][j]=ans;
        }
    }
    

    return (dp[K][n]*T)%10000003;
    
}

/***************************************************************************************************************************/

// Approach 3: Binary Search
// The time complexity is O(N * log (sum (arr[])).

bool isPossible(int t,int numPainters,const vector<int> &boards){
    //  Tell you if its possible to paint the boards in time T or less
    int currentPainter=1;
    int currentPainterTime=0;
    for(int board:boards){
        if(board>t) return false;
        if(currentPainterTime+board>t){
            currentPainter++;
            if(currentPainter>numPainters) return false;
            currentPainterTime=board;
        }else{
            currentPainterTime+=board;
        }
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &C) {
    int s=C[0],e=0,ans;
    for(int board:C){
        s=max(s,board); // If 1 painter paints the largest board then it will take the least time.
        e+=board; // If a single painter paints all the board then it will take the highest time.
    }
    while(s<=e){
        long long mid = (s+e)/2;
        if(isPossible(mid,A,C)){
            // A painters can paint the boards in "mid" time (taking B=1)
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ((long long)ans*B)%10000003; // Multiply ans by B
}
