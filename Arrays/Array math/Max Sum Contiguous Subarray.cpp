// Find the contiguous subarray within an array, A of length N which has the largest sum.

// Note: Min size of subarray should be 1 here i.e should be non empty

// Input 1: A = [1, 2, 3, 4, -10]
// Output 1: 10
// Explanation 1: The subarray [1, 2, 3, 4] has the maximum possible sum of 10.

// Input 2: A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
// Output 2: 6
// Explanation 2: The subarray [4,-1,2,1] has the maximum possible sum of 6.

// Approach 1: Brute force O(n^3)
// Take all subarrays and calculate sum

/***************************************************************************************************************************/

// Approach 2: Brute force O(n^2)
// Take all subarrays and calculate sum in O(1) time for a subarray by going in order or using a prefix sum array


int Solution::maxSubArray(const vector<int> &A) {
    
    int ans=INT_MIN;   // ans = 0 XXX as subarray must be of length atleast 1 in this ques [-500] => ans=-500 
    for(int i=0;i<A.size();i++){
        int sum = 0;
        for(int j=i;j<A.size();j++){
            sum+=A[j];
            ans=max(ans,sum);
        }
    }
    return ans;

}

/***************************************************************************************************************************/

// Approach 3: Dynamic Programming
// Time - O(n)
// Space - O(n)

int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    vector<int> dp(n); // dp[i] - max sum of contiguous subarray ending at i 
    int maxSum = A[0];
    dp[0]=A[0];
    for(int i=1;i<n;i++){
        dp[i]=max(A[i],A[i]+dp[i-1]); // start new array at i or add to previous
        maxSum=max(maxSum,dp[i]);
    }
    return maxSum;
}

/***************************************************************************************************************************/

// Approach 4: Kadane's Algorithm
// Time - O(n)
// Space - O(1)

// IMP NOTE: Can also use Kadane's Algorithm to find Maximum Sum Rectangle In A 2D Matrix (Dynamic Programming)
// in O(cols^2 * rows) or O(rows^2 * cols) time

int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    int maxEndingHere=A[0];
    int maxSofar=A[0];
    for(int i=1;i<n;i++){
        maxEndingHere = max(maxEndingHere+A[i],A[i]); // start new array at i or add to previous
        maxSofar = max(maxSofar,maxEndingHere);
    }
    return maxSofar;
}

/***************************************************************************************************************************/

// Approach 5: Using Divide and Conquer , time - O(nlogn)
// T(n) = 2T(n/2) + Θ(n) recurrence is similar to Merge Sort

class ReturnVal{
    public:
    int maxPrefixSum;
    int maxSuffixSum;
    int maxSum;
    // Initializer List
    ReturnVal(int mps,int mss,int ms) : maxPrefixSum(mps) , maxSuffixSum(mss) , maxSum(ms) {}
};

ReturnVal maxSumDNC(int si,int ei,const vector<int> &A){
    if(si>ei) return {INT_MAX,INT_MAX,INT_MAX};
    if(si==ei) return {A[si],A[si],A[si]};
    
    int maxPrefixSum=INT_MIN;
    int currentPrefixSum=0;
    for(int i=si;i<=ei;i++){
        currentPrefixSum+=A[i];
        maxPrefixSum = max(maxPrefixSum,currentPrefixSum);    
    }

    int maxSuffixSum=INT_MIN;
    int currentSuffixSum=0;
    for(int i=ei;i>=si;i--){
        currentSuffixSum+=A[i];
        maxSuffixSum = max(maxSuffixSum,currentSuffixSum);    
    }
    
    int mid = (si+ei)/2;
    ReturnVal l = maxSumDNC(si,mid,A);
    ReturnVal r = maxSumDNC(mid+1,ei,A);

    int op1 = l.maxSuffixSum + r.maxPrefixSum;
    int op2 = l.maxSum;
    int op3 = r.maxSum;
    int maxSum = max({op1,op2,op3});
    
    return {maxPrefixSum,maxSuffixSum,maxSum};
}

int Solution::maxSubArray(const vector<int> &A) {
    int n = A.size();
    return maxSumDNC(0,n-1,A).maxSum;
}