// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
// A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.
// Example:
// Given “25525511135”,
// return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)

// Approach : Brute force works here
// You need to place only 3 dots and every segment should be a valid one.

// Corner case: 25011255255
// 25.011.255.255 is not valid as 011 is not valid.
// 25.11.255.255 is not valid either as you are not allowed to change the string.
// 250.11.255.255 is valid.

bool isValid(string o){
    if(o.length()>=1&&o.length()<=3){
        int x = stoi(o);
        if(o.length()>1&&o[0]=='0') return false; // 005
        return 0<=x && x<= 255;
    }
    return false;
}

vector<string> Solution::restoreIpAddresses(string A) {

    vector<string> output;
    int n = A.length();
    if(n<4||n>12) return output; // Brute force works as the length is atmost 12 now

    for(int i=1;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                string o1 = A.substr(0,i);
                string o2 = A.substr(i,j-i);
                string o3 = A.substr(j,k-j);
                string o4 = A.substr(k);
                if(isValid(o1)&&isValid(o2)&&isValid(o3)&&isValid(o4)){
                    output.push_back(o1+'.'+o2+'.'+o3+'.'+o4);
                }
            }
        }
    }
    sort(output.begin(),output.end());
    return output;
    
}