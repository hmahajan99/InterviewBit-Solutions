// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.
// For example, given n = 3, a solution set is:
// "((()))", "(()())", "(())()", "()(())", "()()()"
// Make sure the returned list of strings are sorted.

// Approach: Using backtracking

void generate(int open,int close,vector<string> &ans,string &current){

    if(open==0&&close==0){
        ans.push_back(current);
        return;
    }
    
    if(open){
        current+='(';
        generate(open-1,close,ans,current);
        current.pop_back();
    }
    
    if(close>open){
        current+=')';
        generate(open,close-1,ans,current);
        current.pop_back();
    }

}

vector<string> Solution::generateParenthesis(int n) {
    vector<string> ans;
    string current="";
    generate(n,n,ans,current);
    return ans;
}
