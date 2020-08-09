// Given a singly linked list L: L0 → L1 → … → Ln-1 → Ln, reorder it to: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
// You must do this in-place without altering the nodes’ values.

// Approach 1 : Time O(n^2) 
// 1) Initialize current node as head.
// 2) While next of current node is not null, do following
//     a) Find the last node, remove it from the end and insert it as next
//        of the current node.
//     b) Move current to next to next of current

// Better Solution
// 1) Copy contents of given linked list to a vector. 
// IMP NOTE!!!=> LL + HASHING (i.e vector<Node*> v => v[i] will give node at position i now)
// 2) Rearrange given vector by swapping nodes from both ends.
// 3) Copy the modified vector back to the linked list.

/***************************************************************************************************************************/

// Approach 2 : Like palindrome list
// 1) Break the list from middle into 2 lists.
// 2) Reverse the latter half of the list.
// 3) Now merge the lists so that the nodes alternate.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* mid(ListNode* head){
    if(head==NULL||head->next==NULL) return head;
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

ListNode* reverse(ListNode* head){
    ListNode *prev=NULL,*curr=head;
    while(curr!=NULL){
        ListNode* next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

void insert(ListNode* &head,ListNode* &tail,ListNode* node){
    if(head==NULL){
        head=tail=node;
    }else{
        tail->next=node;
        tail=tail->next;
    }
} 

ListNode* mergeAlternatively(ListNode* head1, ListNode* head2){
    ListNode *head=NULL,*tail=NULL;
    while(head2){
        insert(head,tail,head1);
        head1=head1->next;
        insert(head,tail,head2);
        head2=head2->next;
    }
    if(head1) insert(head,tail,head1);
    //if(tail) tail->next=NULL;
    return head;
}

ListNode* Solution::reorderList(ListNode* head) {
    ListNode *m=mid(head);
    ListNode *head2=reverse(m->next);
    m->next=NULL;
    return mergeAlternatively(head,head2);
    
}

// IMP NOTE : In while loop, if we insert in this order => WRONG 
        // insert(head,tail,head1);
        // insert(head,tail,head2);
        // head1=head1->next; NOW HEAD1->NEXT DOESNT POINT TO THE DESIRED NODE
        // head2=head2->next;

/***************************************************************************************************************************/

// Approach 3 : Recursive, Like palindrome list
// Recursive call : len => len-2 , Base case : len = 1 or 2

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int len(ListNode* head){
    if(!head) return 0;
    return 1+len(head->next);
} 
 
ListNode* reorder(ListNode* head,int len){

    // Base cases
    if(len==1){
       ListNode *temp = head->next;
       head->next=NULL;
       return temp; 
    }  
    if(len==2){
        ListNode *temp = head->next->next;
        head->next->next = NULL;
        return temp;
    }  
    
    ListNode *n=reorder(head->next,len-2);
    ListNode *temp=n->next;
    n->next=head->next;
    head->next=n;

    return temp;

} 
  
ListNode* Solution::reorderList(ListNode* head) {
    if(head==NULL || head->next==NULL) return head;
    reorder(head,len(head));
    return head;
}