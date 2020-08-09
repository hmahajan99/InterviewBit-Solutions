// Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.
// Chech whether A has redundant braces or not. Return 1 if A has redundant braces, else return 0.
// Input 1: A = "((a + b))"
// Output 1: 1
// Input 2: A = "(a + (a + b))"
// Output 2: 0

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
