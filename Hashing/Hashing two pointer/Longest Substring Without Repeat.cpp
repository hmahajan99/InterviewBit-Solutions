// Given a string, find the length of the longest substring without repeating characters.
// Example: The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
// For "bbbbb" the longest substring is "b", with the length of 1.

// Approach 1: Brute force
// Time - O(n^3)
// We can consider all substrings one by one and check for each substring whether it contains all unique characters or not

/***************************************************************************************************************************/

// Approach 2: 2 pointers + Hashmap 
// Time - O(n)
// This solution uses extra space(Hashmap) to store the last indexes of already visited characters
// All you need to do is use two pointers to keep a window with no repetitions of characters. 
// Keep moving the right pointer and if you encounter any repeating character start moving left pointer untill no character is repeated.

int Solution::lengthOfLongestSubstring(string A) {
    unordered_map<char,int> m; // character -> index of last occurence
    int start=0,end=0,maxLen=0;
    while(end<A.size()){
        // Repeating character found at index end. Move start of window ahead 
        if(m.count(A[end])&&m[A[end]]>=start){
            start=m[A[end]]+1;
        }
        // Current window length
        if(maxLen<end-start+1){
            maxLen=end-start+1;
        }
        m[A[end]]=end;
        end++;
    }
    return maxLen;
}
