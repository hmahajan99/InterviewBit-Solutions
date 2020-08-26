// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
// If the fractional part is repeating, enclose the repeating part in parentheses.

// Example :
// Given numerator = 1, denominator = 2, return "0.5"
// Given numerator = 2, denominator = 1, return "2"
// Given numerator = 2, denominator = 3, return "0.(6)"

// Note : If fraction is in the form p/(2^m ⋅ 5^n), it has terminating  decimal expansion.

// Integer part is floor(numerator / denominator).
// Now you are left with ( remainder = numerator%denominator ) / denominator.
// If you remember the process of converting to decimal, at each step you do the following :
// 1) multiply the remainder by 10,
// 2) append remainder / denominator to your decimals
// 3) remainder = remainder % denominator.
// At any moment, if your remainder becomes 0, you are done.
// However, there is a problem with recurring decimals. For example if you look at 1/3, the remainder never becomes 0.
// Notice one more important thing.
// If you start with remainder = R at any point with denominator d, you will always get the same sequence of digits.
// So, if your remainder repeats at any point of time, you know that the digits between the last occurrence of R will keep repeating.



#define ll long long
string Solution::fractionToDecimal(int A, int B) {
    
    ll num=A,den=B;

    if (num == 0) 
        return "0"; 
  
    int sign = (num < 0) ^ (den < 0) ? -1 : 1; // XOR to find sign
  
    num = abs(num); 
    den = abs(den); 
  
    long long initial = num / den; 
  
    string res=""; 
  
    if (sign == -1) 
        res += "-"; 
  
    res += to_string(initial); 
  
    if (num % den == 0) 
        return res; 
  
    res += "."; 
  
    long long rem = num % den;  
    unordered_map<int, int> m; 
    
    while(rem){
        
        if(m.count(rem)){
            
            //res = res.substr(0,m[rem]) + "(" + res.substr(m[rem]) + ")";
            res.insert(m[rem],"(");
            res += ")";
            return res;
        }   
        
        m[rem]=res.size();
        rem *= 10;
        res += to_string(rem/den);
        rem = rem%den;

    }
    
    return res;

}