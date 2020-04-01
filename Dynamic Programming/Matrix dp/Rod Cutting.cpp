// There is a rod of length N lying on x-axis with its left end at x = 0 and right end at x = N. 
// Now, there are M weak points on this rod denoted by positive integer values(all less than N) A1, A2, …, AM. 
// You have to cut rod at all these weak points. You can perform these cuts in any order. 
// After a cut, rod gets divided into two smaller sub-rods. 
// Cost of making a cut is the length of the sub-rod in which you are making a cut.
// Your aim is to minimise this cost. Return an array denoting the sequence in which you will make cuts. If two different sequences of cuts give same cost, return the lexicographically smallest.

// IMP NOTE!!!=> HAVE TO RETURN SEQUENCE IN THIS QUES
// SO NEED TO KEEP A PARENT ARRAY ALSO TO REGENERATE SEQUENCE

// Approach 1: Top Down, Time complexity will be O(N^3).

// We rewrite our problem as given N cut points(and you cannot make first and last cut), decide order of these cuts to minimise the cost. 
// So, we insert 0 and N at beginning and end of vector B. 
// Now, we have solve our new problem with respect to this new array(say A).
// We define dp(i, j) as minimum cost for making cuts Ai, Ai+1, …, Aj. 
// Note that you are not making cuts Ai and Aj, but they decide the cost for us.
// For solving dp(i, j), we iterate k from i+1 to j-1, assuming that the first cut we make in this interval is Ak. 
// The total cost required(if we make first cut at Ak) is Aj - Ai + dp(i, k) + dp(k, j).


// For actually building the solution, after calculating dp(i, j), 
// we can store the index k which gave the minimum cost and then we can build the solution backwards.

#define ll long long

ll minCostCuts(int si,int ei,vector<int> &cuts,vector<vector<ll>> &dp,vector<vector<int>> &cutAt){

    if(ei==si+1) return 0;   
    
    if(dp[si][ei]!=-1) return dp[si][ei];
    
    ll minCost = LLONG_MAX;
    int minIndex=-1;
    for(int i=si+1;i<=ei-1;i++){
       ll cost = minCostCuts(si,i,cuts,dp,cutAt) + minCostCuts(i,ei,cuts,dp,cutAt);
       if(cost<minCost){
           minCost=cost;
           minIndex=i;
       }
    }
    cutAt[si][ei]=minIndex;
    return dp[si][ei]=(cuts[ei]-cuts[si])+(minCost);
    
}

void buildSequence(int si,int ei,vector<int> &ans,vector<int> &cuts,vector<vector<int>> &cutAt){
    if(ei==si+1) return;
    ans.push_back(cuts[cutAt[si][ei]]);
    buildSequence(si,cutAt[si][ei],ans,cuts,cutAt);
    buildSequence(cutAt[si][ei],ei,ans,cuts,cutAt);
}

vector<int> Solution::rodCut(int N, vector<int> &cuts) {
    
    sort(cuts.begin(),cuts.end());
    cuts.insert(cuts.begin(),0); // vector.insert(iterator,value)
    cuts.insert(cuts.end(),N);

    int n = cuts.size();
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
    vector<vector<int>> cutAt(n+1,vector<int>(n+1,-1)); // Like Parent array
    minCostCuts(0,n-1,cuts,dp,cutAt);

    vector<int> ans;
    buildSequence(0,n-1,ans,cuts,cutAt);    
    return ans;
    
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up

#define ll long long

void buildSequence(int si,int ei,vector<int> &ans,vector<int> &cuts,vector<vector<int>> &cutAt){
    if(ei==si+1) return;
    ans.push_back(cuts[cutAt[si][ei]]);
    buildSequence(si,cutAt[si][ei],ans,cuts,cutAt);
    buildSequence(cutAt[si][ei],ei,ans,cuts,cutAt);
}

vector<int> Solution::rodCut(int N, vector<int> &cuts) {
    
    sort(cuts.begin(),cuts.end());
    cuts.insert(cuts.begin(),0); // vector.insert(iterator,value)
    cuts.insert(cuts.end(),N);

    int n = cuts.size();
    vector<vector<ll>> dp(n,vector<ll>(n,0));
    vector<vector<int>> cutAt(n,vector<int>(n,-1)); // Like Parent array

    for(int len=2;len<=n;len++){
        for(int i=0;i+len-1<n;i++){
            int j=i+len-1;
            if(len==2) dp[i][i+1]=0; // Base case
            else{
                ll minCost = LLONG_MAX;
                int minIndex=-1;
                for(int k=i+1;k<=j-1;k++){
                   ll cost = dp[i][k] + dp[k][j];
                   if(cost<minCost){
                       minCost=cost;
                       minIndex=k;
                   }
                }
                cutAt[i][j]=minIndex;
                dp[i][j]=(cuts[j]-cuts[i])+(minCost);
            }
        }
    }


    vector<int> ans;
    buildSequence(0,n-1,ans,cuts,cutAt);    
    return ans;
    
}

