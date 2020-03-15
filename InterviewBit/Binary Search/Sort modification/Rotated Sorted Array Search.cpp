// NOTE:- Array A was sorted in non-decreasing order before rotation.

// Approach 1: Linear search

/***************************************************************************************************************************/

// Approach 2: Binary search
// Note: If there are duplicates, making either decision might be difficult and hence linear search might be required.

int Solution::search(const vector<int> &A, int B) {

    int s=0,e=A.size()-1;
    
    while(s<=e){
        int mid=(s+e)/2;
        if(A[mid]==B) return mid;
        //Left Half(s->mid) is sorted
        if(A[s]<=A[mid]){
            if(A[s]<=B&&B<=A[mid]){
                e=mid-1;               
            }else{
                s=mid+1;
            }
        }
        //Right Half(mid->e) is sorted
        else{
            if(A[mid]<=B&&B<=A[e]){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        
    }
    
    return -1;
    
}
