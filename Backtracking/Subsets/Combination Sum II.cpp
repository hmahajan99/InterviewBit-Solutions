void findCombinations(vector<vector<int>>& ans,vector<int> &current,vector<int> &A, int B,int i,int currentSum){

    if(currentSum>B) return;
        
    if(currentSum==B){
        ans.push_back(current);
        return;
    }

    if(i==A.size()) return;
    
    // Exclude
    findCombinations(ans,current,A,B,i+1,currentSum);

    // Include
    current.push_back(A[i]);
    findCombinations(ans,current,A,B,i+1,currentSum+A[i]);
    current.pop_back();

}


vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {

    sort(A.begin(),A.end());
    vector<vector<int>> ans;
    vector<int> current;
    int i=0;
    findCombinations(ans,current,A,B,i,0);
    // Removing duplicate combinations
    vector<vector<int>> finalAns;
    vector<int> prev;
    for(vector<int> v:ans){
        if(v!=prev){
            finalAns.push_back(v);
            prev = v;
        }
    }
    return finalAns;
}

// Alterative : Can use hashmap to store count of how many times an element can be used in a valid combination to avoid duplicates