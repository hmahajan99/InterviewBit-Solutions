// Evaluate the value of an arithmetic expression in Reverse Polish Notation

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
