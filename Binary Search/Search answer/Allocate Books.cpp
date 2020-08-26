// Given an array of integers A of size N and an integer B.
// College library has N bags,the ith book has A[i] number of pages.
// You have to allocate books to B number of students so that maximum number of pages alloted to a student is minimum.
// A book will be allocated to exactly one student.
// Each student has to be allocated at least one book.
// Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.
// Calculate and return that minimum possible number.
// NOTE: Return -1 if a valid assignment is not possible.

// Input 1:
//     A = [12, 34, 67, 90]
//     B = 2
// Output 1:
//     113
// Explanation 1:
//     There are 2 number of students. Books can be distributed in following fashion : 
//         1) [12] and [34, 67, 90]
//         Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
//         2) [12, 34] and [67, 90]
//         Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
//         3) [12, 34, 67] and [90]
//         Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages
//         Of the 3 cases, Option 3 has the minimum pages = 113.

// Input 2:
//     A = [5, 17, 100, 11]
//     B = 4
// Output 2:
//     100

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