// Bucket - Graph adhoc

// Approach 1: Brute force
// Find the middle of the list, make it the root. 
// Left part of the tree comes from the first half and right part of the tree comes from the later half.
// Time complexity: O(nLogn) where n is the number of nodes in Linked List.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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

 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    
    if(A==NULL) return NULL;
    ListNode *midpointLL=mid(A);
    ListNode *prevMid=NULL,*temp=A;
    while(temp!=midpointLL){
        prevMid=temp;
        temp=temp->next;
    }
    if(prevMid) prevMid->next=NULL;
    TreeNode *root = new TreeNode(midpointLL->val);
    root->left = sortedListToBST((A==midpointLL)?(NULL):(A));
    root->right = sortedListToBST(midpointLL->next);
    return root;
}

/***************************************************************************************************************************/

// Approach 2: Tricky, O(n)

// Method 1 constructs the tree from root to leaves. In this method, we construct from leaves to root. 
// The idea is to insert nodes in BST in the same order as they appear in Linked List so that 
// the tree can be constructed in O(n) time complexity.
// After counting nodes, we take left n/2 nodes and recursively construct the left subtree. After left subtree is constructed, we allocate memory for root and link the left subtree with root. Finally, we recursively construct the right subtree and link it with root.
// While constructing the BST, we also keep moving the list head pointer to next so that we have the appropriate pointer in each recursive call.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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

TreeNode* generate(ListNode* &head,int n){
    if(n==0) return NULL;
    TreeNode *left = generate(head,n/2);
    TreeNode *root = new TreeNode(head->val);
    root->left=left;
    head = head->next;
    root->right = generate(head,n-n/2-1);
    return root;
}

TreeNode* Solution::sortedListToBST(ListNode* head) {
    return generate(head,len(head));
}
