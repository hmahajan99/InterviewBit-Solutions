// NOTE: Starts from 1, not 0
// 1 -> A
// 2 -> B
// 3 -> C
// ...
// 26 -> Z
// 27 -> AA
// 28 -> AB 

string Solution::convertToTitle(int A) {

    string ans="";
    while(A>0){
        // IMP NOTE!!!=> char + int => int => typecast else compilation error
        ans += (char)('A'+(A-1)%26);
        // A-1 (not A) as num = __*(26^2) + __*(26^1) + __*(26^0) [ __ = 1 to 26 ] 
        A=(A-1)/26;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}