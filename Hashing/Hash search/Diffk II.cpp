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