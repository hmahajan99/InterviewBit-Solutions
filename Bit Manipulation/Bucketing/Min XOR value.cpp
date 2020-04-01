// Approach 1: Brute force
// The brute-force would be to try every pair (x, y). If the array is sorted, do you need to check for every pair? 

/***************************************************************************************************************************/

// Approach 2: Sorting and XORing consecutive elements

// The first step is to sort the array. The answer will be the minimal value of X[i] XOR X[i+1] for every i.
// Proof:
// Let’s suppose that the answer is not X[i] XOR X[i+1], but A XOR B and there exists C in the array such as A <= C <= B.
// Next is the proof that either A XOR C or C XOR B are smaller than A XOR B.
// Let A[i] = 0/1 be the i-th bit in the binary representation of A
// Let B[i] = 0/1 be the i-th bit in the binary representation of B
// Let C[i] = 0/1 be the i-th bit in the binary representation of C
// This is with the assumption that all of A, B and C are padded with 0 on the left until they all have the same length
// Let i be the leftmost (biggest) index such that A[i] differs from B[i]. There are 2 cases now:
// 1) C[i] = A[i] = 0,
// then (A XOR C)[i] = 0 and (A XOR B)[i] = 1
// This implies (A XOR C) < (A XOR B)
// 2) C[i] = B[i] = 1,
// then (B XOR C)[i] = 0 and (A XOR B)[i] = 1
// This implies (B XOR C) < (A XOR B)
// Time complexity: O(N * logN) to sort the array and O(N) to find the smallest XOR

int Solution::findMinXor(vector<int> &A) {

    sort(A.begin(),A.end());
    
    int ans=(A[0]^A[1]);
    for(int i=1;i<A.size()-1;i++){
        if((A[i]^A[i+1])<ans) ans=(A[i]^A[i+1]);
    }
    
    return ans;
    
}