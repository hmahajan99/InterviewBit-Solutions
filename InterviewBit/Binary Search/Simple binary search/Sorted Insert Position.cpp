// Given a sorted array and a target value, return the index if the target is found. 
// If not, return the index where it would be if it were inserted in order.

// Approach 1: Using STL lower_bound 

int Solution::searchInsert(vector<int> &A, int B) {
    return lower_bound(A.begin(),A.end(),B)-A.begin();
}

/***************************************************************************************************************************/

// Approach 2: Implementing lower_bound 

int lowerBound(vector<int> &A, int B){
    // returns first number >= B, or n if no such exists
    int n=A.size();
    int ans=n;
    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(A[mid]>=B){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans;
}

int Solution::searchInsert(vector<int> &A, int B) {
    return lowerBound(A,B);
}
