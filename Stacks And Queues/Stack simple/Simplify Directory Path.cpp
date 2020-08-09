// Given a string A representing an absolute path for a file (Unix-style).
// Return the string A after simplifying the absolute path.
// Note: Absolute path always begin with ’/’ ( root directory ).
// Path will not have whitespace characters.

// Input 1: A = "/home/"
// Output 1: "/home"
// Input 2: A = "/a/./b/../../c/"
// Output 2: "/c"

// Approach 1: str.split('/') => Using single loop
// Break the string along ‘/’ and process the substrings in order one by one

string Solution::simplifyPath(string A) {

    stack<string> s;

    // Split string A on "/"
    string dir="";
    for(int i=0;i<=A.size();i++){
        if(i==A.size()||A[i]=='/'){
            // dir holds substring now 
            if(dir=="."){
                // Do nothing
            }
            else if(dir==".."){
                if(!s.empty()) s.pop();
            }
            else if(dir!=""){
                s.push(dir);
            }
            // start dir as empty string again
            dir="";
        }else{
            dir+=A[i];
        }
    }

    string ans="";
    while(!s.empty()){
        dir=s.top();
        s.pop();
        ans = '/' + dir + ans;
    }
    if(ans=="") ans="/";
    return ans;
    
}

/***************************************************************************************************************************/

// Approach 2: str.split('/') => Using nested loop

string Solution::simplifyPath(string A) {

    stack<string> s;

    // Split string A on "/"
    for(int i=0;i<A.size();i++){

        string dir="";
        for(;i<A.size()&&A[i]!='/';i++){
            dir+=A[i];
        }

        // dir holds substring now 
        if(dir=="."){
            // Do nothing
        }
        else if(dir==".."){
            if(!s.empty()) s.pop();
        }
        else if(dir!=""){
            s.push(dir);
        }
        
    }

    string ans="";
    while(!s.empty()){
        string dir=s.top();
        s.pop();
        ans = '/' + dir + ans;
    }
    if(ans=="") ans="/";
    return ans;
    
}