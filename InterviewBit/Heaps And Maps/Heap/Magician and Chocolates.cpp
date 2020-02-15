int Solution::nchoc(int A, vector<int> &B) {
    int M = (1e9+7);
    priority_queue<int> pq;
    for(int a:B){
        if(a) pq.push(a);
    }
    int ans=0;
    while(!pq.empty()&&A){
        int a = pq.top();
        pq.pop();
        ans = ((long)ans + a)%M; // IMP NOTE!!!!!!! => TYPECAST to long as INT + INT => INT
        if(a/2!=0) pq.push(a/2);            
        A--;
    }
    return ans;
    
}
