// N light bulbs are connected by a wire.
// Each bulb has a switch associated with it, however due to faulty wiring, a switch also changes the state of all the bulbs to the right of current bulb.
// Given an initial state of all bulbs, find the minimum number of switches you have to press to turn on all the bulbs.
// You can press the same switch multiple times.
// Note : 0 represents the bulb is off and 1 represents the bulb is on.

// Input: A = [0 1 0 1]
// Output: 4
// Explanation:
// 	press switch 0 : [1 0 1 0]
// 	press switch 1 : [1 1 0 1]
// 	press switch 2 : [1 1 1 0]
// 	press switch 3 : [1 1 1 1]

int Solution::bulbs(vector<int> &A) {
    int count=0;
    for(int i=0;i<A.size();i++){
        if((A[i]+count)%2==0) count++;
    }
    return count;
}
