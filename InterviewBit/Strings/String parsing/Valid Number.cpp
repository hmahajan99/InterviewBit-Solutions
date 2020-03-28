// Validate if a given string is numeric.

// Note: There might be multiple corner cases here. Clarify all your doubts in the interview.

// Examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true

// Q1) Is 1u ( which may be a representation for unsigned integers valid? For this problem, no.
// Q2) Is 0.1e10 valid? Yes
// Q3) -01.1e-10? Yes
// Q4) Hexadecimal numbers like 0xFF? Not for the purpose of this problem
// Q5) 3. (. not followed by a digit)? No
// Q6) Can exponent have decimal numbers? 3e0.1? Not for this problem.
// Q7) Is 1f ( floating point number with f as prefix ) valid? Not for this problem.
// Q8) How about 1000LL or 1000L ( C++ representation for long and long long numbers )? Not for this problem.
// Q9) How about integers preceded by 00 or 0? like 008? Yes for this problem

string removeSpacesInBeginning(string s){
    int i=0;
    while(i<s.size()&&s[i]==' ') i++;
    if(i==s.size()) return "";
    else return s.substr(i);
}

string removeSpacesAtEnd(string s){
    int i=s.size()-1;
    while(i>=0&&s[i]==' ') i--;
    if(i==-1) return "";
    else return s.substr(0,i+1);
}

bool onlyDigits(string s){
    // NOTE: Using isdigit defined in CCTYPE
    for(int i=0;i<s.size();i++) if(!isdigit(s[i])) return false;
    return true;
}

bool isValidInteger(string s){
    int n = s.length();
    if(n==0) return false;
    int i=0;
    if(s[0]=='+'||s[0]=='-'){
        if(n==1) return false;
        i++;
    }
    return onlyDigits(s.substr(i));
}

bool isValidDecimal(string s){
    int n=s.length();
    if(n<2) return false; // .3 valid
    int i=0;
    while(i<s.size()&&s[i]!='.'){
        i++;
    }
    if(i==s.size()||i==s.size()-1) return false;
    string integer = s.substr(0,i);
    string decimal = s.substr(i+1);
    return (integer==""||isValidInteger(integer))&&onlyDigits(decimal);
}

bool isValidExpo(string s){
    int n=s.length();
    if(n<3) return false; 
    int i=0;
    while(i<s.size()&&s[i]!='e'){
        i++;
    }
    if(i==s.size()||i==s.size()-1) return false;
    string mantissa = s.substr(0,i);
    string expo = s.substr(i+1);
    return (isValidInteger(mantissa)||isValidDecimal(mantissa))&&isValidInteger(expo);
}

int Solution::isNumber(const string A) {
    string s = removeSpacesInBeginning(A);
    s = removeSpacesAtEnd(s);
    return isValidInteger(s)||isValidDecimal(s)||isValidExpo(s);
}
