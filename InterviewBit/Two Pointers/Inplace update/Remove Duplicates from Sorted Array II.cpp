int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();
    int i=0;
    int f=1;
    for(int j=0;j<n;j++){
        if(j<n-1&&A[j]==A[j+1]){
            f=min(f+1,2);
        }else{
            while(f--) A[i++]=A[j];
            f=1; // Reset
        }
    }    
    return i;
}

// Alternative:

int Solution::removeDuplicates(vector<int> &A) {
    int n = A.size();
    int i=0;
    int f=1;
    for(int j=0;j<n;j++){
        if(j<n-2&&A[j]==A[j+1]&&A[j+1]==A[j+2]){
            continue;
        }else{
            A[i++]=A[j];
        }
    }    
    return i;
}
