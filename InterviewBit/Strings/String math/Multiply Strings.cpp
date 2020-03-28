// Given two numbers represented as strings, return multiplication of the numbers as a string
// Note1: The numbers can be arbitrarily large and are non-negative.
// Note2: Your answer should not have leading zeroes. 
// For example, given strings "12", "10", your answer should be “120”.

// Approach 1
// Time complexity is O(nm)
// Eg: 231*12
//     231
//  x   12
//     ---
//     462
//    231x 
//    ----
//    2772

string add(string A,string B){
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    int i=0,j=0,carry=0;
    string ans="";
    while(i<A.size()||j<B.size()||carry){
        int sum = (i<A.size()?A[i++]-'0':0)+(j<B.size()?B[j++]-'0':0)+carry;
        ans+=(char)('0'+(sum%10));
        carry=sum/10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

string mulByDigit(string A,int d){
    
    if(d==0) return "0";
    if(d==1) return A;
    
    reverse(A.begin(),A.end());
    
    string ans="";
    int carry=0;
    for(int i=0;i<A.size();i++){
        int x = (A[i]-'0')*d + carry;
        ans += (char)('0'+(x%10));
        carry = x/10;
    }
    if(carry){
        ans += (char)('0'+carry);
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}

string Solution::multiply(string A, string B) {
    
    if(A<B) swap(A,B);

    string ans="0";
    // Eg : 523 * 142 = 523*(2) + 523*(4*10) + 523*(1*100)
    for(int i=0;i<B.size();i++){
        string x = mulByDigit(A,B[B.size()-1-i]-'0');
        for(int j=1;j<=i;j++) x += '0';
        ans = add(ans,x);
    }

    // Alternatively could use an array to store digits of the result

    return ans;
    
}
