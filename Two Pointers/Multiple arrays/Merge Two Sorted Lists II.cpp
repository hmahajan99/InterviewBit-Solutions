// Given two sorted integer arrays A and B, merge B into A as one sorted array.
// If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n

// Approach 1: O(N) space

void Solution::merge(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    int i=0,j=0;
    while(i<A.size()&&j<B.size()){
        if(A[i]<B[j]) ans.push_back(A[i++]);
        else ans.push_back(B[j++]);
    }
    while(i<A.size()) ans.push_back(A[i++]);
    while(j<B.size()) ans.push_back(B[j++]);
    A=ans;
}

// Alternative, using single while loop
void Solution::merge(vector<int> &A, vector<int> &B) {
    vector<int> ans;
    int n = A.size(), m = B.size();
    int i=0,j=0;
    while(i<n||j<m){
        if(j==m||(i<n&&A[i]<B[j])) ans.push_back(A[i++]);
        else ans.push_back(B[j++]);
    }
    A=ans;
}

/***************************************************************************************************************************/

// Approach 2: O(1) space
// Resize A and begin from last indices => No overwriting

void Solution::merge(vector<int> &A, vector<int> &B) {
    int i = A.size()-1;
    int j = B.size()-1;
    int k = A.size()+B.size()-1;
    A.resize(A.size() + B.size()); // NOTE IMP!!!!=> vector.resize()
    while(k>=0){
        if(j<0||(i>=0&&A[i]>B[j])) A[k--]=A[i--];
        else A[k--]=B[j--];
    }
}