// Given an unsorted integer array, find the first missing positive integer.
// Example: Given [1,2,0] return 3,
// [3,4,-1,1] return 2,
// [-8, -7, -6] returns 1

// Approach 1: Brute Force
// To simply solve this problem, search all positive integers, starting from 1 in the given array. 
// We may have to search at most n+1 numbers in the given array. So this solution takes O(n^2) in worst case.

/***************************************************************************************************************************/

// Approach 2: Sorting
// We can use sorting to solve it in lesser time complexity. We can sort the array in O(nLogn) time.
// Once the array is sorted, then a linear scan of the array is all that remains to be done.
// So this approach takes O(nLogn + n) time which is O(nLogn).

/***************************************************************************************************************************/

// Approach 3: Hashing, O(n) time & space
// We can also use hashing. We can build a hash table of all positive elements in the given array.
// Once the hash table is built, all positive integers, starting from 1 can be searched here. As soon as we find a number which is not there in the hash table, we return it.
// Approximately, this approach may take O(n) time, but it requires O(n) extra space.

/***************************************************************************************************************************/

// Approach 4: O(n) time, O(1) space
// IMP NOTE: O(1) Space => ***can change input array*** REM!!! 

// Numbers A[i]<=0 and A[i]>N ( N being the size of the array ) is not important to us since the missing positive integer will be in the range [1, N+1].
// The answer will be N+1 only if all of the elements of the array are exact one occurrence of [1, N].
// Now, since additional space is not allowed either, the given array itself needs to be used to track it.
// It may be helpful to use the fact that the size of the set we are looking to track is [1, N]
// which happens to be the same size as the size of the array.
// This means we can use the array to track these elements.
// We traverse the array and if A[i] is in [1,N] range, we try to put in the index of same value in the array.

int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    for(int i=0;i<n;){
        if(A[i]>0&&A[i]<=n) {
            // Move A[i] to its correct position
            int pos = A[i]-1; // 0 indexed
            if(A[pos]==A[i]) i++; 
            else swap(A[pos], A[i]); // Dont increment i here
        }else{
            i++;
        }
    }
    
    for (int i=0;i<n;i++) {
        if(A[i]!=i+1) return (i+1);
    }
    
    return n+1;
}

// Alternatively,
// 1. Segregrate Positve and Negative Numbers in the array.
// 2. Traverse all the Positive Numbers, 
//      i) if, the number is larger then the input array size, do nothing
//      ii) else, the number is within input array size limit, consider number as array index, and mark the element at that index Negative.
// 3. After doing the above operation, Traverse the array with initial Positve values again, and store the first occurunce of index, whose value is Non-Negative. (Because this means that index value was not present in the array)