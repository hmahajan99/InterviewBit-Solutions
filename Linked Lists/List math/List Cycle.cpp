// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

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

  //          -------------------
  //          |                 |
  // X->X->X->X->X->X->X->X->X->X
  // <--m-----><-----k--->^
  //                      |
  //                 slow/fast meet

// Note that before meeting the point shown above, fast was moving at twice speed.
// Distance traveled by fast pointer = 2 * (Distance traveled by slow pointer)
// (m + n*x + k) = 2*(m + n*y + k)
// m -->  Distance of first node of cycle from head
// n -->  Length of cycle
// k -->  Distance of point where slow & fast meet from first node of cycle
// x -->  Number of complete cyclic rounds made by fast pointer before they meet first time
// y -->  Number of complete cyclic rounds made by slow pointer before they meet first time

// m + k = (x-2y)*n
// Which means m+k is a multiple of n. 

// So if we start moving both pointers again at same speed such that one pointer (say slow) begins from head node of linked list and other pointer (say fast) begins from meeting point. 
// When slow pointer reaches beginning of loop (has made m steps), fast pointer would have made also moved m steps as they are now moving same pace. 
// Since m+k is a multiple of n and fast starts from k, they would meet at the beginning. 
// Can they meet before also? No because slow pointer enters the cycle first time after m steps.


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

