// Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of the ith histogram’s bar. 
// Width of each bar is 1. Find the area of largest rectangle in the histogram.

// Approach 1 : Brute force O(N^2) time complexity
// We can iterate on all the histograms, and for each histogram H, we try to create the maximum rectange with H as the height.
// To do that, we keep going left L and right R till we encounter a histogram with height less than H.
// Now, (R - L - 1) * H is one of the possibilities for the largest rectangle.
// Doing this for all the histograms will give us the right solution.

/***************************************************************************************************************************/

// Appoach 2 : Using stack
// Since every bar is pushed and popped only once time complexity is O(n), space complexity is O(n)

// For each histogram H, we need to know index of the first smaller (smaller than H) bar on left of H (lets call it L) and index of first smaller bar on right of H.
// When traversing left for L, we would want to look at the first histogram left of H[i] with height less than H[i]
// => When I traverse left, I only need entries in decreasing order.
// Every histogram is pushed to stack once. 
// A histogram is popped from stack when a histogram of smaller height is seen. 
// When a histogram is popped, we calculate the area with the popped histogram as smallest histogram. 
// How do we get left and right indexes of the popped histogram – the current index tells us the ‘right index’ R and index of previous item in stack is the ‘left index’ L


int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> s;
    int maxArea=INT_MIN;
    int i;
    for(i=0;i<A.size();){
        if(s.empty()||A[s.top()]<=A[i]){
            s.push(i);
            i++;
        }else{
            int h = A[s.top()];
            s.pop();
            if(s.empty()){
                maxArea=max(maxArea,h*i);
            }else{
                maxArea=max(maxArea,h*(i-s.top()-1));
            }            
        }
    }
    
    while(!s.empty()){
        int h = A[s.top()];
        s.pop();
        if(s.empty()){
            maxArea=max(maxArea,h*i);
        }else{
            maxArea=max(maxArea,h*(i-s.top()-1));
        }            
    }
   
    return maxArea;
    
}

// Better alternative : Append 0 height bar at end of input

int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> s;
    int maxArea=INT_MIN;
    A.push_back(0); // For remaining bars in the stack
    int i;
    for(i=0;i<A.size();){
        if(s.empty()||A[s.top()]<=A[i]){
            s.push(i);
            i++;
        }else{
            int h = A[s.top()];
            s.pop();
            if(s.empty()){
                maxArea=max(maxArea,h*i);
            }else{
                maxArea=max(maxArea,h*(i-s.top()-1));
            }            
        }
    }
    
    return maxArea;
    
}

/***************************************************************************************************************************/

// Approach 3 : TODO We can use Divide and Conquer to solve this in O(nLogn) time