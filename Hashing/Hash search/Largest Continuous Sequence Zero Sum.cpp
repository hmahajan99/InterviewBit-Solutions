// Find the largest continuous sequence in a array which sums to zero.
// NOTE : If there are multiple correct answers, return the sequence which occurs first in the array

// There are two steps:
// 1. Create cumulative sum array where ith index in this array represents total sum from 1 to ith index element.
// 2. Iterate all elements of cumulative sum array and use hashing to find two elements where value at ith index == value at jth index but i != j.
// 3. IF element is not present in hash in fill hash table with current element.

vector<int> Solution::lszero(vector<int> &A) {
    int n=A.size();
    vector<int> sum(n+1); // represents prefix sum
    unordered_map<int,int> m;
    
    sum[0]=0;
    m[0]=0;
    int startIndex=-1,len=0;
    
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+A[i-1];
        if(!m.count(sum[i])){
            m[sum[i]]=i;
        }else if(i-m[sum[i]]>len){
            len=i-m[sum[i]];
            startIndex=m[sum[i]];
        }
    }

    vector<int> ans;
    for(int i=startIndex;len>0;len--,i++){
        ans.push_back(A[i]);
    }
    return ans;
}
