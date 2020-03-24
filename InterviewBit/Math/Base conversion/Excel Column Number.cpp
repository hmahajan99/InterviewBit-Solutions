// A -> 1
// B -> 2
// C -> 3

// ...

// Z -> 26
// AA -> 27
// AB -> 28 

// Approach 1

int Solution::titleToNumber(string A) {
    if(A.size()==0) return 0;
    int ans=0;
    for(int i=A.size()-1,p=1;i>=0;i--,p*=26){
        ans += (A[i]-'A'+1)*p;
    }
    return ans;
}

/***************************************************************************************************************************/

// Approach 2

int Solution::titleToNumber(string A) {
    if(A.size()==0) return 0;
    int ans=0;
    for(int i=0;i<A.size();i++){
        ans = ans*26 + (A[i]-'A'+1);
    }
    return ans;
}
