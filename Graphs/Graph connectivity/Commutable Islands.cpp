// There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.
// We need to find bridges with minimal cost such that all islands are connected.
// It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

// Input Format:
// The first argument contains an integer, A, representing the number of islands.
// The second argument contains an 2-d integer matrix, B, of size M x 3:
//     => Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].

// We can assume islands as the vertex points and bridges as the edges and can construct a graph with the the help of them. 
// After constructing the graph, the problem boils down to finding a subset of edges which helps in connecting vertices in a single connected component such that the sum of their edge weights is as minimum as possible.
// Well the answer to this problem is the classic minimum spanning tree algorithm.
// Can use Kruskal’s algorithm, Prim’s algorithm 

// Appraoch 1: Kruskals algo, using union by rank and path compression

bool cmp(const vector<int> &v1,const vector<int> &v2){
    return v1[2]<v2[2];
}

class DisjointSet{
    int V;
    int *parent,*rank;
public:
    DisjointSet(int v){
        V=v;
        parent = new int[V];
        rank = new int[V];
        for(int i=0;i<V;i++){
           parent[i]=-1;
           rank[i]=0;
        }
    }
    int find(int node){ 
        if(parent[node]==-1){
          return node;  
        } 
        // Path Compression
        return parent[node]=find(parent[node]);
    }
    void Union(int n1,int n2){    // since union is a keyword
        int p1 = find(n1);
        int p2 = find(n2);
        if(rank[p1]<rank[p2]){
            parent[p1]=p2;
        }else if(rank[p1]>rank[p2]){
            parent[p2]=p1;
        }else{
            parent[p1]=p2;
            rank[p2]++;
        }
    }
    
};


int Solution::solve(int V, vector<vector<int> > &edgeList) {


    DisjointSet ds(V);

    int e=edgeList.size();
    sort(edgeList.begin(),edgeList.end(),cmp);
    int count=1,i=0,minCost=0;
    while(count<=V-1){
        vector<int> currEdge=edgeList[i];
        int p1=ds.find(currEdge[0]-1);
        int p2=ds.find(currEdge[1]-1);
        if(p1!=p2){
            minCost+=currEdge[2];
            count++;
            ds.Union(currEdge[0]-1,currEdge[1]-1);
        }
        i++;
    }
    return minCost;
    
}

/***************************************************************************************************************************/

// Approach 2: Prims Algo

#include<list>

int Solution::solve(int V, vector<vector<int>> &edgeList) {
    vector<list<pair<int,int>>> adjList(V);
    for(vector<int> edge: edgeList){
        int u=edge[0],v=edge[1],weight=edge[2];
        adjList[u-1].push_back({v-1,weight});
        adjList[v-1].push_back({u-1,weight}); // Since undirected graph
    }
    
    vector<bool> inMST(V,false); // Visited array
    vector<int> key(V,INT_MAX);
    vector<int> parent(V,-1);
    set<pair<int,int>> s;
    key[0]=0;
    s.insert({key[0],0});
    while(!s.empty()){
        int minWeightVertex = s.begin()->second;
        s.erase(s.begin());
        inMST[minWeightVertex] = true;  
        for(auto p:adjList[minWeightVertex]){
            int v=p.first, cost=p.second;
            if(!inMST[v]&&cost<key[v]){
                auto it = s.find({key[v],v});
                if(it!=s.end()) s.erase(it);
                s.insert({cost,v});
                key[v]=cost;
                parent[v]=minWeightVertex;
            }
        }
    }

    int costMST=0;
    for(int k:key) costMST+=k;
    return costMST;
    
}
