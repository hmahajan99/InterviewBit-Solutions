// Approach 1: cout when pushing in queue
// Time - O(V+E)

/* You have to complete this function*/
/* Function to do BFS of graph
*  adj[]: array of vectors
*  vis[]: array to keep track of visited nodes
*/
void bfs(int src, vector<int> adj[], bool vis[]){
    queue<int> q;
    vis[src] = true; // vis = true when push in queue
    cout<<src<<" ";
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int neighbour:adj[node]){
            if(!vis[neighbour]){
                vis[neighbour]=true; // vis = true when push in queue
                cout<<neighbour<<" ";
                q.push(neighbour);
            }
        }
    }
    
    
}

/***************************************************************************************************************************/

// Approach 2 : cout when popping from queue

/* You have to complete this function*/
/* Function to do BFS of graph
*  adj[]: array of vectors
*  vis[]: array to keep track of visited nodes
*/
void bfs(int src, vector<int> adj[], bool vis[]){
    queue<int> q;
    vis[src] = true; // vis = true when push in queue
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        for(int neighbour:adj[node]){
            if(!vis[neighbour]){
                vis[neighbour]=true; // vis = true when push in queue
                q.push(neighbour);
            }
        }
    }    
}
