// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.
// Return a deep copy of the list.

// Example: Given list 1 -> 2 -> 3 with random pointers going from
//   1 -> 3
//   2 -> 1
//   3 -> 1
// You should return a deep copy of the list. 
// The returned answer should not contain the same node as the original list, but a copy of them. 
// The pointers in the returned list should not link to any node in the original input list

// Approach 1 : Hashing, using 2 traversals of the list
// Use a hashmap to store the mapping from oldListNode to the newListNode. 

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
void insert(RandomListNode* &head,RandomListNode* &tail,RandomListNode* node){
    if(head==NULL){
        head=tail=node;
    }else{
        tail->next=node;
        tail=tail->next;
    }
} 

RandomListNode* cloneLL(RandomListNode *head,unordered_map<RandomListNode*,RandomListNode*> &m){
    RandomListNode *clonedLLHead=NULL,*clonedLLTail=NULL;
    RandomListNode *temp = head;
    while(temp){
        RandomListNode *node = new RandomListNode(temp->label);
        m[temp]=node;
        insert(clonedLLHead,clonedLLTail,node);
        temp=temp->next;
    }
    return clonedLLHead;
} 
 
RandomListNode* Solution::copyRandomList(RandomListNode* head) {
    
    unordered_map<RandomListNode*,RandomListNode*> m;
    RandomListNode *clonedLLHead=cloneLL(head,m);

    RandomListNode *temp1=head,*temp2=clonedLLHead;
    while(temp1){
        if(temp1->random==NULL){
            temp2->random=NULL;
        }else{
            temp2->random=m[temp1->random];
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    
    return clonedLLHead;

}

/***************************************************************************************************************************/

// Approach 2 : Hashing, using single traversal of the list
// Use a hashmap to store the mapping from oldListNode to the newListNode. 
// Whenever you encounter a new node in the oldListNode (either via random pointer or through the next pointer ), create the newListNode, store the mapping. 
// and update the next and random pointers of the newListNode using the mapping from the hashmap.

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
void insert(RandomListNode* &head,RandomListNode* &tail,RandomListNode* node){
    if(head==NULL){
        head=tail=node;
    }else{
        tail->next=node;
        tail=tail->next;
    }
} 

RandomListNode* Solution::copyRandomList(RandomListNode* head) {
    
    unordered_map<RandomListNode*,RandomListNode*> m;
    RandomListNode *clonedLLHead=NULL,*clonedLLTail=NULL;
    RandomListNode *temp = head;
    while(temp){
        if(!m.count(temp)){
            m[temp] = new RandomListNode(temp->label);
        }
        insert(clonedLLHead,clonedLLTail,m[temp]);
        if(temp->random){
            if(!m.count(temp->random)){
                m[temp->random] = new RandomListNode(temp->random->label);
            } 
            m[temp]->random = m[temp->random];
        }
        temp=temp->next;
    }
    return clonedLLHead;

}

/***************************************************************************************************************************/

// Approach 3 : Without hashing, using 2 traversals of the list
// Using 2 traversals of the list.
// Step 1: create a new node for each existing node and join them together eg: A->B->C will be A->A’->B->B’->C->C’
// Step 2: copy the random links: for each new node n’, n’.random = n.random.next
// Step 3: detach the list: basically n.next = n.next.next; n’.next = n’.next.next

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
void insert(RandomListNode* &head,RandomListNode* &tail,RandomListNode* node){
    if(head==NULL){
        head=tail=node;
    }else{
        tail->next=node;
        tail=tail->next;
    }
} 

RandomListNode* Solution::copyRandomList(RandomListNode* head) {
    RandomListNode *temp=head;
    while(temp){
        RandomListNode *next=temp->next;
        temp->next = new RandomListNode(temp->label);
        temp->next->next = next;
        temp = next;
    }
    
    // Copy the Random Links
    temp=head;
    while(temp){
        if(temp->random){
            temp->next->random = temp->random->next;
        }
        temp = temp->next->next;
    }
    
    // Detach the list
    RandomListNode *clonedLLHead=NULL,*clonedLLTail=NULL;
    temp=head;
    while(temp){
        insert(clonedLLHead,clonedLLTail,temp->next);
        temp->next = temp->next->next;
        temp = temp->next;
    }
    
    return clonedLLHead;

}