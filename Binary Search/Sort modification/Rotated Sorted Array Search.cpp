// Given an array of integers A of size N and an integer B.
// Array A is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).
// You are given a target value B to search. If found in the array, return its index, otherwise return -1.
// You may assume no duplicate exists in the array.
// NOTE:- Array A was sorted in non-decreasing order before rotation.

// Note: If there are duplicates, making either decision might be difficult and hence linear search might be required.
//                mid
//                 |
// 1 1 1 1 2 0 1 1 1 1 1 1 1 1 1 1 1 
// arr[mid] = arr[end]
// Indecisive. We would need to explore the whole array.

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
