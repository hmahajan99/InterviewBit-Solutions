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
