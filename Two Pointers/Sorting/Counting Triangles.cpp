// You are given an array of N non-negative integers, A0, A1 ,…, AN-1.
// Considering each array element Ai as the edge length of some line segment, 
// count the number of triangles which you can form using these array values.
// You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. 

// Approach 1: Brute Force, O(n^3)

/***************************************************************************************************************************/

// Approach 2: O(n^2) , Fix i and 2 pointers from beginning
// Loop on i. For each i, use two pointers j(=i+1) & k(=i+2), i.e dont run another loop for k but reuse the variable
// Thus for every i and j, we can find the maximum value of k such that the triangle inequality holds.

int Solution::nTriang(vector<int> &A) {
    sort(A.begin(),A.end());
    long long count=0;
    for(int i=0;i<A.size()-2;i++){
        int k=i+2; 
        for(int j=i+1;j<A.size()-1;j++){
            while(k<A.size()&&A[i]+A[j]>A[k]) k++;
            count+=k-j-1;
            count%=(int)(1e9+7);
        }
    }
    return count;
}

// Alternative: Better

int Solution::nTriang(vector<int> &A) {
    sort(A.begin(),A.end());
    long long count=0;
    for(int i=0;i<A.size();i++){
        int j=i+1,k=i+2; // Initialize k outside j loop
        while(j<A.size()){
            if(k==A.size()||A[i]+A[j]<=A[k]){
                count+=k-j-1;
                count%=(int)(1e9+7);
                j++;
                if(j==k&&k<A.size()) k++;
            }else{
                k++;
            }
        }
    }
    return count;
}
