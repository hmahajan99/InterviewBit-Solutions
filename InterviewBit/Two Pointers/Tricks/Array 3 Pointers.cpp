// Same problem as Minimize the absolute difference

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
