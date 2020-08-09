// Find the number of distinct Max Heap can be made from A distinct integers.
// You have to ensure the following properties for the max heap :
// Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.)
// Every node is greater than all its children.

// 1. Suppose there are n distinct elements to be used in Max heap. Now it is for sure that the maximum element among this n distinct element will surely be placed on the root of the heap.
// 2. Now there will be remaining (n-1) elements to be arranged.
// 3. Now point to be remembered here is that the structure of the heap will remain the same. That is only the values within the node will change however the overall structure remaining the same.
// 4. As structure of the heap remains the same, the number of elements that are present in the left sub-tree of the root (L) will be fixed. And similarly the number of the elements on the right sub-tree (R) of the root. And also following equality holds .
// L + R = (n-1) 

// 1. Now as all the remaining (n-1) elements are less than the element present at the root(The Max Element), whichever L elements among ‘n-1` elements we put in the left sub-tree, it doesn’t matter because it will satisfy the Max Heap property.
// 2. So now there are (n-1)CL ways to pickup L elements from (n-1) elements. And then recurse the solution.
// 3. So final equation will be as follows :
// (n-1)CL * getNumberOfMaxHeaps(L) * getNumberOfMaxHeaps(R) 

// 1. So now the question remains only of finding L for given n. It can be found as follows:
// 2. Find the height of the heap h = log2(n)
// 3. Find the max number of elements that can be present in the hth level of any heap . Lets call it m. m = 2^h
// 4. Find the number of elements that are actually present in last level(hth level) in heap of size n. Lets call it p. p = n - (2^h - 1)
// 5. Now if the last level of the heap is more than or equal to exactly half filled, then L would be 2^h - 1
// 6. However if it is half filled then it will reduced by the number of elements in last level left to fill exactly half of the last level.
// 7. So final equation for L will be as follows :
//  L = 2^h - 1 if p >= m/2
//    = 2^h - 1 - (m/2 - p) if p<(m/2) 

#define ll long long

int f(int N,ll C[][101],int M,int* dp){
    
    if(N==0||N==1) return 1;
    
    if(dp[N]!=0) return dp[N];
    
    int h = (int)log2(N)+1; // Height, NOTE: USING LOG2 INBUILT FUNCTION
    int ph2 = (int)(pow(2,h-2)+0.5); // 2^(h-2) OR have used bitwise operator (1<<(h-2))
    int ph1 = 2*ph2; // 2^(h-1)
    int L,R;
    
    int p = N-(ph1-1); // No of nodes actually present in last level = N - (complete BT of height h-1)
    int m = ph1; // No of elements that can be present in last level of heap (i.e h'th level)
    if(p>=m/2) L = ph1 -1; // L => complete BT of height h-1 
    else L = (ph2-1)+p; // L => (complete BT of height h-2) + p
    R = (N-1)-L; // R+L=N-1    
    
    long ans = C[N-1][L];
    ans = (ans*f(L,C,M,dp))%M;
    ans = (ans*f(R,C,M,dp))%M;
    return dp[N]=ans; // C[N-1][L] * f(l) * f(R)

}

int Solution::solve(int N) {
    int M = (int)(1e9+7);
    ll C[101][101]; // BOTTOM UP nCr
    for(int n=0;n<=100;n++){
        for(int r=0;r<=n;r++){
            if(n==0||n==1||r==0||r==n){
                C[n][r]=1;
            }else{
                C[n][r] = (C[n-1][r]+C[n-1][r-1])%M;
            }
        }
    }
    
    int dp[101]={0}; 
    return f(N,C,M,dp);

}


