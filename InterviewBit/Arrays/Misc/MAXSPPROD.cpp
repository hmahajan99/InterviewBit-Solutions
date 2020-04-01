// You are given an array A containing N integers. 
// The special product of each ith integer in this array is defined as the product of the following:
// LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (i>j). 
// If multiple A[j]’s are present in multiple positions, the LeftSpecialValue is the maximum value of j.
// RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (j>i). 
// If multiple A[j]s are present in multiple positions, the RightSpecialValue is the minimum value of j.
// Write a program to find the maximum special product of any integer in the array.
// Input: You will receive array of integers as argument to function.
// Return: Maximum special product of any integer in the array modulo 1000000007.
// Note: If j does not exist, the LeftSpecialValue and RightSpecialValue are considered to be 0.

// Approach: O(n) using stack
// Ok, lets try to calculate LeftSpecialValue.
// Lets make a stack A.
// We will keep elements in strictly decreasing order in stack A.
// When processing the ith element remove all the elements from the stack which have value less than or equal to ith element.
// Now whatever element will remain at the top of index will give the index corresponding to LeftSpecialValue. If no element is at top then take it as 0.
// Push ith element in stack A now.
// You can see each element is pushed and popped for atmax one time. Hence the solution runs in O(n) time.
// Do the similar thing for RightSpecialValue.

int Solution::maxSpecialProduct(vector<int> &A) {
    int n = A.size();
    vector<int> lsv(n),rsv(n);
    
    // lsv[i] - closest prev greater element
    // We will keep elements in strictly decreasing order in stack s1
    // Traverse from start
    stack<int> s1; // Store indices in stack
    for(int i=0;i<n;i++){
        while(!s1.empty()){
            if(A[s1.top()]<=A[i]) s1.pop();
            else break;
        }
        lsv[i] = (s1.empty())?(0):(s1.top());
        s1.push(i);
    }
    

    // rsv[i] - closest next greater element
    // We will keep elements in strictly decreasing order in stack s2 also
    // Traverse from end
    stack<int> s2; // Store indices in stack
    for(int i=n-1;i>=0;i--){
        while(!s2.empty()){
            if(A[s2.top()]<=A[i]) s2.pop();
            else break;
        }
        rsv[i] = (s2.empty())?(0):(s2.top());
        s2.push(i);
    }
    
    long long max = LLONG_MIN;
    for(int i=0;i<n;i++){
        if((long long)lsv[i]*rsv[i]>max){
            max = (long long)lsv[i]*rsv[i];
        }
    }
    
    return max%((int)(1e9+7));

}