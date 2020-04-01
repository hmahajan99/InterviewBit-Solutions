// The problem can be simply broken down as two binary searches for the begining and end of the range, respectively.

// Approach 1: Using STL lower_bound & upper_bound

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // NOTE : Use CONST ITERATOR instead of ITERATOR
    vector<int>::const_iterator it1 = lower_bound(A.begin(),A.end(),B);
    if(*it1!=B) return {-1,-1};
    vector<int>::const_iterator it2 = upper_bound(A.begin(),A.end(),B);
    return {it1-A.begin(),it2-A.begin()-1};
}

/***************************************************************************************************************************/

// Approach 2: Implementing lower_bound & upper_bound

int lowerBound(const vector<int> &A, int B){
    int ans=-1;
    int n=A.size();
    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(A[mid]==B){
            ans=mid;
            e=mid-1;
        }else if(A[mid]>B){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans;
}

int upperBound(const vector<int> &A, int B){
    int ans=-1;
    int n=A.size();
    int s=0,e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(A[mid]==B){
            ans=mid;
            s=mid+1;
        }else if(A[mid]>B){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    return {lowerBound(A,B),upperBound(A,B)};
}
