// Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
// If such an integer is found return 1 else return -1.

// Approach: Use sorting to find count in O(1)
// Time - O(nlogn)
// Corner case: when certain element repeats many times

int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    for(int i=0;i<A.size();i++){
        while(i+1<A.size()&&A[i]==A[i+1]) i++;
        int count = A.size()-1-i;
        if(count==A[i]) return 1;
    }
    return -1;
}