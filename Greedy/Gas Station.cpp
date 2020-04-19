// Given two integer arrays A and B of size N.
// There are N gas stations along a circular route, where the amount of gas at station i is A[i].
// You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
// Return the minimum starting gas station’s index if you can travel around the circuit once, otherwise return -1.
// You can only travel in one direction. i to i+1, i+2, … n-1, 0, 1, 2.. Completing the circuit means starting at i and ending up at i again.

// Approach 1: O(n^2)

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
// A-Gas, B-Cost
    int n=A.size();
    for(int i=0;i<n;i++){
        int currGas=0;
        for(int j=i,c=1;c<=n;j=(j+1)%n,c++){
            currGas += A[j]-B[j];
            if(currGas<0) break;
        }
        if(currGas>=0) return i;
    }
    return -1;
    
}

/***************************************************************************************************************************/

// Approach 2: O(n)
// The bruteforce solution should be obvious. Start from every i, and check to see if every point is reachable with the gas available. Return the first i for which you can complete the trip without the gas reaching a negative number.
// This approach would however be quadratic.
// Lets look at how we can improve.
// 1) If sum of gas is more than sum of cost, does it imply that there always is a solution ?
// 2) Lets say you start at i, and hit first negative of sum(gas) - sum(cost) at j. We know TotalSum(gas) - TotalSum(cost) > 0. What happens if you start at j + 1 instead ? Does it cover the validity clause for i to j already ?

int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {

    int sumGas = 0;
    int sumCost = 0;
    int start = 0;
    int tank = 0;

    for (int i = 0; i < A.size(); i++) {
        sumGas += A[i];
        sumCost += B[i];
        tank += A[i] - B[i];
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }

    if (sumGas < sumCost) return -1;
    else return start;

}
