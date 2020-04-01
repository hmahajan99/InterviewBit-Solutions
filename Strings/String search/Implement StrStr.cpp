// Implement strStr().
// strstr - locate a substring ( needle ) in a string ( haystack ). 
// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
// NOTE: Good clarification questions:
// What should be the return value if the needle is empty?
// What if both haystack and needle are empty?
// For the purpose of this problem, assume that the return value should be -1 in both cases

// Approach 1: Using library function
// string.find(substring) -> returns position of the first character of the found substring or npos if no such substring is found
// Complexity not specified in docs

int Solution::strStr(const string A, const string B) {
    if(A.find(B)==string::npos) return -1;
    return A.find(B);
}

/***************************************************************************************************************************/

// Approach 2: Brute force 
// One by one check every index of A. For every index, check if B is present
// Time complexity : O(m * n)

int Solution::strStr(const string A, const string B) {
    // find B in A

    if(A.size()==0||B.size()==0) return -1;

    for(int i=0;i+B.size()<=A.size();i++){
        bool isPossible = true;
        for(int j=i;j<i+B.size();j++){
            if(A[j]!=B[j-i]){
                isPossible=false;
                break;
            }
        }
        if(isPossible) return i;
    }
    
    return -1;
    
}

/***************************************************************************************************************************/

// Approach 3: Using KMP Algorithm for Pattern Searching
// The Naive pattern searching algorithm doesn’t work well in cases where we see many matching characters followed by a mismatching character
// The basic idea behind KMP’s algorithm is: whenever we detect a mismatch (after some matches), we already know some of the characters in the text of the next window. 
// We take advantage of this information to avoid matching the characters that we know will anyway match

// Need of Preprocessing?
// An important question arises from the above explanation, how to know how many characters to be skipped. 
// lps array gives the longest proper prefix which is also suffix. 
// A proper prefix is prefix with whole string not allowed. 
// For example, prefixes of “ABC” are “”, “A”, “AB” and “ABC”. Proper prefixes are “”, “A” and “AB”.
// Note : lps[i] could also be defined as longest prefix which is also proper suffix. We need to use properly at one place to make sure that the whole substring is not considered.

// How to use lps[] to decide next positions ?
// When we see a mismatch =>
  // We know that characters pat[0..j-1] match with txt[i-j…i-1] (Note that j starts with 0 and increment it only when there is a match).
  // We also know (from above definition) that lps[j-1] is count of characters of pat[0…j-1] that are both proper prefix and suffix.
  // From above two points, we can conclude that we do not need to match these lps[j-1] characters with txt[i-j…i-1] because we know that these characters will anyway match.


// Time Complexity: O(m+n)
// Space Complexity: O(m) , m = pattern.size()

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

int hasSubstringKMP(string text,string pattern){
    int n=text.size(),m=pattern.size();
    
    vector<int> lps = computeLPSArray(pattern);
    
    int i=0,j=0;
    while(i<n){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }else{
            // Do not match lps[0..lps[j-1]] characters, they will match anyway 
            if(j>0) j=lps[j-1];
            else i++;
        }
        
        if(j==m){
            // Pattern found at index i-j
            return i-j;
        }
        
    }
    
    return -1;
}

int Solution::strStr(const string A, const string B) {
    // find B in A
    return hasSubstringKMP(A,B);
}
