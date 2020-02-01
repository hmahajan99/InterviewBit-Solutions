// Approach 1 : Brute force 
// A naive solution would be to take a nested loop, and for every element keep iterating back till we find a smaller element.
// This can be O(N^2) in worst case.

/***************************************************************************************************************************/

// Approach 2: Using stack

// Time complexity of above program is O(n) as every element is pushed and popped at most once to the stack. 
// So overall constant number of operations are performed per element.



// Look at A[i-1]. All elements with index smaller than i - 1 and greater than A[i-1] are useless to us because they would never qualify for G[i], G[i+1], ...
// We only need previous numbers in descending order

vector<int> Solution::prevSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> ans(n);
    stack<int> s; // Storing indexes in stack, as can always get back value from index (i.e A[index]) but not vice versa 
    for(int i=0;i<n;i++){
        while(!s.empty()&&A[s.top()]>=A[i]){
            s.pop();
        }
        ans[i] = (s.empty()?-1:A[s.top()]);
        s.push(i);
    }
    return ans;    
}
