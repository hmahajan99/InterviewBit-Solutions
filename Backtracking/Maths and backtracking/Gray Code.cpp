// The gray code is a binary numeral system where two successive values differ in only one bit.
// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2

// Approach 1: Recursion
// Reverse first half and 1 bit leftmost to get seccond half
//    00
//    01
// -----
//    11
//    10

vector<int> Solution::grayCode(int N) {
    // N is no. of bits    
    
    if(N==0) return vector<int>();
    if(N==1) return {0,1};
    
    vector<int> v = grayCode(N-1);

    int n = v.size();
    for(int i=0;i<n;i++){
        v.push_back(v[n-1-i]+(1<<(N-1)));
    }

    return v;
    
}

/***************************************************************************************************************************/

// Approach 2: Iterative

vector<int> Solution::grayCode(int N) {
    // N is no. of bits
    vector<int> v(1,0);
    for(int numBits=1;numBits<=N;numBits++){
        int n=v.size();
        for(int i=0;i<n;i++){
            v.push_back(v[n-1-i]+(1<<(numBits-1)));
        }
    }
    return v;
}