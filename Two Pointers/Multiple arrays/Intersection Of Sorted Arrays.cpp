// Find the intersection of two sorted arrays OR in other words,
// Given 2 sorted arrays, find all the elements which occur in both the arrays.

// Approach 1: Linear Search on B
// For each element of A linear search on B
// Time - O(n*m)

/***************************************************************************************************************************/

// Approach 2: Binary Search on B
// Time - O(n*logm)

/***************************************************************************************************************************/

// Approach 3: Hashtable, doesnt require arrays to be sorted
// Time - O(n+m)
// Space - O(n+m)

/***************************************************************************************************************************/

// Approach 4: 2 pointers, makes use of information that both arrays are sorted
// Time - O(n+m)
// Space - O(1)

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    vector<int> ans;
    int i=0,j=0;
    while(i<A.size()&&j<B.size()){
        if(A[i]==B[j]){
            ans.push_back(B[j]); 
            i++; 
            j++;
        }
        else if(A[i]<B[j]) i++;
        else j++;
    }
    return ans;
}
