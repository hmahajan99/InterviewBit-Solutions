// You are given an integer N. You have to find smallest multiple of N which consists of digits 0 and 1 only. 
// Since this multiple could be large, return it in form of a string.
// For N = 55, 110 is smallest multiple consisting of digits 0 and 1.
// For N = 2, 10 is the answer.

// Approach 1: Brute force
// We multiply N with positive numbers and then check it consists of only ones and zeros.

/***************************************************************************************************************************/

// Approach 2: Time O(N)

// A recursive solution where we build all possible numbers consists of digits ones and zeroes only.
// For example, something like:

//         1
//        / \
//       /   \ 
//      /     \ 
//     /       \ 
//    10       11   
//   /  \     /  \
//  /    \   /    \  
// 100  101  110  111
// We can merge nodes in this based on values with modulo N in such a way that we don’t visit all possible states.
// Let’s represent our numbers as strings here. Now, consider there are N states, where i’th state stores the smallest string which when take modulo with N gives i. 
// Our aim is to reach state 0. Now, we start from state “1” and at each step we have two options, either to append “0” or “1” to current state. 
// We try to explore both the options, but note that if I have already visited a state, why would I visit it again? 
// It already stores the smallest string which achieves that state and if I visit it again with a new string it will surely have more characters than already stored string.
// So, this is basically a BFS on the states. We’ll visit a state atmost once, hence overall complexity is O(N). 
// Interesting thing is that I need not store the whole string for each state, I can just store the value modulo N and I can easily see which two new states I am going to.
// But, how do we build the solution?
// If I reach a state x, I store two values
// From which node I arrived at node x from. Say this is node y.
// What(0 or 1) did I append at string at node y to reach node x
// Using this information, I can build my solution by repeatedly going to parents starting from node 0.

string Solution::multiple(int N) {

    if(N==0||N==1) return to_string(N);

    int *parent=new int[N];
    char *choice=new char[N];    
    queue<int> q;  
    for(int i=0;i<N;i++){
      parent[i]=-1;  
    } 

    parent[1]=INT_MIN;
    choice[1]='1';
    q.push(1);

    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(node==0){
            string ans="";
            while(node!=INT_MIN){
                ans+=choice[node];
                node=parent[node];
            }
            reverse(ans.begin(),ans.end());
            // NOTE : IMPORTANT USE DELETE ELSE GETTING MLE MEM EXCEEDED IMP!!!!!!!!!
            delete [] parent; 
            delete [] choice;
            return ans;
        }
        int x = (node*(10%N))%N;
        if(parent[x]==-1){ // not visited
            parent[x]=node;
            choice[x]='0';
            q.push(x);
        }
        int y = (x+1)%N;
        if(parent[y]==-1){
            parent[y]=node;
            choice[y]='1';
            q.push(y);
        }
    }

}
