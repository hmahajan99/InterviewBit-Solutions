// You are given two positive numbers A and B. You need to find the maximum valued integer X such that:
// X divides A i.e. A % X = 0
// X and B are co-prime i.e. gcd(X, B) = 1

// For example,
// A = 30
// B = 12
// We return X = 5

// Approach 1: Using __gcd() STL function 
// Time - O(sqrt(A))

int Solution::cpFact(int A, int B) {
    int x=INT_MIN;
    
    for(int i=1;i*i<=A;i++){
        if(A%i==0){
            if(__gcd(B,i)==1) x = max(i,x);
            if(__gcd(B,A/i)==1){ 
                x = max(A/i,x);
                return x;
            }
        }
    }
    return x;

}

/***************************************************************************************************************************/

// Approach 2: Time - O(log(A))

// We know A is the greatest number dividing A. 
// So if A and B are coprime, we can return the value of X to be A. 
// Else, we can try to remove the common factors of A and B from A.

// On doing prime factorisation of A and B, we get :
// A = p1^x1 . p2^x2 . … . pk^xk
// B = q1^y1 . q2^y2 . … . ql^yl
// By repeating STEP1, we are reducing the respective powers of ri by at least one, each time

int Solution::cpFact(int A, int B) {
  while(__gcd(A,B) != 1){
    A = A / __gcd(A,B);
  } 
  return A;
}
