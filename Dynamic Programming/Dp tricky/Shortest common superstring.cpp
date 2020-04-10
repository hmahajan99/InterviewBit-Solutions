// Given a set of strings, A of length N.
// Return the length of smallest string which has all the strings in the set as substring.
// Constraints:
// 1 <= N <= 18
// 1 <= A[i] <= 100

// Input 1: A = ["aaaa", "aa"]
// Output 1: 4
// Explanation 1: Shortest string: "aaaa"

// Input 2: A = ["abcd", "cdef", "fgh", "de"]
// Output 2: 8
// Explanation 2: Shortest string: "abcdefgh"

// Approach: Brute Force
// Let’s say we have only two strings say s1 and s2, the possible cases are:
// 1) They do not overlap [ans = len(s1) + len(s2) ]
// 2) They overlap partially [ans = len(s1)+len(s2)-len(max. overlapping part)]
// 3) They overlap completely [ans = max(len(s1), len(s2)]
// What we can see here is we can easily combine two strings. In the brute force, we could take all the permutations of numbers [1 .. N], then combine the strings in that order.
// e.g: strings = [s1, s2, s3], order = [2,3,1]
// Steps are: [s1, s2,s3] –> [s2+s3, s1] –> [s1+s2+s3].
// (Here addition of strings is according to the method described above.
// This will give the optimal solution whatever the case may be. Considering all the permutations is optimal but time consuming.

/***************************************************************************************************************************/

// Approach: DP + BITMASKS

// IMP NOTE !!!!
// Use Bitmasks when you can represent the state of a state in the DP using bits. Like a set of elements. 
// This helps keep the representation concise, and allows us to perform operations like intersection and union equivalent binary operations like AND and OR

// There is a optimal substructure and overlapping subproblems in the brute force algorithm described above. 
// Example:
// Input = [s1, s2, s3, s4]
// Order 1 = [2,3,1,4] , Steps: [s2+s3, s1, s4] –> [s2+s3+s1, s4] –> [s1+s2+s3+s4]
// Order 2 = [1,3,2,4] , Steps: [s1+s3, s2, s4] –> [s1+s2+s3, s4] –> [s1+s2+s3+s4].
// Do you see here that Order1 and Order2 both calculated the optimal solution for set of strings [s1, s2, s3]
// (Intermediate string s1+s2+s3 is the optimal solution for this set)

// Bitmasking in DP
// Well, this kind of DP formulations require a specific technique called Bitmasking. 
// It is not the conventional type and in this case T(N) = CCNN + CN*(2^N) (Still better than O(N!) )

// Formulation:
// dp[i][mask] = Optimal solution for set of strings corresponding to 1’s in the mask where the last added string to our solution is i-th string.

// Recurrence:
// dp[i][mask] = min(dp[x][mask ^ (1«i)] where {mask | (1«x) = 1} )




//Global variables
int targetMask;
vector<vector<int>> nonOverlapLen;
vector<vector<int>> dp;

/*
This can be done faster using KMP algorithm and some preprocessing

Let's say s1 = words[a] and s1 = words[b].

If we append string s2 to the solution, then as string s1 is already
added, we would need to add only the characters of string words[b] that are
not overlapping with the solution.
lenToADD = len(s2)-len(suffix of s1 which is also a prefix of s2);

e.g.: s1 = "lara", s2 = "raghav"
      Now in the previous step, we added s1 to solution and let's say our solution
      at the time looks like "brilara" [made from strings "brila" and "lara"],
      if we add "raghav" to the solution, the only characters to be added are "ghav"
      and new solution = "brilaraghav"
*/
int combineString(vector<string> &words, int a, int b){
	
	//Only 1 string in the mask 
	if(a==-1) return words[b].size();
  	
  	//Check if already calculated the ans
	if(nonOverlapLen[a][b] != -1) return nonOverlapLen[a][b];
  	
	for(int i=0;i<words[a].size();i++){
		bool suffix = true;
		for(int j=0;j<words[b].size()&&i+j<words[a].size();j++){
			if(words[a][i+j] != words[b][j]){
			    suffix=false;
			    break;
			}
		}
		if(suffix){
			int overlap = words[a].size()-i;
			return nonOverlapLen[a][b] = words[b].size()-overlap;
		}
	}
	
	return nonOverlapLen[a][b] = words[b].size(); // No overlap
}

//Main function to find the optimal solution
int findOptimal(vector<string> &words, int pos, int mask){
	// mask --> Set of strings that are considered for the solution.
	// pos --> index of string that we added into the mask the last time
	// pos == -1 --> 1st string (=> store ans in dp[pos+1][mask])
	// dp[pos+1][mask] --> optimal answer for set of strings corresponding 
	// to mask(1's in mask) if pos is index of last added string in mask 
	
	if(mask == targetMask) return 0; // We considered all strings into the solution

 	if(dp[pos+1][mask]!=-1) return dp[pos+1][mask];
 	
	int ans = INT_MAX;
	
	for(int i=0;i<words.size();i++){
		// Check if i-th word is already considered or not
		if(((1<<i)&mask)==0){
		    // Add i-th word to mask
		    int smallAns = findOptimal(words,i,mask|(1<<i)) + combineString(words,pos,i);
			ans = min(ans,smallAns);
		}
	}
    
    return dp[pos+1][mask] = ans;

}

int Solution::solve(vector<string>& A){
	int n = A.size();
	
	// Check the strings which are completely overlapping with some other string
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i!=j && A[i].find(A[j]) != string::npos) A[j] = "";
		}
	}
	
	// Make a new vector of only the strings which are not completely overlapping with some other string
 	vector<string> newA;
 	for(int i=0; i<n; i++){
 		if(A[i] != "") newA.push_back(A[i]);
 	}
  
    int N = newA.size();
    nonOverlapLen = vector<vector<int>>(N,vector<int>(N,-1));
    dp = vector<vector<int>>(N+1,vector<int>((1<<N),-1));

	//Set the mask initially to all 0's
    int mask = 0;
	
	//Set the target mask
    targetMask = (1<<N)-1;
    
    // Find the length of optimal solution
    // pos = -1 initially (no last string currently)
    return findOptimal(newA, -1, mask);

}
