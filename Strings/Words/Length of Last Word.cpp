// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
// If the last word does not exist, return 0.

// Given s = "Hello World",
// return 5 as length("World") = 5.

int Solution::lengthOfLastWord(const string A) {
    int len=A.size();
    int ans=0;
    int i=len-1;
    
    // Trim whitespace at end
    while(i>=0&A[i]==' '){
        if(A[i]!=' ') break;
        i--;
    }
    
    while(i>=0&A[i]!=' '){
        ans++;
        i--;
    }

    return ans;
}