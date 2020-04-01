// Given a positive integer n and a string s consisting only of letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.
// D means the next number is smaller, while I means the next number is greater.
// Length of given string s will always equal to n - 1
// Input: n = 3, s = ID Return: [1, 3, 2]

// Approach: O(n)
// Keep an available range of element [l,r]. Initially, l=1 and r=n.
// You always need to select smallest or largest element from available range.

vector<int> Solution::findPerm(const string s, int n) {
    int l=1,r=n;
    vector<int> perm;
    for(int i=0;i<s.size();i++){
        perm.push_back(s[i]=='D'?r--:l++);
    }
    perm.push_back(l);
    return perm;
}