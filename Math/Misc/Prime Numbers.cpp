// Given a number N, find all prime numbers upto N ( N included ).
// Example:
// if N = 7, all primes till 7 = {2, 3, 5, 7}
// Make sure the returned array is sorted.

// n*log(log n) time complexity
vector<int> Solution::sieve(int A) {

    bool* seive = new bool[A+1];
    fill(seive,seive+A+1,true);    

    seive[0]=seive[1]=false;
    for(int i=2;i*i<=A;i++){
        if(seive[i]){
            for(int j=i*i;j<=A;j+=i){
                seive[j]=false;
            }
        }
    }

    vector<int> ans;
    for(int i=0;i<=A;i++) if(seive[i]) ans.push_back(i);
    return ans;
    
}
