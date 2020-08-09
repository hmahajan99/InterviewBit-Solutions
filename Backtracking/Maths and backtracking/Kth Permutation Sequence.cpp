// The set [1,2,3,…,n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3 ) :
// 1. "123"
// 2. "132"
// 3. "213"
// 4. "231"
// 5. "312"
// 6. "321"
// Given n and k, return the kth permutation sequence.
// For example, given n = 3, k = 4, ans = "231"

// Approach 1: Using next_permutation STL (Can also implement next_permutation from scratch)
// Time complexity is O(n * n!)

string Solution::getPermutation(int n, int k) {
    
    vector<int> v;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    
    k--;
    
    int factN=1;
    for(int i=2;i<=n;i++){
        factN = factN*i;
        if(factN>k) {
            factN = k+1;
            break;
        } 
    }
    
    k = k % factN;
    
    for(int i=1;i<=k;i++){
        next_permutation(v.begin(),v.end());
    }
    
    string ans="";
    for(int n:v) ans += to_string(n);
    
    return ans;
}

/***************************************************************************************************************************/

// Wrong Approach
// Traversing permutations in this order is not correct as this is not lexicographical ordering
// for 123 we get (see by drawing tree)
// 123 132 213 231 XX321XX 312

bool findKthPermutation(vector<int> &v,int i,int &count,int k){
    if(i==v.size()-1){
        if(count==k){
            return true;  
        } 
        count++;
        return false;
    }
    
    for(int j=i;j<v.size();j++){
        swap(v[i],v[j]);
        if(findKthPermutation(v,i+1,count,k)) return true;  
        swap(v[i],v[j]);
    }    
    
    return false;
}

string Solution::getPermutation(int n, int k) {
    
    vector<int> v;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    
    k--;

    int factN=1;
    for(int i=2;i<=n;i++){
        factN = factN*i;
        if(factN>k) {
            factN = k+1;
            break;
        } 
    }
    
    k = k % factN;
    
    int count=0;
    findKthPermutation(v,0,count,k);

    string ans="";
    for(int n:v) ans += to_string(n);
    
    return ans;

}

/***************************************************************************************************************************/

// Approach 2: Using recursion
// Lets first make k 0 based.
// Let us first look at what our first number should be.
// Number of sequences possible with 1 in first position : (n-1)!
// Number of sequences possible with 2 in first position : (n-1)!
// Number of sequences possible with 3 in first position : (n-1)!
// Hence, the number at our first position should be k / (n-1)! + 1 th integer.
// Can we reduce the k and modify the set we pick our numbers from ( initially 1 2 3 … n ) to call the function for second position onwards ?

// Can also precompute factorials
int fact(int n){
    if(n>12) return INT_MAX; // IMP, to avoid overflow
    if(n==0) return 1;
    return n*fact(n-1);
}

string answer(int k, vector<int> &v){
    int n=v.size();
    if(n==0) return "";
    int f=fact(n-1);
    int pos=k/f;
    k%=f;
    string s=to_string(v[pos]);
    v.erase(v.begin()+pos); // vector.erase
    return s+answer(k,v);
}

string Solution::getPermutation(int n, int k) {
    vector<int> v;
    for(int i=1;i<=n;i++) v.push_back(i);
    k--; // Converting to 0 based indexing
    return answer(k,v);
}
