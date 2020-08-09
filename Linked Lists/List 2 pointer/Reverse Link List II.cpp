// Reverse a linked list from position m to n. Do it in-place and in one-pass.
// Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.

// Approach : Using DUMMY NODE

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* getIthNode(ListNode* head,int i){
    // Return ith node from start
    ListNode* temp=head;
    for(int k=1;k<=i-1;k++) temp=temp->next;
    return temp;
}

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
 
ListNode* Solution::reverseBetween(ListNode* head, int M, int N) {

    if(M==N) return head;
    
    // Using Dummy Node
    ListNode *dummyStart = new ListNode(0);
    dummyStart->next=head;
    
    ListNode *temp=getIthNode(dummyStart,M);

    // Now temp points to node prev to pos M
    temp->next = reverseKLength(temp->next,N-M+1);

    return dummyStart->next;
    
}