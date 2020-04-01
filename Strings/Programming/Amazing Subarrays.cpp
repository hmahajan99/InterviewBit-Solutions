// You are given a string S, and you have to find all the amazing substrings of S.
// Amazing Substring is one that starts with a vowel (a, e, i, o, u, A, E, I, O, U).
// Return a single integer X mod 10003, here X is number of Amazing Substrings in given string.
// Input
//     ABEC
// Output
//     6
// Explanation
// 	Amazing substrings of given string are :
// 	1. A
// 	2. AB
// 	3. ABE
// 	4. ABEC
// 	5. E
// 	6. EC

bool isVowel(char c){
    char a[]= {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int n = sizeof(a)/sizeof(char);
    for(int i=0;i<n;i++){
        if(a[i]==c) return true;
    }
    return false;
}

int Solution::solve(string A) {
    
    int len=A.size();
    int ans=0;
    int M=10003;
    
    for(int i=0;i<len;i++){
        if(isVowel(A[i])){
            ans+= len-i;
            ans%=M;
        }    
    }
    
    return ans;
}

