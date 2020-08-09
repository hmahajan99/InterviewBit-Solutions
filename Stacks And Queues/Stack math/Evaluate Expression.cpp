// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.
// Input 1: A =   ["2", "1", "+", "3", "*"]
// Output 1: 9

int Solution::evalRPN(vector<string> &A) {
    stack<int> s;
    
    for(string st:A){
        if(st=="+"||st=="-"||st=="*"||st=="/"){
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            
            if(st=="+"){
                s.push(a+b);
            }else if(st=="-"){
                s.push(a-b);
            }else if(st=="*"){
                s.push(a*b);
            }else if(st=="/"){
                s.push(a/b);
            }
            
        }else{
            s.push(stoi(st));
        }
    }
    
    return s.top();
    
}
