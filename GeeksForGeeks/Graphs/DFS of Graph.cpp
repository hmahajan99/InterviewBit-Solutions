// Approach 1: Recursive
// Time - O(V+E)

/* Function to do DFS of graph
*  g[]: array of vectors to represent graph
*  vis[]: array to keep track of visited vertex
*/
void dfs(int s, vector<int> g[], bool vis[]){
    vis[s]=true; // vis = true when push in stack (so doesn't get pushed again)
    cout<<s<<" ";
    for(int neighbour:g[s]){
        if(!vis[neighbour]){
            dfs(neighbour,g,vis);
        }
    }
}

// Alternative : [Above approach is better]
// Pushing before calling function recursively

/* Function to do DFS of graph
*  g[]: array of vectors to represent graph
*  vis[]: array to keep track of visited vertex
*/

void dfsHelper(int s, vector<int> g[], bool vis[]){
    cout<<s<<" ";
    for(int neighbour:g[s]){
        if(!vis[neighbour]){
            vis[neighbour]=true;
            dfsHelper(neighbour,g,vis);
        }
    }
}

void dfs(int s, vector<int> g[], bool vis[]){
    vis[s]=true;
    dfsHelper(s,g,vis);
}

/***************************************************************************************************************************/

// Approach 2 : Iterative

/* Function to do DFS of graph
*  g[]: array of vectors to represent graph
*  vis[]: array to keep track of visited vertex
*/

void dfs(int src, vector<int> g[], bool vis[]){
    stack<int> s;
    cout<<src<<" ";
    vis[src] = true; // vis = true when push in stack
    s.push(src);
    while(!s.empty()){
        int node=s.top();
        bool push=false;
        for(int neighbour:g[node]){
            if(!vis[neighbour]){
                cout<<neighbour<<" ";
                vis[neighbour] = true; // vis = true when push in stack
                s.push(neighbour);
                push=true;
                break; // Important to break also
            }
        }   
        if(!push){
            s.pop();
        }
    }
}