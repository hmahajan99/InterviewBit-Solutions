// Bucket - Depth first search

// Given an arbitrary unweighted rooted tree which consists of N nodes.
// The goal of the problem is to find largest distance between two nodes in a tree.
// Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree).
// The nodes will be numbered 0 through N - 1.
// The tree is given as an array A, there is an edge between nodes A[i] and i (0 <= i < N). 
// Exactly one of the i's will have A[i] equal to -1, it will be root node.

// Approach 1: Like calculating diameter of a generic N-ary tree instead of a binary tree
// Diameter - Max Distance b/w any 2 nodes

pair<int,int> heightDiameter(int root,unordered_map<int,vector<int>> &m){
    if(!m.count(root)){
        //Leaf
        return {1,0};
    }
    
    int maxSubTreeDiameter=-1;
    priority_queue<int> pq; // max heap, stores height of subtrees

    vector<int> children = m[root];
    for(int i=0;i<children.size();i++){
        pair<int,int> p = heightDiameter(children[i],m);
        maxSubTreeDiameter=max(maxSubTreeDiameter,p.second);
        pq.push(p.first);
    }
    
    int maxH=pq.top();
    pq.pop();

    int currentDiameter=maxH; // In case of skewed tree, Second maximum height = 0
    if(children.size()>=2){
        // Max height + Second maximum height
        currentDiameter=maxH+pq.top();
    }
    currentDiameter = max(currentDiameter,maxSubTreeDiameter);
    
    return {1+maxH,currentDiameter};
}

int Solution::solve(vector<int> &A) {
    
    unordered_map<int,vector<int>> m; // node -> vector<children>
    for(int i=0;i<A.size();i++){
        m[A[i]].push_back(i);
    }
    
    return heightDiameter(m[-1][0],m).second;
   
}

/***************************************************************************************************************************/

// Approach 2: Using 2 BFS
// We can find longest path using two BFSs. The idea is based on the following fact: If we start BFS from any node u and find a node with the longest distance from u, it must be an end point of the longest path.
// First BFS to find an end point of the longest path and second BFS from this end point to find the actual longest path. 

// 1) pick any node u
// 2) find the node which is farthest from u, call it x 
// 3) find the node which is farthest from x, call it q 
// The answer will be the length of a path from x to q.

// Proof of correctness:
// The crucial step is to prove that x will be one of the endpoints of the path with maximal length (note that there might be more than one such path). 
// If it is, then the longest path from x will be the longest path in the tree.
// Let’s prove it by contradiction: 
// Assume there is a strictly longer path between s and t, neither of which is x. 
// Let h be a node which is closest to u among the nodes on a path between s and t.
// h is LCA(s,t) 
// Then there are two cases:
// 1) h is on path between u and x

//     u
//     |
//     |
//     |
//     h   x
//    / \ /
//   /   *
//  /     \
// s       t 

// 2) h is not on path between u and x

//     u
//     |
//     *---x
//     |
//     h
//    / \
//   /   \
//  /     \
// s       t

#include<list>

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int v){
        V=v;
        adj = new list<int>[V];
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pair<int,int> bfs(int src){
        unordered_set<int> vis;
        queue<pair<int,int>> q;
        vis.insert(src);
        q.push({src,0});
        pair<int,int> maxNodeDist = make_pair(src,0);
        while(!q.empty()){
            pair<int,int> node = q.front();
            q.pop();
            if(node.second>maxNodeDist.second) maxNodeDist = node;
            for(int neighbour:adj[node.first]){
                if(!vis.count(neighbour)){
                    vis.insert(neighbour);
                    q.push({neighbour,node.second+1});
                }
            }
        }
        return maxNodeDist;
    }
};


int Solution::solve(vector<int> &A) {

    int V = A.size();
    Graph g(V);
    for(int i=0;i<V;i++){
        if(A[i]!=-1) g.addEdge(A[i],i);
    }
    pair<int,int> px = g.bfs(0);
    pair<int,int> pq = g.bfs(px.first);
    return pq.second;
    
}
