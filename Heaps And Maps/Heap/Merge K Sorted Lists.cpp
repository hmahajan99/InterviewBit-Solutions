// Merge k sorted linked lists and return it as one sorted list.

// Approach 1: Brute force
// A Simple Solution is to initialize result as first list. 
// Now traverse all lists starting from second list. 
// Insert every node of currently traversed list into result in a sorted way. 
// Time complexity of this solution is O(N^2) where N is total number of nodes.


/***************************************************************************************************************************/

// Approach 2: Better brute force
// Lets keep a pointer for every linked list. 
// At any instant you will need to know the minimum of elements at all pointer. 
// Following it you will need to advance that pointer. 
// Can you do this in complexity better than O(K) ? => MIN HEAP
// Time complexity of this solution is O(N*K) 

/***************************************************************************************************************************/

// Approach 3: Using Min Heap
// If push all nodes in heap => O(NlogN)
// Push only the heads of the K sorted linked lists in heap => O(NlogK)
// NOTE: Try to keep size of heap small

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class NodeCompare{
    public:
    bool operator()(ListNode* A,ListNode* B){
        return A->val>B->val; // MIN HEAP
    }
} ;

void insert(ListNode* &head,ListNode* &tail,ListNode* node){
    if(head==NULL){
        head=tail=node;
    }else{
        tail->next=node;
        tail=tail->next;
    }
} 

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {

    // Custom Class in Priority Queue
    priority_queue <ListNode*, vector<ListNode*>, NodeCompare > pq;
    
    for(ListNode* headK:A){
        if(headK) pq.push(headK);
    }
    
    ListNode *head=NULL,*tail=NULL;
    while(!pq.empty()){
        ListNode *top=pq.top();
        pq.pop();
        insert(head,tail,top);
        if(top->next) pq.push(top->next);
    }
    
//    if(tail) tail->next=NULL;
    
    return head;
    
}


/***************************************************************************************************************************/

// Approach 4: Using Divide and conquer
// Solve the problem for first k/2 and last k/2 list. Then you have 2 sorted lists. Then simiply merge the lists.

// Say K lists, n size each
// T(K) = 2 T(K/2) + K*n
// Time => O(n*klogk) 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void insert(ListNode* &head,ListNode* &tail,ListNode* A){
    if(head==NULL){
        head=tail=A;
    }else{
        tail->next=A;
        tail=tail->next;
    }
} 
 
ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
    
    ListNode *head=NULL,*tail=NULL;
    while(A!=NULL&&B!=NULL){
        if(A->val<B->val){
            insert(head,tail,A);
            A=A->next;
        }else{
            insert(head,tail,B);
            B=B->next;
        }
    }
    
    if(A!=NULL){
        insert(head,tail,A);
    }
    
    if(B!=NULL){
        insert(head,tail,B);
    }
    
    return head;
    
}

void mergeKUtil(vector<ListNode*> &A,int si,int ei){
    // Base case
    if(si>=ei) return;
    
    int mid=(si+ei)/2;
    // Recursive calls
    mergeKUtil(A,si,mid);
    mergeKUtil(A,mid+1,ei);
    
    // Merge A[si] & A[mid+1] and store merged list in A[si]
    A[si]=mergeTwoLists(A[si],A[mid+1]); 
    
}

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    mergeKUtil(A,0,A.size()-1);
    return A[0];
}
