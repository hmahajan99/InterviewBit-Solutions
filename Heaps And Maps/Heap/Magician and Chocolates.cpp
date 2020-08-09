// Given N bags, each bag contains Bi chocolates. There is a kid and a magician. 
// In one unit of time, kid chooses a random bag i, eats Bi chocolates, then the magician fills the ith bag with floor(Bi/2) chocolates.
// Find the maximum number of chocolates that kid can eat in A units of time.

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
