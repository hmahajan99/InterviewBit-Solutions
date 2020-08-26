// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
// Example : Input : [1, 10, 5]
// Output : 5 
// You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
// You may also assume that the difference will not overflow.

// Approach 1: Sorting O(nlogn)

int Solution::maximumGap(const vector<int> &A) {
    if(A.size()==1) return 0;
    vector<int> B(A);
    sort(B.begin(),B.end());
    int diff=INT_MIN;
    for(int i=0;i<B.size()-1;i++){
        diff=max(diff,B[i+1]-B[i]);
    }
    return diff;
}

/***************************************************************************************************************************/

// Approach 2: Time O(n) Space O(n)

// Also, you can use extra O(n) space.
// Try to think starting from maximum and minimum of array.
// How can you use the gap between them to separate elements into different blocks/buckets in such a way that you dont have to evaluate the answer for elements within buckets.

// Now, first try to think if you were already given the minimum value MIN and maximum value MAX in the array of size N, under what circumstances would the max gap be minimum and maximum ?
// Obviously, maximum gap will be maximum when all elements are either MIN or MAX making maxgap = MAX - MIN.
// Maximum gap will be minimum when all the elements are equally spaced apart between MIN and MAX. Lets say the spacing between them is gap.
// So, they are arranged as
// MIN, MIN + gap, MIN + 2*gap, MIN + 3*gap, ... MIN + (N-1)*gap 
// where MIN + (N-1)*gap = MAX 
// => gap = (MAX - MIN) / (N - 1). 
// So, we know now that our answer will lie in the range [gap, MAX - MIN].
// Now, if we know the answer is more than gap, what we do is create buckets of size gap for ranges
//   [MIN, MIN + gap), [Min + gap, MIN + 2* gap) ... and so on
// There will only be (N-1) such buckets. We place the numbers in these buckets based on their value.
// If you pick any 2 numbers from a single bucket, their difference will be less than gap, and hence they would never contribute to maxgap ( Remember maxgap >= gap ). We only need to store the largest number and the smallest number in each bucket, and we only look at the numbers across bucket.
// Now, we just need to go through the bucket sequentially ( they are already sorted by value ), and get the difference of min_value with max_value of previous bucket with at least one value. We take maximum of all such values.

int Solution::maximumGap(const vector<int> &num) {
    int n = num.size();
    if(n<2) return 0;
    int maxNum = *max_element(num.begin(), num.end());
    int minNum = *min_element(num.begin(), num.end());

    //average gap from minNum to maxNum.
    double gap=(maxNum-minNum)/(double)(n-1);
    if(gap==0) return 0; // Eg: nums = [10,10,10,10]

    // number of buckets = n
    // Eg: nums=[1,5,10] min=1 max=10 gap=4.5
    // Bucket 0 [1,5.5)  1,5
    // Bucket 1 [5.5,10)  -
    // Bucket 2 [10,14.5)  10      - Make seperate bucket for max element to simplify code
    vector<int> bucketsMin(n,INT_MAX);
    vector<int> bucketsMax(n,INT_MIN);

    //put into buckets
    for (int i=0;i<n;i++) {
        int buckInd = (num[i] - minNum) / gap;
        bucketsMin[buckInd] = min(bucketsMin[buckInd], num[i]);
        bucketsMax[buckInd] = max(bucketsMax[buckInd], num[i]);
    }
    
    int maxGap = INT_MIN;
    int previous = minNum;
    for (int i=0;i<n;i++) {
        if(bucketsMin[i]==INT_MAX && bucketsMax[i]==INT_MIN) continue; // Empty Bucket

        //i_th gap is minvalue in i+1_th bucket minus maxvalue in i_th bucket 
        maxGap = max(maxGap, bucketsMin[i] - previous);
        previous = bucketsMax[i];
    }

    return maxGap;
}