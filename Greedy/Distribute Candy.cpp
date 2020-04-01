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
