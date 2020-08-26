// There are N children standing in a line. Each child is assigned a rating value.
// You are giving candies to these children subjected to the following requirements:
// 1. Each child must have at least one candy.
// 2. Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?

// Input 1: A = [1, 2]
// Output 1: 3
// Explanation 1: The candidate with 1 rating gets 1 candy and candidate with rating cannot get 1 candy as 1 is its neighbor. 
// So rating 2 candidate gets 2 candies. In total, 2 + 1 = 3 candies need to be given out.

// Input 2: A = [1, 5, 2, 1]
// Output 2: 7
// Explanation 2: Candies given = [1, 3, 2, 1]

// Greedy works here 
// Start with the guy with the least rating. Obviously he will receive 1 candy.
// Now lets move to the one which is second least. If the least element is its neighbor, then it receives 2 candies, else we can get away with assigning it just one candy.
// Keep repeating the same process

int Solution::candy(vector<int> &A) {
    // NOTE: COMMON PATTERN => Need to sort the elements but also need to retain their original order
    vector<pair<int,int>> v;
    for(int i=0;i<A.size();i++){
        v.push_back({A[i],i}); // vector<value,index>
    }
    sort(v.begin(),v.end());
    vector<int> ans(A.size(),0);
    for(int i=0;i<v.size();i++){
        int index = v[i].second;
        int left=0,right=0;
        if(index>=1&&A[index-1]<A[index]){
            left=ans[index-1];
        }
        if(index<A.size()-1&&A[index+1]<A[index]){
            right=ans[index+1];
        }
        ans[index]=1+max(left,right);
    }
    int candies=0;
    for(int a:ans) candies+=a;
    return candies;
}
