// There are A cities numbered from 1 to A. You have already visited M cities, the indices of which are given in an array B of M integers.

// If a city with index i is visited, you can visit either the city with index i-1 (i >= 2) or the city with index i+1 (i < A) if they are not already visited.
// Eg: if N = 5 and array M consists of [3, 4], then in the first level of moves, you can either visit 2 or 5.

// You keep visiting cities in this fashion until all the cities are not visited.
// Find the number of ways in which you can visit all the cities modulo 10^9+7.

// Input:
//     A = 5
//     B = [2, 5]
// Output:
//     6
   
// Explanation:
//     All possible ways to visit remaining cities are :
//     1. 1 -> 3 -> 4
//     2. 1 -> 4 -> 3
//     3. 3 -> 1 -> 4
//     4. 3 -> 4 -> 1
//     5. 4 -> 1 -> 3
//     6. 4 -> 3 -> 1

// Approach 1: Brute Force
// Brute force solution for this would create a graph and do BFS for all possible combinations to visit all cities. But this will result in a timeout.

/***************************************************************************************************************************/

// Approach 2: Using combinatorics, nCr

// Creates groups of continuous unvisited cities.
// Suppose there are n cities on a group. Then we can arrange these cities in 2^(n-1) ways .
// Logic is that we can start from either direction and we can then go left or right in each step.
// ans *= (2^n-1) for each group
// This factor is not taken for corner groups on both side.
// Like for [3,5] and total cities 7, this factor is not taken for group (1,2) and group(6,7)
// Now we have to multiply the factor that comes from different arrangements of groups.
// Suppose there are 3 groups have 2, 1, 3 elements. AA B CCC
// We can arrange them in C(0+2,2) * C(2+1, 1) * C (3+3, 3) ways.
// For every group factor is C(total cities till now, cities in this group)
// Multiply this factor found.
// We have got the answer.

// [ _ _ V _ _ _ _ V _ _ V _ _ _]
// [ 1 2 V 4 5 6 7 V 9 10 V 12 13 14]
// 14-3=11 moves reqd
// For middle groups => (11C4 * 2^3) * (7C2 * 2^1)
// First group => 5C2
// Last group => 5C3


#define MOD (int)(1e9+7)

int* precomputePow2(int N){
    int *pow2 = new int[N];
    pow2[0]=1;
    for(int i=1;i<N;i++){
        pow2[i]=((long long)pow2[i-1]*2)%MOD;
    }
    return pow2;
}

int **precomputeNCR(int N){
    int **nCr;
    nCr = new int*[N+1];
    for(int n=0;n<=N;n++){
        nCr[n] = new int[n+1];
        for(int r=0;r<=n;r++){
            if(r==0||r==n) nCr[n][r] = 1;
            else nCr[n][r] = ((long long)nCr[n-1][r]+nCr[n-1][r-1])%MOD; 
        }
    }
    return nCr;
}

int Solution::solve(int A, vector<int> &B) {
    int *pow2 = precomputePow2(A);
    int **nCr = precomputeNCR(A);

    sort(B.begin(),B.end());
    long long ans=1;
    int n=A-B.size();
    for(int i=0;i<B.size()-1;i++){
        int grpSize = B[i+1]-B[i]-1;
        if(grpSize==0) continue;
        ans*=nCr[n][grpSize];
        ans%=MOD;
        ans*=pow2[grpSize-1];
        ans%=MOD;
        n-=grpSize;
    }
    
    
    int grpSizeLast=A-B.back();
    if(grpSizeLast>0){
        ans*=nCr[n][grpSizeLast];
        n-=grpSizeLast;
        ans%=MOD;
    }

    int grpSizeFirst=B.front()-1;
    if(grpSizeFirst>0){
        ans*=nCr[n][grpSizeFirst];
        ans%=MOD;
    }

    return ans;
    
}
