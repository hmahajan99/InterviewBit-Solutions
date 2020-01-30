// NOTE: The digits are stored in reverse order

// Approach 1 : Converting LL to strings and doing string addition (integer will overflow)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

string getValue(ListNode* head){
    if(head==NULL) return "";
    return getValue(head->next) + (char)('0' + head->val) ;
} 

string add(string s1,string s2){
    
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());

    int len = min(s1.length(),s2.length());
    string ans = "";
    int carry = 0,i;
    
    for(i=0;i<len;i++){
       int temp = (s1[i]-'0') + (s2[i]-'0') + carry;
       carry = temp/10;
       temp %= 10;
       ans += (char)('0'+temp);
    }
    
    
    while(i<s1.length()){
       int temp = (s1[i]-'0') + carry;
       carry = temp/10;
       temp %= 10;
       ans += (char)('0'+temp);
       i++;
    }

    while(i<s2.length()){
       int temp = (s2[i]-'0') + carry;
       carry = temp/10;
       temp %= 10;
       ans += (char)('0'+temp);
       i++;
    }
    
    if(carry){
        ans += (char)('0'+carry);
    }

    reverse(ans.begin(),ans.end());

    return ans;
    
}

void insert(ListNode* &head,ListNode* &tail,ListNode* node){
    if(head==NULL){
        head=tail=node;
    }else{
        tail->next=node;
        tail=tail->next;
    }
} 

 
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {

    string num1 = getValue(A);
    string num2 = getValue(B); 
    string num3 = add(num1,num2);

    ListNode *head = NULL;
    ListNode *tail = head;
    for(int i=num3.length()-1;i>=0;i--){
        insert(head,tail,new ListNode(num3[i]-'0'));
    }
    return head;
    
}

/***************************************************************************************************************************/

// Approach 2 

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

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode *head=NULL,*tail=NULL;
    int carry=0;

    while(A&&B){
        insert(head,tail,new ListNode((A->val+B->val+carry)%10));
        carry = (A->val+B->val+carry)/10;
        A=A->next;
        B=B->next;
    }

    while(A){
        insert(head,tail,new ListNode((A->val+carry)%10));
        carry = (A->val+carry)/10;
        A=A->next;
    }

    while(B){
        insert(head,tail,new ListNode((B->val+carry)%10));
        carry = (B->val+carry)/10;
        B=B->next;
    }

    if(carry) insert(head,tail,new ListNode(carry));
    
    return head;

}

// Shorter Alternative for this approach

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

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode *head=NULL,*tail=NULL;
    int carry=0;

    while(A||B){
        int temp = (A ? A->val : 0) + (B ? B->val : 0) + carry;
        carry = temp/10;
        temp %= 10;
        insert(head,tail,new ListNode(temp));
        if(A) A=A->next;
        if(B) B=B->next;
    }

    if(carry) insert(head,tail,new ListNode(carry));
    
    return head;

}

// Even shorter, single loop only

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

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode *head=NULL,*tail=NULL;
    int carry=0;

    while(A||B||carry){
        int temp = (A ? A->val : 0) + (B ? B->val : 0) + carry;
        insert(head,tail,new ListNode(temp%10));
        carry = temp/10;
        if(A) A=A->next;
        if(B) B=B->next;
    }

    return head;

}

/***************************************************************************************************************************/

// Approach 3 : Using recursion 
// Time Complexity: O(m+n) where m and n are the sizes of given two linked lists.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int carry=0; // GLOBAL VARIABLE => HELPFUL IN RECURSION

ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    // Base case
    if(A==NULL&&B==NULL&&carry==0) return NULL;

    int temp = (A ? A->val : 0) + (B ? B->val : 0) + carry;
    ListNode *node = new ListNode(temp%10);
    carry = temp/10;
    node->next = addTwoNumbers((A?A->next:NULL),(B?B->next:NULL));
    return node;

}
