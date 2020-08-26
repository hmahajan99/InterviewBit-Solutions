// Given an integer A, generate a square matrix filled with elements from 1 to A^2 in spiral order.
// Input: A = 3
// Output 
//     [   [ 1, 2, 3 ],
//         [ 8, 9, 4 ],
//         [ 7, 6, 5 ]   ]

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> mat (A,vector<int>(A));
    int T=0,B=A-1,L=0,R=A-1;
    int dir=0,num=1;
    while(T<=B&&L<=R){
        if(dir==0){
            for(int i=L;i<=R;i++,num++) mat[T][i]=num;
            T++;
        }else if(dir==1){
            for(int i=T;i<=B;i++,num++) mat[i][R]=num;
            R--;
        }else if(dir==2){
            for(int i=R;i>=L;i--,num++) mat[B][i]=num;
            B--;
        }else if(dir==3){
            for(int i=B;i>=T;i--,num++) mat[i][L]=num;
            L++;
        }
        dir=(dir+1)%4;
    }
    return mat;
}