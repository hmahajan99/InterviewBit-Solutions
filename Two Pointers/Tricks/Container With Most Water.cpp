// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
// 'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
// Find two lines, which together with x-axis forms a container, such that the container contains the most water.
// Your program should return an integer which corresponds to the maximum area of water that can be contained 
// Note: You may not slant the container. 

// Example : Input : [1, 5, 4, 3]
// Output : 6
// Explanation : 5 and 3 are distance 2 apart. So size of the base = 2. Height of container = min(5, 3) = 3. 
// So total area = 3 * 2 = 6

// Approach : 2 pointers
// Area will be basically min(ai,aj)*(j-i) where j>i.
// Note 1: When you consider a1 and aN, then the area is (N-1) * min(a1, aN).
// Note 2: The base (N-1) is the maximum possible.
// This implies that if there was a better solution possible, it will definitely have height greater than min(a1, aN).
// This means that we can discard min(a1, aN) from our set and look to solve this problem again from the start.
// If a1 < aN, then the problem reduces to solving the same thing for a2, aN.
// Else, it reduces to solving the same thing for a1, aN-1

int Solution::maxArea(vector<int> &A) {
    int n = A.size();
    int ans=0;
    int i=0,j=n-1;
    while(i<j){
        int area = (j-i)*(min(A[i],A[j]));
        ans = max(ans,area);
        if(A[i]<A[j]) i++;
        else j--;
    }
    return ans;    
}
