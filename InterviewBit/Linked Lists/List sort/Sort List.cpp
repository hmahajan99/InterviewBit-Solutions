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
 
pair<ListNode*,ListNode*> partition(ListNode* head, int X) {
    
    ListNode *h1=NULL,*t1=NULL,*h2=NULL,*t2=NULL;
    while(head!=NULL){
        if(head->val<X){
            insert(h1,t1,head);
        }else{
            insert(h2,t2,head);
        }
        head=head->next;
    }
    
    if(t1) t1->next=NULL;
    if(t2) t2->next=NULL;
    
    return make_pair(h1,h2);
}

pair<ListNode*,ListNode*> quickSort(ListNode* head){
    if(head==NULL||head->next==NULL) return make_pair(head,head);
    
    pair<ListNode*,ListNode*> r = partition(head->next,head->val);
    
    pair<ListNode*,ListNode*> p1 = quickSort(r.first);
    pair<ListNode*,ListNode*> p2 = quickSort(r.second);
    
    ListNode *sortedHead,*sortedTail;

    if(!p1.first){
        sortedHead=head;
    }else{
        sortedHead=p1.first;
        p1.second->next=head;
    }

    if(!p2.first){
        sortedTail=head;
        head->next=NULL;
    }else{
        sortedTail=p2.second;
        head->next=p2.first;
    }

    return make_pair(sortedHead,sortedTail);

} 
 
ListNode* Solution::sortList(ListNode* head) {
    return quickSort(head).first;
}