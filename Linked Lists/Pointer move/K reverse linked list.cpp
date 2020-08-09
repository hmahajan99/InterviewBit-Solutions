// Given a singly linked list and an integer K, reverses the nodes of the list K at a time and returns modified linked list.
// NOTE : The length of the list is divisible by K 

// Approach 1 : Iterative approach

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseKLength(ListNode* head,int K){
    ListNode *prev=NULL,*curr=head,*next;
    for(int i=1;i<=K;i++){
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head->next=next; // head of curr LL would be tail of rev LL 
    return prev;
} 
 
 
ListNode* Solution::reverseList(ListNode* head, int K) {
    
    if(head==NULL||head->next==NULL||K==1) return head;
    
    // Using DUMMY NODE
    ListNode *dummyStart=new ListNode(0);
    dummyStart->next=head;
    
    // temp stands one node behind list to reverse
    ListNode *temp=dummyStart;
    while(temp->next!=NULL){
        ListNode *newTemp = temp->next;
        ListNode *headRev = reverseKLength(temp->next,K);
        temp->next = headRev;
        temp = newTemp;
    }
    
    return dummyStart->next;
    
}

/***************************************************************************************************************************/

// Approach 2 : Recursive Approach

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* reverseKLength(ListNode* head,int K){
    ListNode *prev=NULL,*curr=head,*next;
    for(int i=1;i<=K;i++){
        next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    head->next=next; // head of curr LL would be tail of rev LL 
    return prev;
} 
 
 
ListNode* Solution::reverseList(ListNode* head, int K) {
    
    if(head==NULL||head->next==NULL||K==1) return head;
    
    ListNode *revHead = reverseKLength(head,K);
    head->next = reverseList(head->next,K); // head of curr LL would be tail of rev LL
    return revHead;

}