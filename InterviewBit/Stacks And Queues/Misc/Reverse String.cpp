// Given a string S, reverse the string using stack.

string Solution::reverseString(string A) {
    stack<char> s;
    for(char ch:A) s.push(ch);
    string ans="";
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    return ans;
}
