// Given a string A.
// Return the string A after reversing the string word by word.

// NOTE:
// A sequence of non-space characters constitutes a word.
// Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
// If there are multiple spaces between words, reduce them to a single space in the reversed string.

// Input 1:
//     A = "the sky is blue"
// Output 1:
//     "blue is sky the"

// Approach 1: Split string approach, str.split(' ')

string Solution::solve(string A) {
    vector<string> v;
    int i=0;
    while(i<A.size()){
        while(i<A.size()&&A[i]==' ') i++;
        string word="";
        while(i<A.size()&&A[i]!=' '){
            word += A[i];
            i++;
        }
        v.push_back(word);
    }
    
    string ans="";
    if(!v.size()) return ans;
    for(auto it=v.rbegin();it!=v.rend();it++){
        ans += *it;
        ans += ' ';
    }
    ans.pop_back(); // Removing space after last word
    
    return ans;
}

/***************************************************************************************************************************/

// Approach 2: First reverse the whole string, then reverse the reversed words individually

string Solution::solve(string A) {
    reverse(A.begin(),A.end());
    string ans="";
    int start=0;
    while(start<A.size()){
        while(start<A.size()&&A[start]==' ') start++;
        if(start<A.size()){
            int end=start;
            while(end<A.size()&&A[end]!=' ') end++;
            reverse(A.begin()+start,A.begin()+end);
            ans = ans + A.substr(start,end-start) + ' ';
            start=end;
        }
    }
    if(ans.size()>0) ans.pop_back();
    return ans;
}
