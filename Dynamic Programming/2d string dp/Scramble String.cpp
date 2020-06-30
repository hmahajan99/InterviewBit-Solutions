// Given a string A, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
// Below is one possible representation of A = “great”:
//     great
//    /    \
//   gr    eat
//  / \    /  \
// g   r  e   at
//            / \
//           a   t
// To scramble the string, we may choose any non-leaf node and swap its two children. 
// Note: We can do 0 or more swappings
// For example, if we choose the node “gr” and swap its two children, it produces a scrambled string “rgeat”.
//     rgeat
//    /    \
//   rg    eat
//  / \    /  \
// r   g  e   at
//            / \
//           a   t
// We say that “rgeat” is a scrambled string of “great”.
// Similarly, if we continue to swap the children of nodes “eat” and “at”, it produces a scrambled string “rgtae”.
//     rgtae
//    /    \
//   rg    tae
//  / \    /  \
// r   g  ta  e
//        / \
//       t   a
// We say that “rgtae” is a scrambled string of “great”.
// Given two strings A and B of the same length, determine if B is a scrambled string of S.

// Approach: Divide and Conquer + Dynamic Programming (key of the cache = s1+"$"+s2)

// In the bruteforce solution, we loop to find out the root of the tree.
// Lets say the root is the ith character of string s1. 
// Then the first part of s1 [0…i) can either match ( be a scrambled string of ) to s2[0…i) or s2(i+1 .. L]. 
// Depending on which part s1[0…i) matches to, we match the remaining part of s1 to remaining part of s2. 
// Just to clarify when we say s1 matches s2, we mean s1 is a scrambled string of s2.
// We can write a recursive function for this.
// An optimization step to consider here is to check beforehand if the two strings are anagrams of each other. If not, it indicates that the strings contain different characters and can’t be a scrambled form of each other.

//     public boolean isScramble(String s1, String s2) {
//         // CHECK BASE CASES HERE

//         if (s1 not anagram of s2) return false;
        
//         for(int i = 1; i < s1.length(); i++) { // i being the root position
//             if(isScramble(s1.substring(0,i), s2.substring(0,i)) && isScramble(s1.substring(i), s2.substring(i))) return true;
//             if(isScramble(s1.substring(0,i), s2.substring(s2.length()-i)) && isScramble(s1.substring(i), s2.substring(0, s2.length()-i))) return true;
//         }
//         return false;
//     }

// IMP: To memoize recursive solution, we make a key of the cache as s1+"$"+s2 for lookup

unordered_map<string,bool> cache;

bool isScrambled(string s1,string s2){
    int n = s1.size();
    if(s1==s2) return true;
    if(n<=1) return false;
    
    string key = s1 + "$" + s2;
    if(cache.count(key)) return cache[key];
    
    bool ans = false;
    for(int i=1;i<=n-1;i++){
        bool dontSwap = isScrambled(s1.substr(0,i),s2.substr(0,i)) && isScrambled(s1.substr(i,n-i),s2.substr(i,n-i));
        ans = ans | dontSwap; 
        if(ans) break;
        bool swap = isScrambled(s1.substr(n-i,i),s2.substr(0,i)) && isScrambled(s1.substr(0,n-i),s2.substr(i,n-i));
        ans = ans | swap; 
        if(ans) break;
    }
    
    return cache[key]=ans;
    
}

int Solution::isScramble(const string A, const string B) {
    if(A.size()!=B.size()) return false;
    cache.clear();
    return isScrambled(A,B);
}
