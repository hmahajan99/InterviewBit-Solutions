// Given two binary strings, return their sum (also a binary string).

// Approach 1

// Note 1: It might be easier if you construct the reverse of the answer, reversing the strings that we have to add.
// Note 2: Make sure you don’t stop before carry is 0. (Cases like 11 + 1.)

// Since sizes of two strings may be different, we first make the size of smaller string equal to that of bigger string by adding leading 0s for simplicity
// Note that you can handle the addition without adding zeroes as well by adding a few if statements.
// After making sizes same, one by one, we add bits from rightmost bit to leftmost bit.

// Sum = (a + b + c) % 2
// Carry = (a + b + c ) / 2

string Solution::addBinary(string A, string B) {

    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    
    int i=0,j=0;
    int carry=0;
    string ans="";
    while(i<A.size()&&j<B.size()){
        int sum = (A[i]-'0') + (B[j]-'0') + carry;
        ans += (char)('0'+(sum%2)); // NOTE:  Typecast necessary, as char + int => int
        carry = sum/2;
        i++;
        j++;
    }
    while(i<A.size()){
        int sum = (A[i]-'0') + carry;
        ans += (char)('0' + (sum%2)); // Typecast necessary
        carry = sum/2;
        i++;
    }
    while(j<B.size()){
        int sum = (B[j]-'0') + carry;
        ans += (char)('0' + (sum%2)); // Typecast necessary
        carry = sum/2;
        j++;
    }
    if(carry){
        ans += '1';
    }
    
    reverse(ans.begin(),ans.end());
    
    return ans;
    
}


// Alternative: Better, single while loop

string Solution::addBinary(string A, string B) {

    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    
    int i=0,j=0;
    int carry=0;
    string ans="";
    while(i<A.size()||j<B.size()||carry){
        int sum=0;
        if(i<A.size()){
            sum+=(A[i]-'0');
            i++;
        }
        if(j<B.size()){
            sum+=(B[j]-'0');
            j++;
        }
        sum+=carry;
        ans+=(char)('0'+(sum%2)); // NOTE:  Typecast necessary, as char + int => int
        carry = sum/2;
    }

    reverse(ans.begin(),ans.end());
    
    return ans;
    
}
