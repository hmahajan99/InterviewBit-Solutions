bool isPossible(int maxPages,vector<int> &P, int maxStudents){
    // if true tells answer is <= maxPages
    int current=0;
    int i=0;
    int students=1;
    while(i<P.size()){
        if(P[i]>maxPages) return false;
        
        if(current+P[i]<=maxPages){
            current+=P[i];
            i++;
        }else{
            current=0;
            students++;
        }
    }
    return students<=maxStudents;
}

int Solution::books(vector<int> &P, int students) {

    if(students>P.size()) return -1;
    
    int s=0,e=INT_MAX,ans;
    
    while(s<=e){
        long long mid=(s+e)/2;
        // Is number of students required to keep max number of pages below MID < M 
        if(isPossible(mid,P,students)){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    
    return ans;
}