// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.
// The solution set must not contain duplicate triplets.

// NOTE:
// Getting a Time Limit exceeded or Output Limit exceeded? 
// Make sure you handle case of empty input []. 
// In C++/C, usually if you run a loop till array.size() - 2, 
// it can lead to the program running indefinitely as array.size() is unsigned int, and the subtraction just makes it wrap over to a big integer.

// Approach 1: Brute Force, O(n^3)

/***************************************************************************************************************************/

// Approach 2: Fix i, and use 2 pointer for j(=i+1) & k(=n-1)
// Time - O(n^2)

vector<vector<int> > Solution::threeSum(vector<int> &A) {

    vector<vector<int>> ans;
    sort(A.begin(),A.end());
    int i=0;
    while(i<A.size()){

        int j=i+1,k=A.size()-1;
        while(j<k){
            if(A[i]+A[j]+A[k]==0){
                ans.push_back({A[i],A[j],A[k]});
                int temp=A[j];
                while(A[j]==temp) j++; // To avoid duplicate triplets
                temp=A[k];
                while(A[k]==temp) k--; // To avoid duplicate triplets
            }
            if(A[i]+A[j]+A[k]<0){
                int temp=A[j];
                while(A[j]==temp) j++; // To avoid duplicate triplets
            }
            if(A[i]+A[j]+A[k]>0){
                int temp=A[k];
                while(A[k]==temp) k--; // To avoid duplicate triplets
            }
            
        }
        
        int temp=A[i];
        while(temp==A[i]) i++; // To avoid duplicate triplets

    }
    
    return ans;
    
}
