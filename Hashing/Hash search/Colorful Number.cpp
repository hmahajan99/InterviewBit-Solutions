// For Given Number N find if its COLORFUL number or not
// COLORFUL number: A number can be broken into different contiguous sub-subsequence parts. 
// Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
// And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
// Example:

// N = 23
// 2 3 23
// 2 -> 2
// 3 -> 3
// 23 -> 6
// this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

int Solution::colorful(int A) {
    unordered_map<long long,bool> m;
    string s = to_string(A);
    
    for(int i=0;i<s.size();i++){
        long long prod = 1;
        for(int j=i;j<s.size();j++){
            prod*= s[j]-'0';
            if(m.count(prod)>0) return 0;
            m[prod] = true;
        }
    }
    
    return 1;
}
