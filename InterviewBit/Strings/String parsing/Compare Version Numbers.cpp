// Compare two version numbers version1 and version2.
// If version1 > version2 return 1,
// If version1 < version2 return -1,
// otherwise return 0.
// The . character does not represent a decimal point and is used to separate number sequences.
// Here is an example of version numbers ordering:
// 0.1 < 1.1 < 1.2 < 1.13 < 1.13.4

// Note: There might be multiple corner cases here. Clarify all your doubts in the interview.

// Approach: Implementing str.split('.')

vector<string> getVersionAsList(string version){
    // str.split('.')
    vector<string> ans;
    for(int i=0;i<version.length();i++){
        string subVersion="";
        while(i<version.length()&&version[i]!='.'){
            subVersion += version[i];
            i++;
        }
        ans.push_back(subVersion);
    }
    while(ans.back()=="0") ans.pop_back(); // Remove trailing subversions which are 0
    return ans;
}

string removeLeadingZeroes(string s){
    int i=0;
    while(i<s.size()&&s[i]=='0') i++;
    if(i==s.size()) return "";
    else return s.substr(i);
}

int compareStrings(string a,string b){
    
    a = removeLeadingZeroes(a);
    b = removeLeadingZeroes(b);

    if(a.size()>b.size()) return 1;
    else if(a.size()<b.size()) return -1;
    else{
        if(a>b) return 1;
        else if(a<b) return -1;
        else if(a==b) return 0;
    }
}

int Solution::compareVersion(string A, string B) {

    vector<string> a=getVersionAsList(A),b=getVersionAsList(B);
    int x = min(a.size(),b.size());
    int i;
    for(i=0;i<x;i++){
        int cmp = compareStrings(a[i],b[i]);
        if(cmp!=0) return cmp;
    }
    
    if(i!=a.size()) return 1;
    else if(i!=b.size()) return -1;
    else return 0;
        
}
