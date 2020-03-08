// We can find all strongly connected components in O(V+E) time using Kosaraju’s algorithm. 
// Following is detailed Kosaraju’s algorithm.
// 1) Create an empty stack ‘S’ and do DFS traversal of a graph. In DFS traversal, after calling recursive DFS for adjacent vertices of a vertex, push the vertex to stack.
// 2) Reverse directions of all arcs to obtain the transpose graph.
// 3) One by one pop a vertex from S while S is not empty. Let the popped vertex be ‘v’. Take v as source and do DFS (call DFSUtil(v)). The DFS starting from v prints strongly connected component of v. 

// Time Complexity: The above algorithm calls DFS, finds reverse of the graph and again calls DFS. 
// DFS takes O(V+E) for a graph represented using adjacency list. 
// Reversing a graph also takes O(V+E) time.

/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/

void dfs(int node,vector<int> adj[],bool *vis,stack<int> &s,bool push){
    vis[node]=true;
    for(int neighbour:adj[node]){
        if(!vis[neighbour]) dfs(neighbour,adj,vis,s,push);
    }
    if(push) s.push(node);
}

vector<int>* reverseGraph(vector<int> adj[],int V){
    vector<int> *revAdj = new vector<int>[V];
    for(int u=0;u<V;u++){
        for(int v:adj[u]) revAdj[v].push_back(u);
    }
    return revAdj;    
}

int kosaraju(int V, vector<int> adj[]){
    bool *vis1 = new bool[V]{0};
    stack<int> s; // it holds vertices by finish time in reverse order
    // populate stack with vertices with vertex finishing last at the top.
    for(int i=0;i<V;i++){
        if(!vis1[i]) dfs(i,adj,vis1,s,true);
    }
    
    // reverse the graph
    vector<int> *revAdj = reverseGraph(adj,V);

    bool *vis2 = new bool[V]{0};
    int count=0;
    //Do a DFS based off vertex finish time in decreasing order on reverse graph.
    while(!s.empty()){
        int node=s.top();
        s.pop();
        if(!vis2[node]){
            dfs(node,revAdj,vis2,s,false);
            count++;
        }
    }
    
    return count;

}
