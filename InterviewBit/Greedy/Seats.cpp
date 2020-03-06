// Approach 1: Brute force
// Group all the k people together and form a window size of k. 
// Move the window and compare to the original positions, then count the hops and get minimum value. 
// Time complexity is O((n - k) * n), we can optimize to O((n - k) * k), n is the number of seats, and k is the number of people.

/***************************************************************************************************************************/

// Approach 2: Greedy, using Median O(n)
// string :  .x..x..x.
// positions where x are present {1, 4, 7}
// Median is 4. So we will move all x near our median. 1st person would need to jump 2 steps and 3rd person would also need to jump 2 steps. Total answer = 4. 

int Solution::seats(string A) {
    vector<int> v;
    for(int i=0;i<A.size();i++){
        if(A[i]=='x') v.push_back(i);
    }
    int ans=0;
    int mid = (v.size()-1)/2;
    for(int i=0;i<v.size();i++){
        int start = v[i];
        int dest = v[mid] + (i-mid);
        ans = ans + abs(start-dest);
        ans %= 10000003;
    }
    return ans;
}
