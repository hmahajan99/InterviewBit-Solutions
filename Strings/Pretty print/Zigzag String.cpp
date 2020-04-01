// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P.......A........H.......N
// ..A..P....L....S....I...I....G
// ....Y.........I........R
// And then read line by line: PAHNAPLSIIGYIR
// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"

// Example 2 :
// ABCD, 2 can be written as
// A....C
// ...B....D    and hence the answer would be ACBD

// Approach
// Just look at simply simulating what is being told in the problem.
// Follow the simple steps:
// You need to maintain numRows number of strings S[numRows].
// And then populating string S in each row in zigzag fashion.
// Finally concatenate S[0] .. S[numRows-1] to get the answer.

string Solution::convert(string A, int B) {

    if(B<=1) return A;

    vector<string> ans(B,"");
    int j=0,dir=1;
    for(int i=0;i<A.length();i++){
        ans[j].push_back(A[i]);
        if(j==0) dir=1;
        else if(j==B-1) dir=-1;
        j = j + dir;
    }
    
    string output="";
    for(string s:ans) output += s;
    return output;
    
}
