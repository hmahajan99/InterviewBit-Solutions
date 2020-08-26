// Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j

int Solution::diffPossible(const vector<int> &A, int B) {

    unordered_map<int,bool> m;
    for(int a:A){
        if(m.count(a+B)||m.count(a-B)){ // Tricky condition
            return 1;
        }
        m[a]=true;
    }
    return 0;
    
}