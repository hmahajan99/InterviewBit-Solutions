// Given two words A and B, and a dictionary, C, find the length of shortest transformation sequence from A to B, such that:
// You must change exactly one character in every transformation.
// Each intermediate word must exist in the dictionary.

// Input:
//    A = "hit"
//    B = "cog"
//    C = ["hot", "dot", "dog", "lot", "log"]
// Output: 5
// Explanation: "hit" -> "hot" -> "dot" -> "dog" -> "cog"

// Think in terms of a graph.
// When can you do the transition from one word to another ? Does it mean it can indicate a graph edge between those 2 words ? 

// Approach: BFS

bool possible(const string &s1,const string &s2){
    int l = min(s1.size(),s2.size());
    int count=0;
    for(int i=0;i<l;i++){
        if(s1[i]!=s2[i]) count++;
        if(count>1) break;
    }
    return count==1;
}

int Solution::solve(string start, string end, vector<string> &dictV) {
    if(start==end) return 1;
    
    vector<string>::iterator it = find(dictV.begin(),dictV.end(),end);
    if(it==dictV.end()) dictV.push_back(end);
    
    int n = dictV.size();
    queue<pair<string,int>> q;
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(possible(start,dictV[i])){
          vis[i]=true;
          q.push({dictV[i],2});  
        } 
    }
   
    while(!q.empty()){
        pair<string,int> p = q.front();
        q.pop();
        if(p.first==end) return p.second;
        for(int i=0;i<n;i++){
            if(!vis[i]&&possible(p.first,dictV[i])){
                vis[i]=true;
                q.push({dictV[i],p.second+1});
            }
        }
    }
    return 0;

}
