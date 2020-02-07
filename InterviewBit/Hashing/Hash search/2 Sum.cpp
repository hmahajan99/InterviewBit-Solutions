// Approach 1: Use sorting, and 2 pointer approach(Meet in the middle)
// Time: O(nlogn)

/***************************************************************************************************************************/

// Approach 2: Hashing 
// Time: O(n)

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    unordered_map<int,int> m; // element -> index
    vector<int> ans;
    
    for(int i=0;i<A.size();i++){
        if(m.count(B-A[i])){
           ans.push_back(m[B-A[i]]+1); // As indexes are 1 based
           ans.push_back(i+1);
           return ans;
        }
        if(!m.count(A[i])){
            m[A[i]] = i;            
        }
    }
    return ans;
    
}
