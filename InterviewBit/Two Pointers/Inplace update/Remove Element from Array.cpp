// Maintain 2 pointers in the array:
// One pointer iterates over the array
// Other pointer only moves when it finds an element different from ‘elem’.
// In other words, the second pointer only moves when the first pointer is on an element worth keeping in the final array.

int Solution::removeElement(vector<int> &A, int B) {
    int i,j;
    for(i=0,j=0;j<A.size();j++){
        if(A[j]!=B) {
            A[i++]=A[j];
        }
    }
    // A.erase(A.begin()+i,A.end());
    return i;
}
