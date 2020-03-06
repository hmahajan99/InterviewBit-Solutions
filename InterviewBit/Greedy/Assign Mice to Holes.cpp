// sort mice positions (in any order)
// sort hole positions 

// Loop i = 1 to N:
//     update ans according to the value of |mice(i) - hole(i)|

// Proof of correctness:
// Let i1 < i2 be the positions of two mice and let j1 < j2 be the positions of two holes.
// It suffices to show via case analysis that
// max(|i1 - j1|, |i2 - j2|) <= max(|i1 - j2|, |i2 - j1|) , 

int Solution::mice(vector<int> &A, vector<int> &B) {
    int ans=0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i=0;i<A.size();i++){
        if(abs(A[i]-B[i])>ans){
            ans = abs(A[i]-B[i]);
        }
    }
    return ans;
}
