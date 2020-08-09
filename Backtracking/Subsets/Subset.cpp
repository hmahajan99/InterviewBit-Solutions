// Given a set of distinct integers, S, return all possible subsets.
// Note:
// Elements in a subset must be in non-descending order.
// The solution set must not contain duplicate subsets.
// Also, the subsets should be sorted in ascending ( lexicographic ) order.
// The list is not necessarily sorted.

// Approach 1: Include and Exclude every element

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

vector<vector<int> > Solution::subsets(vector<int> &A) {

    sort(A.begin(),A.end());
    set<vector<int>> output; // Using set => Sorting the result vector
    vector<int> current;
    generate(0,A,current,output);
    
    // vector<vector<int>> ans;
    // for(auto it=output.begin();it!=output.end();it++){
    //     ans.push_back(*it);
    // }

    // Better way
    vector<vector<int>> ans(output.begin(),output.end());

    return ans;
    
}

/***************************************************************************************************************************/

// Approach 2 : Without sorting the result vector => USE DFS

void generateSubsetsDFS(int i,vector<int> &A,vector<int> &current,vector<vector<int>> &output){
    
    output.push_back(current);
    
    for(int j=i;j<A.size();j++){
        current.push_back(A[j]);
        generateSubsetsDFS(j+1,A,current,output);
        current.pop_back();
    }
    
}

vector<vector<int> > Solution::subsets(vector<int> &A) {

    // METHOD : Without sorting the result vector => USE DFS
    /*
         [] 
        / | \
       /  |  \
      1   2   3
    /  \   \
  1,2  1,3  \
   /        2,3
1,2,3
    */

    sort(A.begin(),A.end());
    vector<vector<int>> output;
    vector<int> current;
    generateSubsetsDFS(0,A,current,output);
    return output;
    
}

/***************************************************************************************************************************/

// Approach 3 : Generating subsets iteratively using bitmaks. (sorting the result vector)

vector<vector<int> > Solution::subsets(vector<int> &A) {

    sort(A.begin(),A.end());
    set<vector<int>> output;

    int range=(1<<A.size())-1;
    for(int i=0;i<=range;i++){
        vector<int> subset;
        int num=i,j=0;
        while(num){
            if(num&1) subset.push_back(A[j]);
            num>>=1;
            j++;
        }
       output.insert(subset); 
    }
    
    return vector<vector<int>>(output.begin(),output.end());
    
}
