// You are given an array A consisting of strings made up of the letters ‘a’ and ‘b’ only.
// Each string goes through a number of operations, where:

// 1.	At time 1, you circularly rotate each string by 1 letter.
// 2.	At time 2, you circularly rotate the new rotated strings by 2 letters.
// 3.	At time 3, you circularly rotate the new rotated strings by 3 letters.
// 4.	At time i, you circularly rotate the new rotated strings by i % length(string) letters.

// Eg: String is "abaa"

// 1.	At time 1, string is "baaa", as 1 letter is circularly rotated to the back
// 2.	At time 2, string is "aaba", as 2 letters of the string "baaa" is circularly rotated to the back
// 3.	At time 3, string is "aaab", as 3 letters of the string "aaba" is circularly rotated to the back
// 4.	At time 4, string is again "aaab", as 4 letters of the string "aaab" is circularly rotated to the back
// 5.	At time 5, string is "aaba", as 1 letters of the string "aaab" is circularly rotated to the back

// After some units of time, a string becomes equal to it’s original self.
// Once a string becomes equal to itself, it’s letters start to rotate from the first letter again (process resets). So, if a string takes t time to get back to the original, at time t+1 one letter will be rotated and the string will be it’s original self at 2t time.
// You have to find the minimum time, where maximum number of strings are equal to their original self.
// As this time can be very large, give the answer modulo 109+7.

// Example:
// Input -  A: [a,ababa,aba]
// Output - 4

// String 'a' is it's original self at time 1, 2, 3 and 4.
// String 'ababa' is it's original self only at time 4. (ababa => babaa => baaba => babaa => ababa)
// String 'aba' is it's original self at time 2 and 4. (aba => baa => aba)
// Hence, 3 strings are their original self at time 4.

// Approach : 

// The number of bits being rotated for each string goes in the series 1,1+2,1+2+3,1+2+3+4 etc. So for the ith operation, (i*(i+1))/2 bits are rotated.
// Find the smallest i for which you get the same string.

// With respect to a single string, the total number of bits rotated after N operations is 1+2+3+….+N which is (N*(N+1))/2.
// We get back the original string only when the total number of rotated bits is a multiple of the length of the string S(LEN).

// This can be done in O(N) time for each string (Summation of length of all strings is <= 1e6), by finding all (N(N+1))/2 where N starts from 1 and goes upto (2LEN-1).

// But there is a catch, this wont always give you the minimum number of operations.
// Its possible that during rotation, you can get the original string before the number of bits rotated is a multiple of LEN.

// Example: S=> 100100
// Here, in 2 operations, we get the original string back.
// This takes place because the string is made up of recurring substrings.

// Assume string A to be 100
// S => AA
// Hence, over here our length S of string is the length of recurring substring A, so N*(N+1)/2 should be a multiple of length of A.

// Length of recurring substring can easily be found out using KMP algorithm in O(N) time complexity for each string.

// Find the minimum number of operations for each string, and take the LCM of all these values to get the answer.
// Handling of overflow for LCM should be handled by breaking the number down into factors, and then taking LCM (Not needed for languages that don’t have integer limit).

// Hence total time complexity is O(N).

#define lli long long

int lenRecurringSubs(string s){
    int n = s.size();
    int ans=-1;
    if(n<=1) return 1;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            // Is minimum length of recurring substring i ? 
            string a = s.substr(0,i);
            int j;
            for(j=i;j<n;j+=i){
                string x = s.substr(j,i);
                if(a!=x){
                    break;
                }
            }
            if(j==n){
                return i;
            }
            // Is minimum length of recurring substring n/i ? 
            a = s.substr(0,n/i);
            for(j=n/i;j<n;j+=n/i){
                string x = s.substr(j,n/i);
                if(a!=x){
                    break;
                }
            }
            if(j==n){
                ans =n/i;
            }
        }
    }
    return (ans!=-1)?(ans):(n);
}

int geti(int len){
    for(int i=1;i<=2*len-1;i++){ // Upper limit i=2len-1 , as i(i+1)/2 is a multiple of len
        if(((((lli)i*(i+1))/2)%len)==0){
            return i;
        }
    }
}

// CB - CP course - To generate prime factors
// To get divisors of all numbers from 1 to N
// Precomputation - O(N)
// prime[i] -> stores smallest prime factor that divides i
// Each query - O(log n)
// prime[15] = 3, prime[5] = 5
// So, 15 = 3*5
// prime[8] = 2, prime[4] = 2, prime[2] = 2
// So, 8 = 2*2*2


void fillPrimes(int prime[]){
    // Precomputation
    // prime[i] -> stores smallest prime factor that divides i
    for(int i=2;i<300000;i++){
        if(prime[i]==0){
            for(int j=i;j<300000;j+=i){
                prime[j]=i;
            }
        }
    }
}

void generatePrimeFactors(int num,int prime[],unordered_map<int,int> &mp){
    // Query
    // mp1 - stores prime factorisation of num
    // For num = 40 = 2*2*2*5 => mp1[2]=3,mp1[5]=1 
    unordered_map<int,int> mp1; 
    while(num>1){
        mp1[prime[num]]++;
        if(mp.count(prime[num])==0||mp1[prime[num]]>mp[prime[num]]){
            // Update global mp
            mp[prime[num]]=mp1[prime[num]];
        }
        num = num/prime[num];
    }
}

int Solution::solve(vector<string> &A) {

    int prime[300000] = {0};
    fillPrimes(prime);
    unordered_map<int,int> mp; // prime divisor -> maximum power encountered in all x's
    for(string s:A){
        int x = geti(lenRecurringSubs(s));
        generatePrimeFactors(x,prime,mp);
    }
    long long lcm=1;
    for(auto p:mp){
        int divisor=p.first,maxPower=p.second;
        while(maxPower--){
            lcm = (lcm*divisor)%((int)(1e9+7));
        }
    }
    
    return lcm;
}
