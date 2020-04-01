// Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
// You should pack your words in a greedy approach; that is, pack as many words as you can in each line.

// Pad extra spaces ‘ ‘ when necessary so that each line has exactly L characters.
// Extra spaces between words should be distributed as evenly as possible.
// If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
// For the last line of text, it should be left justified and no extra space is inserted between words.

// Your program should return a list of strings, where each string represents a single line.

// Example:
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.
// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length. 

// Corner Cases:
// 1) A line other than the last line might contain only one word. What should you do in this case?
// In this case, that line should be left-justified.
// 2) Have you noticed that the last line is an exception in terms of spaces?


string justify(const vector<string> &v,int L){
    int numWords = v.size(), spacesBetweenWords = numWords-1;
    if(numWords==1){
        string ans = v[0];
        ans += string(L-ans.length(),' '); // IMP NOTE: String constructor (count,character)
        return ans;
    } 
    int totSize=0;
    for(string s:v) totSize += s.length();
    int totalSpaces = L-totSize;
    int space = totalSpaces/spacesBetweenWords; // IMP Note : DIV BY 0 ERROR => treat numWords==1 case seperately
    int extra = totalSpaces%spacesBetweenWords; 
    string ans="";
    for(int i=0;i<v.size();i++){
        ans += v[i];
        if(i+1!=v.size()) ans += string(space,' '); // IMP NOTE: String constructor (count,character)
        if(extra){
            ans += ' ';
            extra--;
        }
    }
    return ans;
}

string getLast(const vector<string> &v,int L){
    string last="";
    for(int i=0;i<v.size();i++){
        last +=  v[i];
        if(i<v.size()-1) last += ' ';
    }
    last += string(L-last.length(),' '); // IMP: String constructor (count,character)
    return last;
}

vector<string> Solution::fullJustify(vector<string> &words, int L) {

    if(words.size()==0) return vector<string>();

    vector<vector<string>> v; // list<list of words for each line>
    int current=0;
    vector<string> cur; // list of words for current line
    for(int i=0;i<words.size();){
        if(current+words[i].length()<=L){
            cur.push_back(words[i]);
            current = current+words[i].length()+1; // +1 for space
            i++;
        }else{
            v.push_back(cur);
            current=0;
            cur.clear();
        }
    }
    // IMP NOTE!!!> Always check LEFTOVER AFTER LOOP
    if(current>0){
        v.push_back(cur);
    }

    
    vector<string> ans;
    for(int i=0;i+1<v.size();i++){
        ans.push_back(justify(v[i],L));
    }
    ans.push_back(getLast(v.back(),L)); // Lst line should be left justified
    
    return ans;
}
