// Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.
// Sample Input: [3 4 1 4 1]
// Sample Output: 1
// If there are multiple possible answers ( like in the sample case above ), output any one.
// If there is no duplicate, output -1
// Note: Duplicate sure to exist as n+1 integers

// Approach 1: Modifying the input array
// The basic idea is to use a HashMap to solve the problem.
// But there is a catch, the numbers in the array are from 1 to n, and the input array has length n. 
// So, the input array can be used as a HashMap.
// While traversing the array, if an element a is encountered then make the value of ath element as negative.

int Solution::repeatedNumber(const vector<int> &A) {
    // NOTE : integers between 1 and n
    vector<int> B(A);
    for(int i=0;i<B.size();i++){
        int pos = abs(B[i])-1;
        if(B[pos]<0){
            return pos+1; // want 1 indexed
        }
        B[pos] *= -1;
    }
}

/***************************************************************************************************************************/

// Approach 2: BUCKETING 
// sqrt(n) space complexity

// Split the numbers from 1 to n in sqrt(n) ranges so that range i corresponds to [sqrt(n) * i .. sqrt(n) * (i + 1)).
// Do one pass through the stream of numbers and figure out how many numbers fall in each of the ranges.
// At least one of the ranges will contain more than sqrt(n) elements.
// Do another pass and process just those elements in the oversubscribed range.
// Using a hash table to keep frequencies, you’ll find a repeated element.
// This is O(sqrt(n)) memory and 2 sequential passes through the stream.

int Solution::repeatedNumber(const vector<int> &A) {

    int size = A.size();
    int n=size-1,rn=sqrt(n);
    if(size==2) return 1;
    vector<int> blocks(rn+2,0); // i-> [rn*i+1,rn*(i+1)]
    for(int i=0;i<size;i++){
        blocks[(A[i]-1)/rn]++;
    }
    for(int i=0;i<=rn+1;i++){
        int rs = (rn*i+1), re = min(rn*(i+1),n);
        int range = re-rs+1; // Range of this bucket
        if(blocks[i]>range){
            unordered_map<int,bool> m;
            for(int i=0;i<size;i++){
                if(rs<=A[i]&&A[i]<=re){
                    if(m.count(A[i])==1) return A[i];
                    m[A[i]]=true;
                }
            }
        }
    }

}

