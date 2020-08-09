// Merge two sorted linked lists and return it as a new list.
// The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

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
 
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
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

    // NOTE : While not needed here
    while(A!=NULL){
        insert(head,tail,A);
        A=A->next;
    }
    while(B!=NULL){
        insert(head,tail,B);
        B=B->next;
    }
    
 // if(tail) tail->next=NULL;
 // tail->next=NULL Not needed in this ques bcoz tail would already have next as NULL
    
    return head;
    
}

/***************************************************************************************************************************/

// Approach 2 : Minor optimization

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
 
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
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
    
    // NOTE : While not needed here, since adds all the remaining LL
    if(A!=NULL){
        insert(head,tail,A);
    }
    if(B!=NULL){
        insert(head,tail,B);
    }
    
 // if(tail) tail->next=NULL;
 // tail->next=NULL Not needed in this ques bcoz tail would already have next as NULL
    
    return head;
    
}