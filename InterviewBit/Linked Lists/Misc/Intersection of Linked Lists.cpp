// Approach 1 : Method 1(Simply use two loops)
// Use 2 nested for loops. The outer loop will be for each node of the 1st list and inner loop will be for 2nd list. 
// In the inner loop, check if any of nodes of the 2nd list is same as the current node of the first linked list. 
// The time complexity of this method will be O(M * N) where m and n are the numbers of nodes in two lists.

/***************************************************************************************************************************/

// Approach 2 : Using difference of lengths

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
int len(ListNode* head){
    int l=0;
    ListNode* temp=head;
    while(temp){
        l++;
        temp=temp->next;
    }
    return l;
}
 
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    int len1 = len(A), len2 = len(B);
    while(len1>len2){
        A = A->next;
        len1--;
    }
    while(len2>len1){
        B = B->next;
        len2--;
    }
    while(A&&B){
        if(A==B) return A;
        A=A->next;
        B=B->next;
    }
    return NULL;
}

/***************************************************************************************************************************/

// Approach 3 : Make circle in first list. Now view the problem as finding the loop in the second linked list.

/***************************************************************************************************************************/

// Approach 4 : Using hashing. Hash all nodes of the first list and then check the second list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    unordered_set<ListNode*> vis;
    ListNode *temp=A;
    while(temp){
        vis.insert(temp);
        temp=temp->next;
    }
    temp=B;
    while(temp){
        if(vis.count(temp)==1) return temp;
        temp=temp->next;
    }
    return NULL;
}
