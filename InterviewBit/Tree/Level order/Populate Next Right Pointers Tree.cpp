// Approach 1 : Using level order traversal

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    if(!A) return;
    queue<TreeLinkNode*> q;
    q.push(A);
    q.push(NULL);
    while(!q.empty()){
        TreeLinkNode* front = q.front();
        q.pop();
        if(front!=NULL){
            front->next=q.front();
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }else{
            if(!q.empty()) q.push(NULL);
        }
    }
    
}

/***************************************************************************************************************************/

// Approach 2: Using constant extra space, insert in LL approach

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

void insert(TreeLinkNode* &head,TreeLinkNode* &tail,TreeLinkNode *node){
    if(!head){
        head=tail=node;
    }else{
        tail->next=node;
        tail=tail->next;
    }
} 
void Solution::connect(TreeLinkNode* A) {
    if(!A) return;
    A->next=NULL;
    TreeLinkNode *head=A;
    while(head){
        TreeLinkNode *nextHead=NULL,*tail=NULL,*temp=head;
        while(temp){
            if(temp->left) insert(nextHead,tail,temp->left);
            if(temp->right) insert(nextHead,tail,temp->right);
            temp=temp->next;
        }
        if(tail) tail->next=NULL;
        head=nextHead;
    }
}

