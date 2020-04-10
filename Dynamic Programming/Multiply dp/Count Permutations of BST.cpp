// You are given two positive integers A and B. 
// For all permutations of [1, 2, …, A], we create a BST. 
// Count how many of these have height B.

// Notes:
// 1) Values of a permutation are sequentially inserted into the BST by general rules i.e in increasing order of indices.
// 2) Height of BST is maximum number of edges between root and a leaf.
// 3) Return answer modulo 109 + 7.

// For example, A = 3, B = 1
// Two permutations [2, 1, 3] and [2, 3, 1] generate a BST of height 1.
// In both cases the BST formed is

//     2
//    / \
//   1   3  

// Another example, A = 3, B = 2 Return 4.

// Approach 1: Top Down DP, O(N^4)

// BST follows the property that all values in left subtree and less than value at current node and all values in right subtree are greater than current node.
// If we fix the root node, the BST formed will be unique.

// Also, the actual values that are being inserted in BST don’t matter. So, we can directly deal with number of values being inserted in BST instead of the actual values. This helps in defining states of DP.

// Now, what should be the states of DP? Of course, number of elements is one state. Other can be the height required.

// So, we define DP(N, M) as the number of permutations of N elements which when inserted into BSTs generate BSTs of height exactly M.

// Now, to define a recurrence, we’ll iterate over the root of BST we choose. We have N options and based on each option, the size of left and right subtrees are defined.

// If i’th element is choosen as root, the left subtree will now contain (i - 1) elements and right subtree will contain (N - i) elements.
// Now, at least one of these subtrees must have a height of (M - 1) because we are right now solving for height M.
// Again, we’ll iterate over the heights of left and right subtrees.

// Now, number of permutations to form left subtree of size x with some height are say, X. Also, we call these permutations set A.
// And similarly, number of permutations to form right subtree of size y with some height are say, Y. And we call these permutations set B.
// Now, we can choose any permutation from A and any permutation from B, to form a unique tree. So, there are total of X*Y permutations. Also, any sequence of size (x+y) can give the same BST if the mutual ordering of the permutation from set A and permutation of set B is maintained. There are choose(x + y, y) ways to do that. So, total ways are X*Y*choose(x + y, y).

#define lli long long int
#define M (int)(1e9+7)

vector<vector<lli>> dp;
int **nCr;

int **precomputeNCR(int N){
    int **nCr;
    nCr = new int*[N+1];
    for(int n=0;n<=N;n++){
        nCr[n] = new int[n+1];
        for(int r=0;r<=n;r++){
            if(r==0||r==n) nCr[n][r] = 1;
            else nCr[n][r] = ((long long)nCr[n-1][r]+nCr[n-1][r-1])%M; 
        }
    }
    return nCr;
}


lli countPermutationsBST(int N,int H){

    if(N<=1) return H==0;
    
    if(H==0) return N<=1;

    if(dp[N][H]!=-1) return dp[N][H];
    
    lli ans=0;
    for(int root=1;root<=N;root++){
        int left = root-1;
        int right = N-root;
        lli smallAns=0;
        for(int h=0;h<=H-2;h++){
            smallAns+=countPermutationsBST(left,H-1)*countPermutationsBST(right,h);
            smallAns%=M;
        }
        for(int h=0;h<=H-2;h++){
            smallAns+=countPermutationsBST(left,h)*countPermutationsBST(right,H-1);
            smallAns%=M;
        }
        smallAns+=countPermutationsBST(left,H-1)*countPermutationsBST(right,H-1);
        smallAns%=M;
        
        ans+=nCr[left+right][left]*smallAns;
        ans%=M;
    }
    
    return dp[N][H]=ans;    
    
}

int Solution::cntPermBST(int N, int H) {
    nCr = precomputeNCR(N);
    dp = vector<vector<lli>>(N+1,vector<lli>(H+1,-1));
    return countPermutationsBST(N,H);
}


/***************************************************************************************************************************/

// Approach 2: Bottom Up DP 

#define lli long long int
#define M (int)(1e9+7)

int **precomputeNCR(int N){
    int **nCr;
    nCr = new int*[N+1];
    for(int n=0;n<=N;n++){
        nCr[n] = new int[n+1];
        for(int r=0;r<=n;r++){
            if(r==0||r==n) nCr[n][r] = 1;
            else nCr[n][r] = ((long long)nCr[n-1][r]+nCr[n-1][r-1])%M; 
        }
    }
    return nCr;
}

int Solution::cntPermBST(int N, int H) {
    int **nCr = precomputeNCR(N);
    vector<vector<lli>> dp = vector<vector<lli>>(N+1,vector<lli>(H+1,-1));

    for(int n=0;n<=N;n++){
        for(int h=0;h<=H;h++){
            if(n<=1) dp[n][h] = h==0;
            else if(h==0) dp[n][h] = n<=1;
            // else if(n<h) dp[n][h] = 0;
            else{
                lli ans=0;
                for(int root=1;root<=n;root++){
                    int left = root-1;
                    int right = n-root;
                    lli smallAns=0;
                    for(int rh=0;rh<=h-2;rh++){
                        smallAns+=dp[left][h-1]*dp[right][rh];
                        smallAns%=M;
                    }
                    for(int lh=0;lh<=h-2;lh++){
                        smallAns+=dp[left][lh]*dp[right][h-1];
                        smallAns%=M;
                    }
                    smallAns+=dp[left][h-1]*dp[right][h-1];
                    smallAns%=M;
                    
                    ans+=nCr[left+right][left]*smallAns;
                    ans%=M;
                }
                dp[n][h]=ans;
            }
        }
    }
    
    return dp[N][H];
}
