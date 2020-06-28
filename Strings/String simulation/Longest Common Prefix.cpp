// Given the array of strings A,
// you need to find the longest string S which is the prefix of ALL the strings in the array.

// Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1
// and S2.

// For Example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".

// Approach 1: Word by Word Matching
// LCP(string1, string2, string3) = LCP (LCP (string1, string2), string3)

/***************************************************************************************************************************/

// Approach 2: Character by Character Matching

// The prefix has to be the prefix of ALL the strings.
// So, you can pick any random string from the array and start checking its characters from the beginning in order to see if they can be a part of the common substring.

string Solution::longestCommonPrefix(vector<string> &A) {

    string prefix="";
    
    for(int i=0;i<A[0].size();i++){
        char ch = A[0][i];
        // checking if character i of A[0] qualifies to be in the answer.
        for(int j=1;j<A.size();j++){
            if(i>=A[j].size()) return prefix;
            if(A[j][i]!=ch) return prefix;
        }
        prefix += ch;
    }
    
    return prefix;
    
}
