// Bucket - Interval tree/Segment Tree

// You are given the following :
// 1) A positive number N
// 2) Heights : A list of heights of N persons standing in a queue
// 3) Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P
// You need to return list of actual order of persons’s height

// Consider that heights will be unique

// Example

// Input : 
// Heights: 5 3 2 6 1 4
// InFronts: 0 1 2 0 3 2
// Output : 
// actual order is: 5 3 2 1 6 4 
// So, you can see that for the person with height 5, there is no one taller than him who is in front of him, and hence Infronts has 0 for him.

// For person with height 3, there is 1 person ( Height : 5 ) in front of him who is taller than him.

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

// Approach 3 : Segment Trees
// What if you knew how many elements are there in first half of the array, and the second half of the array ?
// To efficiently answer the query of finding the ith empty space.
// The query can be solved using segment / interval tree.
// The root contains the number of elements in [0, N].
// Left node contains the number of elements in [0, N/2]
// Right node contains the number of elements in [N/2 + 1, N]
// Lets say we need to find the ith empty position.
// We look at the number of elements X in [0, N/2].

// If
//     N / 2 - X >= i, the position lies in the left part of array and we move down to the left node.
//     N / 2 - X < i, we now look for i - (N / 2 - X) th position in the right part of the array and move to the right node in the tree.