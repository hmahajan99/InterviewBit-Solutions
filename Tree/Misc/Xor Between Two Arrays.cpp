// Given two integer array A and B, you have to pick one element from each array such that their xor is maximum.
// Return this maximum xor value.

class Node {
public:
    Node **children;
    Node(){
        children = new Node*[2];
        children[0] = children[1] = NULL;
    }
};

class Trie{
    Node *root;
public:
    Trie(){
        root = new Node();
    }
    
    void insertNumber(int num){
        Node *curr = root;
        for(int p=31;p>=0;p--){
            int mask = 1<<p;
            int bit = (mask & num) ? 1 : 0;
            if(!curr->children[bit]) curr->children[bit] = new Node();
            curr = curr->children[bit];
        }
    }
    
    int getMaxXOR(int num){
        Node *curr = root;
        int maxXor = 0;
        for(int p=31;p>=0;p--){
            int mask = 1<<p;
            int bit = (mask & num) ? 1 : 0;
            if(curr->children[1-bit]){
                maxXor += mask;
                curr = curr->children[1-bit];
            }else{
                curr = curr->children[bit];
            } 
        }
        return maxXor;
    }
    
};

int Solution::solve(vector<int> &A, vector<int> &B) {
    Trie tr;
    for(int a:A) tr.insertNumber(a);
    int ans = 0;
    for(int b:B) ans = max(ans, tr.getMaxXOR(b));
    return ans;
}
