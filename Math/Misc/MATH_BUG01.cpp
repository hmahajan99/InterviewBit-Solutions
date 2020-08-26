// Following code tries to figure out if a number is prime 
//  1 is neither a prime number nor a composite number
// iterating until the sqrt(n) only as one factor should be <= sqrt(n) and another should be >= sqrt(n)

// Return 1 if A is prime, else 0
int Solution::isPrime(int A) {
    if(A<2) return 0;
    int upperLimit = (int)(sqrt(A)+0.5);
    for (int i = 2; i <= upperLimit; i++) {
        if (A % i == 0) return 0;
    }
    return 1;
}
