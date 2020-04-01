// Same as Different Bits Sum Pairwise in Bit Manipulation/Bit Play

// Hamming distance between two non-negative integers is defined as the number of positions at which the corresponding bits are different.
// Given an array of N non-negative integers, find the sum of hamming distances of all pairs of integers in the array.

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

int Solution::hammingDistance(const vector<int> &A) {

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