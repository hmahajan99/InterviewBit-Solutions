// How many minimum numbers from fibonacci series are required such that sum of numbers should be equal to a given Number N?
// Note : repetition of number is allowed.
// Example:
// N = 4
// Fibonacci numbers : 1 1 2 3 5 .... so on
// here 2 + 2 = 4 
// so minimum numbers will be 2 

// This problem is basically coin change problem with coins having Fibonacci values. By taking some examples, we can notice that With Fibonacci coin values Greedy approach works

// Approach 1 : BFS
// Can you apply shortest path algorithm for finding solution
// start vertex = 0
// end vertex = N
// Ans = shortest path from start vertex to end_vertex
// Can you define moves ??
// Lets take an exmaple:
// N = 10
// Fibonacci elements : 1 1 2 3 5 8 ... so on
// Assume:
// start vertex = 0
// end vertex = 10
// Lets do a Breadth First Search. 
// we can go from 0 to 1 2 3 5 8 .... so on
// So, there will be an edge of weight 1 from 0 to vertices 1, 2, 3, 5, 8 ( We don't care about vertices > 10 for this case ).
// Then from 1 2 3 5 8 
// we can go to 4 6 9 7 10  ( We do not go to 3 again, because its already visited ). 
// Thus, we reach at 10 in only 2 step so our answer will be 2
// How would this approach work for big numbers ?

/***************************************************************************************************************************/

// Approach 2 : DP
// Lets say you knew the minimum numbers required for all numbers < N. Can you use that to figure out the answer for N ?
// ANSWER[N] = MIN ( ANSWER(N - FIB[I]) for I = 1 to X where FIB[X + 1] > N and FIB[X] <= N )
// Does this approach work though if the numbers are really big ?

/***************************************************************************************************************************/

// Approach 3 :Greedy

// Greedy is the winner here.
// Because of how the fibonacci numbers behave, the approach of picking the largest number less than or equal to the number N works.
// So, an approach like :
// solve(N) : 
//   find F as the largest Fib <= N. 
//   return solve(N-F) + 1

int Solution::fibsum(int A) {

    //Suppose you decomposed 64 into its fibonnaci addends: 64 = 55 + 8 + 1.
    //Any other decomposition would further subdivide the existing addends (55,8), thus giving you a larger set. 
    //Therefore, on some level this is the minimum set that you could obtain, and it is through the greedy method.    

    vector<int> fib = {1,1};
    while(fib.back()<=A){
        int n = fib.size();
        fib.push_back(fib[n-1]+fib[n-2]);  
    }
    
    int n = fib.size();
    int j=n-1;
    int ans=0;
    while(A>0){
        if(fib[j]<=A){
            ans++;
            A-=fib[j];
        }else{
            j--;
        }
    }
    return ans;
    
}
