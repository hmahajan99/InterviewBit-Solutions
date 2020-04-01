string get(char ch){
    switch(ch){
        case '0': return "0"; 
        case '1': return "1"; 
        case '2': return "abc"; 
        case '3': return "def"; 
        case '4': return "ghi"; 
        case '5': return "jkl"; 
        case '6': return "mno"; 
        case '7': return "pqrs"; 
        case '8': return "tuv"; 
        case '9': return "wxyz"; 
    }
}

void generate(int i,string A,string &current,vector<string> &ans){
    if(i==A.size()){
        ans.push_back(current);
        return;
    }
    string mapping = get(A[i]);
    for(int j=0;j<mapping.size();j++){
        // IMP NOTE: pushback & popback (character) works for strings also
        current.push_back(mapping[j]);
        generate(i+1,A,current,ans);
        current.pop_back();
    }
} 

vector<string> Solution::letterCombinations(string A) {
    vector<string> ans;
    string current="";
    generate(0,A,current,ans);
    return ans;
}