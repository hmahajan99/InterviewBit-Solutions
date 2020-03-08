// Approach 1: Using graphs
// We will have n nodes and an edge directed from node i to node j if the element at i’th index must be present at j’th index in the sorted array.
// The graph will now contain many non-intersecting cycles. Now a cycle with m nodes will only require m-1 swaps. 
// Time Complexity: O(n Log n)
// Auxiliary Space: O(n)


/* You are required to complete this method */
int minSwaps(int A[], int N){
    
    bool *vis=new bool[N]{0};
    
    // NOTE: Need to sort but need to retain order also
    vector<pair<int,int>> v(N);
    for(int i=0;i<N;i++){
        v[i]={A[i],i};
    }
    sort(v.begin(),v.end());
    
    int *ind=new int[N]; // Index of element i in sorted array
    for(int i=0;i<N;i++){
        ind[v[i].second]=i;
    }
    
    int swaps=0;
    for(int i=0;i<N;i++){
        if(!vis[i]){
            vis[i]=true;
            int j=ind[i],count=1;
            while(j!=i){
                vis[j]=true;
                j=ind[j];
                count++;
            }
            swaps+=count-1;
        }
    }
    
    delete []vis;
    delete []ind;
    return swaps;
}

/***************************************************************************************************************************/

// Approach 2 : Answer is the number of swaps in selection sort
// Time Complexity: O(n^2)

/* You are required to complete this method */
int minSwaps(int A[], int N){

    int swaps=0;
    for(int i=0;i<N-1;i++){
        int min=A[i],minIndex=-1;
        for(int j=i+1;j<N;j++){
            if(A[j]<min){
                min=A[j];
                minIndex=j;
            }
        }
        if(minIndex!=-1){
            swaps++;
            swap(A[i],A[minIndex]);
        }
    }    
    return swaps;
}
