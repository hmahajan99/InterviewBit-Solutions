// Similar to Dynamic Programming/Misc/Word Break II.cpp

// Given an array A with non negative numbers, divide the array into two parts such that the average of both the parts is equal.
// Return both parts (If exist). If there is no solution. return an empty list
// If multiple solutions exist, return the solution where length(A) is minimum. If there is still a tie, return the one where A is lexicographically smallest.
// Array will contain only non negative numbers.

// Input: A = [1 7 15 29 11 9]
// Output: [9 15] [1 7 11 29]
// Explanation: The average of part is (15+9)/2 = 12, average of second part elements is (1 + 7 + 11 + 29) / 4 = 12

// Approach: 3D DP & Dp optimized backtrack
// Assume sum of set1 = s1, with size = n1
// Assume sum of set2 = s2, with size = n2
// s1/n1 = s2/n2 = (s-s1)/(n-n1)
// On cross multiplying and simplifying, s1 = (n1*s)/n
// s1 must be an integer as elements of array are integers
// Now this problem reduces to the fact that if we can select a particular size of subset whose sum is equal to the current subset’s sum, we are done.
// This recursive relation can be defined as:
// partition(ind, curr_sum, curr_size) = partition(ind+1, curr_sum, curr_size) || partition(ind+1, curr_sum – val[ind], curr_size-1)
// This is a deviation from the classic subset sum problem

#include<numeric> // for accumulate

typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;

vvvb dp;

bool isPossible(int i,int sum,int numElements,vector<int> &A,vector<int> &res){
    int n = A.size();
    if(numElements==0) return sum==0;
    if(i==n) return false;
    
    if(dp[i][sum][numElements]==false) return false; // return if false, if true will go on to fill res
    
    // include
    if(A[i]<=sum){
        res.push_back(A[i]);
        if(isPossible(i+1,sum-A[i],numElements-1,A,res)){
            return dp[i][sum][numElements]=true;
        }
        res.pop_back();
    }

    // exclude
    if(isPossible(i+1,sum,numElements,A,res)){
        return dp[i][sum][numElements]=true;
    }

    return dp[i][sum][numElements]=false;

}

vector<vector<int> > Solution::avgset(vector<int> &A) {
    int n = A.size();
    int sum = accumulate(A.begin(),A.end(),0);
    sort(A.begin(),A.end());
    dp = vvvb(n,vvb(sum+1,vb(n,true))); // marking true since need to push elements in set1
    for(int n1=1;n1<=n-1;n1++){
        if((sum*n1)%n==0){
            int s1 = (sum*n1)/n;
            vector<int> set1;
            if(isPossible(0,s1,n1,A,set1)){
                vector<int> set2;
                int i=0,j=0;
                while(j<n){
                    if(i<set1.size()&&set1[i]==A[j]){
                        i++;
                        j++;
                    }else{
                        set2.push_back(A[j]);
                        j++;
                    }
                }
                return {set1,set2};
            }
        }
    }
    return {};
}
