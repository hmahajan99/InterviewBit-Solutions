// You are climbing a stair case and it takes A steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Approach 1: Recursive, can memoize

int Solution::climbStairs(int n) {
    if(n<0) return 0;
    if(n==0) return 1;
    return climbStairs(n-1) + climbStairs(n-2);
}

/***************************************************************************************************************************/

// Approach 2:  O(1) space like fibonacci, dont need dp array

int Solution::climbStairs(int n) {
    if(n<=1) return 1;
    int a=1,b=1,c=2;
    for(int i=3;i<=n;i++){
        a=b;
        b=c;
        c=a+b;
    }
    return c;
}
