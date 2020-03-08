// Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary the task is to complete the function which returns a string denoting the order of characters in the language.0
// Examples:
// Input:  Dict[] = { "baa", "abcd", "abca", "cab", "cad" }, k = 4
// Output: Function returns "bdac"
// Here order of characters is 'b', 'd', 'a', 'c'
// Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.

//User function Template for C++
/*The function should return a string denoting the 
order of the words in the Alien Dictionary */

class Graph{
    int V;
    unordered_map<char,list<char>> adj;
public:
    void addEdge(char u,char v){
        adj[u].push_back(v);
    }
    string topoSort(){
        unordered_map<char,int> inDegree;
        for(auto p:adj){
            for(auto v:p.second) inDegree[v]++;
        }
        queue<char> q;
        for(auto p:adj){
            if(!inDegree.count(p.first)) q.push(p.first);
        }
        string ans="";
        while(!q.empty()){
            char ch = q.front();
            q.pop();
            ans += ch;
            for(char neighbour:adj[ch]){
                inDegree[neighbour]--;
                if(!inDegree[neighbour]) q.push(neighbour);
            }
        }
        return ans;
    }
};

string printOrder(string dict[], int N, int k){
   Graph g;
   for(int i=0;i<N-1;i++){
       string s1=dict[i],s2=dict[i+1];
       int l = min(s1.size(),s2.size());
       for(int i=0;i<l;i++){
           if(s1[i]!=s2[i]){
              g.addEdge(s1[i],s2[i]);
              break;
           } 
       }
   }
   return g.topoSort();
}