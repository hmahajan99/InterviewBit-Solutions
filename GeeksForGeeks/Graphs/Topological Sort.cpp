// Approach 1: Using DFS - O(V+E)

// The Graph structure is as folows
/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array 
*/

void dfs(int node, stack<int> &s,vector<int> adj[],bool *vis){
    vis[node]=true;
    for(int neighbour:adj[node]){
        if(!vis[neighbour]){
            dfs(neighbour,s,adj,vis);
        }
    }
    s.push(node); // Push when exiting
}

int* topoSort(int V, vector<int> adj[]){
    
    stack<int> s;
    bool* vis = new bool[V]{0}; // NOTE: Initialise Boolean array to false
    // NOTE: Remember to DEALLOCATE also when using new operator
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,s,adj,vis);
        }
    }
    
    int* sorted = new int[V];
    for(int i=0;i<V;i++){
        sorted[i] = s.top();
        s.pop();
    }
    return sorted;
}

/***************************************************************************************************************************/

// Approach 2 : Using BFS - O(V+E)
// Kahns algo for topological sort

// The Graph structure is as folows
/*  Function which sorts the graph vertices in topological form
*   N: number of vertices
*   adj[]: input graph
*   NOTE: You must return dynamically allocated array 
*/
int* topoSort(int V, vector<int> adj[]){
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
    
    int* sorted = new int[V];
    int count=0;
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        sorted[count++]=node;
        for(int neighbour:adj[node]){
            indegree[neighbour]--;
            if(!indegree[neighbour]){
                q.push(neighbour);
            }
        }
    }
    // If count (i.e count of visited nodes) != V (i.e no of nodes) here then topological sort is not possible for this graph
    // TO DETECT CYCLE in a directed graph using BFS, if count!=V => cycle, else => no cycle
    return sorted;
}
