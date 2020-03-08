// Approach 1: Inefficient, using backtracking

using namespace std;

bool check(string arr[],bool vis[],int n,int i,int count){
    if(count==n){
        return arr[i].back()==arr[0].front();
    }
    
    vis[i]=true;
    for(int j=0;j<n;j++){
        if(!vis[j]&&arr[i].back()==arr[j].front()){
            if(check(arr,vis,n,j,count+1)) return true;
        }
    }
    vis[i]=false; // Needed (fr rb bx xf rc cb br)
    return false;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string arr[n];
        bool vis[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            vis[i]=false;
        } 
        cout<<check(arr,vis,n,0,1)<<"\n";
    }

	return 0;
}

/***************************************************************************************************************************/

// Approach 2 : Eulerian circuit in directed graph

// The idea is to create a directed graph of all characters and then find if their is an eulerian circuit in the graph or not.
// If there is an eulerian circuit, then chain can be formed, otherwise not.
// Note that a directed graph has eulerian circuit only if in degree and out degree of every vertex is same, and all non-zero degree vertices form a single strongly connected component.
// Following are detailed steps of the algorithm.
// 1) Create a directed graph g
// 2) Do following for every string in the given array of strings.
//   a) Add an edge from first character to last character of the given graph.
// 3) If the created graph has eulerian circuit, then return true, else return false.

#include<bits/stdc++.h>
using namespace std;

typedef unordered_map<char,list<char>> adj;

class Graph {
    adj adjList;
public:
    void addEdge(char u,char v){
        adjList[u].push_back(v);
    }
    
    void dfs(int node,adj adjList,unordered_set<char> &vis,stack<char> &s,bool push){
        vis.insert(node);
        for(int neighbour:adjList[node]){
            if(!vis.count(neighbour)) dfs(neighbour,adjList,vis,s,push);
        }
        if(push) s.push(node);
    }

    adj reverseGraph(){
        adj revAdjList;
        for(auto p:adjList){
            char u = p.first;
            for(char v:adjList[u]) revAdjList[v].push_back(u);
        }
        return revAdjList;    
    }
    
    int kosaraju(){
        unordered_set<char> vis1;
        stack<char> s; 
        for(auto p:adjList){
            char node = p.first;
            if(!vis1.count(node)) dfs(node,adjList,vis1,s,true);
        }
        
        adj revAdjList = reverseGraph();
    
        unordered_set<char> vis2;
        int count=0;
        while(!s.empty()){
            char node=s.top();
            s.pop();
            if(!vis2.count(node)){
                dfs(node,revAdjList,vis2,s,false);
                count++;
            }
        }
        
        return count;
    }
    
    bool hasEulerianCircuit(){
        
        unordered_map<char,int> inDegree;
        unordered_map<char,int> outDegree;
        for(auto p:adjList){
            char u = p.first;
            outDegree[u]+=p.second.size();
            for(char v:adjList[u]) inDegree[v]++;
        }
        for(auto p:adjList){
            char node=p.first;
            if(inDegree[node]!=outDegree[node]) return false;
        }
        
        return kosaraju() == 1;
        
    }
    
    bool canBeChained(){
        return hasEulerianCircuit();
    }
  
};

int main(){
    int t;
    cin>>t;
    while(t--){
        Graph g;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            g.addEdge(s.front(),s.back());
        }
        cout<<g.canBeChained()<<"\n";
    }

	return 0;
}
