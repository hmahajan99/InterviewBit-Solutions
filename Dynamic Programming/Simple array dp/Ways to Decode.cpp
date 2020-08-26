// A message containing letters from A-Z is being encoded to numbers using the following mapping:
//  'A' -> 1
//  'B' -> 2
//  ...
//  'Z' -> 26
// Given an encoded message A containing digits, determine the total number of ways to decode it modulo 109 + 7.
// Input: A = "12"
// Output: 2, Given encoded message "12", it could be decoded as "AB" (1, 2) or "L" (12).

// Approach 1: Top Down

bool isValid(int num){
    return 1<=num&&num<=26;
}

int numWays(int i,const string &A,int* dp){
    
    int n=A.size();
    if(i==n) return 1;
    
    if(dp[i]!=-1) return dp[i];

    int ways=0;
    
    // A[i]='0' => ways=0 => Edge case  
    if(isValid(A[i]-'0')) ways+=numWays(i+1,A,dp);

    if(i<n-1&&A[i]!='0'){
        int num = (A[i]-'0')*10+(A[i+1]-'0'); 
        if(isValid(num)) ways += numWays(i+2,A,dp);
    }
    
    return dp[i]=ways;
        
}

int Solution::numDecodings(string A) {

    int n = A.size();
    int *dp = new int[n];
    fill(dp,dp+n,-1); // STL fill => to initialize
    return numWays(0,A,dp);
    
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up

bool isValid(int num){
    return 1<=num&&num<=26;
}

int get(int *dp,int i){
    if(i<0) return 1;
    return dp[i];
}

int Solution::numDecodings(string A) {

    int n = A.size();
    if(n==0) return 0;

    int *dp = new int[n]; // dp[i] => ways to decode sting A[0...i]
    dp[0]=(A[0]!='0');
    for(int i=1;i<n;i++){
        int ways=0;
        if(isValid(A[i]-'0')) ways+=get(dp,i-1);
        if(i>0&&A[i-1]!='0'){
            int num = (A[i-1]-'0')*10+(A[i]-'0'); 
            if(isValid(num)) ways+=get(dp,i-2);            
        }
        dp[i]=ways;
    }
    return dp[n-1];
}