// Approach 1: O(no of bits) = O(logn)

int Solution::numSetBits(unsigned int N) {
    int ans=0;
    while(N>0){
        if(N&1) ans++;
        N>>=1;
    }
    return ans;
}

/***************************************************************************************************************************/

// Approach 2: Efficient, O(no of set bits)

int Solution::numSetBits(unsigned int N) {
    int ans=0;
    while(N>0){
        N=(N&(N-1)); // Removes the last set bit
        ans++;
    }
    return ans;
}

/***************************************************************************************************************************/

// Approach 3: Efficient, O(no of set bits)

int Solution::numSetBits(unsigned int N) {
    int ans=0;
    while(N>0){
        int p = N&(-N); // Last set bit
        N-=p; 
        ans++;
    }
    return ans;
}
