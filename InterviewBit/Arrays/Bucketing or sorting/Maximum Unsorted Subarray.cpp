// You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
// Find the MINIMUM sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
// If A is already sorted, output -1.
// Example :
// Input 1: A = [1, 3, 2, 4, 5] Return: [1, 2]
// Input 2: A = [1, 2, 3, 4, 5] Return: [-1]
// In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.

// Approach 1: O(n)

// If the input array is [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60], your program should be able to find that the subarray lies between the indexes 3 and 8.
// 1) Find the candidate unsorted subarray
// a) Scan from left to right and find the first element which is greater than the next element. Let s be the index of such an element. In the above example 1, s is 3 (index of 30).
// b) Scan from right to left and find the first element (first in right to left order) which is smaller than the next element (next in right to left order). Let e be the index of such an element. In the above example 1, e is 7 (index of 31).
// 2) Check whether sorting the candidate unsorted subarray makes the complete array sorted or not. If not, then include more elements in the subarray.
// a) Find the minimum and maximum values in arr[s..e]. Let minimum and maximum values be min and max. min and max for [30, 25, 40, 32, 31] are 25 and 40 respectively.
// b) Find the first element (if there is any) in arr[0..s-1] which is greater than min, change s to index of this element. There is no such element in above example 1.
// c) Find the last element (if there is any) in arr[e+1..n-1] which is smaller than max, change e to index of this element. In the above example 1, e is changed to 8 (index of 35)

vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    if(n<=1) return {-1};
    
    int s=-1,e=-1;
    
    for(int i=0;i<n-1;i++){
        if(A[i]>A[i+1]){
            s=i;
            break;
        }
    }
    
    for(int i=n-1;i>0;i--){
        if(A[i]<A[i-1]){
            e=i;
            break;
        }
    }
    
    if(s==-1&&e==-1) return {-1};
    
    int maximum=INT_MIN,minimum=INT_MAX;
    for(int i=s;i<=e;i++){
        maximum = max(maximum,A[i]);
        minimum = min(minimum,A[i]);
    }
    
    for(int i=0;i<=s;i++){
        if(A[i]>minimum){
            s = i;
            break;
        }
    }
    
    for(int i=n-1;i>=e;i--){
        if(A[i]<maximum){
            e = i;
            break;
        }
    }
    
    return {s,e};
}

// Alternatively, O(n)
// rifhtmost point(r) of the required subarray is the last point in the array which is less than some number to the left of it
// leftmost point(l) of the required subarray is the first point in the array which is greater than some number to the right of it

vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    if(n<=1) return {-1};
    
    int l=-1,r=-1;
    int mx=A[0];
    for(int i=1;i<n;i++){
        if(A[i]<mx) r=i;
        mx=max(mx,A[i]);
    }
    int mn=A[n-1];
    for(int i=n-2;i>=0;i--){
        if(A[i]>mn) l=i;
        mn=min(mn,A[i]);
    }
    
    if(l==-1||r==-1) return {-1};
    return {l,r};
    
}
