// Given an array of integers, every element appears thrice except for one which occurs once.
// Find that element which does not appear thrice.

// Approach 1: Brute force

/***************************************************************************************************************************/

// Approach 2: Hashmap

/***************************************************************************************************************************/

// Approach 3: Time O(N), Space O(1)
// Every number that occurs thrice will either contribute 3 ‘1’s or 3 ‘0’s to the position.
// The number that occurs once X will contribute exactly one 0 or 1 to the position depending on whether it has 0 or 1 in that position.
// A straightforward implementation is to use an array of size 32 to keep track of the total count of ith bit.
// We can improve this using bitmask variable

int Solution::singleNumber(const vector<int> &A) {
    int ans=0;
    for(int i=1,p=1,mask=1;i<=31;i++,mask<<=1,p*=2){
        int bit=0;
        for(int num:A) if((num&mask)>0) bit=(bit+1)%3;
        ans = ans + p*bit;
    }
    return ans;
}


