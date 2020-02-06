// Approach 1 : Brute force
// The obvious brute force solution with run time complexity of O(nw) is definitely not efficient enough. 
// Every time the window is moved, you have to search for a total of w elements in the window.

/***************************************************************************************************************************/

// Approach 2 : Using self balancing BST -> Time O(n lg w) 
// Using multiset in C++ STL

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    multiset<int> ms;
    vector<int> ans;
    
    for(int i=0;i<A.size();i++){
        ms.insert(A[i]);
        if(i>=B-1){
            ans.push_back(*ms.rbegin()); // Last element as want maximum
            ms.erase(ms.find(A[i-B+1]));
            // NOTE : ms.erase(value) XXXXX WRONG
            // ms.erase(value) removes all elements with key = value
            // ms.find(value) -> returns iterator
            // ms.erase(iterator) -> removes element at pos
            // So use ms.erase(ms.find(value)
        }
    }
    
    return ans;
    
}

/***************************************************************************************************************************/

// Approach 3 : Using deque
// Time complexity is O(n). This is because each element in the list is being inserted and then removed at most once. 
// Therefore, the total number of insert + delete operations is 2n.

// Deque stores only useful elements of current window of k elements

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    // Maintain q in sorted order such that largest is at front
    deque<int> q; // Store indexes in deque, as can always get back value from index (i.e A[index]) but not vice versa
    vector<int> ans;
    
    for(int i=0;i<B;i++){
        while(!q.empty()&&A[i]>=A[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
    }
    
    ans.push_back(A[q.front()]);
    for(int i=B;i<A.size();i++){
        
        // Eject from last
        while(!q.empty()&&A[i]>=A[q.back()]){
            q.pop_back();
        }
        
        // Out of range
        while(!q.empty()&&q.front()<=i-B){
            q.pop_front();
        }
        
        q.push_back(i);
        
        ans.push_back(A[q.front()]);
        
    }
    
    return ans;
    
}
