// Approach 1 : Using sorting

int getDiff(string s,string t){
    int i;
    for(i=0;i<min(s.length(),t.length());i++){
        if(s[i]!=t[i]){
            return i+1;
        }
    }
}

vector<string> Solution::prefix(vector<string> &A) {

    if(A.size()==1) return vector<string>(1,"");
    vector<pair<string,int>> v;
    for(int i=0;i<A.size();i++){
      v.push_back({A[i],i});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<=A.size()-1;i++){
        int a = INT_MIN,b=INT_MIN;
        if(i!=0) a=getDiff(v[i].first,v[i-1].first);
        if(i!=A.size()-1) b=getDiff(v[i].first,v[i+1].first);
        v[i].first = v[i].first.substr(0,max(a,b));
    }
    for(int i=0;i<v.size();i++){
        A[v[i].second] = v[i].first;
    }
    return A;

}

/***************************************************************************************************************************/

// Approach 2 : Using Trie - More efficient
// Store COUNT (frequency) with each node
// Using HASHMAP to store CHILDREN

class TrieNode {
    public :
    unordered_map<char,TrieNode*> children;
    int count; // Number of times node is visited during insertion
    TrieNode() {
        count=0;
    }
};

class Trie {
    TrieNode *root;

    public :

    Trie() {
        root = new TrieNode;
    }

    void insertWord(string word) {
        insertWord(root, word, 0);
    }

    void insertWord(TrieNode *root, const string &word,int i) {

        root->count++;

        // Base case
        if(i==word.size()) return;

        if(root->children.count(word[i]) == 0) {
            root->children[word[i]] = new TrieNode;
        }

        insertWord(root->children[word[i]],word,i+1);
    }

    string shortestUniquePrefix(string word) {
        int len = find(root,word,0);
        return word.substr(0,len);
    }

    int find(TrieNode *root, const string &word,int i) {
        
        if(root->count==1) return i;

        return find(root->children[word[i]],word,i+1);

    }

};

vector<string> Solution::prefix(vector<string> &A) {
    Trie t;
    for(string s:A) t.insertWord(s);
    vector<string> ans;
    for(int i=0;i<A.size();i++){
        ans.push_back(t.shortestUniquePrefix(A[i]));
    }
    return ans;
}

