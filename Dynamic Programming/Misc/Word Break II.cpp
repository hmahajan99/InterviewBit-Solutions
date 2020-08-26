// Bucket - Dp optimized backtrack

// Similar to Dynamic Programming/Knapsack/Equal Average Partition.cpp

// Given a string A and a dictionary of words B, add spaces in A to construct a sentence where each word is a valid dictionary word.
// Return all such possible sentences.

// Input 1:
//     A = "catsanddog",
//     B = ["cat", "cats", "and", "sand", "dog"]

// Output 1:
//     ["cat sand dog", "cats and dog"]

// Approach: Dp optimized backtrack
// Exploring every substring from the start of the string, and check if its in the dictionary. 
// If it is, then you check if it is possible to form rest of the string using the dictionary words. 
// If yes, answer is true. If none of the substrings qualify, then answer is false.

vector<bool> dp;

bool canBreak(int i, string &s, unordered_set<string> &dict,string &sentence,vector<string> &ans) {
    int n = s.size();
    if(i==n){
        sentence.pop_back();
        ans.push_back(sentence);        
        return true;
    } 
    
    if(dp[i]==false) return false; // return if false, if true will go on to fill ans

    string temp = sentence;
    bool result = false;
    for (int j=i;j<n;j++) {
        string substring = s.substr(i,j-i+1);
        if(dict.count(substring)){
            sentence = temp + substring + " ";
            result |= canBreak(j+1,s,dict,sentence,ans);  
            // if(result) break;
            sentence=temp; // backtrack
        }
    }
    return dp[i]=result;
}

vector<string> Solution::wordBreak(string A, vector<string> &B) {
    unordered_set<string> dict;
    for(string s:B) dict.insert(s);
    dp = vector<bool>(A.size(),true); // marking true since need to push elements in ans
    string sentence = "";
    vector<string> ans;
    canBreak(0,A,dict,sentence,ans);
    return ans;
}
