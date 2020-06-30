// Given a string A and a dictionary of words B, determine if A can be segmented into a space-separated sequence 
// of one or more dictionary words.

// Input 1:
//     A = "myinterviewtrainer",
//     B = ["trainer", "my", "interview"]
// Output 1:
//     1

// Approach 1: Top down DP
// Exploring every substring from the start of the string, and check if its in the dictionary. 
// If it is, then you check if it is possible to form rest of the string using the dictionary words. 
// If yes, answer is true. If none of the substrings qualify, then answer is false.

vector<int> dp;

bool canBreak(int i, string &s, unordered_set<string> &dict) {
    int n = s.size();
    if(i==n) return true;
    
    if(dp[i]!=-1) return dp[i];

    bool result = false;
    for (int j=i;j<n;j++) {
        string substring = s.substr(i,j-i+1);
        if(dict.count(substring)){
            result |= canBreak(j+1,s,dict);  
            if(result) break;
        }
    }
    return dp[i]=result;
}

int Solution::wordBreak(string A, vector<string> &B) {
    unordered_set<string> dict;
    for(string s:B) dict.insert(s);
    dp = vector<int>(A.size(),-1);
    return canBreak(0,A,dict);
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up

bool canBreak(string &s, unordered_set<string> &dict) {
    int N = s.size();
    vector<bool> dp(N,false);
    for(int i=0;i<N;i++){
        dp[i]=false;
        for(int j=i;j>=0;j--){
            if(dp[i]) break;
            string str = s.substr(j,i-j+1);
            if(dict.count(str)){
                if(j-1>=0) dp[i] = dp[j-1];
                else dp[i] = true;
            }
        }
    }
    return dp[N-1];
}

int Solution::wordBreak(string A, vector<string> &B) {
    unordered_set<string> dict;
    for(string s:B) dict.insert(s);
    return canBreak(A,dict);
}
