// Given a 3 x A board, find the number of ways to color it using at most 4 colors such that no 2 adjacent boxes have same color.
// Diagonal neighbors are not treated as adjacent boxes.
// Return the ways modulo 10^9 + 7 as the answer grows quickly.

// Input 1: A = 1
// Output 1: 36

// Approach 1: Top Down DP, 4 states

// Let us first color a given column with three colors such that no two adjacent boxes have the same color. 
// A simple combinatorics reveal that there are 36 ways to do so. (4C3*3! + 4C2*2)
// Let’s say colors are: {0,1,2,3}
// Triplets of color: {0,1,2} , {3,1,2}, {4,1,2}, …..

// Now, suppose that we color the given column with one of these triplets. We scan color the next column with the triplets of color that do not contradict our coloring scheme.
// E.g.:	0 |	1	 	 	 
//      	1 |	3	 	 	 
//      	2 |	0	 	 	 
// Here, we can color third column using triplets that go well with the triplet {1,3,0}. These are {0,1,2}, {2,1,3}, ……
// This can be coded using a simple dynamic programming approach.
// Recurrence:
// {x,y,z} = triplet of color used to paint nth column in the order given. (1st row: i, 2nd row: j, …. }
// solve(x,y,z,n) = no. of ways to color a 3xn board such that nth column is painted with color triplet {x,y,z}
// solve(x,y,z,n) = [sum over (x1,y1,z1) ] ( solve(x1,y1,z1,n-1) ) such that {x,y,z} and {x1,y1,z1} go well with each other.

#define M (int)(1e9+7)

int memo[100005][4][4][4];

int numWays(int i,int x,int y,int z,int N){
    if(i==N) return 1;

    if(memo[i][x][y][z]!=-1) return memo[i][x][y][z];
    
    long long ans=0;
    for(int x1=0;x1<=3;x1++){
        for(int y1=0;y1<=3;y1++){
            for(int z1=0;z1<=3;z1++){
                // If new triplet is valid & compatible with current triplet
                if(x1!=y1&&y1!=z1&&x!=x1&&y!=y1&&z!=z1){
                    ans += numWays(i+1,x1,y1,z1,N);
                    ans %= M;
                }
            }
        }
    }
    
    return memo[i][x][y][z] = ans;
    
}

int Solution::solve(int N) {
    for(int i=1;i<=N;i++){
        for(int x=0;x<=3;x++){
            for(int y=0;y<=3;y++){
                for(int z=0;z<=3;z++){
                    memo[i][x][y][z] = -1;
                }
            }
        }
    }
    
    long long ans=0;
    for(int x=0;x<=3;x++){
        for(int y=0;y<=3;y++){
            for(int z=0;z<=3;z++){
                if(x!=y&&y!=z){
                    // Color 1st row with x,y,z
                    ans += numWays(1,x,y,z,N);
                    ans %= M;
                }
            }
        }
    }
    
    return ans;
}


/***************************************************************************************************************************/

// Approach 2: Top Down DP, 2 states
// Could represent {x,y,z} as a colorCode = x + 4y + 16z
// Also could add i=0 as a dummy row so dont have to use nested loop in calling function

/***************************************************************************************************************************/

// Approach 2: Bottom Up DP, 4 states

#define mod 1000000007
#define ll long long

struct triplet{
	int x, y, z;
};

vector<triplet> trip;  //vector of 36 triplets

// IMP!!!! => DECLARE DP AS GLOBAL TO AVOID RUNTIME ERROR/MEMORY ISSUES
int dp[4][4][4][100005]; // dp[i][j][k][n] = ways to color nth col colored with {i,j,k} in grid having columns 1,2,....n

void fillTriplets(){
	//trip vector contain the triplets of color that can be used to paint a certain column
  trip.clear();
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			for(int k=0; k<4; k++){
				if(i!=j&&j!=k) trip.push_back({i,j,k});
			}
		}
	}
}


bool isCompatible(const triplet& t1,  const triplet& t2){
	//check if triplets t1 and t2 are compatible
	return t1.x!=t2.x && t1.y!=t2.y && t1.z!=t2.z;
}

int Solution::solve(int N){
    fillTriplets();
	if(N<=0) return -1;
	
    //Bottom-up dp
	for(int n=1;n<=N;n++){
		for(int i=0; i<36; i++){
			if(n==1) dp[trip[i].x][trip[i].y][trip[i].z][n] = 1; // Base case
			else{
				ll temp = 0;
				for(int j=0;j<36;j++){
					if(isCompatible(trip[i], trip[j])){
						temp += dp[trip[j].x][trip[j].y][trip[j].z][n-1];
						temp %= mod;
					}
				}
				dp[trip[i].x][trip[i].y][trip[i].z][n] = temp;
			}
		}
	}
	
	ll ans = 0;
	for(int i=0;i<trip.size();i++){
		ans = (ans + dp[trip[i].x][trip[i].y][trip[i].z][N])%mod;
	}
	return ans;
}
