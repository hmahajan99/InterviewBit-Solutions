// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

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
        
        if(A->next==NULL || A->val!=A->next->val){
            //insert A
            insert(head,tail,A);
            A=A->next;
        }else{
            // skip A-val
            int val = A->val;
            while(A!=NULL&&A->val==val){
                ListNode* temp = A;
                A=A->next;
                delete temp;
            }
        }
    }
    
    if(tail) tail->next=NULL;
    
    return head;

}