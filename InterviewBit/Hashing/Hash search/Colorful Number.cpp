int Solution::colorful(int A) {
    unordered_map<long long,bool> m;
    string s = to_string(A);
    
    for(int i=0;i<s.size();i++){
        long long prod = 1;
        for(int j=i;j<s.size();j++){
            prod*= s[j]-'0';
            if(m.count(prod)>0) return 0;
            m[prod] = true;
        }
    }
    
    return 1;
}
