// Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
// The same repeated number may be chosen from C unlimited number of times.

void findCombinations(vector<vector<int>>& ans,vector<int> &current,vector<int> &A, int reqSum,int i,int currSum){

    if(currSum>reqSum) return;
    
    if(currSum==reqSum){
        ans.push_back(current);
        return;
    }
    
    if(i==A.size()) return;

    // Include
    current.push_back(A[i]);
    // i not i+1, as the same repeated number may be chosen unlimited number of times
    findCombinations(ans,current,A,reqSum,i,currSum+A[i]);
    current.pop_back();

    // Dont Include
    findCombinations(ans,current,A,reqSum,i+1,currSum);

}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {

    // NOTE: All numbers (including target) will be positive integers.
    vector<vector<int>> ans;
    vector<int> current;
    sort(A.begin(),A.end());

    vector<int> uniqueCandidates;
    // Since Duplicates in the Candidate Set
    for (int i=0;i<A.size();i++) {
        if(i==0||A[i]!=A[i-1]) uniqueCandidates.push_back(A[i]);
    }    

    findCombinations(ans,current,uniqueCandidates,B,0,0);    
    return ans;
    
}