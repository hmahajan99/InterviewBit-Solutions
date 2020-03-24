// Trailing zeroes are obtained from powers of 10.
// The ZERO comes from 10.
// The 10 comes from 2 x 5
// So, if we take all the numbers with 5 as a factor, we will have plenty of even numbers to pair with them to get factors of 10

// For given number 4617.
// 5^1 : 4617 ÷ 5 = 923.4, so we get 923 factors of 5
// 5^2 : 4617 ÷ 25 = 184.68, so we get 184 additional factors of 5
// 5^3 : 4617 ÷ 125 = 36.936, so we get 36 additional factors of 5
// 5^4 : 4617 ÷ 625 = 7.3872, so we get 7 additional factors of 5
// 5^5 : 4617 ÷ 3125 = 1.47744, so we get 1 more factor of 5
// 5^6 : 4617 ÷ 15625 = 0.295488, which is less than 1, so stop here.
// Therefore, 4617! has 923 + 184 + 36 + 7 + 1 = 1151 trailing zeroes.

// Approach 1: Iterative

int Solution::trailingZeroes(int A) {
    int ans=0;
    while(A>0){
        ans+=A/5;
        A/=5;
    }
    return ans;
}

/***************************************************************************************************************************/

// Approach 2: Recursive

int Solution::trailingZeroes(int A) {
    return (A==0) ? 0 : (A/5)+trailingZeroes(A/5); 
}