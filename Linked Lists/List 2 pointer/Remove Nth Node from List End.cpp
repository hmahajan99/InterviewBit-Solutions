// Given a linked list, remove the nth node from the end of list and return its head.

// Approach 1: Remove (len-N+1)th node from start 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int len(ListNode* head){
    int l=0;
    ListNode* temp=head;
    while(temp){
        l++;
        temp=temp->next;
    }
    return l;
}

ListNode* getIthNode(ListNode* head,int i){
    // Return ith node from start
    ListNode* temp=head;
    for(int k=1;k<=i-1;k++) temp=temp->next;
    return temp;
}

ListNode* Solution::removeNthFromEnd(ListNode* head, int N) {
    
    int l=len(head);
    
    if(N>=l){
        ListNode* temp = head->next;
        delete head;
        return temp;
    }
    
    ListNode* temp = getIthNode(head,l-N);
    ListNode* d = temp->next;
    temp->next=temp->next->next;
    delete d;
    return head;
    
}

/***************************************************************************************************************************/

// Approach 2 : Without calculating length of LL.
// Make the first pointer go n nodes. 
// Then move the second and first pointer simultaneously. 
// This way, the first pointer is always ahead of the second pointer by n nodes. 
// So when first pointer reaches the end, you are on the node to be removed.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* getIthNode(ListNode* head,int i){
    ListNode* temp=head;
    for(int k=1;k<=i-1;k++){
      if(!temp) return NULL; // Important here as N can be > than len of LL
      temp=temp->next;  
    } 
    return temp;
}
 
ListNode* Solution::removeNthFromEnd(ListNode* head, int N) {
    ListNode *temp1=head;
    ListNode *temp2=getIthNode(head,N+2);
    if(!temp2){
        ListNode *newHead = head->next;
        delete head;
        return newHead;
    }
    
    while(temp2){
        temp2=temp2->next;
        temp1=temp1->next;
    }
    
    ListNode *d = temp1->next;
    temp1->next = temp1->next->next;
    delete d;
    
    return head;    
}
