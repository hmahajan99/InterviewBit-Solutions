// There are certain problems which are asked in the interview to also check how you take care of overflows in your problem.
// This is one of those problems.
// Please take extra care to make sure that you are type-casting your ints to long properly and at all places. Try to verify if your solution works if number of elements is as large as 105

// Food for thought :
// Even though it might not be required in this problem, in some cases, you might be required to order the operations cleverly so that the numbers do not overflow.
// For example, if you need to calculate n! / k! where n! is factorial(n), one approach is to calculate factorial(n), factorial(k) and then divide them.
// Another approach is to only multiple numbers from k + 1 ... n to calculate the result.
// Obviously approach 1 is more susceptible to overflows.

// You are given a read only array of n integers from 1 to n.
// Each integer appears exactly once except A which appears twice and B which is missing.
// Return A and B.
// Input:[3 1 2 5 3] 
// Output:[3, 4] 
// A = 3, B = 4

// Approach: Find relations b/w actual sum & sum of n natural numbers

// Sum(Actual) = Sum(1…N) + A - B
// We need one more relation. How about the sum of squares?
// Sum(Actual Squares) = Sum(1^2 ... N^2) + A^2 - B^2
// Sum(Actual Squares) - Sum(1^2 ... N^2) = (A - B)(A + B)= (Sum(Actual) - Sum(1...N)) ( A + B). 

#define lli long long int
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    lli n = A.size();

    lli sum1=0,sum2=0;
    lli x,y,z;
    
    for(auto a:A){
        sum1+=a; // Sum(Actual)
        sum2+=(lli)a*a; // Sum(Actual Squares)
    }

    x = sum1 - n*(n+1)/2; // x = A-B
    y = sum2 - n*(n+1)*(2*n+1)/6; // y = (A-B)(A+B)
    z = y/x; // z = A+B
    vector<int> ans;
    ans.push_back((x+z)/2); // A
    ans.push_back((z-x)/2); // B
    return ans;
    
}