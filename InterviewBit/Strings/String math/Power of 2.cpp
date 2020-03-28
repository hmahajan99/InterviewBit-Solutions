// Find if Given number is power of 2 or not.
// More specifically, find if given number can be expressed as 2^k where k >= 1.
// number length can be more than 64, which mean number can be greater than 2 ^ 64 (out of long long range)

// Approach:
// We need to divide the number by 2 till it is greater than 1.
// At any point, if the last digit is odd, then the number is not a power of 2.
// For example, If the number is 10. 
// 10 has 0 as the last digit, so it is even
// Next step, 10 / 2 = 5
// 5 is odd, so the answer is 0.

// Lets see how we would implement division by 2.
// The division process is just the simulation of human division process.
// Start from the first digit. If the current digit is less than 2, then we append the next digit to current digit, and append 0 to our answer.

string divBy2(string A){
    // Assuming number is divisible by 2
    
    if(A=="0") return "0";
    
    string ans="";
    
    int rem,i;
    rem = A[0]-'0';  
    i=0;
    // To avoid leading zeroes in ans
    if(rem==1){ // if A starts with 1, eg: 123
        rem = rem*10+(A[1]-'0');
        i=1;
    }
    
    while(i<A.size()){
        ans += '0'+(rem/2);
        rem=rem%2;
        if(i+1<A.size()) rem = rem*10+(A[i+1]-'0');
        i++;
    }
    
    // Eg: 1200312 / 2 = 600156
    
    return ans;
}

int Solution::power(string A) {

    if(A=="0") return true;
    if(A=="1") return false;

    while(A!="1"){
        int lastDigit = A.back()-'0';
        if(lastDigit%2==1) return false;
        A=divBy2(A);
    }
    
    return true;
    
}