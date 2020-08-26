// Bucket - Graph hashing

// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

// Approach 1: BFS
// Before we continue, we first need to make sure if the graph is directed or not. If you notice how Node is defined above, it is quite obvious that the graph is a directed graph. 
// For example, A can have a neighbor called B. Therefore, we may traverse from A to B. 
// An undirected graph implies that B can always traverse back to A. Is it true here? No, because whether B could traverse back to A depends if one of B’s neighbor is A.
// The fact that B can traverse back to A implies that the graph may contain a cycle.
// You must take extra care to handle this case.


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> m;
    queue<UndirectedGraphNode*> q;
    m[node]=new UndirectedGraphNode(node->label);
    q.push(node);
    while(!q.empty()){
        UndirectedGraphNode* front=q.front();
        q.pop();
        for(UndirectedGraphNode* neighbour : front->neighbors){
            if(!m.count(neighbour)){
                m[neighbour]=new UndirectedGraphNode(neighbour->label);
                q.push(neighbour);
            }
            m[front]->neighbors.push_back(m[neighbour]);
        }
    }
    return m[node];
}

/***************************************************************************************************************************/

// Approach 2: DFS

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

void dfs(UndirectedGraphNode *node,unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> &m){
    m[node]=new UndirectedGraphNode(node->label);
    for(UndirectedGraphNode* neighbour : node->neighbors){
        if(!m.count(neighbour)){
            dfs(neighbour,m);
        }
        m[node]->neighbors.push_back(m[neighbour]);
    }
}
 
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> m;
    dfs(node,m);
    return m[node];
}
