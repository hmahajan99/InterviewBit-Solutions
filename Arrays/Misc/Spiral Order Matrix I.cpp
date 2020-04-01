// Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.
// Example:
// Given the following matrix:
// [
//     [ 1, 2, 3 ],
//     [ 4, 5, 6 ],
//     [ 7, 8, 9 ]
// ]
// You should return [1, 2, 3, 6, 9, 8, 7, 4, 5]

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    // n*m
    vector<int> ans;
    int n=A.size();
    int m=A[0].size();
    int T=0,B=n-1,L=0,R=m-1;
    int dir=0;
    while(T<=B&&L<=R){
        if(dir==0){
            for(int i=L;i<=R;i++) ans.push_back(A[T][i]);
            T++;
        }else if(dir==1){
            for(int i=T;i<=B;i++) ans.push_back(A[i][R]);
            R--;
        }else if(dir==2){
            for(int i=R;i>=L;i--) ans.push_back(A[B][i]);
            B--;
        }else if(dir==3){
            for(int i=B;i>=T;i--) ans.push_back(A[i][L]);
            L++;
        }
        dir=(dir+1)%4;
    }
    return ans;
}
