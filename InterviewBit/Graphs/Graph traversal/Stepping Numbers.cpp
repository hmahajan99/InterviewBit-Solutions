// Approach 1: Brute force

bool isStepping(int n){
    int prev=n%10;
    n/=10;
    while(n>0){
        int curr=n%10;
        n/=10;
        if(abs(curr-prev)!=1) return false;
        prev=curr;
    }
    return true;
}

vector<int> Solution::stepnum(int A, int B) {

    vector<int> ans;
    for(int n=A;n<=B;n++){
        if(isStepping(n)) ans.push_back(n);
    }
    return ans;
}

/***************************************************************************************************************************/

// Approach 2: Using BFS traversal
// Every single digit number is considered as a stepping Number, so bfs traversal for every digit will give all the stepping numbers starting from that digit.
// Do a bfs/dfs traversal for all the numbers from [0,9]
// In this ques have to do BFS since need stepping numbers in sorted order. If do DFS then sort numbers at end.
// For node 0, no need to explore neighbors during BFS traversal since it will lead to 01, 012, 010 and these will be covered by the BFS traversal starting from node 1.

vector<int> Solution::stepnum(int A, int B) {
    vector<int> ans;
    queue<int> q ({0,1,2,3,4,5,6,7,8,9});  // for(int stepNum=0;stepNum<=9;stepNum++) q.push(stepNum);
    while(!q.empty()&&q.front()<=B){
        int stepNum = q.front();
        q.pop();
        if(A<=stepNum) ans.push_back(stepNum);
        if(stepNum==0) continue;
        int lastDigit = stepNum%10;
        if(lastDigit>0) q.push(stepNum*10+lastDigit-1);
        if(lastDigit<9) q.push(stepNum*10+lastDigit+1);
    }
    return ans;
}