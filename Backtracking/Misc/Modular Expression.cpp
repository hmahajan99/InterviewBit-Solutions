// NOTE: In C++ (-1)%20 = -1

int power(int A, int B, int C){
    if(B==0) return 1%C;
    if(B==1) return A%C;
    long long smallAns = power(A,B/2,C);
    smallAns*= smallAns;
    smallAns%=C;
    if(B%2==1){
      smallAns*=(A%C);
      smallAns%=C;
    } 
    return smallAns;
}

int Solution::Mod(int A, int B, int C) {
    // Incase answer is negative 
    return (power(A,B,C)+C)%C;
}

