// Bucket - String search & String tricks & String parsing

// Given an string A. The only operation allowed is to insert characters in the beginning of the string.
// Find how many minimum characters are needed to be inserted to make the string a palindrome string.

// Input 1:
//     A = "ABC"
// Output 1:
//     2
//     Explanation 1:
//         Insert 'B' at beginning, string becomes: "BABC".
//         Insert 'C' at beginning, string becomes: "CBABC".

// Input 2:
//     A = "AACECAAAA"
// Output 2:
//     2
//     Explanation 2:
//         Insert 'A' at beginning, string becomes: "AAACECAAAA".
//         Insert 'A' at beginning, string becomes: "AAAACECAAAA".

// Approach 1: O(n^2)
// Idea is to find longest palindrome length starting from index 0 . Differece of this length from string length is the required value

bool isPalindrome(string s){
    int n = s.size();
    if(n<=1) return true;
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-1-i]) return false;
    }
    return true;
}

int Solution::solve(string A) {

    int n = A.size();
    if(n==0) return 0;
    
    for(int j=n-1;j>=0;j--){
        if(isPalindrome(A.substr(0,j+1))){
            return n-1-j;
        }
    }
    
}

// Alternative: More efficient, not making a new string each time to check for palindrome

bool isPalindrome(const string &s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int Solution::solve(string A) {

    int n = A.size();
    if(n==0) return 0;
    
    for(int j=n-1;j>=0;j--){
        if(isPalindrome(A,0,j)){
            return n-1-j;
        }
    }
    
}

/***************************************************************************************************************************/

// Approach 2:  O(n) time using LPS array of KMP algorithm
// KMP (Knuth Morris Pratt) is used for Pattern Searching
// lps array gives the longest proper prefix which is also suffix. A proper prefix is prefix with whole string not allowed. 

// First we concat string by concatenating given string, a special character and reverse of given string 
// then we will get lps array for this concatenated string, 
// recall that each index of lps array represent longest proper prefix which is also suffix. 
// We can use this lps array for solving the problem.

// For string = [AACECAA]AA
// Concatenated String = [AACECAA]AA$AA[AACECAA]
// LPS array will be {0, 1, 0, 0, 0, 1, 2, 2, 2, 0, 1, 2, 2, 2, 3, 4, 5, 6, 7}

// Here we are only interested in the last value of this lps array because it shows us the largest suffix of the reversed string 
// that matches the prefix of the original string i.e these many characters already satisfy the palindrome property. 
// Finally minimum number of character needed to make the string a palindrome is length of the input string minus last entry of our lps array. 

vector<int> computeLPSArray(string s){
    int n=s.size();
    vector<int> lps(n);
    int len=0;
    int i=1;
    lps[0]=0; // lps[0] is always 0 
    while(i<n){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
        }else{ // (str[i] != str[len])
            if(len!=0){
                len=lps[len-1]; // TRICKY PART
                // We do not increment i here 
            }else{ // if (len == 0)
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

int Solution::solve(string A) {
    int n = A.size();
    if(n==0) return 0;
    string revA=A;
    reverse(revA.begin(),revA.end());
    vector<int> lps = computeLPSArray(A+'$'+revA);
    return n-lps.back();
}
