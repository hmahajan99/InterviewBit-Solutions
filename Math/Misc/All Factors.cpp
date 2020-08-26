// Given a number N, find all factors of N.
// Make sure the returned array is sorted.

// Approach 1: Use sorting, O(sqrt(n)log(n))

/***************************************************************************************************************************/

// Approach 2: O(sqrt(n))

vector<int> Solution::allFactors(int A) {
    vector<int>  v1,v2;
    for(int i=1;i*i<=A;i++){
        if(A%i==0){
            v1.push_back(i);
            if(i!=A/i) v2.push_back(A/i);
        }
    }
    v1.insert(v1.end(),v2.rbegin(),v2.rend()); // vector.insert(pos,start,end) , insert before pos [start,end)
    return v1;
}

