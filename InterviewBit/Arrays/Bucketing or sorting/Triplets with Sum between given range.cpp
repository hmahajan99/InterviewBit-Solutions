// Given an array of real numbers greater than zero in form of strings.
// Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 .
// Return 1 for true or 0 for false.
// Example:
// Given [0.6, 0.7, 0.8, 1.2, 0.4] , You should return 1 as 0.6+0.7+0.4=1.7

// Approach 1: Brute Force
// The brute force approach would be using three loops and checking each triplet for the sum.It will be O(n³).

/***************************************************************************************************************************/

// Approach 2: 2 pointers, O(n^2)
// Use STL STOD - stod(string) to convert string to double  
// First sort array
// Fix i, use 2 pointers for j(=i+1) & k(=n-1)

int Solution::solve(vector<string> &A) {
    int n = A.size();
    vector<double> B;
    for(string s:A) B.push_back(stod(s));
    sort(B.begin(), B.end());
    
    for(int i=0;i<n;i++){
        int j = i+1;
        int k = n-1;
        if(B[i]+B[n-2]+B[n-1]<=1) continue; // underflow
        if(B[i]+B[i+1]+B[i+2]>=2) continue; // overflow
        while(j<k){
            double sum = B[i]+B[j]+B[k];
            if(sum>=2) k--;
            else if(sum<=1) j++;
            else return 1;
        }
    }
    
    return 0;
}
