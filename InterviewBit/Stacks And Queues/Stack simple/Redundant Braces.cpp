// Note: A will be always a valid expression.
// Corner cases : (a*(a))  and (a)

int Solution::braces(string A) {
    stack<char> s;
    for(char ch:A){
        if(ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            s.push(ch);
        }
        if(ch==')'){
            if(s.top()=='('){
                return 1;
            }else{
                while(s.top()!='('){
                    s.pop();
                }
                s.pop();
            }
        }
    }
    
    return 0;
    
}
