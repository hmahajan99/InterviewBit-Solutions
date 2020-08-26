// Remove duplicates from Sorted Array
// Given a sorted array, remove the duplicates in place such that each element appears only once and return the new length.

// Notice that the array is sorted.
// This implies that all repetitions for an element are clustered together in the array.
// Try maintaining 2 pointers in the array: 
// One pointer iterates over the array and
// Other pointer only moves per occurrence of a value in the array.
// So, the second pointer only moves when A[i] != A[i+1]

int Solution::removeDuplicates(vector<int> &A) {

    if(A.size()==0) return 0;
    int prev=A[0];
    int i=0,j=1;
    while(j<A.size()){
        if(A[j]==prev){
            j++;
        }else{
            A[++i]=A[j];
            prev=A[j];
        }
    }
    return i+1;
    
}

// Alternative

int Solution::removeDuplicates(vector<int> &A) {

    if(A.size()==0) return 0;
    int i=0, n=A.size();
    for (int j=0;j<n;j++) { 
        if (j<n-1&&A[j]==A[j+1]) continue;
        else {
            A[i]=A[j];
            i++;
        }
    }
    return i;
    
}