// Find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

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
