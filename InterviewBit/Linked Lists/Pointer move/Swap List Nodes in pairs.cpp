// Note : You may not modify the values in the list, only nodes itself can be changed.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* swap(ListNode* A){
    ListNode* B=A->next;
    A->next=B->next;
    B->next=A;
    return B;
} 
  
 
ListNode* Solution::swapPairs(ListNode* head) {
    if(head==NULL||head->next==NULL){
        return head;
    }
    
    // Using DUMMY NODE
    ListNode *dummyStart=new ListNode(0);
    dummyStart->next=head;
    
    // temp stands one node behind list to reverse
    ListNode *temp=dummyStart;
    while(temp->next&&temp->next->next){
        temp->next = swap(temp->next);
        temp = temp->next->next;
    }
    
    return dummyStart->next;
}
