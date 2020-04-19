// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

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
