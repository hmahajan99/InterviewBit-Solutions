// It’s Tushar’s birthday today and he has N friends.
// Friends are numbered [0, 1, 2, ...., N-1] and ith friend have a positive strength B[i].
// Today being his birthday, his friends have planned to give him birthday bombs (kicks).
// Tushar's friends know Tushar's pain bearing limit and would hit accordingly.
// If Tushar’s resistance is denoted by A (>=0) then find the lexicographically smallest order of friends 
// to kick Tushar so that the cumulative kick strength (sum of the strengths of friends who kicks) doesn’t exceed his resistance capacity 
// and total no. of kicks hit are maximum.
// Also note that each friend can kick unlimited number of times (If a friend hits x times, his strength will be counted x times)
// Return the lexicographically smallest array of maximum length where the ith index represents the index of the friend who will hit.

// Input 1: A = 12 B = [3, 4]
// Output 1: [0, 0, 0, 0]
// Input 2: A = 11 B = [6, 8, 5, 4, 7]
// Output 2: [0, 2]

// Approach 1: Greedy works here

// Let the index of friend with minimum strength be F. (Take smallest index in case of a tie)
// It is obvious that –> Maximum no. of kicks = R/(S[F]).
// This is the length of the answer but since we need lexicographically smaller order (according to index), friends whose index is less than the F can also hit provided they do not change the length of the answer. 
// R = 11, S = [6, 8, 5, 4, 7]
// In this case:
// Max no. of kicks = 11/4 = 2.
// answer = [3,3] (if we do not consider the lexicographic order)
// But answer may be [0,3] or [0,2] or [2,3] as they also have the same length.
// Here, only required friends to consider are newS = [6,5,4] as we will rather choose friend with strength 6 than choosing a friend with strength 8

// Algorithm:
// Find the max no. of kicks (length of our answer).
// Make a new S vector which only takes the friends that can be in the answer.
// Iterate through the S vector formed above and see if the friend at consideration can be used instead of the friend with minimum strength.
// If he can be successfully used then use him instead of the friend with minimum strength to get a lexicographically smaller answer.

vector<int> Solution::solve(int R, vector<int> &S) {

    int mn = INT_MAX;
    unordered_map<int,int> index;
    for(int i=0;i<S.size();i++){
        if(!index.count(S[i])) index[S[i]]=i; // take smaller index when duplicates
        mn=min(mn,S[i]);
    }
    
    vector<int> newS;
    int currMin = INT_MAX;
    for(int i=0;i<=index[mn];i++){
        if(S[i]<currMin){
            newS.push_back(S[i]);
            currMin=S[i];
        }
    }
    
    int kicks = R/mn;
    int sum = kicks*mn;
    vector<int> ans;
    int count=0;
    for(int i=0;i<newS.size();i++){
        while(sum-mn+newS[i]<=R&&count<kicks){
            ans.push_back(index[newS[i]]);
            sum = sum-mn+newS[i];
            count++;
        }
    }
    return ans;
    
}

/***************************************************************************************************************************/

// Approach 2: DP, like unbounded knapsack plus back pointer to generate the indexes
// The lexicographic constraint is solved by using dp[r] < dp[r - p[i]] + 1 (i.e. use < instead of <=), 
// then for a specific resistance you save the index of the kick power that gives you the maximum number of kicks for that resistance

vector<int> Solution::solve(int R, vector<int> &S) {

	int n = S.size();
	vector<int> dp(R + 1, 0); // dp[r] = max kicks possible for r
	vector<int> back(R + 1); // back[r] = first index for r

	back[0] = 0;
	for (int r = 0; r <= R; r++) {
		for (int i = 0; i < n; i++) {
			if (r >= S[i] && dp[r] < dp[r - S[i]] + 1) {
				dp[r] = dp[r - S[i]] + 1;
				back[r] = i;
			}
		}
	}
	
	vector<int> ans;
	int r = R;
	while (r >= 0 && (r - S[back[r]]) >= 0) {
		ans.push_back(back[r]);
		r = r - S[back[r]];
	}
	return ans;
    
}