// Given an array of integers, every element appears twice except for one. Find that single one.

// Approach 1: Brute force

/***************************************************************************************************************************/

// Approach 2: Hashmap

/***************************************************************************************************************************/

// Approach 3: XORing all values
// Time O(N), Space O(1)
// A ^ A = 0 and A ^ B ^ A = B.
// So, all even occurences will cancel out using XOR.

int Solution::singleNumber(const vector<int> &A) {
    int ans=0;
    for(auto num:A) ans=(ans^num);
    return ans;
}

