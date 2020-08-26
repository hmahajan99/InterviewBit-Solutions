// Same problem as Minimize the absolute difference

// You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

// Find i, j, k such that :
// max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
// Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))
// OR 
// Minimize the absolute difference
// Given three sorted arrays A, B and Cof not necessarily same sizes.
// Calculate the minimum absolute difference between the maximum and minimum number from the triplet a, b, c such that a, b, c belongs arrays A, B, C respectively.
// i.e. minimize | max(a,b,c) - min(a,b,c) |.

// Example :

// Input : 
//         A : [1, 4, 10]
//         B : [2, 15, 20]
//         C : [10, 12]

// Output : 5 
//          With 10 from A, 15 from B and 10 from C. 

// Note that we increment the pointer of the array which has the minimum, because our goal is to decrease the difference.

int getDiff(int a,int b,int c){
    return abs(max({a,b,c})-min({a,b,c}));
    // return abs(max(a,max(b,c)) - min(a,min(b,c)));
}

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {

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
