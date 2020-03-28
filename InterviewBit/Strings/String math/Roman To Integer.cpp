// Given a string A representing a roman numeral.
// Convert A into integer.
// A is guaranteed to be within the range from 1 to 3999.

// Approach:
// Note how the number XVI(10+5+1) and XIV(10-1+5) differs.
// In one case we are adding the numeric value of a letter and in other case we are subtracting it.
// The key is to notice that in a valid Roman numeral representation the letter with the most value always occurs at the start of the string.
// Whenever a letter with lesser value precedes a letter of higher value, it means its value has to be added as negative of that letter’s value.
// In all other cases, the values get added.

// CMXLVII = -100 + 1000 -10 + 50 + 5 + 1 + 1 = 947

int Solution::romanToInt(string A) {

    // Alternatively, could have used a function with switch statement
    unordered_map<char,int> m;
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;
    
    int ans=0;
    

    for(int i=0;i<A.size();i++){
        int sign=1;
        if(i<A.size()&&m[A[i]]<m[A[i+1]]){
            sign=-1;
        }
        ans += sign*m[A[i]];
    }
    
    return ans;
    
}
