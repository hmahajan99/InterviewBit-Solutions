// Given three sorted arrays A, B and Cof not necessarily same sizes.
// Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
// i.e. minimize | max(a,b,c) - min(a,b,c) |.

// Approach: 3 pointers

// Start with the smallest elements in each of the arrays A,B & C. Maintain a variable to update the answer during each of the steps to be followed.
// In every step, the only possible way to decrease the difference is to increase the minimum element out of the three elements.

// Alternatively, we can pick the largest elements and decrease the maximum element out of the three elements.

int getDiff(int a,int b,int c){
    return abs(max({a,b,c})-min({a,b,c}));
    // return abs(max(a,max(b,c)) - min(a,min(b,c)));
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {

    int i=0,j=0,k=0;
    int ans=INT_MAX;
    while(i<A.size()&&j<B.size()&&k<C.size()){
        ans=min(ans,getDiff(A[i],B[j],C[k]));
        if(ans==0) return 0;
        // int m = min(A[i],min(B[j],C[k]));
        int m = min({A[i],B[j],C[k]});
        if(m==A[i]) i++;
        else if(m==B[j]) j++;
        else k++;
    }
    return ans;
    
}