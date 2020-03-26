// A robot is located at the top-left corner of an A x B grid 
// The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked ‘Finish’ in the diagram below).
// How many possible unique paths are there?
// Note: A and B will be such that the resulting answer fits in a 32 bit signed integer.


// Note that you have to take m + n - 2 steps in total. You have to take (m - 1) steps going down and (n-1) steps going right.
// Let 0 denote a down step and 1 denote a right step.
// So we need to find out the number of strings of length m + n - 2 which have exactly m - 1 zeroes and n - 1 ones.
// Essentially we need to choose the positions of ‘1s’, and then ‘0s’ fall into the remaining positions.
// So, the answer becomes Choose(m+n-2, n - 1).

int nCr(int n, int r) { 
    // O(r) time and O(1) extra space

    // num holds the value of n*(n-1)*(n-2)..., 
    // denom holds the value of r*(r-1)... 
    long long num = 1, denom = 1; 
  
    // C(n, r) == C(n, n-r), 
    if (n-r<r) r=n-r; // choosing the smaller value
  
    while(r){ 
        num *= n; 
        denom *= r; 

        // gcd of num, denom 
        long long gcd = __gcd(num, denom); 

        // dividing by gcd, to simplify product 
        // division by their gcd saves from the overflow 
        num /= gcd; 
        denom /= gcd; 

        n--; 
        r--; 
    } 

    // Now num = ans and denom =1 
    // denom should be simplified to 1 as C(n, r) is a natural number (denominator should be 1 ) 

    return num; 
} 


int Solution::uniquePaths(int A, int B) {
    // A x B grid
    return nCr(A+B-2,A-1);
}

// Alternative: Should not overflow here also
// as dividing by 1,2,3,4... r and in numerator any 2 consecutive numbers will have 2 as a factor,any 3 consecutive numbers will have 3 as a factor and so on

int nCr(int n, int r) { 
    // O(r) time and O(1) extra space
    // nCr = [n*(n-1)*(n-2)...*(n-r+1)] / [r*(r-1)... *1]
    long long ans = 1; 
  
    if(n-r<r) r=n-r; // choosing the smaller value
  
    for (int i=1;i<=r;i++){  
        ans *= (n-r+i);  
        ans /= i;  
    } 

    return ans; 
} 


int Solution::uniquePaths(int A, int B) {
    // A x B grid
    return nCr(A+B-2,A-1);
}

// Another alternative: Should not overflow here also

int nCr(int n, int r) { 
    // O(r) time and O(1) extra space
    // nCr = [n*(n-1)*(n-2)...*(n-r+1)] / [r*(r-1)... *1]
    long long ans = 1; 
  
    if (n-r<r) r=n-r; // choosing the smaller value
  
    for (int i=1;i<=r;i++){  
        ans *= (n-i+1);  
        ans /= i;  
    } 

    return ans; 
} 


int Solution::uniquePaths(int A, int B) {
    // A x B grid
    return nCr(A+B-2,A-1);
}