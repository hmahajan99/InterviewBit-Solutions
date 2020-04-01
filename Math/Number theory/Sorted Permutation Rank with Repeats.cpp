// Given a string, find the rank of the string amongst its permutations sorted lexicographically.
// Note that the characters might be repeated. If the characters are repeated, we need to look at the rank in unique permutations.

// Example :
// Input : 'aba'
// Output : 2
// The order permutations with letters 'a', 'a', and 'b' : 
// aab
// aba -> 2
// baa

// Approach 

// If the first character is X, all permutations which had the first character less than X would come before this permutation when sorted lexicographically.
// Number of permutation with a character C as the first character = number of permutation possible with remaining N-1 character = (N-1)! / (p1! * p2! * p3! ... ) where p1, p2, p3 are the number of occurrences of repeated characters.
// rank = number of permutation possible with placing characters smaller than current first character in the first position + rank of permutation of string with the first character removed
// (1/A) % P = A ^ (P - 2) % P using Fermats theorem if P is prime

// (a/b)%M = ((a%M)*(b^-1%M))%M , b^-1 = Multiplicative Modulo Inverse

// Eg: bacb = 4 (0 indexed)
// i=0 'a' => 3!/2! = 3
// i=1 
// i=2 ba'b' => 1! = 1
// i=3

// Eg: cbab = 10 (0 indexed)
// i=0 'a' => 3!/2! = 3 , 'b' => 3! = 6
// i=1 c'a' => 2!/2! = 1
// i=2
// i=3


#define MOD 1000003
#define lli long long int

// To compute x^y under modulo M (y,M>0)
int fastPower(int x,int y,int M){ 
    if(y==0) return 1; 
    lli smallAns = fastPower(x,y/2,M); 
    smallAns*=smallAns;
    smallAns%=M;
    return (y%2==0)?(smallAns):(x*smallAns)%M; 
} 

// Function to find modular inverse of a under modulo M
// Assumption: M is prime => Fermat's Little Theorem
int modInverse(int a, int P){ 
    return fastPower(a,P-2,P); 
} 

int Solution::findRank(string A) {
    
    int n = A.size();
    lli* fact = new lli[n];
    fact[0]=1;
    for(int i=1;i<n;i++){
        fact[i] = (i*fact[i-1])%MOD;
    }


    unordered_map<char,int> freq;
    for(char ch:A) freq[ch]++;
    
    lli ans=0; // O indexed
    for(int i=0;i<n;i++){
        for(auto p1:freq){
            if(p1.first<A[i]){ // placing p1.first as the first character and counting the number of permutations possible
                lli count = fact[n-1-i];
                for(auto p2:freq){
                    if(p1.first!=p2.first) count*=modInverse(fact[p2.second],MOD);
                    else count*=modInverse(fact[p2.second-1],MOD);
                    count%=MOD;
                }
                ans+=count;
                ans%=MOD;
            }
        }
        freq[A[i]]--;
        if(freq[A[i]]==0) freq.erase(A[i]); // remove the current character from the set
    }
    
    return (ans+1)%MOD; // as want answer 1 indexed
    
}
