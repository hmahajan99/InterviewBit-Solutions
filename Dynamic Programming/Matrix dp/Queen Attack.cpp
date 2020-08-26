// On a N * M chessboard, where rows are numbered from 1 to N and columns from 1 to M, there are queens at some cells. 
// Return a N * M array A, where A[i][j] is number of queens that can attack cell (i, j). 
// While calculating answer for cell (i, j), assume there is no queen at that cell.

// Let chessboard be,
// [0 1 0]
// [1 0 0]
// [0 0 1]
// We return matrix
// [3, 1, 2]
// [1, 3, 3]
// [2, 3, 0]

// Approach 1: Brute Force
// If you actually traverse in all 8 directions for each cell, total complexity in the worst case will be O(N*M*(N+M)).

/***************************************************************************************************************************/

// Approach 2: Bottom Up

vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    int n = A.size(), m = A[0].size();
    // n*m
    vector<int> l(n,INT_MAX),r(n,INT_MIN);
    vector<int> t(m,INT_MAX),b(m,INT_MIN);
    vector<int> tr(m+n-1,INT_MAX),bl(m+n-1,INT_MIN); // x+y => 0 -> m+n-2
    vector<int> tl(m+n-1,INT_MAX),br(m+n-1,INT_MIN); // x-y => -(m-1)-> (n-1)
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j]=='1'){
                l[i] = min(l[i],j);
                r[i] = max(r[i],j);
                t[j] = min(t[j],i);
                b[j] = max(b[j],i);
                tr[i+j] = min(tr[i+j],i);
                bl[i+j] = max(bl[i+j],i);
                tl[i-j+(m-1)] = min(tl[i-j+(m-1)],i);
                br[i-j+(m-1)] = max(br[i-j+(m-1)],i);
            }
        }
    }

    vector<vector<int>> ans(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[i][j] += (l[i]!=INT_MAX&&l[i]<j)?(1):0;
            ans[i][j] += (r[i]!=INT_MIN&&r[i]>j)?(1):0;
            ans[i][j] += (t[j]!=INT_MAX&&t[j]<i)?(1):0;
            ans[i][j] += (b[j]!=INT_MIN&&b[j]>i)?(1):0;
            ans[i][j] += (tr[i+j]!=INT_MAX&&tr[i+j]<i)?(1):0;
            ans[i][j] += (bl[i+j]!=INT_MIN&&bl[i+j]>i)?(1):0;
            ans[i][j] += (tl[i-j+(m-1)]!=INT_MAX&&tl[i-j+(m-1)]<i)?(1):0;
            ans[i][j] += (br[i-j+(m-1)]!=INT_MIN&&br[i-j+(m-1)]>i)?(1):0;
        }
    }
    
    return ans;
}

/***************************************************************************************************************************/

// Approach 3: Top Down

// We define f(i, j, k) as a number of queen attacks on the cell (i, j) from direction k. Eight directions can be given numbers 0 to 7.
// Now, to see how many attacks are there on a cell (i, j), we go to its neighbour in direction k(say n_i, n_j). If the cell (n_i, n_j) has a queen, then there is just 1 attack. Else, number of attacks is f(n_i, n_j, k).
// We just have to take the sum of f(i, j, k) for all k=0 to 7 to find the answer for the position (i, j).
// The total number of states is O(N*M*8) , so total complexity is O(N*M).

vector<vector<int> > dp[8];

// Direction vectors
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

bool isValid(int i,int j,int n,int m){
    if(i<0||i>=n||j<0||j>=m)return false;
    return true;
}

int f(int i, int j, int k, vector<string> &A){
    int n=A.size(), m=A[0].size();

    if(dp[k][i][j]!=-1) return dp[k][i][j];
    
    int queenAttackK=0;
    
    //new positions
    int i1=i+dx[k];
    int j1=j+dy[k];
    
    if(isValid(i1,j1,n,m)){
        if(A[i1][j1]=='1'||f(i1,j1,k,A)) queenAttackK=1;
    }
    
    return dp[k][i][j]=queenAttackK;
}

vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    // n*m
    int n=A.size(), m=A[0].size();
    for(int i=0;i<8;i++){
        dp[i].clear();
        dp[i].resize(n,vector<int>(m,-1)); // vector.resize()
    }

    vector<vector<int>> ans(n,vector<int>(m,0));
    for(int k=0;k<8;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans[i][j]+=f(i,j,k,A);
            
    return ans;
    
}

