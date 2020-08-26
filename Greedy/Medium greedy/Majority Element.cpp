// Similar to Arrays/Missing or repeated number/N by 3 Repeat Number

// Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.
// You may assume that the array is non-empty and the majority element always exist in the array.
// Input : [2, 1, 2]
// Return  : 2 which occurs 2 times which is greater than 3/2. 

// Approach 1: Using Hashmap O(n) space

int Solution::majorityElement(const vector<int> &A) {
    unordered_map<int,int> m;
    for(int a:A){
        m[a]++;
        if(m[a]>(A.size()/2)) return a;
    }
}

/***************************************************************************************************************************/

// Approach 2: O(1) space
// Note: You may assume that the array is non-empty and the majority element always exist in the array.
// If we cancel out each occurrence of an element e with all the other elements that are different from e then e will exist till end if it is a majority element. 
// Loop through each element and maintains a count of the element that has the potential of being the majority element. 
// If next element is same then increments the count, otherwise decrements the count. 
// If the count reaches 0 then update the potential index to the current element and reset count to 1.

int Solution::majorityElement(const vector<int> &A) {
    int ans=A[0];
    int count=1;
    for(int i=1;i<A.size();i++){
        if(count==0){
            count=1;
            ans=A[i];
        }else if(ans==A[i]){
            count++;
        }else{
            count--;
        }
    }
    return ans;   
}
