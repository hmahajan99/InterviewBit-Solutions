// Given a string A representating json object. Return an array of string denoting json object with proper indentaion.
// Rules for proper indentaion:
// 1) Every inner brace should increase one indentation to the following lines.
// 2) Every close brace should decrease one indentation to the same line and the following lines.
// 3) The indents can be increased with an additional ‘\t’
// Note: 
// 1) [] and {} are only acceptable braces in this case.
// 2) Assume for this problem that space characters can be done away with.

// Input 1:
//     A = "{A:"B",C:{D:"E",F:{G:"H",I:"J"}}}"
// Output 1:
//     { 
//         A:"B",
//         C: 
//         { 
//             D:"E",
//             F: 
//             { 
//                 G:"H",
//                 I:"J"
//             } 
//         } 
//     }

// Input 2:
//     A = ["foo", {"bar":["baz",null,1.0,2]}]
// Output 2:
//     [
//         "foo", 
//         {
//             "bar":
//             [
//                 "baz", 
//                 null, 
//                 1.0, 
//                 2
//             ]
//         }
//     ]


// Approach

// This is more of a parsing problem.
// Make sure you take a lot of time thinking about the corner cases and structure of the code before you start coding.
// Fixing corner cases on the fly can make your code really ugly.
// Note the following:
// 1) ‘{‘, ‘[’ have the same effect on the printing
// 2) ‘}’, ‘]’ have the same effect as well
// 3) ‘:’ and ‘,’ are the only other 2 characters that matter.


string addIndentation(string &str,int numIndents){
    string ans="";
    for(int i=1;i<=numIndents;i++) ans += '\t';
    ans += str;
    return ans;
}

vector<string> Solution::prettyJSON(string A) {

    int numIndents=0;
    vector<string> output;
    for(int i=0;i<A.length();){
        string str = "";
        if(A[i]=='{'||A[i]=='['){
            str+=A[i];
            i++;
            output.push_back(addIndentation(str,numIndents));
            numIndents++;
        }else if(A[i]=='}'||A[i]==']'){
            str += A[i]; 
            i++;
            if(i<A.length()&&A[i]==','){  // },
                str += A[i]; 
                i++;
            }
            numIndents--;
            output.push_back(addIndentation(str,numIndents));
        }else{
            while(A[i]!=','&&A[i]!='}'&&A[i]!=']'&&A[i]!='{'&&A[i]!='['){
                str += A[i];
                i++;
            }
            if(A[i]==','){   // "baz", 
                str += A[i];
                i++;
            }
            output.push_back(addIndentation(str,numIndents));
        }
        
    }
    
    return output;
}
