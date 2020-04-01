// Reverse digits of an integer.
// x = -123, return -321
// Return 0 if the result overflows and does not fit in a 32 bit signed integer

// Approach 1: Using STL, to_string() and reverse() & stoll()
// O(n) space

int Solution::reverse(int A) {
    long long num = A;
    int sign = A<0 ? -1 : 1;
    num = abs(num);
    string str = to_string(num);
    // Have to use STD::REVERSE since same name
    std::reverse(str.begin(), str.end()); 
    long long ans = sign*stoll(str);
    if(ans<INT_MIN||ans>INT_MAX) return 0; // Overflow
    return ans;
}

/***************************************************************************************************************************/

// Approach 2: O(1) Space, Construct reverse of number 
// First digit of reversed num = Last digit of num

long long reverseDigits(int num){
    int sign = num<0 ? -1 : 1;
    num=abs(num);
    long long ans=0;
    while(num>0){
        ans*=10;
        ans+=num%10;
        num/=10;
    }
    ans *= sign;
    return ans;
}

int Solution::reverse(int A) {
    long long ans = reverseDigits(A);
    if(ans<INT_MIN||ans>INT_MAX) return 0; // Overflow
    return ans;
}

// Alternative

int reverseDigits(int num){
    int sign = num<0 ? -1 : 1;
    num=abs(num);
    int ans=0;
    while(num>0){
        int digit=num%10;
        if(ans>INT_MAX/10 || (ans==(INT_MAX/10)&&digit>(INT_MAX%10)) ) return 0; // Overflow
        ans=ans*10+digit;
        num/=10;
    }
    ans *= sign;
    return ans;
}

int Solution::reverse(int A) {
    return reverseDigits(A);
}
