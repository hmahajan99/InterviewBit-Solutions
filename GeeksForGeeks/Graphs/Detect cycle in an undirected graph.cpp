// Approach 1 : DFS -  O(V+E)

/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/

bool isCyclicHelper(int node,int parent,bool* vis,vector<int> adj[]){
    vis[node]=true;
    for(int neighbour:adj[node]){
        if(vis[neighbour]&&neighbour!=parent) return true;
        if(!vis[neighbour]&&isCyclicHelper(neighbour,node,vis,adj)) return true;
    }
    return false;
}

bool isCyclic(vector<int> adj[], int V){
    bool* vis = new bool[V]{0};
    for(int i=0;i<V;i++){
        if(!vis[i]){ 
            // To detect cycle in different DFS trees
            if(isCyclicHelper(i,-1,vis,adj)) return true;
        }
    }
    return false;   
}

/***************************************************************************************************************************/

// Approach 2 : Using BFS - O(V+E)

/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/

bool isCyclicConnected(int src,vector<int> adj[],bool* vis,int* parent){
    queue<int> q;
    vis[src]=true;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int neighbour:adj[node]){
            if(!vis[neighbour]){
                vis[neighbour]=true;
                parent[neighbour]=node;
                q.push(neighbour);
            }else{
                if(neighbour!=parent[node]) return true;
            }
        }
    }
    return false;
}

bool isCyclic(vector<int> adj[], int V){
    // USING BFS
    bool *vis = new bool[V]{0};
    int *parent=new int[V];
    fill(parent,parent+V,-1); // NOTE: Using fill STL
    for(int i=0;i<V;i++){
        if(!vis[i]){
            // for all connected components
            if(isCyclicConnected(i,adj,vis,parent)) return true;
        }
    }
    return false;
}

/***************************************************************************************************************************/

// Approach 3 : Disjoint Set (or Union-Find)

// A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. 
// A union-find algorithm is an algorithm that performs two useful operations on such a data structure:
// Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.
// Union: Join two subsets into a single subset.

// Implementation of union() and find() is naive and takes O(n) time in worst case. 
// These methods can be improved to O(Logn) using Union by Rank or Height. 

/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/

// NOTE: IMP!!!!!
// TO USE PAIR IN UNORDERED_MAP
struct hash_pair { 
    template <class T1, class T2> 
    // size_t is an unsigned integer type
    size_t operator()(const pair<T1, T2>& p) const{ 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

/* Recursive find function
int find(int node,int *parent){ 
    if(parent[node]==-1) return node;
    return find(parent[node],parent);
}
*/


int find(int node,int *parent){ // Could write recursive
    while(parent[node]!=-1) node=parent[node];
    return node;
}

void Union(int n1,int n2,int* parent){ // since union is a keyword
    int p1 = find(n1,parent);
    int p2 = find(n2,parent);
    if(p1!=p2) parent[p1]=p2;
}

bool isCyclic(vector<int> adj[], int V){
   // If edge list in question wouldn't have to use map
   unordered_map<pair<int, int>, int, hash_pair> m; 
   int *parent = new int[V];
   fill(parent,parent+V,-1);
   for(int u=0;u<V;u++){
       for(int v:adj[u]){
           // Take care for self loop && parallel edge 10-4 && 4-10 cycle
           if(!m.count({min(u,v),max(u,v)})){
               int p1 = find(u,parent);
               int p2 = find(v,parent);
               if(p1==p2) return true;
               Union(u,v,parent);
           }
           m[{min(u,v),max(u,v)}]++;
           // For parallel edges, eg:
           // 4:10,10  10:4,4 in adj list
           if(m[{min(u,v),max(u,v)}]>2) return true;  
       }
   }

   return false;
   
}

/***************************************************************************************************************************/

// Approach 4: Union By Rank and Path Compression

// The above union() and find() are naive and the worst case time complexity is linear. The trees created to represent subsets can be skewed and can become like a linked list
// The above operations can be optimized to O(Log n) in worst case. 
// The idea is to always attach smaller depth tree under the root of the deeper tree. 
// This technique is called union by rank. 
// The term rank is preferred instead of height because if path compression technique is used, then rank is not always equal to height. 

// The second optimization to naive method is Path Compression. 
// The idea is to flatten the tree when find() is called. When find() is called for an element x, root of the tree is returned. 
// The find() operation traverses up from x to find root. 
// The idea of path compression is to make the found root as parent of x so that we don’t have to traverse all intermediate nodes again.

// The two techniques complement each other. The time complexity of each operation becomes even smaller than O(Logn). 
// In fact, amortized time complexity effectively becomes small constant. (Amortized Analysis is used for algorithms where an occasional operation is very slow, but most of the other operations are faster)

/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const{ 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

class Node{
    public:
    int parent,rank;
};

int find(int node,Node *subsets){ 
    if(subsets[node].parent==-1){
      return node;  
    } 
    // Path Compression
    return subsets[node].parent=find(subsets[node].parent,subsets);
}

void Union(int n1,int n2,Node *subsets){ // since union is a keyword
    int p1 = find(n1,subsets);
    int p2 = find(n2,subsets);
    if(subsets[p1].rank<subsets[p2].rank){
        subsets[p1].parent=p2;
    }else if(subsets[p1].rank>subsets[p2].rank){
        subsets[p2].parent=p1;
    }else{
        subsets[p1].parent=p2;
        subsets[p2].rank++;
    }
}

bool isCyclic(vector<int> adj[], int V){
   unordered_map<pair<int, int>, int, hash_pair> m; 
   Node *subsets = new Node[V];
   for(int i=0;i<V;i++){
       subsets[i].parent=-1;
       subsets[i].rank=0;
   }
   
   for(int u=0;u<V;u++){
       for(int v:adj[u]){
           // Take care for self loop && parallel edge 10-4 && 4-10 cycle
           if(!m.count({min(u,v),max(u,v)})){
               int p1 = find(u,subsets);
               int p2 = find(v,subsets);
               if(p1==p2) return true;
               Union(u,v,subsets);
           }
           m[{min(u,v),max(u,v)}]++;
           if(m[{min(u,v),max(u,v)}]>2) return true; // Parallel edges 
       }
   }

   return false;
   
}

// Alternate: More modular code, DisjointSet Class

/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const{ 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

class DisjointSet {
    int V;
    int *parent;
    int *rank;
public:
    DisjointSet(int V){
        this->V=V;
        parent = new int[V];
        fill(parent,parent+V,-1);
        rank = new int[V]{0};
    }
    int find(int node){ 
        if(parent[node]==-1) return node;  
        // Path Compression
        return parent[node]=find(parent[node]);
    }
    void Union(int n1,int n2){ // since union is a keyword
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


bool isCyclic(vector<int> adj[], int V){
   unordered_map<pair<int, int>, int, hash_pair> m; 
   DisjointSet ds(V);

   for(int u=0;u<V;u++){
       for(int v:adj[u]){
           // Take care for self loop && parallel edge 10-4 && 4-10 cycle
           if(!m.count({min(u,v),max(u,v)})){
               int p1 = ds.find(u);
               int p2 = ds.find(v);
               if(p1==p2) return true;
               ds.Union(u,v);
           }
           m[{min(u,v),max(u,v)}]++;
           if(m[{min(u,v),max(u,v)}]>2) return true; // Parallel edges 
       }
   }

   return false;
   
}