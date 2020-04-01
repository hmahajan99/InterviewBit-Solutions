int Solution::maxPoints(vector<int> &X, vector<int> &Y) {

    int ans=0;
    if(X.size()<=2){
        return X.size();
    }
    for(int i=0;i<X.size();i++){
        // NOTE: USING MAP SINCE KEY IS pair<int,int> 
        // By default we don't have hash function for pairs 
        // mp stores slope(Cannot use double since precision errors) -> count
        map<pair<int,int>,int> mp; 
 
        unordered_map<int,int> vertical; // Line equation => x = c , Store c -> count
        int same=1; // For overlapping points
        int currMax=0;
        
        for(int j=i+1;j<X.size();j++){

            // Same point
            if(X[i]==X[j]&&Y[i]==Y[j]){
                same++;
                continue;
            }
            // Vertical Line, slope infinity
            if(X[i]==X[j]){
                vertical[X[i]]++;
                if(vertical[X[i]]>currMax){
                    currMax=vertical[X[i]];
                }
                continue;
            }
            
            int g = __gcd(abs(Y[j]-Y[i]), abs(X[j]-X[i]));
            int yd = Y[j]-Y[i];
            int xd = X[j]-X[i];
            if(yd>0&&xd<0){
                // If diff signs => Want yd -ve xd +ve 
                yd *=-1;
                xd *=-1;
            }
            if(yd<0&&xd<0){
                // If same signs => Want yd +ve xd +ve 
                yd *=-1;
                xd *=-1;
            }
            
            pair<int,int> p;
            if(yd==0) p = make_pair(0,1); // For horizontal line
            else p = make_pair((yd/g),(xd/g)); // Reduce pair by their gcd before inserting into map

            mp[p]++;
            currMax = max(currMax,mp[p]);
        }
        
        ans=max(ans,currMax+same);
    }
    
    return ans;
    
}