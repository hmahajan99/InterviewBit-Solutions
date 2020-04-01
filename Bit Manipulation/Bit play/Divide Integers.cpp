// Divide two integers without using multiplication, division and mod operator.
// Return the integer part of the result of the division.
// Also, consider if there can be overflow cases. For overflow case, return INT_MAX.

// Approach 1: Using division operator

int Solution::divide(int A, int B) {
    if(A==INT_MIN&&B==-1) return INT_MAX; // Overflow case
    return (A/B);     
}

/***************************************************************************************************************************/

// Approach 2: Repeated Subtraction
// Keep subtracting the divisor from dividend until dividend becomes less than divisor. 
// The dividend becomes the remainder, and the number of times subtraction is done becomes the quotient.
// Time complexity : O(dividend)
// Auxiliary space : O(1)

/***************************************************************************************************************************/

// Approach 3: Efficient Approach, using bit manipulation in order to find the quotient
// The divisor and dividend can be written as dividend = quotient * divisor + remainder
// The quotient can be represented in binary form i.e sum of powers of 2
// Eg: for 16/3=5(101), 16=3*(2^2+2^0) + 1
// Time complexity : O(log(dividend))
// Auxiliary space : O(1)

int Solution::divide(int A, int B) {
    
    if(A==INT_MIN&&B==-1) return INT_MAX;
    long long dividend=A,divisor=B;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1; 

    dividend = abs(dividend); 
    divisor = abs(divisor);     
    
    long long quotient = 0, temp = 0;     

    for (int i = 31; i >= 0; i--) { 
        if(temp+(divisor<<i)<=dividend){ 
            temp+=divisor<<i; 
            quotient+=1LL<<i; 
        } 
    } 
  
    return sign*quotient; 

}
