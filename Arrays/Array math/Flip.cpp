// You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. 
// In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. 
// By flipping, we mean change character 0 to 1 and vice-versa.

// Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. 
// If you don’t want to perform the operation, return an empty array. 
// Else, return an array consisting of two elements denoting L and R. 
// If there are multiple solutions, return the lexicographically smallest pair of L and R.

// For example, S = 010
// Pair of [L, R] | Final string
// _______________|_____________
// [1 1]          | 110
// [1 2]          | 100
// [1 3]          | 101
// [2 2]          | 000
// [2 3]          | 001
// We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].

// Another example, If S = 111
// No operation can give us more than three 1s in final string. So, we return empty array [].

// Approach : Using KADANE's Algorithm [ALSO NEED START AND END OF MAX SUM SUBARRAY]

// Say it has A 0s and B 1s. Eventually when we flip, there are B 0s and A 1s.
// So, number of 1s increase by A - B. We want to choose a subarray which maximises this. 
// Note, if we change 1s to -1, then sum of values will give us A - B. 
// Then, we have to find a subarray with maximum sum, which can be done via Kadane’s Algorithm.

vector<int> Solution::flip(string A) {
    int n = A.size();
    int maxEndingHere=(A[0]=='1')?-1:1;
    int maxSofar=(A[0]=='1')?-1:1;
    int currLen=1;
    pair<int,int> maxSubArray={0,0}; // START AND END OF MAX SUM SUBARRAY
    // Here we are considering subarray to be of size at leat 1 i.e non empty
    for(int i=1;i<n;i++){
        
        int val = (A[i]=='1')?-1:1;
        if(val>maxEndingHere+val){
            // starting new array here
            currLen=1;
            maxEndingHere=val;
        }else{
            // add to previous
            currLen++;
            maxEndingHere=maxEndingHere+val;
        }
        
        if(maxEndingHere>maxSofar){
            // Update start & end
            maxSubArray.first=i-currLen+1;
            maxSubArray.second=i;
            maxSofar = maxEndingHere;
        }

    }
    
    vector<int> ans;
    // If maxSum -ve ans=[] , eg: S="111"
    if(maxSofar>0){ 
        ans = {maxSubArray.first+1,maxSubArray.second+1}; // as want 1 indexed
    }
    return ans; 

}