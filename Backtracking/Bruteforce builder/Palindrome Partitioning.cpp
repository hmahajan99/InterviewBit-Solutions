// When on index i, you incrementally check all substring starting from i for being palindromic. 
// If found, you recursively solve the problem for the remaining string and add it to your solution. 
// Start this recursion from starting position of the string.
// PS: You can optimize your solution by not computing the answer for same index multiple times using Dynamic Programming.

bool isPalindrome(const string &s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}

void getPartitions(string &A,int i,vector<vector<string>> &ans,vector<string> &current){
    if(i==A.size()){
        ans.push_back(current);
        return;
    }
    for(int j=i;j<A.size();j++){
        if(isPalindrome(A,i,j)){
            current.push_back(A.substr(i,j-i+1));
            getPartitions(A,j+1,ans,current);
            current.pop_back();
        }
    }
}

vector<vector<string>> Solution::partition(string A){
    vector<vector<string>> ans;
    vector<string> current;
    getPartitions(A,0,ans,current);
    return ans;
}
