// Approach 1: Brute force, Time - O(m+n)
// Here we need to find the median of the two sorted arrays of different sizes so we keep two variables 
// to point to the arrays and one used to count the no of elements read. 
// We used a simple Merge based solution just we are not merging the array instead we are keeping track of the last element read 
// till we reach the median

/***************************************************************************************************************************/

// Approach 2: Like Matrix Median approach, binary search on each row and count number of elements <= mid
// Time - log(INT_MAX)*(logm+logn)

/***************************************************************************************************************************/

// Approach 3: Binary search on smaller array, Partition both such that total elements on left side is half
// Time - O(log(min(m,n)))
// NOTE: COMMON APPROACH For BINARY SEARCH on 2 SORTED ARRAYS
// See GeeksForGeeks/Divide and Conquer/Must Do/K-th element of two sorted Arrays.cpp

double Solution::findMedianSortedArrays(const vector<int> &X, const vector<int> &Y) {
    int x = X.size(), y = Y.size();
    if(x>y) return findMedianSortedArrays(Y,X);
    
    if(x==0){
        if(y%2==0) return (Y[(y-1)/2]+Y[y/2])*1.0/2;
        return Y[y/2];
    }
    
    
    int l=0,r=x;
    while(l<=r){
        // size(leftPartitionX)=partitionX
        int partitionX = (l+r)/2;
        // size(leftPartitionY)=partitionY
        int partitionY = (x+y+1)/2 - partitionX;
        
        int maxLeftX = (partitionX==0)?(INT_MIN):X[partitionX-1];
        int minRightX = (partitionX==x)?(INT_MAX):X[partitionX];

        int maxLeftY = (partitionY==0)?(INT_MIN):Y[partitionY-1];
        int minRightY = (partitionY==y)?(INT_MAX):Y[partitionY];
        
        if(maxLeftX<=minRightY&&maxLeftY<=minRightX){
            if((x+y)%2==0){
                return (max(maxLeftX,maxLeftY)+min(minRightX,minRightY))*1.0/2 ;   
            }
            return max(maxLeftX,maxLeftY);
        }
        
        else if(maxLeftX>minRightY) r = partitionX-1;
        else l = partitionX+1;
        
    }
    
}
