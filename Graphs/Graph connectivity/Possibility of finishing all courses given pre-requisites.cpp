// There are a total of A courses you have to take, labeled from 1 to A.
// Some courses may have prerequisites, for example to take course 2 you have to first take course 1, which is expressed as a pair: [1,2].
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
// Input: A = 2, B = [1, 2], C = [2, 1]
// Output: 0
// Explanation: It is not possible to complete all the courses.

// Approach: Detecting cycle in a directed graph
// Consider a graph with courses from 1 to N representing the nodes of the graph and each prerequisite pair [u, v] correspond to a directed edge from u to v.
// It is obvious that we will get several disjoint components of the graph.
// When is it possible for you to finish all the courses? 
// The problem reduces down to finding a directed cycle in the whole graph. If any such cycle is present, it is not possible to finish all the courses.

#include<list>
class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int v){
        V=v;
        adj=new list<int>[v];
    }
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
    bool topoSort(){
        int *indegree = new int[V]{0};
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
        return count==V; // => means no cycle (there can be disjoint components in the graph)
    }
};

int Solution::solve(int A, vector<int> &B, vector<int> &C) {

    Graph g(A);
    for(int i=0;i<B.size();i++){
        g.addEdge(B[i]-1,C[i]-1);
    }
    return g.topoSort();
    
}
