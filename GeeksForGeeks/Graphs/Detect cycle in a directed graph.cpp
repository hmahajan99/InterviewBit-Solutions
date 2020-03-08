// NOTE: OUTPUT of a DFS can be described in a SPANNING TREE with tree,forward,cross,back edges.
// Cycle in graph => Only if back edge present

// Approach 1: DFS, innefficient solution
// Call DFS from each node. Keep track of vertices only in current path(using backtracking) & if back edge => cycle 

/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool isCyclicHelper(int node,bool* vis,vector<int> adj[]){
    vis[node]=true;
    for(int neighbour:adj[node]){
        if(vis[neighbour]) return true;
        if(isCyclicHelper(neighbour,vis,adj)) return true;
    }
    vis[node]=false; // Backtrack (IMPORTANT)
    return false;
}

bool isCyclic(int V, vector<int> adj[]){
    // Inefficient soln : DFS fashion from each node of graph 
    bool* vis = new bool[V]{0};
    for(int i=0;i<V;i++){
        if(isCyclicHelper(i,vis,adj)) return true;
    }
    return false;
}

// Wrong approach : Like DFS approach to detect cycle in undirected graph

/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool isCyclicHelper(int node,bool* vis,vector<int> adj[]){
    vis[node]=true;
    for(int neighbour:adj[node]){
        if(vis[neighbour]) return true;
        if(isCyclicHelper(neighbour,vis,adj)) return true;
    }
    return false;
}

bool isCyclic(int V, vector<int> adj[]){
    bool* vis = new bool[V]{0};
    for(int i=0;i<V;i++){
        if(!vis[i]){  // XXXXXXXXXXXXXXXXX
            if(isCyclicHelper(i,vis,adj)) return true;
        }
    }
    return false;
}

/***************************************************************************************************************************/

// Approach 2: DFS , efficient solution - O(V+E) (can also do this dfs soln using colors)
// TO detect a back edge keep track of vertices currently in recursion stack of function.
// If we reach a vertex that is already in recursion stack => back edge

/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool isCyclicHelper(int node,bool *vis,bool *recStack,vector<int> adj[]){

    vis[node]=true; // Vertex is being processed
    recStack[node]=true; // DFS has started for this node but not ended
    
    for(int neighbour:adj[node]){
        if(!vis[neighbour]){
            if(isCyclicHelper(neighbour,vis,recStack,adj)) return true;
        }else{
            if(recStack[neighbour]) return true;
        }
    }
    
    recStack[node]=false; // Vertex and all its descendants have been processed 
    return false;
}

bool isCyclic(int V, vector<int> adj[]){
    // efficient solnn : using DFS  
    // Need 2 arrays
    bool* vis = new bool[V]{0}; // Vertex not processed yet
    bool* recStack = new bool[V]{0};
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(isCyclicHelper(i,vis,recStack,adj)) return true;
        }
    }
    return false;
}

/***************************************************************************************************************************/

// Approach 2: Using BFS O(V+E), Kahns algo for topological sort
// if count of visited nodes != num of nodes in graph => cycle
// Works even for more than 1 component

/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool isCyclic(int V, vector<int> adj[]){
    int* indegree = new int[V]{0};
    for(int i=0;i<V;i++){
        for(int neighbour:adj[i]){
            indegree[neighbour]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++){
        if(!indegree[i]) q.push(i);
    }
    
    int count=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        count++;
        for(int neighbour:adj[node]){
            indegree[neighbour]--;
            if(!indegree[neighbour]){
                q.push(neighbour);
            }
        }
    }
    return count!=V;
}
