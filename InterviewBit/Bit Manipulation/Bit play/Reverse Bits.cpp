// Reverse the bits of an 32 bit unsigned integer A.

unsigned int Solution::reverse(unsigned int A) {
    // Use two masks
    unsigned int m1=1;
    unsigned int m2=1<<31;
    for(int i=1;i<=16;i++){
        int bitl = (m2&A)?1:0;
        int bitr = (m1&A)?1:0;
        if(bitl^bitr) A=(A^m1)^m2;       
        // Alternatively:
        // if(bitl==1&&bitr==0) A = A - m2 + m1;
        // else if(bitl==0&&bitr==1) A = A - m1 + m2;
        m2>>=1;
        m1<<=1;
    }
    return A;
}
