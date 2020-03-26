// Bucket - Number encoding

// Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.
// Lets say N = size of the array. Then, following holds true :
// All elements in the array are in the range [0, N-1]
// N * N does not overflow for a signed integer
// Example:
// Input : [1, 0]
// Return : [0, 1]

// Approach: Encoding two numbers into one

// You will need a copy of older version but you cant use extra space.
// Can you think of something so that we can extract more than one entries from existing numbers.
// Encoding two numbers into one?

// If we could somehow store 2 numbers in every index ( that is, Arr[i] can contain the old value and the new value somehow ), then the problem becomes very easy.
// NewValue of Arr[i] = OldValue of Arr[OldValue of Arr[i]]

// Now, we will do a slight trick to encode 2 numbers in one index.
// This trick assumes that N * N does not overflow.

// 1) Increase every Array element Arr[i] by (Arr[Arr[i]] % n)*n.
// 2) Divide every element by N.

// Given a number as
//    A = B + C * N   if ( B, C < N )
//    A % N = B
//    A / N = C

void Solution::arrange(vector<int> &A) {
    int n=A.size();
    for(int i=0;i<n;i++){
        A[i] += (A[A[i]]%n)*n;
    }
    for(int i=0;i<n;i++){
        A[i] /= n;
    }
    
}