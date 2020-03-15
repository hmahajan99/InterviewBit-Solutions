// Given a matrix of integers A of size N x M in which each row is sorted.
// Find an return the overall median of the matrix A.
// N*M is odd

// Approach 1: Brute force
// Store all the elements of the given matrix in an array of size r*c. 
// Then we can sort the array and find the median element in O(r*clog(r*c))

/***************************************************************************************************************************/

// Approach 2: Binary search
// In a row you can binary search to find how many elements are smaller than a value X in O(log M).
// Say k = N*M/2. We need to find (k + 1)^th smallest element.
// We can use binary search on answer. In O(N log M), we can count how many elements are smaller than X in the matrix.
// So, we use binary search on interval [1, INT_MAX]. So, total complexity is O(30 * N log M).

// NOTE: Keep answer variable and update it if mid is a valid answer and then do either s=mid+1 or e=mid-1

int count(int num,vector<vector<int> > &A){
    int n=A.size();
    int ans=0;
    for(int i=0;i<n;i++){
        ans += upper_bound(A[i].begin(),A[i].end(),num)-A[i].begin();
    }        
    return ans;
}

int Solution::findMedian(vector<vector<int> > &A) {

    int n=A.size(),m=A[0].size();

    int s=INT_MAX,e=INT_MIN;
    for(int i=0;i<n;i++){
        s=min(s,A[i][0]);
        e=max(e,A[i][m-1]);
    }
    
    int d = (n*m)/2 + 1;
    int ans;
    
    while(s<=e){
        int mid=(s+e)/2;                         
        int c = count(mid,A);
        if(c>=d){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    
    return ans;
}

/***************************************************************************************************************************/

// Approach 3: Using Min heap 
// Push 1st elements of all the rows and find the kth smallest element
// Time Complexity: O(NM*logN)

// IMP NOTE!!!!=> TIME COMPLEXITY OF BUILDING HEAP i.e n or nlogn ?
// If you have an array of size n and you want to build a heap from all items at once, 
// Floyd's algorithm can do it with O(n) complexity. 
// See Building a heap. This corresponds to the std::priority_queue constructors that accept a container parameter.
// If you have an empty priority queue to which you want to add n items, one at a time, then the complexity is O(n * log(n)).
// So if you have all of the items that will go into your queue before you build it, then the first method will be more efficient. 
// You use the second method--adding items individually--when you need to maintain a queue: adding and removing elements over some time period.


int Solution::findMedian(vector<vector<int> > &A) {

    int N=A.size(),M=A[0].size();
    // Min Heap <element,row>
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> i(N,0); // one index for each row
    
    for(int j=0;j<N;j++) pq.push({A[j][0],j});
    
    for(int j=1;j<=(N*M)/2;j++){
        pair<int,int> p = pq.top();
        pq.pop();
        int row = p.second;
        i[row]++;
        if(i[row]<M) pq.push({A[row][i[row]],row});
    }
    
    return pq.top().first;
}
