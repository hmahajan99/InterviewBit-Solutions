// Note: Make sure the combinations are sorted.

// Approach 1: Backtracking

void generate(vector<vector<int>> &ans,vector<int> &current,int i,int n,int k){

    if(current.size()==k){
        ans.push_back(current);
        return;
    }
    
    if(i==n+1) return;

    current.push_back(i);
    generate(ans,current,i+1,n,k);
    current.pop_back();    

    generate(ans,current,i+1,n,k);

}

vector<vector<int> > Solution::combine(int n, int k) {

    vector<vector<int>> ans;
    vector<int> current;
    if(k>n) return ans;
    generate(ans,current,1,n,k);
    return ans;
}

/***************************************************************************************************************************/

// Approach 2: Iterative, sorting the result vector(using set)

int countSetBits(int num){
    int count=0;
    while(num){
        count++;
        num=num&(num-1);
    }
    return count;
}


vector<vector<int> > Solution::combine(int n, int k) {

    set<vector<int>> output;
    vector<int> current;
    if(k>n) return vector<vector<int>>();

    int range=(1<<n)-1;
    for(int i=0;i<=range;i++){
        if(countSetBits(i)!=k) continue;
        vector<int> subset;
        int num=i,j=1;
        while(num){
            if(num&1) subset.push_back(j);
            num>>=1;
            j++;
        }
       output.insert(subset); 
    }

    return vector<vector<int>>(output.begin(),output.end());
}