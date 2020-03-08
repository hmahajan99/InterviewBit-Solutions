/*  Function to implement Dijkstra
*   graph: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/

int findMinVertex(int *dist,bool *vis,int V){
    int minVertex=-1;
    for(int i=0;i<V;i++){
        if(!vis[i]&&(minVertex==-1||dist[i]<dist[minVertex])){
            minVertex=i;
        }
    }
    return minVertex;
}

void dijkstra(vector<vector<int>> graph, int src, int V){
    bool *vis=new bool[V]{0};
    int *dist=new int[V];
    fill(dist,dist+V,INT_MAX);  // for(int i=0;i<V;i++) dist[i]=INT_MAX;
    dist[src]=0;
    for(int i=0;i<V-1;i++){
        int minVertex = findMinVertex(dist,vis,V);
        vis[minVertex]=true; // IMP LINE
        for(int j=0;j<V;j++){
            if(graph[minVertex][j]!=0&&!vis[j]){
                int d = dist[minVertex]+graph[minVertex][j];
                if(d<dist[j]) dist[j]=d;
            }
        }
    }
    for(int i=0;i<V;i++){
        cout<<dist[i]<<" ";
    }
}