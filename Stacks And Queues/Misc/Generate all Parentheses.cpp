int Solution::isValid(string A) {
    stack<char> s;
    for(char ch:A){
        if(ch=='('||ch=='{'||ch=='[') s.push(ch);
        else {
            if(s.empty()) return false;
            if(ch==')'&&s.top()!='(') return false; 
            if(ch=='}'&&s.top()!='{') return false; 
            if(ch==']'&&s.top()!='[') return false;
            s.pop();
        }
    }
    // return true => XXXXX WRONG eg : A = "[{"
    return s.empty();
}
