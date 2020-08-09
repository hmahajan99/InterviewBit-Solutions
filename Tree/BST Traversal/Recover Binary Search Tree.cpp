// Two elements of a binary search tree (BST) are swapped by mistake. Tell us the 2 values swapping which the tree will be restored.

// Lets look at the inorder traversal of the tree.
// In the ideal case, the inorder traversal should be sorted. But in this case, because of the swapping 2 cases might arise :
// 1) A sequence like {1, 4, 3, 7, 9}, where the swapped pair are adjacent to each other. Only one inversion ( Inversion here means pair of integer A[i], A[i+1] where A[i] > A[i+1] ).
// 2) A sequence like {1, 9, 4, 5, 3, 10} where the swapped pair are not adjacent. 2 inversions. We take the min and max of the inversion numbers and we know the number we need to swap to get the right answer.

// Now to figure this out, we need to do an inorder traversal. However, the traditional recursive inorder traversal has memory overhead of the depth of the tree.
// Using a stack has the same memory overhead.

// So, we need something which does not use recursion or stack and can still do the inorder traversal.

// Solution - Time=O(n) Space=O(1)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* findPred(TreeNode* current){
    TreeNode *temp=current;
    temp=temp->left;
    while(temp->right!=NULL&&temp->right!=current){
        temp=temp->right;
    }
    return temp;
} 
 
vector<pair<int,int>> MorrisTraversal(TreeNode* root){
    vector<pair<int,int>> ans;
    int prev=INT_MIN;
    
    TreeNode* current = root;

    while(current!=NULL){
        if(!current->left){

            // Visit current
            if(current->val<prev){
                ans.push_back({prev,current->val});
            }
            prev = current->val;

            current = current->right;
        }else{
            TreeNode* predecessor = findPred(current);
            if(!predecessor->right){
                predecessor->right = current;
                current = current ->left;
            }else{
                predecessor->right = NULL;

                // Visit current
                if(current->val<prev){
                    ans.push_back({prev,current->val});
                }
                prev = current->val;

                current=current->right;
            }
        }
    }
    
    return ans;
    
} 
 

vector<int> Solution::recoverTree(TreeNode* A) {

    vector<pair<int,int>> inversions = MorrisTraversal(A);
    
    if(inversions.size()==1){
        pair<int,int> p = inversions[0];
        return {p.second,p.first};
    }

    pair<int,int> p1 = inversions[0];
    pair<int,int> p2 = inversions[1];
    return { p2.second , p1.first }; 

}