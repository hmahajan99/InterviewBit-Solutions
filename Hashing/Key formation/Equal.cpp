// Find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

// 1) Return the indices `A1 B1 C1 D1`, so that 
//   A[A1] + A[B1] = A[C1] + A[D1]
//   A1 < B1, C1 < D1
//   A1 < C1, B1 != D1, B1 != C1 
// 2) If there are more than one solutions, then return the tuple of values which are lexicographical smallest. 
// Example:
// Input: [3, 4, 7, 1, 2, 9, 8]
// Output: [0, 2, 3, 5] (O index)

// Approach 1: Brute force O(n^4)

/***************************************************************************************************************************/

// Approach 2: O(n^3)
// We know that A[I] + A[J] = A[K] + A[L].
// If we know, I, J and K, then we can determine what A[L] should be.
// We can lookup the value A[L] = A[I] + A[J] - A[K] in a hashmap.

/***************************************************************************************************************************/

// Approach 3: O(n^2) Hashing pairwise sums

vector<int> Solution::equal(vector<int> &A) {
    unordered_map<int,pair<int,int>> m;
    vector<int> ans;
    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++){
            if(m.count(A[i]+A[j])){
                int k=m[A[i]+A[j]].first,l=m[A[i]+A[j]].second;
                vector<int> v1 {k,l,i,j};
                bool isValid = (k<i)&&(l!=i)&&(l!=j); 
                if(isValid&&(ans.size()==0||v1<ans)){
                    // Update answer
                    ans=v1;
                }
            }
            else{
                m[A[i]+A[j]]=make_pair(i,j);
            }
        }
    }
    return ans;
    
}
