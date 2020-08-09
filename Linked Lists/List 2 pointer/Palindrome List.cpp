// Approach 1 : By reversing the list
// This method takes O(n) time and O(1) extra space
// Can get original linked list back by reversing the second half again and attaching it back to the first half

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

 
int Solution::lPalin(ListNode* A) {

    if(A==NULL || A->next==NULL) return 1;
    
    ListNode* m = mid(A);
    
    ListNode* h2=reverse(m->next);
    ListNode* h1=A;

    m->next = NULL;

    while(h2!=NULL){
        if(h2->val!=h1->val) return 0;
        h2=h2->next;
        h1=h1->next;
    }
    
    return 1;
    
}

/***************************************************************************************************************************/

// Approach 2 : Using a stack, Time - O(n), Space - O(n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* head) {
    stack<ListNode*> s;
    ListNode *temp=head;
    while(temp){
        s.push(temp);
        temp=temp->next;
    }
    temp=head;
    while(temp){
        ListNode *top=s.top();
        s.pop();
        if(top->val!=temp->val) return 0;
        temp=temp->next;
    }
    return 1;
}

/***************************************************************************************************************************/

// Approach 3 : Using recursion
// Recursive call : len => len-2 , Base case : len = 1 or 2
// Time Complexity: O(n)
// Auxiliary Space: O(n) if Function Call Stack size is considered, otherwise O(1).

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int lenRecursive(ListNode* head){
    if(!head) return 0;
    return 1+lenRecursive(head->next);
} 

int len(ListNode* head){
    int l=0;
    ListNode* temp=head;
    while(temp){
        l++;
        temp=temp->next;
    }
    return l;
}

pair<bool,ListNode*> isPalindrome(ListNode* node,int len){
    // Base case
    if(len==1) return {true,node->next};
    if(len==2) return {node->val==node->next->val,node->next->next};
    
    auto p = isPalindrome(node->next,len-2);
    return {p.first&&node->val==p.second->val,p.second->next};
}
 
int Solution::lPalin(ListNode* head) {
    int l = len(head);
    if(l==0||l==1) return true;
    return isPalindrome(head,l).first;
}

// Alternative recursive approach

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *temp; // use temp to traverse list in forward direction

bool isPalindrome(ListNode* head){
    if(!head) return true;
    int smallAns = isPalindrome(head->next);
    if(smallAns&&head->val==temp->val){
        temp = temp->next;
        return true;
    }
    return false;
    
}

int Solution::lPalin(ListNode* head) {
    temp = head;
    return isPalindrome(head);
}


/***************************************************************************************************************************/

// Approach 4 : Simple solution would be to create clone of the linked list, reverse it and check if both linked lists are equal or not. 
// This approach requires three traversals of the linked list and requires extra space for storing duplicates list.

// LL + HASHING
// OR ALTERNATIVELY PUSH NODES INTO A VECTOR (i.e vector<Node*> v => v[i] will give node at position i now)

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

ListNode* cloneLL(ListNode *head){
    ListNode *clonedLLHead=NULL,*clonedLLTail=NULL;
    ListNode *temp = head;
    while(temp){
        ListNode *node = new ListNode(temp->val);
        insert(clonedLLHead,clonedLLTail,node);
        temp=temp->next;
    }
    return clonedLLHead;
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
 
int Solution::lPalin(ListNode* head) {
    ListNode *clonedLLHead = cloneLL(head);
    ListNode *revLLHead = reverse(clonedLLHead);
    ListNode *temp1=head, *temp2=revLLHead;
    while(temp1){
        if(temp1->val!=temp2->val) return 0;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return 1;
}

