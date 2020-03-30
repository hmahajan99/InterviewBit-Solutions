// Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].
// If there is no solution possible, return -1.
// Example : A : [3 5 4 2]
// Output : 2  for the pair (3, 4)

// Approach 1: Sorting, O(nlogn)
// While sorting the array we must also store the original index of the values instead of blindly sorting it.
// We are looking for all values of A[j] which are bigger than A[i].
// Since the array is sorted, the values will be all the elements to the right of A[i].
// Since we want to maximize index[j] - index[i], and index[i] is fixed, we are essentially looking at max index[j] for all j > i.
// The problem concludes to finding the max in all the suffix of the array.
// We can preprocess the index array and let indexMax[i] store the maximum of index[i….len]
// This is how we can calculate max of all the suffix in O(n) :

//        int maxIndex = INT_MIN; // -Infinity
//            for (int i = len - 1; i >= 0; i--) {
//             maxIndex = max(maxIndex, index[i]);
//             indexMax[i] = maxIndex;
//         }

int Solution::maximumGap(const vector<int> &A) {

    int n = A.size();

    if(n==0) return -1;
    
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back({A[i],i});
    }
    
    // Sorting the array, but need original order also
    sort(v.begin(),v.end());
    vector<int> maxIndex(n); // maxIndex[i] => max j for A[i] 
    maxIndex[n-1] = v[n-1].second;
    int ans=0;

    // Traversing over sorted array from end
    // OR 
    // TRAVERSING THE ORIGINAL ARRAY STARTING WITH THE LARGEST ELEMENT TO THE SMALLEST
    for(int i=n-2;i>=0;i--){
        maxIndex[i]=max(v[i].second,maxIndex[i+1]); // Could use a single variable for maxIndex also
        ans = max(ans,maxIndex[i]-v[i].second);
    }
    return ans;
    
}

/***************************************************************************************************************************/

// Approach 2: O(n) using sliding window
// Maintain sliding window using 2 pointers i(=0) & j(=0)
// If there exits an element with value >= A[i] to the right of j , Expand window i.e j++
// Else shrink window i.e i++
// To see if element with value >= A[i] to the right of j, create an auxiliary array RMax
// RMax[j] holds the greatest element on right side of arr[j] including arr[j]

int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    if(n==0) return -1;
    vector<int> RMax(n);
    RMax[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--) RMax[i]=max(A[i],RMax[i+1]);
    int i=0,j=0;
    int ans=-1;
    while(i<n&&j<n){
        if(A[i]<=RMax[j]){
            ans=max(ans,j-i);
            j++;    
        }
        else i++;
    }
    return ans;
}