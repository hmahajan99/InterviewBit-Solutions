// Approach 1: Brute force
// The naive solution will be to check prime factorization of every natural number incrementally till k numbers are found.

/***************************************************************************************************************************/

// Approach 2: Use set like a priority queue, Like modified BFS

vector<int> Solution::solve(int p1, int p2, int p3, int k) {

    // Using sets  (Use set like a pq)
    set<int> s = {p1,p2,p3};
    vector<int> ans;
    while(k--){
        int val = *s.begin();
        ans.push_back(val);
        s.erase(s.begin());
        s.insert(val*p1);
        s.insert(val*p2);
        s.insert(val*p3);
    }
    return ans;

    
}