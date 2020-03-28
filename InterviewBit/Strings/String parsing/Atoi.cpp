// Implement atoi to convert a string to an integer

// Example :
// Input : "9 2704"
// Output : 9

// Note: There might be multiple corner cases here. Clarify all your doubts in the interview.

// Questions: Q1. Does string contain whitespace characters before the number? A. Yes 
// Q2. Can the string have garbage characters after the number? A. Yes. Ignore it. 
// Q3. If no numeric character is found before encountering garbage characters, what should I do? A. Return 0. 
// Q4. What if the integer overflows? A. Return INT_MAX if the number is positive, INT_MIN otherwise.

// Approach 1

long long convertStringToInteger(int sign,string A){
    int n = A.size();
    long long p=1,ans=0;
    
    for(int i=n-1;i>=0;i--,p*=10){
        ans = ans + sign*p*(A[i]-'0');
        if(ans>INT_MAX) return INT_MAX;
        else if(ans<INT_MIN) return INT_MIN;
    }
    
    return ans;
}

int Solution::atoi(const string A) {


    int n = A.size();
    int start=-1,end=-1;
    int sign=1;
    
    for(int i=0;i<n;i++){
        if(A[i]=='-'&&i<n-1&&isdigit(A[i+1])){ // IMP NOTE: Using isdigit(char) defined in header CCTYPE
            sign=-1;
        }else if(A[i]=='+'&&i<n-1&&isdigit(A[i+1])){
            sign=1;
        }else if(!isdigit(A[i])){
            if(A[i]==' ') continue; 
            else break;
        }else if(isdigit(A[i])){
            start=end=i;
            i++;
            while(isdigit(A[i])){
                end=i;
                i++;
            }
            break;
        }
    }
    
    if(start==-1) return 0;
    
    return convertStringToInteger(sign,A.substr(start,end-start+1));
}

/***************************************************************************************************************************/

// Approach 2: Detecting OVERFLOW without using long data type, detecting overflow before the number is about to overflow

// We only need to handle four cases:

// 1 Discards all leading whitespaces
// 2 Sign of the number
// 3 Overflow
// 4 Invalid input

// IMP NOTE !!!!=>
// Detecting overflow gets tricky. You need to detect overflow before the number is about to overflow.
// So:
// 1.) If the number is positive and the current number is greater than MAX_INT/10, and you are about to append a digit, then certainly your number will overflow.
// 2.) f the current number = MAX_INT / 10, then based on the last digit, we can detect if the number will overflow.

int Solution::atoi(const string str) {
    int sign = 1, base = 0, i = 0;
    
    while (str[i] == ' ')  i++; 
    
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i++] == '-') ? -1 : 1; 
    }
    
    while (str[i] >= '0' && str[i] <= '9') {
        // checking overflow will give wrong ans for INT_MIN (as abs(INT_MIN)=INT_MAX+1) ??
        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > INT_MAX%10 )) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        base  = 10 * base + (str[i++] - '0');
    }
    
    return base * sign;
}
