// Approach 1: Iterative

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::reverseList(ListNode* head) {
    ListNode *prev=NULL,*curr=head;
    while(curr!=NULL){
        ListNode* next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

/***************************************************************************************************************************/

// Approach 2: Recursive

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::reverseList(ListNode* head) {
    if(!head||!head->next) return head;
    ListNode *revHead = reverseList(head->next);
    // tail of rev LL is head->next
    head->next->next = head;
    head->next = NULL;
    return revHead;    
}
