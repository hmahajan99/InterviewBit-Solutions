// Approach 1: Sorting
// Time: Say, n strings length m each => O((mlogm)*n + (nlogn)*m) = O(nmlog(mn))
// Sorting 2 anagrams gives the same string
// Anagrams will map to the same string if the characters in the string are sorted.

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    vector<pair<string,int>> v;  //  pair<string,index>
    for(int i=0;i<A.size();i++){
        v.push_back(make_pair(A[i],i));
        sort(v[i].first.begin(),v[i].first.end()); // sort the string
    }
    
    sort(v.begin(),v.end());

    vector<vector<int> > ans;    
    for(int i=0;i<v.size();){
            string t=v[i].first;
            vector<int> sans;
            while(i<v.size()&&v[i].first==t){
                sans.push_back(v[i].second+1);
                i++;
            }
            ans.push_back(sans);
    }
    
    return ans;
}

/***************************************************************************************************************************/

// Approach 2 : Using Hashmap
// Time: Say, n strings length m each => O(n*mlog(m))
// We can maintain a hashmap with the key being the sorted string and the value being the list of strings ( which have the sorted characters as key ).

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    unordered_map<string,vector<int>> m;  // sorted string -> vector of indices
    for(int i=0;i<A.size();i++){
        string s=A[i];
        sort(s.begin(),s.end()); // sort the string
        m[s].push_back(i+1); // As 1 based indexing
    }

    vector<vector<int>> ans;
    for(auto p:m) ans.push_back(p.second);
    return ans;

}
