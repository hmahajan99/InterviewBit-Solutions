// Approach 1: Brute Force, O(n^2)

/***************************************************************************************************************************/

// Approach 2: Hashmap
// Time O(n) ,Space O(n)

/***************************************************************************************************************************/

// Approach 3: 2 pointers in the beginning i.e i=0 & j=1
// Time O(n) ,Space O(1)
// Use the fact that the array is sorted

// Let us first look at why 2 pointer approach works here.
// A naive 2 loop approach would be:
// for (int i = 0; i < len; i++) {
//   for (int j = i + 1; j < len; j++) {
//     if (A[j] - A[i] > diff) break; // No need going forward as the difference is going to increase even further. 
//     if (A[j] - A[i] == diff) return true; 
//   }
// }

// So, j only keeps moving in forward direction and never needs to come back as i increases.

int Solution::diffPossible(vector<int> &A, int B) {

    sort(A.begin(),A.end());
    int j=1; // Initialize j outside i loop
    for(int i=0;i+1<A.size();i++){
        if(j==i) j=i+1;
        while(j<A.size()&&A[j]-A[i]<=B){
            if(A[j]-A[i]==B) return 1;
            j++;
        }
    }
    return 0;
   
}

// Alternative: Better

int Solution::diffPossible(vector<int> &A, int B) {

    sort(A.begin(),A.end());
    int i=0,j=1;

    while(i<A.size()&&j<A.size()){
        if(A[j]-A[i]==B) return 1;

        if(A[j]-A[i]<B){
            j++;
        }else{
            i++;
            if(i==j) j++;
        }
        
    }
    
    return 0;

}