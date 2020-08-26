// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
// Note: Using library sort function is not allowed.
// Example : Input : [0 1 2 0 1 2]
// Modify array so that it becomes : [0 0 1 1 2 2]

// Approach 1: 2 pass

void Solution::sortColors(vector<int> &A) {

    int count0=0,count1=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==0) count0++;
        else if(A[i]==1) count1++;
    }
    
    int i=0;
    while(count0--) A[i++]=0;
    while(count1--) A[i++]=1;
    while(i<A.size()) A[i++]=2;

}

/***************************************************************************************************************************/

// Approach 2: 1 pass using 3 pointers
// Swap the 0s to the start of the array maintaining a pointer, and 2s to the end of the array. 1s will automatically be in their right position
// The problem was posed with three colours, here `0′, `1′ and `2′. The array is divided into four sections:
// 1. a[0..Lo-1] => zeroes 
// 2. a[Lo..Mid-1] => ones 
// 3. a[Mid..Hi] => unknown
// 4. a[Hi+1..N-1] => twos 
// The unknown region is shrunk while maintaining these conditions
// Lo := 0; Mid := 0; Hi := N-1;
// while Mid <= Hi do
//   Invariant: a[0..Lo-1]=0 and a[Lo..Mid-1]=1 and a[Hi+1..N]=2; a[Mid..Hi] are unknown.
//   case a[Mid] in
//     0: swap a[Lo] and a[Mid]; Lo++; Mid++
//     1: Mid++
//     2: swap a[Mid] and a[Hi]; Hi–

void Solution::sortColors(vector<int> &A) {
    int n=A.size();

    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(A[mid]==0){
            swap(A[low],A[mid]);
            low++;
            mid++;
        }else if(A[mid]==1){
            mid++;
        }else if(A[mid]==2){
            swap(A[mid],A[high]);
            high--;
        }
    }

}
