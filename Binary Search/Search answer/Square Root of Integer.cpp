// Given an integar A. Compute and return the square root of A.
// If A is not a perfect square, return floor(sqrt(A)).

// Approach 1: Linear Search 

/***************************************************************************************************************************/

// Approach 2: Binary Search 

int Solution::sqrt(int A) {
    int s=0,e=A,ans;
    // IMP NOTE!!!!=> NOT s<e but s<=e    
    while(s<=e){
        // NOTE!!!!=> ALWAYS USE LLI TO PREVENT OVERFLOWS FOR MID
        long long mid=(s+e)/2;
        if(mid*mid<=A){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return ans;
}