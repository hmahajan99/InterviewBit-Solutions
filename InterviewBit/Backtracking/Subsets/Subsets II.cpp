// Given a collection of integers that might contain duplicates, S, return all possible subsets.

// Approach 1: Include and Exclude

void generate(int i,vector<int> &A,vector<int> &current,set<vector<int>> &output) {
    if(i==A.size()){
        output.insert(current);
        return;
    }
    
    // Exclude A[i]
    generate(i+1,A,current,output);

    // Include A[i]
    current.push_back(A[i]);
    generate(i+1,A,current,output);
    current.pop_back();    
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(),A.end());
    set<vector<int>> output;
    vector<int> current;
    generate(0,A,current,output);
    return vector<vector<int>>(output.begin(),output.end());
    
}

/***************************************************************************************************************************/

// Approach 2: Using DFS

void generateDFS(int i,vector<int> &A,vector<int> &current,set<vector<int>> &output){
    
    output.insert(current);
    for(int j=i;j<A.size();j++){
        current.push_back(A[j]);
        generateDFS(j+1,A,current,output);
        current.pop_back();
    }
    
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(),A.end());
    set<vector<int>> output;
    vector<int> current;
    generateDFS(0,A,current,output);
    return vector<vector<int>>(output.begin(),output.end());
    
}
