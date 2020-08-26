// Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.
// Maximum sub-array is defined in terms of the sum of the elements in the sub-array.
// Find and return the required subarray.
// NOTE:
// 1. If there is a tie, then compare with segment's length and return segment which has maximum length.
// 2. If there is still a tie, then return the segment with minimum starting index.

// Input: A = [10, -1, 2, 3, -4, 100]
// Output: [100]
// Explanation: The three sub-arrays are [10], [2, 3], [100]. The answer is [100] as its sum is larger than the other two.

// Approach : O(n) , don't need Kadane here

#define lli long long int
vector<int> Solution::maxset(vector<int> &A) {

    lli maxSum=0; // NOTE: LLI TO AVOID OVERFLOW
    pair<int,int> p(-1,-1); // start & end index of max sub array
    
    int i=0;
    
    while(i<A.size()){
        
        while(i<A.size()&&A[i]<0) i++;
        
        int startIndex=i;
        lli currSum=0;
        while(i<A.size()&&A[i]>=0){
            currSum += A[i];
            i++;
        }
        
        if(currSum>maxSum){
            maxSum = currSum;
            p = {startIndex,i-1};
        }else if(currSum==maxSum && i-startIndex>p.second-p.first+1){
            p = {startIndex,i-1};
        }

    }
    
    if(p.first==-1) return vector<int>();
    // SYNTAX, m.second+1 since end not inclusive in range
    return vector<int>(A.begin()+p.first,A.begin()+p.second+1);
    
}