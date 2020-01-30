// Approach : Keeping the original order i.e stable approach

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void insert(ListNode* &head,ListNode* &tail,ListNode* node){
    if(head==NULL){
        head=tail=node;
    }else{
        tail->next=node;
        tail=tail->next;
    }
} 
 
ListNode* Solution::partition(ListNode* head, int X) {
    
    ListNode *h1=NULL,*t1=NULL,*h2=NULL,*t2=NULL;
    while(head!=NULL){
        if(head->val<X){
            insert(h1,t1,head);
        }else{
            insert(h2,t2,head);
        }
        head=head->next;
    }
    
    if(t1) t1->next=h2;
    if(t2) t2->next=NULL;
    
    return h1 ? h1 : h2;
}

/***************************************************************************************************************************/

// Approach 2 : If we don’t care about making the elements of the list “stable” then we can instead rearrange the elements by growing the list at the head and tail.
// In this approach, we start a “new” list (using the existing nodes). 
// Elements bigger than the pivot element are put at the tail and elements smaller are put at the head. Each time we insert an element, we update either the head or tail.

