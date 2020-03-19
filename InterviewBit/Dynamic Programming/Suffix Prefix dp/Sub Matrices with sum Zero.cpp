// Approach 1: O(n^4) solution
// Precompute prefix 2d array to get sum of sum matrix in O(1)
// dp[i][j] = Sum of all elements in submatrix (0,0) to (i,j)
// dp[i][j] = A[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]

// For rectangle with 1st & last point (i,j) & (k,l) resp
// Sum of all elements in submatrix = dp[k][l]-dp[i-1][l]-dp[k][j-1]+dp[i-1][j-1]

typedef vector<vector<int>> vvi;  // NOTE: typedef

vector<vector<int>> getPrefix(vvi &A){

    // IMP NOTE!!!!=> By passing vector as constructor. 
    // At the time of declaration of vector, passing an old initialized vector
    // , copies the elements of passed vector into the newly declared vector. 
    // They are deeply copied.

    vvi prefix(A);
    // prefix[i][j] = sum of elements of sub matrix (0,0) to (i,j)
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(i>0) prefix[i][j] += prefix[i-1][j];
            if(j>0) prefix[i][j] += prefix[i][j-1];
            if(i>0&&j>0) prefix[i][j] -= prefix[i-1][j-1];
        }
    }
    return prefix;
}

int getSubmatrixSum(int r1,int r2,int c1,int c2,const vvi &prefix){
    int ans = prefix[r2][c2];
    if(c1>0) ans-= prefix[r2][c1-1];
    if(r1>0) ans-= prefix[r1-1][c2];
    if(c1>0&&r1>0) ans+= prefix[r1-1][c1-1];
    return ans;
}

int Solution::solve(vector<vector<int> > &A) {

    int n=A.size();
    if(n==0) return 0;
    int m=A[0].size();
    if(m==0) return 0;
    // n*m

    vvi prefix = getPrefix(A);
    // O(n^4) soln
    int ans=0;    
    for(int r1=0;r1<n;r1++){
        for(int r2=r1;r2<n;r2++){
            for(int c1=0;c1<m;c1++){
                for(int c2=c1;c2<m;c2++){
                    if(getSubmatrixSum(r1,r2,c1,c2,prefix)==0) ans++;
                }
            }
        }
    }
    return ans;

}

/***************************************************************************************************************************/

// Approach 2: O(n^3) solution => Approach similar to when we have 1D array ARR and we want to find number of subarrays such that subarray sum is equal to 0
// Iterate over all pairs of rows. When fixing two rows r1 and r2, we can convert this to 1D version of the problem.
// When we have a 1D array ARR we want to find number of subarrays such that the sum of the elements in the subarray is equal to 0. 
// To do that lets iterate from left to right, say we are currently at i-th element. 
// If we have i-th prefix sum equal to sum(ARR[0..i]), then we want to find number of such j’s that sum(ARR[0..i]) = sum(ARR[0..j]). 
// That means that the subarray ARR[j + 1..i] will have zero sum. To efficiently count number of such j’s we can use a HashMap

// When we have two fixed rows r1, r2 and have calculated PRE, we can obtain ARR. 
// Note that we don’t really need to calculate each element of ARR, since we only need prefix sums of ARR, that is sum(ARR[0..i]) for each i. 
// The sum(ARR[0..i]) is equal to PRE[r2][i] - PRE[r1 - 1][i] (if r1 - 1 < 0 then omit second operand).  
// Being able to efficiently calculate sum(ARR[0..i]), let’s apply the 1D solution.

// The answer to the problem will be simply the sum of answers for all different pairs of rows.


typedef vector<vector<int>> vvi;  // NOTE: typedef

vector<vector<int>> getPrefix(vvi &A){

    // IMP NOTE!!!!=> By passing vector as constructor. 
    // At the time of declaration of vector, passing an old initialized vector
    // , copies the elements of passed vector into the newly declared vector. 
    // They are deeply copied.

    vvi prefix(A);
    // prefix[i][j] = sum of elements of sub matrix (0,0) to (i,j)
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(i>0) prefix[i][j] += prefix[i-1][j];
            if(j>0) prefix[i][j] += prefix[i][j-1];
            if(i>0&&j>0) prefix[i][j] -= prefix[i-1][j-1];
        }
    }
    return prefix;
}

int getSum(int r1,int r2,int i,const vvi &prefix){
    return prefix[r2][i] - ((r1==0)?(0):(prefix[r1-1][i]));
}

int Solution::solve(vector<vector<int> > &A) {

    int n=A.size();
    if(n==0) return 0;
    int m=A[0].size();
    if(m==0) return 0;
    // n*m

    vvi prefix = getPrefix(A);
   // O(n^3)
    int ans=0;
    for(int r1=0;r1<n;r1++){
        for(int r2=r1;r2<n;r2++){
            unordered_map<int,int> mp; // sum (r1,0) to (r2,i) -> freq of sum
            mp[0]=1;
            for(int i=0;i<m;i++){
                int cumSum = getSum(r1,r2,i,prefix); // sum (r1,0) to (r2,i)
                if(mp.count(cumSum)==1){
                    ans+=mp[cumSum];
                    mp[cumSum]++;
                }else{
                    mp[cumSum] = 1;
                }
            }
        }
    }
    return ans;

}
