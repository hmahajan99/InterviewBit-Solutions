// Given a number N >= 0, find its representation in binary.
// Example:
// if N = 6,
// binary form = 110

string Solution::findDigitsInBinary(int A) {
    if(A==0) return "0";
    string binary="";
    while(A){
        binary+='0'+(A%2);
        A/=2;
    }
    reverse(binary.begin(),binary.end());
    return binary;
}
