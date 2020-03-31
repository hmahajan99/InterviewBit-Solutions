// Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers for a given array A of size N.
// If such arrangement is not possible, it must be rearranged as the lowest possible order i.e., sorted in an ascending order.
// Note: The replacement must be in-place, do not allocate extra memory.

// Examples:
// Input 1: A = [1, 2, 3]
// Output 1: [1, 3, 2]
// Input 2: A = [3, 2, 1]
// Output 2: [1, 2, 3]
// Input 3: A = [1, 1, 5]
// Output 3: [1, 5, 1]
// Input 4: A = [20, 50, 113]
// Output 4: [20, 113, 50]

// Approach 1: Using C++ STL next_permutation()

vector<int> Solution::nextPermutation(vector<int> &A) {
    next_permutation(A.begin(),A.end());
    return A;
}

/***************************************************************************************************************************/

// Approach 2: Brute Force - O(n!)
// Generate n! permutations

/***************************************************************************************************************************/

// Approach 3: Time O(n) ,Space O(1)
// 1) An sequence sorted in descending order does not have next permutation.
// 2) For a sequence which is not sorted in descending order
//  a) Traverse from right and find the first item that is not following the descending order.
//  b) Swap the found character with closest greater (or smallest greater) element on right side of it.
//  c) After swapping, sort the string after the position of character found in step a

// Optimizations in step b) and c)
// a) Since the sequence is sorted in decreasing order, we can use binary search to find the closest greater element.
// c) Since the sequence is already sorted in decreasing order (even after swapping as we swapped with the closest greater), we can get the sequence sorted (in increasing order) after reversing it.

// Example 1 : 6 2 1 [5 4 3 0] -> 6 2 3 [5 4 1 0] -> 6 2 3 [0 1 4 5]
// Example 2 : 2 [3 3 2 2 1] -> 3 [3 2 2 2 1] -> 3 [1 2 2 2 3]


vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size();
    
    int i;
    for(i=n-2;i>=0;i--){
        if(A[i]<A[i+1]) break;
    }
    // A[i+1 .... n-1] is decreasing 

    if(i==-1){
        // At last permutation
        reverse(A.begin(),A.end());
    }else{
        // Swap A[i] with the next greater element to the right 
        for(int j=n-1;j>i;j--){
            if(A[j]>A[i]){
                swap(A[i],A[j]);
                break;
            }
        }        
        reverse(A.begin()+i+1,A.end());
    }
    return A;
}

// Optimization, binary search using reverse iterator since sorted in descending order

vector<int> Solution::nextPermutation(vector<int> &A) {
    int n = A.size();
    
    int i;
    for(i=n-2;i>=0;i--){
        if(A[i]<A[i+1]) break;
    }
    // A[i+1 .... n-1] is decreasing 

    if(i==-1){
        // At last permutation
        reverse(A.begin(),A.end());
    }else{
        // Swap A[i] with the next greater element to the right 
        // Use reverse iterator since sorted in descending order
        int j = upper_bound(A.rbegin(),A.rend()-i-1,A[i]) - A.rbegin(); // j = Index of the req num from the end
        swap(A[i],A[n-1-j]); // n-1-j = req index from start
        reverse(A.begin()+i+1,A.end());
    }
    return A;
}
