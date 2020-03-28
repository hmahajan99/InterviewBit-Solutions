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