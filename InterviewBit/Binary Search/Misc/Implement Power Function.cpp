// Bucket - Search step simulation
// Implement pow(x, n) % d.
// Assume power is non negative

// IMP NOTE!!!=> In C++, -1%20 = -1

// Approach 1: Recursive

int Solution::pow(int x, int n, int d) {
    if(n==0){
      return 1%d; // d could be =1  
    } 
    if(n==1) {
        x=x%d; // Eg: (-50^1)%3
        x=(x+d)%d;
        return x;
    }
    
    long long small = pow(x,n/2,d);
    small*=small;
    small%=d;

    if(n%2==0){
        return small;
    }else{
        small*=x;
        small%=d;
        return (small+d)%d;
    }
    
}

/***************************************************************************************************************************/

// Approach 2: Iterative Fast Power, Bitmasks

int Solution::pow(int x, int n, int d) {
    long long res=1%d;
    long long X=x;
    while(n>0){
        int lastBit=n&1;
        if(lastBit){
            res*=X;
            res%=d;
        }
        X*=X;
        X%=d;
        n=n>>1;
    }
    return (res+d)%d;
}
