// You are given an array of N integers, A1, A2 ,..., AN and an integer B. 
// Return the of count of distinct numbers in all windows of size B.
// Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.
// NOTE: if B > N, return an empty array.

vector<int> Solution::dNums(vector<int> &A, int K) {
    int n = A.size();
    vector<int> ans;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        m[A[i]]++;
        if(i>=K-1){
            // m.size() => No of keys
            ans.push_back(m.size());
            m[A[i-K+1]]--;
            // m.erase(key)
            if(m[A[i-K+1]]==0) m.erase(A[i-K+1]); // remove if count becomes 0
        }
    }
    return ans;
}
