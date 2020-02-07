// Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
// Note: The solution set must not contain duplicate quadruplets.

// Approach 1: Brute force
// Time - O(n^4)
// The naive approach obviously is exploring all combinations of 4 integers using 4 loops.

/***************************************************************************************************************************/

// IMP NOTE !!!=> array.size() is unsigned int
// Getting a Time Limit exceeded or Output Limit exceeded ?
// Make sure you handle case of empty input []. 
// In C++/C, Usually if you run a loop till array.size() - 2, it can lead to the program running indefinitely as 
// array.size() is unsigned int, and the subtraction just makes it wrap over to a big integer.

// Approach 2: Fix first 2, and use 2Sum approach(2 pointer approach/Meet in the middle) for other 2
// Time - O(n^3)
// When the array is sorted, try to fix the least and second least integer by looping over it.
// Lets say the least integer in the solution is arr[i] and second least is arr[j].
// Now we need to find a pair of integers k and l such that arr[k] + arr[l] is target-arr[i]-arr[j].
// To do that, lets try the 2 pointer approach. If we fix the two pointers at the end ( that is, j+1 and end of array ), we look at the sum.
// If the sum is smaller than the sum we want, we increase the first pointer to increase the sum.
// If the sum is bigger than the sum we want, we decrease the end pointer to reduce the sum.

vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());

    vector<vector<int> > output;
    for(int i=0;i<A.size();){
        for(int j=i+1;j<A.size();){
            int k = j+1,l=A.size()-1;
            int sreq = B-A[i]-A[j];
            while(k<l){
                if(A[k]+A[l]>sreq){
                    l--;
                }else if(A[k]+A[l]<sreq){
                    k++;
                }else{
                    vector<int> v {A[i],A[j],A[k],A[l]};
                    output.push_back(v);
                    int temp=A[k];
                    while(A[k]==temp) k++; // To avoid duplicates
                    temp = A[l];
                    while(A[l]==temp) l--; // To avoid duplicates
                }
            }
            int temp=A[j];
            while(A[j]==temp) j++; // To avoid duplicates
        }
        int temp=A[i];
        while(A[i]==temp) i++; // To avoid duplicates
    }
    return output;
    
}


/***************************************************************************************************************************/

// Approoach 3: Hashing, In hashmap store Sum -> vector< pair of indices of elements>
// Time - ?  On gfg O(n^2 * logn) of finding any one quadruple
// Can go upto O(n^4) eg: when all elements are same, [a,a,a,a,a,a] and B=4a OR when only 2 sums i.e 2 vectors of size (nC2)/2 in map

vector<vector<int>> Solution::fourSum(vector<int> &A, int B) {
    unordered_map<int,vector<pair<int,int>>> m; // Sum -> vector< pair of indices of elements>
    // NOTE: Storing indices here
    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++){
            m[A[i]+A[j]].push_back({i,j});
        }
    }
    
    set<vector<int>> s; // set<Quadruples>
    for(auto p:m){
        if(m.count(B-p.first)>0){
            for(auto pij:p.second){
                int i=pij.first,j=pij.second;
                for(auto pkl:m[B-p.first]){
                    int k=pkl.first,l=pkl.second;
                    // Make sure all elements are distinct array elements (thats why we stored indices not elements)
                    if(i!=k&&i!=l&&j!=k&&j!=l){
                        vector<int> v {A[i],A[j],A[k],A[l]};
                        sort(v.begin(),v.end());
                        s.insert(v);
                    }
                }
            }
        }
    }

    return vector<vector<int>>(s.begin(),s.end());
}
