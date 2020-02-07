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
