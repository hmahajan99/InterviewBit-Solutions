// Given an array A, of N integers A.
// Return the highest product possible by multiplying 3 numbers from the array.

// Approach 1: Sorting, Time O(nlogn)

bool cmp(int a,int b){
    return a>b;
}

// Handles all cases => + + +, + - -, - - -, - + + (For - + + size of A should be 3)
int Solution::maxp3(vector<int> &A) {
    // sort(A.begin(),A.end(),cmp);
    sort(A.begin(),A.end(),greater<int>()); // FOR DESCENDING ORDER => greater<int>()
    int a = A[0]*A[1]*A[2]; // Handles + + + , - - -
    int b = A[A.size()-1]*A[A.size()-2]*A[0]; // + - -
    return max(a,b);
}

/***************************************************************************************************************************/

// Approach 2: O(n), Calculate 3 maximum elements
// Choosing 3 maximum elements in the array and 2 negative elements with the highest absolute value should be enough.
// One such approach is maintaining 3 variables ( m1, m2, m3 where m1 > m2 > m3 ). When you encounter new value in the array, if the value is less than m3, then the variables are unaffected. Else, depending on where the new value lies, you can update the 3 values.
// Another approach could be maintaining a priority_queue of size 3. You pop out the smallest element if the new element if bigger than the smallest element, and then insert the new element into the priority queue.

// Once you have the 5 elements you desire,
// your answer would be one of the following :
// 1) Product of 3 maximum elements
// 2) Product of the 2 negative elements with max absolute value and maximum positive value.

void setMaximums(int &m1,int &m2,int &m3,int x){
    if(x<m3) return;
    if(x<m2){
        m3=x;  
    }else if(x<m1){
        m3=m2;
        m2=x;
    }else{
        m3=m2;
        m2=m1;
        m1=x;
    } 
} 

void setNegativeMaximums(int &negM1,int &negM2,int x){
    if(x>negM2) return;
    if(x<negM1){
        negM2=negM1;
        negM1=x;
    }else{
        negM2=x;
    }
}

int Solution::maxp3(vector<int> &A) {
    int m1=max({A[0],A[1],A[2]}); // Max of 3 elements using initializer list i.e max({list})
    int m3=min({A[0],A[1],A[2]});
    int m2=A[0]+A[1]+A[2]-(m1+m3);
    int negM1=0,negM2=0;
    for(int i=3;i<A.size();i++){
        setMaximums(m1,m2,m3,A[i]);
    }
    
    for(int i=0;i<A.size();i++){
        if(A[i]<0) setNegativeMaximums(negM1,negM2,A[i]);
    }
    
    int op1 = m1*m2*m3; // + + +, - - -
    int op2 = (negM2==0)?(INT_MIN):(negM1*negM2*m1); // + - -
    return max(op1,op2);
    
}

/***************************************************************************************************************************/

// Approach 3: O(n), Calculate 3 maximum elements and 2 minimum using Min Heap + Max Heap

int Solution::maxp3(vector<int> &A) {
    priority_queue<int,vector<int>,greater<int>> pqMaximums; // Min Heap
    priority_queue<int> pqMinimums; // Max Heap
    for(int a:A){
        if(pqMaximums.size()<3){
            pqMaximums.push(a);
        }else if(a>pqMaximums.top()){
            pqMaximums.pop();
            pqMaximums.push(a);
        }
        
        if(pqMinimums.size()<2){
            pqMinimums.push(a);
        }else if(a<pqMinimums.top()){
            pqMinimums.pop();
            pqMinimums.push(a);
        }
        
    }
    
    int max3 = pqMaximums.top();
    pqMaximums.pop();
    int max2 = pqMaximums.top();
    pqMaximums.pop();
    int max1 = pqMaximums.top();
    pqMaximums.pop();
    
    int min2 = pqMinimums.top();
    pqMinimums.pop();
    int min1 = pqMinimums.top();
    pqMinimums.pop();
    
    return max({max1*max2*max3,max1*min1*min2});
}


