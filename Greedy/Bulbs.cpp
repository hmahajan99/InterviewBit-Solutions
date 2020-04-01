int Solution::bulbs(vector<int> &A) {
    int count=0;
    for(int i=0;i<A.size();i++){
        if((A[i]+count)%2==0) count++;
    }
    return count;
}
