// Bucket: Permutations

// Approach 1: Using next_permutation STL
vector<vector<int> > Solution::permute(vector<int> &A) {
    // Using next_permutation
    vector<vector<int>> ans;
    vector<int> v=A;
    do{
        ans.push_back(v);
        next_permutation(v.begin(),v.end());
    }while(v!=A);
    return ans;
}

/***************************************************************************************************************************/

// Approach 2: Backtracking

void generate(int i,vector<int> &A,vector<vector<int>> &ans){
    
    if(i==A.size()-1){
        ans.push_back(A);
        return;
    }
    
    for(int j=i;j<A.size();j++){
        swap(A[i],A[j]);
        generate(i+1,A,ans);
        swap(A[i],A[j]);
    }    
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> ans;
    if(A.size()==0) return ans;
    generate(0,A,ans);
    return ans;
}

// Note : The above solution prints duplicate permutations if there are repeating characters in input string
