// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...
// 1 is read off as one 1 or 11.
// 11 is read off as two 1s or 21.
// 21 is read off as one 2, then one 1 or 1211.
// Given an integer n, generate the nth sequence.
// Example: if n = 2, the sequence is 11.

// Approach :
// The best way is to simulate.
// Try constructing the sequence starting from 1.
// For constructing the current sequence, you need to look at the previous sequence and count the size of the contiguous sequences.

string Solution::countAndSay(int N) {

    string nthSequence="1";
    
    for(int n=2;n<=N;n++){
        char ch=nthSequence[0];
        int countChar=1;
        string nextSequence = "";
        for(int i=1;i<=nthSequence.length();i++){
            if(i==nthSequence.length()||nthSequence[i]!=ch){
                nextSequence = nextSequence + to_string(countChar) + ch;
                if(nthSequence[i]!=ch){
                    ch=nthSequence[i];
                    countChar=1;
                }
            }else{
                countChar++;
            }
        }
        nthSequence=nextSequence;
    }
    
    return nthSequence;
}

// Alternate: Using a nested loop for counting freq of given character

string Solution::countAndSay(int N) {

    string nthSequence="1";
    
    for(int n=2;n<=N;n++){
        string nextSequence = "";
        for(int i=0;i<nthSequence.length();){
            char ch=nthSequence[i];
            int countChar=0;
            while(i<nthSequence.length()&&nthSequence[i]==ch){
                countChar++;
                i++;
            } 
            nextSequence = nextSequence + (char)('0'+countChar) + ch;
        }
        nthSequence=nextSequence;
    }
    
    return nthSequence;
}