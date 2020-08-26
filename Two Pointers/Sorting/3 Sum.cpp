// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
// Return the sum of the three integers.
// Assume that there will only be one solution

// Example: Given array S = {-1 2 1 -4} and target = 1 .The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)

// Approach 1: Brute Force, O(n^3)

/***************************************************************************************************************************/

// Approach 2: Fix i, and use 2 pointer for j(=i+1) & k(=n-1)
// Time - O(n^2)

int Solution::threeSumClosest(vector<int> &A, int B) {

    sort(A.begin(),A.end());
    int minDiff = INT_MAX;
    int sum;
    for(int i=0;i<A.size();i++){
        int j=i+1,k=A.size()-1;
        while(j<k){
            if(abs(A[i]+A[j]+A[k]-B)<minDiff){
                minDiff = abs(A[i]+A[j]+A[k]-B);
                sum = A[i]+A[j]+A[k];
                if(sum==B) return B;
            }
            if(A[i]+A[j]+A[k]>B) k--;
            else j++;
        }
    }
    
    return sum;
    
}
