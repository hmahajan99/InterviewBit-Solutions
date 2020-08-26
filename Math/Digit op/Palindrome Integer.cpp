// Determine whether an integer is a palindrome. Do this without extra space.

// Approach 1: Using STL, to_string() and reverse()
// O(n) space

int Solution::isPalindrome(int A) {
    // Using to_string() function
    string s=to_string(A),t=s;
    // Reverse inbuilt function
    reverse(t.begin(),t.end());
    return t==s;
}

/***************************************************************************************************************************/

// Approach 2: O(1) Space, Construct reverse of number 
// First digit of reversed num = Last digit of num

int reverseDigits(int num){
    int ans=0;
    while(num>0){
        ans*=10;
        ans+=num%10;
        num/=10;
    }
    return ans;
}

int Solution::isPalindrome(int A) {
    if(A<0) return false;
    return A == reverseDigits(A);
}