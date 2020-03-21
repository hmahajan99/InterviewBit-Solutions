// Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.
// NOTE: A solution will always exist

// Approach: Sieve of Erastothenes

vector<int> Solution::primesum(int A) {

    bool* seive = new bool[A+1];
    
    for(int i=0;i<=A;i++){
        seive[i] = true;
    }
    
    for(int i=2;i*i<=A;i++){
        if(seive[i]){
            for(int j=i*i;j<=A;j+=i){
                seive[j]=false;
            }
        }
    }
    
    // NOTE:- 1 is neither prime nor composite
    for(int i=2;i<=A/2;i++){
        if(seive[i]&&seive[A-i]){
            return {i,A-i};
        }        
    }
    
}