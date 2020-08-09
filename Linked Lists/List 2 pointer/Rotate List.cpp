// Given a list, rotate the list to the right by k places, where k is non-negative.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int length(ListNode* head){
    if(!head) return 0;
    return 1 + length(head->next);
} 

ListNode* getIthNode(ListNode* head,int i){
    // Return ith node from start
    ListNode* temp=head;
    for(int k=1;k<=i-1;k++) temp=temp->next;
    return temp;
}

ListNode* Solution::rotateRight(ListNode* head, int K) {
    int len = length(head);
    K = K%len;
    if(K==0 || len==1) return head;
    ListNode *temp = getIthNode(head,len-K);
    ListNode *newHead = temp->next;
    temp->next = NULL;
    ListNode *tail = newHead;;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next = head;
    return newHead;
}