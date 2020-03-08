// The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem (Dynamic Programming, optimal substructure property)
// Time Complexity: O(V^3)
// We can use Dijskstra’s shortest path algorithm for finding all pair shortest paths by running it for every vertex. Time complexity (V^3).
// Floyd Warshall works for negative edge but no negative cycle, whereas Dijkstra’s algorithm don’t work for negative edges.
// Time Complexity of Dijkstra’s Algorithm: The time complexity for the matrix representation is O(V^2). For adjacency list representation O(ELogV) algorithm.
// Time Complexity of Floyd Warshall: O(V^3)

// Can use Floyd Warshall for Detecting negative cycle 

#define INF (int)(1e7)
using namespace std;

void floydWarshall(int** A,int v){
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
            }
        }
    }
    
    // Print Soln
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            (A[i][j]==INF)?(cout<<"INF "):(cout<<A[i][j]<<" ");
        }
        cout<<"\n";
    }
    
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    int v;
	    cin>>v;
      int** adjMatrix;
      adjMatrix = new int*[v];
      for(int i=0;i<v;i++){
          adjMatrix[i]=new int[v];
      }
    	for(int i=0;i<v;i++){
    	    for(int j=0;j<v;j++){
    	        cin>>adjMatrix[i][j];
    	    }
    	}
    	floydWarshall(adjMatrix,v);
	}
	return 0;
}