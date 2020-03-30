// Given a list of non negative integers, arrange them such that they form the largest number.
// For example:
// Given [3, 30, 34, 5, 9], the largest formed number is 9534330.
// Note: The result may be very large, so you need to return a string instead of an integer.

// Approach: Sorting, using custom comparison function
// Obviously, we can’t simply just sort the numbers or string.
// Have you considered cases like 27, 271 or 12, 121 ?
// Sorting all numbers in descending order is the simplest solution that occurs to us. But this doesn’t work.
// For example, 548 is greater than 60, but in the output, 60 comes before 548. As a second example, 98 is greater than 9, but 9 comes before 98 in the output.
// The solution is to use any comparison based sorting algorithm. Thus, instead of using the default comparison, write a comparison function myCompare() and use it to sort numbers.
// Given two numbers X and Y, how should myCompare() decide which number to put first – we compare two numbers XY (Y appended at the end of X) and YX (X appended at the end of Y).
// If XY is larger, then, in the output, X should come before Y, else Y should come before X.
// For example, let X and Y be 542 and 60. To compare X and Y, we compare 54260 and 60542. Since 60542 is greater than 54260, we put Y first.

#define lli long long
bool cmp(int a,int b){
    lli ab = stoll(to_string(a)+to_string(b));
    lli ba = stoll(to_string(b)+to_string(a));
    return ab>ba;
}

string Solution::largestNumber(const vector<int> &A) {

    vector<int> v(A);
    sort(v.begin(),v.end(),cmp);
    
    // CORNER CASE A : [ 0, 0, 0, 0, 0 ] The expected returned value : 0 (not 00000)
    // CORNER CASE A : [ 0, 0, 0, 0, 1 ] The expected returned value : 10000 

    string ans = "";
    bool onlyZero = true;
    for(int a:v){
      if(a!=0) onlyZero = false;    
      ans += to_string(a); // to_string() STL
    } 
    
    if(onlyZero) ans="0";
    
    return ans;
}