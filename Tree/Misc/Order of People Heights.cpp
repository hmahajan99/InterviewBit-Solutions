// Bucket - Interval tree/Segment Tree

// Approach 1 : Try out all possible permutation of the give numbers, and verify if the infronts numbers match for the given sequence.
// This is obviously too inefficient. O(N!).

/***************************************************************************************************************************/

// Approach 2 : Using Sorting, Time - O(nlogn+n^2)
// Fix the position of the shortest person first, then second shortest and so on ...
// Sort people by heights. Then iterate from shortest to tallest.  
// In each step you need an efficient way to put the next person to the correct position.
// So we have to find a place such that the number of empty positions in the front is equal to the inFronts value of this person.
vector<int> Solution::order(vector<int> &heights, vector<int> &inFronts) {
    int n = heights.size();
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++) v.push_back({heights[i],inFronts[i]});
    sort(v.begin(),v.end());
    vector<int> ans(n,0);
    for(int i=0;i<n;i++){
        int countEmpty=0;
        for(int j=0;j<n;j++){
            if(ans[j]==0) countEmpty++;
            if(countEmpty==v[i].second+1){
                ans[j]=v[i].first;
                break;
            }
        }
    }
    return ans;
}

/***************************************************************************************************************************/

// Approach 3 : TODO Segment Trees
