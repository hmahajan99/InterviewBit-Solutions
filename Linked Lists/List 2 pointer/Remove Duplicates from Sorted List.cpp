// Approach 1 : Single Loop

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
 
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    ListNode *head=NULL,*tail=NULL;
    int val;
    while(A!=NULL){
        if(head==NULL||A->val!=val){
            insert(head,tail,A);
            val=A->val;
            A=A->next;
        }else{
            ListNode* temp = A->next;
            delete A;
            A = temp;
        }
    }
    // IMPORTANT TO SET tail->next=NULL
    if(tail) tail->next=NULL;
    return head;
    
}

/***************************************************************************************************************************/

// Approach 2 : Nested Loop

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
 
ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    ListNode *head=NULL,*tail=NULL;
    while(A!=NULL){
        while(A->next&&A->next->val==A->val){
            ListNode *temp = A->next;
            A->next=A->next->next;
            delete temp;
        }        
        insert(head,tail,A);
        A=A->next;
    }
    
    if(tail) tail->next=NULL;
    return head;
    
}