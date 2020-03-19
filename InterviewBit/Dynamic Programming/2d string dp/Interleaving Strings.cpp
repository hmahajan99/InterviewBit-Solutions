// Given A, B, C, find whether C is formed by the interleaving of A and B.

// Input 1:
//     A = "aabcc"
//     B = "dbbca"
//     C = "aadbbcbcac"

// Output 1:
//     1
    
// Explanation 1:
//     "aa" (from A) + "dbbc" (from B) + "bc" (from A) + "a" (from B) + "c" (from A)

// Approach 1: Recursive Solution

bool isPossible(string &A, string &B, string &C,int a,int b,int c){
    
    if(c==C.size()) return true;
    
    if(a<A.size()&&C[c]==A[a]&&isPossible(A,B,C,a+1,b,c+1)) return true;
    if(b<B.size()&&C[c]==B[b]&&isPossible(A,B,C,a,b+1,c+1)) return true;
    return false;
    
}

int Solution::isInterleave(string A, string B, string C) {
    if(C.size()!=A.size()+B.size()) return false;
    return isPossible(A,B,C,0,0,0);
}

/***************************************************************************************************************************/

// Approach 2: Top Down DP with 3 states

int dp[160][160][160];

bool isPossible(string &A, string &B, string &C,int a,int b,int c){

    if(c==C.size()) return true;
    
    if(dp[a][b][c]!=-1) return dp[a][b][c];

    if(a<A.size()&&C[c]==A[a]&&isPossible(A,B,C,a+1,b,c+1)) return dp[a][b][c]=true;
    if(b<B.size()&&C[c]==B[b]&&isPossible(A,B,C,a,b+1,c+1)) return dp[a][b][c]=true;
    return dp[a][b][c]=false;
    
}

int Solution::isInterleave(string A, string B, string C) {
    if(C.size()!=A.size()+B.size()) return false;
    for(int i=0;i<=A.size();i++){
        for(int j=0;j<=B.size();j++){
            for(int k=0;k<=C.size();k++){
                dp[i][j][k]=-1;
            }
        }
    }
    return isPossible(A,B,C,0,0,0);
}

/***************************************************************************************************************************/

// Approach 3: Top Down DP with 2 states
// Can eliminate one of the state i.e "c"

int dp[160][160];

bool isPossible(string &A, string &B, string &C,int a,int b){

    int c=a+b;
    
    if(c==C.size()) return true;
    
    if(dp[a][b]!=-1) return dp[a][b];

    if(a<A.size()&&C[c]==A[a]&&isPossible(A,B,C,a+1,b)) return dp[a][b]=true;
    if(b<B.size()&&C[c]==B[b]&&isPossible(A,B,C,a,b+1)) return dp[a][b]=true;
    return dp[a][b]=false;
    
}

int Solution::isInterleave(string A, string B, string C) {
    if(C.size()!=A.size()+B.size()) return false;
    for(int i=0;i<=A.size();i++){
        for(int j=0;j<=B.size();j++){
            dp[i][j]=-1;
        }
    }
    return isPossible(A,B,C,0,0);
}

/***************************************************************************************************************************/

// Approach 4: Bottom Up DP

int Solution::isInterleave(string A, string B, string C) {
    if(C.size()!=A.size()+B.size()) return false;

    bool dp[160][160];
    // dp[i][j] = answer when len(A)=i & len(B)=j & len(C)=i+j i.e A[0...i-1] & B[0...j-1]

    for(int i=0;i<=A.size();i++){
        for(int j=0;j<=B.size();j++){
            if(i==0) dp[0][j] = B.substr(0,j) == C.substr(0,j);
            else if(j==0) dp[i][0] = A.substr(0,i) == C.substr(0,i);
            else {
                if(A[i-1]==C[i+j-1]&&dp[i-1][j]) dp[i][j]=true;
                else if(B[j-1]==C[i+j-1]&&dp[i][j-1]) dp[i][j]=true;
                else dp[i][j]=false;
            }
        }
    }
    return dp[A.size()][B.size()];
}