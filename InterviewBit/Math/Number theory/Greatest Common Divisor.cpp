// Given 2 non negative integers m and n, find gcd(m, n)
// GCD of 2 integers m and n is defined as the greatest integer g such that g is a divisor of both m and n.

// Lets say g is gcd(m, n) and m > n.

// m = g * m1
// n = g * m2

// m - n = g * (m1 - m2)

// gcd (m, n) = gcd(m-n, n)

//            = gcd(m - 2n, n) if m >= 2n
//            = gcd(m - 3n, n) if m >= 3n 
//              .
//              .
//              .
//            = gcd(m - k*n, n) if m >= k*n
           
//        In other words, we keep subtracting n till the result is greater than 0. Ultimately we will end up with m % n.
       
//               So gcd(m, n)  = gcd(m % n, n) 



// Approach 1: Using  __gcd(m, n)  ,C++ inbuilt function for finding GCD

int Solution::gcd(int A, int B) {
    return __gcd(A,B);
}

/***************************************************************************************************************************/

// Approach 2: Recursive

int Solution::gcd(int A, int B) {
    // if(A<B) swap(A,B);
    if(B==0) return A;
    return gcd(B,A%B);
}

/***************************************************************************************************************************/

// Approach 3: Iterative

int Solution::gcd(int A, int B) {
    while(B>0){
        int temp=A;
        A=B;
        B=temp%B;
    }
    return A;
}


