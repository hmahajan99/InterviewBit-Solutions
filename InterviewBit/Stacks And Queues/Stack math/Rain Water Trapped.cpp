// Approach 1 : Brute force
// A Simple Solution is to traverse every array element and find the highest bars on left and right sides. 
// Take the smaller of two heights. The difference between the smaller height and height of the current element is the amount of water that can be stored in this array element. 
// Time complexity of this solution is O(n^2).

/***************************************************************************************************************************/

// Approach 2 : PRECOMPUTE left highest and right highest building for each 
// Space - O(n)

int Solution::trap(const vector<int> &A) {
    int n = A.size();
    vector<int> left;
    vector<int> right(n);
    left.push_back(A[0]);
    right[n-1] = (A[n-1]);
    for(int i=1;i<n;i++){
        left.push_back(max(left[i-1],A[i]));
        right[n-i-1] = (max(right[n-i],A[n-i-1]));
    }
    
    int ans=0;
    for(int i=0;i<n;i++){
        ans += min(left[i],right[i])-A[i];
    }
    
    return ans;
}

/***************************************************************************************************************************/

// Approach 3 : 2 pointers approach
// Optimisation in approach 2, O(1) space complexity 
// Space Optimization in above solution: 
// Instead of maintaing two arrays of size n for storing left and right max of each element, we will just maintain two variables to store the maximum till that point. 
// Since water trapped at any element = min( max_left, max_right) – arr[i] we will calculate water trapped on smaller element out of A[lo] and A[hi] first and move the pointers till lo doesn’t cross hi.

// Fix the higher one and flow water from the lower part. 
// For example, if current height of left is lower, we fill water in the left bin. 
// Until left meets right, we filled the whole container.

int Solution::trap(const vector<int> &A) {
    int n = A.size();
    int ans=0;
    int leftMax=0,rightMax=0;
    int i=0,j=n-1;
    while(i<=j){
        if(A[i]<A[j]){
            leftMax=max(leftMax,A[i]);
            ans+=leftMax-A[i];
            i++;
        }else{
            rightMax=max(rightMax,A[j]);
            ans+=rightMax-A[j];
            j--;
        }
    }
    return ans;
}
