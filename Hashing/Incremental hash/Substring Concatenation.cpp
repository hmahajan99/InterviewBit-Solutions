// Approach 1: Brute Force, Sliding Window
// Time : (n-k)*k  ,k=B.size()*B[0].size()  OR O(A.size()*B.size()*B[0].size())
// You know that every word in L is of same length( say x). Let the number of words in L be n.
// You need to check if every segment of length n*x in our main word consist of some permutation of all the words given in the list.
// If you can do that for one segment you can just slide using two pointer and do it for all segments. For a single segment you can use hashing. How?
// Lets say the size of every word is wsize and number of words is lsize.
// You start at every index i. Look at every lsize number of chunks of size wsize and note down the words. Then match the set of words encountered to the set of words expected.

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    vector<int> ans;

    unordered_map<string,int> m; // strings in B -> frequency
    for(int i=0;i<B.size();i++) m[B[i]]++;
    
    int s=B[0].size(),S=s*B.size();
    int n = A.size()-S;

    for(int i=0;i<=n;i++){
        unordered_map<string,int> m1;
        int j=i;
        while(j<=A.size()-s){
            string a = A.substr(j,s);
            if(!m.count(a)) break;
            m1[a]++;
            if(m1[a]>m[a]) break;
            j+=s;
        }
        if(j-i==S) ans.push_back(i);
    }
    return ans;
    
}

/***************************************************************************************************************************/

// Approach 2: Like Rabin Karp String Matching Algorithm

// Solution can be optimized to O(max(A.size(),B.size()*B[0].size())) i.e O(max(n,k))

// Now, lets look at ways we can optimize this.
// Right now, to match words, we do it letter by letter. How about hashing the words ?
// With hashing, hash(w1) + hash(w2) = hash(w2) + hash(w1).
// In short, when adding the hashes, the order of words does not matter.
// Can we optimize the matching of all the words encountered using that ? Can we use sliding pointers to move to index i + wsize from i ?

int hashFunction(string s){
    int h=0;
    for(char c:s) h+=c;
    return h;
}

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    int reqHash = 0;
    unordered_map<string,int> m; // strings in B -> frequency
    for(string s:B){
        reqHash += hashFunction(s);
        m[s]++;
    } 
    
    vector<int> ans;
    int n=A.size(),k=B.size()*B[0].size(),len=B[0].size();
    if(k>n) return ans;
    int h = hashFunction(A.substr(0,k));
    for(int i=0;i<=n-k;i++){
        if(i>0){
            // Sliding window, Compute new hash value 
            h = h - A[i-1] + A[i+k-1];
        }
        if(h==reqHash){
            // Hash matches => Double check
            bool sol=true;
            unordered_map<string,int> m1; 
            for(int j=i;j<i+k;j+=len){
                string a = A.substr(j,len);
                m1[a]++;
                if(!m.count(a)||m1[a]>m[a]){
                    sol=false;
                    break;
                } 
            }
            if(sol) ans.push_back(i);
        }
    }
    return ans;
    
}
