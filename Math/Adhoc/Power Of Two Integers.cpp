// Given a positive integer which fits in a 32 bit signed integer, find if it can be expressed as A^P where P > 1 and A > 0. 
// A and P both should be integers.

// Approach 1

int Solution::isPower(int num) {

    if(num==1) return 1;
    
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            int temp=num;
            while(temp>=i){
                if(temp%i!=0) {temp=0;}
                temp /=i;
            }
            if(temp==1) return 1;
        }
        
    }
    
    return 0;

    
}

/***************************************************************************************************************************/

// Approach 2: Using log function

int Solution::isPower(int num) {

    if(num==1) return 1;
    
    for(int i=2;i*i<=num;i++){
        int p=log(num)/log(i);  // log base i (num)
        if(pow(i,p)==num) return 1;
    }
    
    return 0;

    
}

