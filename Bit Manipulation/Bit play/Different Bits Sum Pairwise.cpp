// Same as Sum of pairwise Hamming Distance in Math

// We define f(X, Y) as number of different corresponding bits in binary representation of X and Y. 
// For example, f(2, 7) = 2, since binary representation of 2 and 7 are 010 and 111, respectively. The first and the third bit differ, so f(2, 7) = 2.
// You are given an array of N positive integers, A1, A2 ,…, AN. Find sum of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N. 
// Return the answer modulo 109+7.
// For example, A=[1, 3, 5]
// We return
// f(1, 1) + f(1, 3) + f(1, 5) + 
// f(3, 1) + f(3, 3) + f(3, 5) +
// f(5, 1) + f(5, 3) + f(5, 5) =
// 0 + 1 + 1 +
// 1 + 0 + 2 +
// 1 + 2 + 0 = 8

// Approach 1: Brute force, check each pair O(N^2)

/***************************************************************************************************************************/

// Approach 2: O(31*N)
// Assume that all values in input have only 1 bit i.e. Ai = 0 or 1.
// Lets say A = count of elements which are 0
// and B = count of elements which are 1
// In this case our answer is just 2AB, since each such pair contributes 1 to answer.
// Can you combine this logic if we have multiple bits?
// Note that all bits are independent in counting, since we are counting number of bits which are different in each pair.
// So, we just do the same process for all different bits. Since Ai is an integer, we just have to do this for 31 different bits, so our solution is O(31*N).

int Solution::cntBits(vector<int> &A) {
    unsigned int mask=1;
    int mod=1e9+7;
    long long ans=0;
    
    for(int i=1;i<=31;i++){
        long long c1=0;
        long long c2=0;
        for(unsigned int a:A){
            if((a&mask)>0) c1++;
            else c2++;
        }
        ans = (ans + 2*c1*c2)%mod;
        mask<<=1;
    }
    
    return ans;
    
}
