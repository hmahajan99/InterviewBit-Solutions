// Approach 1 : Using Hashing, maintain a list of nodes already visited

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* head) {
    ListNode *temp = head;
    unordered_set<ListNode*> s;
    while(temp){
        if(s.count(temp)==1) return temp;
        s.insert(temp);
        temp=temp->next;
    }
    return NULL;
    
}

// Alt : 
// Approach using Mark Visited Nodes: This solution requires modifications to the basic linked list data structure. 
// Have a visited flag with each node. 

// Alt : Modify list [ NOTE: NOT NECESSARILY LIST IS READ ONLY IN QUESTION => DONT ASSUME READ ONLY ]
// Marking visited nodes without modifying the linked list data structure
// In this method, a temporary node is created. The next pointer of each node that is traversed is made to point to this temporary node. 
// This way we are using the next pointer of a node as a flag to indicate whether the node has been traversed or not. 
// Every node is checked to see if the next is pointing to a temporary node or not. 
// In the case of the first node of the loop, the second time we traverse it this condition will be true, hence we find that loop exists. 
// If we come across a node that points to null then loop doesn’t exist.

/***************************************************************************************************************************/

// Approach 2 : 2 pointer approach ( Floyd’s Cycle-Finding Algorithm ) 

// 1. If a loop is found, initialize slow pointer to head, let fast pointer be at its position.
// 2. Move both slow and fast pointers one node at a time.
// 3. The point at which they meet is the start of the loop.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* head) {
    ListNode *slow=head,*fast=head;
    bool loop = false;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            loop = true;
            break;
        } 
    }
    
    if(!loop) return NULL;
    
    slow=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
    
}

