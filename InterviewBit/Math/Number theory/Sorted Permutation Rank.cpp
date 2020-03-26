// Given a string, find the rank of the string amongst its permutations sorted lexicographically.
// Assume that no characters are repeated.

// Approach 1: Brute  force

// One simple solution is to initialize rank as 1, generate all permutations in lexicographic order. 
// After generating a permutation, check if the generated permutation is same as given string, if same, then return rank, if not, then increment the rank by 1. 
// Enumerating all permutations and matching with the current one is going to be exponential.

/***************************************************************************************************************************/

// Approach 2: O(n^2) Iterative

// If the first character is X, all permutations which had the first character less than X would come before this permutation when sorted lexicographically.
// Number of permutation with a character C as the first character = number of permutation possible with remaining N-1 character = (N-1)!

// rank = number of characters less than first character * (N-1)! + rank of permutation of string with the first character removed

// Eg: Lets say out string is “VIEW”.
// Character 1 : 'V'
// All permutations which start with 'I', 'E' would come before 'VIEW'.
// Number of such permutations = 3! * 2 = 12
// Lets now remove ‘V’ and look at the rank of the permutation ‘IEW’.
// Character 2 : ‘I’
// All permutations which start with ‘E’ will come before ‘IEW’
// Number of such permutation = 2! = 2.
// Now, we will limit ourself to the rank of ‘EW’.
// Character 3:
// ‘EW’ is the first permutation when the 2 permutations are arranged.
// So, we see that there are 12 + 2 = 14 permutations that would come before "VIEW".
// Hence, rank of permutation = 15.

#define MOD 1000003
#define lli long long int
int Solution::findRank(string A) {

    lli* fact = new lli[A.size()];
    fact[0]=1;
    for(int i=1;i<A.size();i++){
        fact[i] = (i*fact[i-1])%MOD;
    }
    
    lli ans=0; // 0 indexed
    for(int i=0;i<A.size();i++){
        int count=0; // count of characters smaller than A[i] in A[i+1.....n-1]
        for(int j=i+1;j<A.size();j++){
            if(A[j]<A[i]) {
                count++;
                count %=MOD;
            }
        }
        ans = (ans + (count*fact[A.size()-1-i]))%MOD; 
    }
    return (ans+1)%MOD; // return answer as 1 indexed
}

/***************************************************************************************************************************/

// Approach 3: O(n^2) Recursive

#define MOD 1000003
#define lli long long int

lli* fact;

int findRankRec(string A,int i){
    if(i==A.size()) return 0;
    int count=0; // count of characters smaller than A[i] in A[i+1.....n-1]
    for(int j=i+1;j<A.size();j++){
        if(A[j]<A[i]) {
            count++;
            count %=MOD;
        }
    }
    
    int smallAns = findRankRec(A,i+1);
    
    return ((count*fact[A.size()-1-i])%MOD + smallAns)%MOD;

}

int Solution::findRank(string A) {

    fact = new lli[A.size()];
    fact[0]=1;
    for(int i=1;i<A.size();i++){
        fact[i] = (i*fact[i-1])%MOD;
    }
    
    return (findRankRec(A,0)+1)%MOD; // want answer as 1 indexed

    
}

