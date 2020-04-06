// Find the contiguous subarray within an array (containing at least one number) which has the largest product.
// Return an integer corresponding to the maximum product possible.

// Note: Min size of subarray should be 1 here i.e should be non empty

// Example :

// Input : [2, 3, -2, 4]
// Return : 6  Possible with [2, 3]

// Input: arr[] = {6, -3, -10, 0, 2}
// Output:   180  // The subarray is {6, -3, -10}

// Input: arr[] = {-1, -3, -10, 0, 60}
// Output:   60  // The subarray is {60}

// Input: arr[] = {-2, -3, 0, -2, -40}
// Output:   80  // The subarray is {-2, -40}

// Question similar to Max Sum Contiguous Subarray

// Approach 1: Brute force O(n^3)
// Take all subarrays and calculate product
// Optimize brute force to O(n^2)

/***************************************************************************************************************************/

// Approach 2: Dynamic Programming
// Time - O(n)
// Space - O(n)

// If there were no zeros or negative numbers, then the answer would definitely be the product of the whole array.
// We need to now maintain the maximum product in positive and maximum product in negative. On encountering a negative number, the maximum product in negative can quickly come into picture.

// Maximum product can also be obtained by minimum (negative) product ending with the previous element multiplied by this element. 
// Note: Min size of subarray should be 1 here i.e should be non empty

int Solution::maxProduct(const vector<int> &A) {
    int n = A.size();
    vector<int> dpMax(n); // dp[i] - max product of contiguous subarray ending at i 
    vector<int> dpMin(n); // dp[i] - min product of contiguous subarray ending at i 
    int maxProduct = A[0];
    dpMax[0]=dpMin[0] = A[0];
    for(int i=1;i<n;i++){
        dpMax[i] = max({A[i],A[i]*dpMax[i-1],A[i]*dpMin[i-1]});
        dpMin[i] = min({A[i],A[i]*dpMax[i-1],A[i]*dpMin[i-1]});
        maxProduct = max(maxProduct,dpMax[i]);
    }
    return maxProduct;
}

/***************************************************************************************************************************/

// Approach 3: Similar to Kadane's Algorithm
// Time - O(n)
// Space - O(1)

// Note: Min size of subarray should be 1 here i.e should be non empty

int Solution::maxProduct(const vector<int> &A) {
    int n = A.size();
    int maxProductEndingHere=A[0];
    int minProductEndingHere=A[0];
    int maxProductSofar=A[0];
    for(int i=1;i<n;i++){
        int prevMax = maxProductEndingHere;
        int prevMin = minProductEndingHere;
        maxProductEndingHere = max({A[i],prevMax*A[i],prevMin*A[i]}); 
        minProductEndingHere = min({A[i],prevMax*A[i],prevMin*A[i]}); 
        maxProductSofar = max(maxProductSofar,maxProductEndingHere);
    }
    return maxProductSofar;
}
