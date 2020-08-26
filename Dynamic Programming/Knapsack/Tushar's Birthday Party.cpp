// As it is Tushar’s Birthday on March 1st, he decided to throw a party to all his friends at TGI Fridays in Pune.
// Given are the eating capacity of each friend, filling capacity of each dish and cost of each dish. 
// A friend is satisfied if the sum of the filling capacity of dishes he ate is equal to his capacity. 
// Find the minimum cost such that all of Tushar’s friends are satisfied (reached their eating capacity).

// NOTE:
// 1) Each dish is supposed to be eaten by only one person. Sharing is not allowed.
// 2) Each friend can take any dish unlimited number of times.
// 3) There always exists a dish with filling capacity 1 so that a solution always exists.

// Input Format
// Friends : List of integers denoting eating capacity of friends separated by space.
// Capacity: List of integers denoting filling capacity of each type of dish.
// Cost :    List of integers denoting cost of each type of dish.

// Constraints:
// 1 <= Capacity of friend <= 1000
// 1 <= No. of friends <= 1000
// 1 <= No. of dishes <= 1000

// Input:
//     2 4 6
//     2 1 3
//     2 5 3
// Output: 14
// Explanation: First friend will take 1st and 2nd dish, second friend will take 2nd dish twice.  Thus, total cost = (5+3)+(3*2)= 14

// Approach 1: Top Down DP
// As the friends cannot share dishes, we can calculate the cost for each of them independently and add all such costs.
// Now, the problem instance for every friend is reduced to standard Unbounded KnapSack problem

vector<vector<int>> dp;

long minCost(int i,int totalCapacity,const vector<int> &capacity, const vector<int> &cost){
    int n = capacity.size();
    if(totalCapacity==0) return 0;
    if(i==n) return INT_MAX;

    if(dp[i][totalCapacity]!=-1)return dp[i][totalCapacity];
    
    long exc = minCost(i+1,totalCapacity,capacity,cost);

    long inc = INT_MAX;
    if(totalCapacity-capacity[i]>=0){
        inc = cost[i] + minCost(i,totalCapacity-capacity[i],capacity,cost);        
    } 
    
    return dp[i][totalCapacity]=min(exc,inc);

}

int Solution::solve(const vector<int> &friends, const vector<int> &capacity, const vector<int> &cost) {
    dp = vector<vector<int>>(capacity.size(),vector<int>(1001,-1));
    int totalMinConst=0;
    for(int i=0;i<friends.size();i++){
        totalMinConst+=minCost(0,friends[i],capacity,cost);
    }
    return totalMinConst;
}

/***************************************************************************************************************************/

// Approach 2: Bottom Up

int Solution::solve(const vector<int> &friends, const vector<int> &capacity, const vector<int> &cost) {
    int N = capacity.size();
    vector<vector<long>> dp = vector<vector<long>>(N+1,vector<long>(1001,-1));
    // dp[n][totalCapacity] = min. cost to satisfy a person with capacity totalCapacity using first n dishes i.e len(dishes)=n 
    for(int n=0;n<=N;n++){
        for(int totalCapacity=0;totalCapacity<=1000;totalCapacity++){
            if(totalCapacity==0) dp[n][totalCapacity]=0;
            else if(n==0) dp[n][totalCapacity] = INT_MAX;
            else {
                long exc = dp[n-1][totalCapacity];
            
                long inc = INT_MAX;
                if(totalCapacity-capacity[n-1]>=0){
                    inc = cost[n-1] + dp[n][totalCapacity-capacity[n-1]];        
                } 
                
                dp[n][totalCapacity] = min(inc,exc);
            }
        }
    }

    int totalMinConst=0;
    for(int i=0;i<friends.size();i++){
        totalMinConst+=dp[N][friends[i]];
    }
    return totalMinConst;
}
