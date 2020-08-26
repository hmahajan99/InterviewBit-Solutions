// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.
// Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

// Example :
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC"

// Approach 1: Brute force
// Consider all substrings 

/***************************************************************************************************************************/

// Approach 2: 2 pointers + Hashmap 
// Time - O(n)

// Essentially you have a start and end pointer starting from the beginning of the string. 
// You keep moving the end pointer and including more characters till you have all the characters of T included. 
// At this point, you start moving start pointer and popping out characters till the point that you still have all the characters of T included. 
// Update your answer and keep repeating the process.

string Solution::minWindow(string A, string B) {
    unordered_map<char,int> t; // stores freq of chars for B
    int req=B.size(); // min no of required characters in window
    for(int i=0;i<B.size();i++){
        t[B[i]]++;
    }
    
    int iAns=INT_MAX,len=INT_MAX;
    unordered_map<char,int> s; // for A
    for(int i=0,j=0;j<A.size();j++){
        
            if(t.count(A[j])) s[A[j]]++;
            if(t.count(A[j])&&s[A[j]]<=t[A[j]]) req--;
            while(req==0){
                if(j-i+1<len||(j-i+1==len&&i<iAns)){
                    iAns=i;
                    len=j-i+1;
                }
                if(t.count(A[i])){
                    if(s[A[i]]<=t[A[i]]) req++; 
                    s[A[i]]--;
                }
                i++;
            }

    }
    
    if(len==INT_MAX) return "";
    string ans=A.substr(iAns,len);
    return ans;
    
}
