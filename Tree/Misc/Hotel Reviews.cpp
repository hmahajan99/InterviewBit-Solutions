// Bucket - Tries

// Approach 1 : Brute force - Check whether a word in the review is good or not. Brute force is O(N) per word.
// Approach 2 : Hashmap

// Approach 3 : Tries

class TrieNode {
    public :
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this -> data = data;
        children = new TrieNode*[26];
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;
    public :
    Trie() {
        root = new TrieNode('\0');
    }
    bool search(TrieNode *root, string word) {
        if(word.size() == 0) {
            return root -> isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            return false;
        }
        return search(child, word.substr(1));
    }
    bool search(string word) {
        return search(root, word);
    }
    void insertWord(TrieNode *root, string word) {
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if(root -> children[index] != NULL) {
            child = root -> children[index];
        }
        else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        insertWord(root, word);
    }

};


vector<int> Solution::solve(string A, vector<string> &B) {

    Trie t;
    string word="";
    for(int i=0;i<A.size();i++){
        while(i<A.size()&&A[i]!='_'){
            word+=A[i];
            i++;            
        }
        if(word!=""){
            t.insertWord(word);
            word="";
        }
    }
    
    set<pair<int,int>> s; // < -count, index >
    for(int index=0;index<B.size();index++){
        int count=0; // storing (-1)*(count of good words)
        word="";
        for(int i=0;i<B[index].size();i++){
            while(i<B[index].size()&&B[index][i]!='_'){
                word+=B[index][i];
                i++;            
            }
            if(word!=""){
                if(t.search(word)) count--;
                word="";
            }
        }
        s.insert({count,index});
    }
    
    vector<int> ans;
    for(pair<int,int> p:s){
        ans.push_back(p.second);
    }
    
    return ans;

}
