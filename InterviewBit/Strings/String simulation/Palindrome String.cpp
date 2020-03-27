// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
// Example:
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.

// Note:- Empty strings are palindromes. This is however, a nice question for clarification from the interviewer.

// Approach 1: Using isalnum(char) & toupper(char) defined in cctype

int Solution::isPalindrome(string A) {

  int i=0,j=A.size()-1;

  while(i<j){
      if(isalnum (A[i])&&isalnum (A[j])){
          if(toupper(A[i])!=toupper(A[j])) return false;
          i++;
          j--;
      }else if(!isalnum (A[i])){
          i++;
      }else if(!isalnum (A[j])){
          j--;
      }
  }
  
  return true;
    
}

/***************************************************************************************************************************/

// Approach 2: Implementing isalnum(char) & toupper(char) defined in cctype

bool isAlphaNumeric(char ch){
    bool isLowerCaseLetter = 'a'<=ch&&ch<='z';
    bool isUpperCaseLetter = 'A'<=ch&&ch<='Z';
    bool isDigit = '0'<=ch&&ch<='9';
    return isLowerCaseLetter || isUpperCaseLetter || isDigit;
}

char toUpper(char ch){
    bool isLowerCaseLetter = 'a'<=ch&&ch<='z';
    if(isLowerCaseLetter){
        return 'A'+(ch-'a');
    }
    return ch;
}

int Solution::isPalindrome(string A) {

  int i=0,j=A.size()-1;

  while(i<j){
      if(isAlphaNumeric(A[i])&&isAlphaNumeric(A[j])){
          if(toUpper(A[i])!=toUpper(A[j])) return false;          
          i++;
          j--;
      }else if(!isAlphaNumeric(A[i])){
          i++;
      }else if(!isAlphaNumeric(A[j])){
          j--;
      }
  }

  return true;
    
}

