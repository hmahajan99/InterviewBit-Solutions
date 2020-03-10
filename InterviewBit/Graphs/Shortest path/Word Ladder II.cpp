// IMP QUESTION
// Approach: BFS to construct ALL POSSIBLE SHORTEST PATHS IN THE GRAPH (NEED TO STORE PARENTS FOR EACH NODE)

// This is a classic shortest path problem.
// Think in terms of a graph. You basically need to add an edge between two words which can be converted into one another. Resulting graph will be unweighted and undirected.
// BFS can help you in computing the shortest path in undirected, unweighted graph
// Once you know about the shortest path, how do we construct all shortest paths ?
// When will a node x be a parent of node Y ?

// Idea of the solution : We do normal BFS as is done for calculating the shortest path. 
// We only take care of all the possible parents for a node which happens in following 2 cases :
// 1) Node x discovers node y and y is unvisited. x is parent of y.
// 2) Node x discovers node y and y is visited and distance[y] = distance[x] + 1.
// Once we have constructed the parents, we do backtracking to construct all possible path combinations back from target to source.
// Note that since we are constructing the reverse path, it might be helpful to swap start and end in the beginning.


bool possible(const string &s1,const string &s2){
    int l = min(s1.size(),s2.size());
    int count=0;
    for(int i=0;i<l;i++){
        if(s1[i]!=s2[i]) count++;
        if(count>1) break;
    }
    return count==1;
}

void constructPaths(string start, string end, unordered_map<string,vector<string>> &parents, vector<string> &current, vector<vector<string>> &ans) {
    if(end==start){
        current.push_back(start);
        ans.push_back(current);
        current.pop_back();
        return;
    }
    current.push_back(end);
    for (string parent: parents[end]) {
        constructPaths(start, parent, parents, current, ans);
    }
    current.pop_back();
    return;
}

vector<vector<string> > Solution::findLadders(string start, string end, vector<string> &dictV) {
    if(start==end) return {{start}};
    
    // Note: Both start and end exist in dictV for this question

    // Since the dictionary may contain duplicates, remove duplicates in dictV
    set<string> dictVUnique(dictV.begin(),dictV.end());
    dictV = vector<string>(dictVUnique.begin(),dictVUnique.end());
    
    swap(start, end); // We do this because we construct the path later from end to start
    
    int n = dictV.size();
    vector<vector<string>> ans;
    vector<bool> vis(n,false);
    unordered_map<string,vector<string>> parents;
    unordered_map<string,int> distance;
    distance[start]=1;
    queue<string> q;
    for(int i=0;i<n;i++){
        if(possible(start,dictV[i])){
          vis[i]=true;
          parents[dictV[i]].push_back(start);
          distance[dictV[i]]=2;
          q.push(dictV[i]);  
        } 
    }
   
    while(!q.empty()){
        string s = q.front();
        q.pop();
        if(s==end){
            vector<string> current;
            constructPaths(start,end,parents,current,ans);
            return ans;
        }
        for(int i=0;i<n;i++){
            if(possible(s,dictV[i])){
                if(!vis[i]){
                    vis[i]=true;
                    parents[dictV[i]].push_back(s);
                    distance[dictV[i]]=distance[s]+1;
                    q.push(dictV[i]);
                }else if(vis[i]&&distance[dictV[i]]==distance[s]+1){
                    parents[dictV[i]].push_back(s);
                }
            }
        }
    }
    return ans;
}
