// Similar to Greedy/Medium Greedy/Majority Element

// You’re given a read only array of n integers. 
// Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.
// If so, return the integer. If not, return -1.
// If there are multiple solutions, return any one.
// Example : Input : [1 2 3 1 1] Output : 1 
// 1 occurs 3 times which is more than 5/3 times. 

// Approach 1: Brute Force
// It works to simply pick all elements one by one. For every picked element, count its occurrences by traversing the array.
// If count becomes more than n/3, then print the element. Time Complexity of this method would be O(n^2).

/***************************************************************************************************************************/

// Appraoch 2: Sorting.
// First, sort all elements using a O(nLogn) algorithm. 
// All required elements in a linear scan of array can be found once the array is sorted.
// So overall, time complexity of this method is O(nLogn) + O(n) which is O(nLogn).

/***************************************************************************************************************************/

// Approach 3: Hashing
// Time and space complexity - O(n)

/***************************************************************************************************************************/

// Approach 4: Removing 3 distinct element from the array does not change the answer
// Time O(n) Space O(1)
// It is important to note that if at a given time, you have 3 distinct element from the array, if you remove them from the array, your answer does not change.
// Assume that we maintain 2 elements with their counts as we traverse along the array.
// When we encounter a new element, there are 3 cases possible :
// 1) We don’t have 2 elements yet. So add this to the list with count as 1.
// 2) This element is different from the existing 2 elements. As we said before, we have 3 distinct numbers now. Removing them does not change the answer. So decrement 1 from count of 2 existing elements. If their count falls to 0, obviously its not a part of 2 elements anymore.
// 3) The new element is same as one of the 2 elements. Increment the count of that element.
// Consequently, the answer will be one of the 2 elements left behind. 
// If they are not the answer, then there is no element with count > N / 3.

int Solution::repeatedNumber(const vector<int> &A) {
    
    if(A.size()==0) return -1;
    if(A.size()<3) return A[0];
    
    vector<pair<int,int>> v;
    for(auto a:A){
        bool present=false;
        for(int i=0;i<v.size();i++){
            if(v[i].first==a){
                present=true;
                v[i].second++;
                break;
            }
        }
        if(!present){
            if(v.size()<2){
                v.push_back({a,1});
            }else{
                vector<pair<int,int>> v2;
                for(int i=0;i<=1;i++){
                    v[i].second--;
                    if(v[i].second) v2.push_back(v[i]);                    
                }
                v=v2;
            }
        }
    }
    
    for(int i=0;i<v.size();i++){
        int count=0;
        for(int j=0;j<A.size();j++){
            if(v[i].first==A[j]) count++;
        }
        if(count>A.size()/3) return v[i].first;
    }
    
    return -1;
    
}
