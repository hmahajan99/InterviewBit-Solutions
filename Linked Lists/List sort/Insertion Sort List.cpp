// Sort a linked list using insertion sort.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void insert(ListNode* &head,ListNode* &tail,ListNode* node){
    
    // Insert in beginning
    if(node->val<=head->val){
        node->next=head;
        head=node;
        return;
    }
    
    // Insert in middle
    ListNode* temp=head;
    while(temp!=tail){
        if(node->val<=temp->next->val){
            node->next=temp->next;
            temp->next=node;
            return;
        }
        temp=temp->next;
    }
    
    // Insert at end
    tail->next=node;
    tail=node;
    return;
    
} 
 
ListNode* Solution::insertionSortList(ListNode* A) {
    
    if(A==NULL) return NULL;
    
    ListNode *head,*tail;
    head=tail=A;
    A=A->next;
    while(A!=NULL){
        ListNode* temp = A->next;
        insert(head,tail,A);
        A = temp;
    }
    
    if(tail) tail->next=NULL;

    return head;
}
