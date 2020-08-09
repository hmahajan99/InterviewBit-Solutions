// Given two arrays A & B of size N each.
// Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

// Approach 1 : Brute force is to find all combinations pair sum O(N Square) and return top N max elements.
// Insert all possible combinataions into max heap and take out n elements
// Time - O(n^2)


/***************************************************************************************************************************/

// Approach 2: Sorting + Max Heap + Map/Set
// Sort both the arrays in ascending order.
// Let us take priority queue (heap).
// First max element is going to be the sum of the last two elements of array A and B i.e. (A[n-1] + B[n-1]).
// Insert that in heap with indices of both array i.e (n-1, n-1).
// Start popping from heap (n-iterations).
// And insert the sum (A[L-1]+A[R]) and (A[L]+B[R-1]).
// Take care that repeating indices should not be there in the heap (use map for that).

class Node{
    public:
    int sum,i,j;
    Node(int sum,int i,int j){
        this->sum=sum;
        this->i=i;
        this->j=j;
    }

};

class NodeCompare{
  public:
    bool operator()(Node n1,Node n2){
        return n1.sum<n2.sum; // MAX HEAP
    }
  
};

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n=A.size();

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    vector<int> ans;
    // IMP NOTE: CUSTOM CLASS IN PRIORITY QUEUE
    priority_queue<Node,vector<Node>,NodeCompare> pq; // Max Heap & Custom Class => Need comparator
    set<pair<int,int>> s; // Visited set, so we don't push same pair again

    int i = n-1,j=n-1; 
    pq.push(Node(A[i]+B[j],i,j));
    s.insert(make_pair(i,j));
    while(n--){
        Node t = pq.top();
        pq.pop();
        ans.push_back(t.sum);
        if(!s.count(make_pair(t.i-1,t.j))){
            pq.push(Node(A[t.i-1]+B[t.j],t.i-1,t.j));
            s.insert(make_pair(t.i-1,t.j));
        }
        if(!s.count(make_pair(t.i,t.j-1))){
            pq.push(Node(A[t.i]+B[t.j-1],t.i,t.j-1));
            s.insert(make_pair(t.i,t.j-1));
        }
    }
    
    return ans;
    
}