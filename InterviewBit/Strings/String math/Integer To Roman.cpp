// Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman numeral version
// 1 <= A <= 3999
// Note : This question has a lot of scope of clarification from the interviewer

// Approach 1:

string Solution::intToRoman(int A) {

    char ch[] = {'M','D','C','L','X','V','I'};
    int val[] = {1000,500,100,50,10,5,1};
    
    string ans="";
    for(int i=0;i<=6;i+=2){    // i=M,C,X,I i.e i=1000,100,10,1
        int x = A/val[i];
        if(x==9){
            ans += ch[i];
            ans += ch[i-2];
        }else if(5<=x&&x<=8){
            ans += ch[i-1];
            for(int j=1;j<=x-5;j++){
                ans += ch[i];
            }
        }else if(x==4){
            ans += ch[i];
            ans += ch[i-1];
        }else if(1<=x&&x<=3){
            for(int j=1;j<=x;j++){
                ans += ch[i];
            }
        }
        A=A%val[i];
    }
    return ans;
}

/***************************************************************************************************************************/

// Approach 2:
// Think of some essential numbers whose roman numeral representations can be used to construct other numbers. Its really similar to constructing numbers in different bases after that.
// It is very much like learning our own number system.
// All you need to know is how to write 0-9, 10, 20, 30, 40, .. 90, 100, 200, 300,… 900, 1000, 2000, 3000.
// You can derive rest of the numbers using the above.

string Solution::intToRoman(int num) {
    // 1000, 2000, 3000
    string M[] = {"", "M", "MM", "MMM"};
    // 100, 200, 300, .. 900
    string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    // 10, 20, ... 90
    string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    // 1, 2, ... 9
    string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}
