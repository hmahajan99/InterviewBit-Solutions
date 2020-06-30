// Given an array of positive elements, you have to flip the sign of some of its elements such that the resultant sum of the 
// elements of array should be minimum non-negative(as close to zero as possible). 
// Return the minimum no. of elements whose sign needs to be flipped such that the resultant sum is minimum non-negative.

// Example:
// A = [15, 10, 6] ans = 1 (Here, we will flip the sign of 15 and the resultant sum will be 1 )
// A = [14, 10, 4] ans = 1 (Here, we will flip the sign of 14 and the resultant sum will be 0)

// Approach
// This problem can be reduced to a Knapsack problem where we have to fill a Knapsack of capacity (S/2) as fully as possible 
// and using the minimum no. of elements. We will fill the Knapsack with the given elements. 
// Sign of all the elements which come into the knapsack will be flipped.
// As sum of all the elements in the Knapsack will be as close to S/2 as possible, 
// we are indirectly calculating minimum non-negative sum of all the elements after flipping the sign.

// Space optimised approach
int Solution::solve(const vector<int> &A) {
    int sum=0;
    for(int i=0;i<A.size();i++) sum+=A[i];
    sum/=2;
    vector<int> dp(sum+1, INT_MAX); // dp[i] = min elements required to get a sum of i
    dp[0]=0;
    for(int i=0;i<A.size();i++){
      for(int j=sum;j>=A[i];j--){
         if(dp[j-A[i]]!=INT_MAX) dp[j]=min(dp[j], dp[j-A[i]]+1);
      }
    }
    for(int i=sum;i>=0;i--){
        if(dp[i]!=INT_MAX) return dp[i];
    }
}
