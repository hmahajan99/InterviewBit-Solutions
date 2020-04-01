// Given a collection of intervals, merge all overlapping intervals.
// For example: Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].
// Make sure the returned intervals are sorted.

// Approach 1: Using MAXIMUM INTERVAL OVERLAP concept
// Uses sorting

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::merge(vector<Interval> &A) {

    vector<pair<int,char>> v; // <time,arrive/depart> OR <time,start/end>

    // If at same time A & D, want A first in the sorted array for this question 
    for(Interval i:A){
        v.push_back({i.start,'A'});
        v.push_back({i.end,'D'});
    }
    sort(v.begin(),v.end());

    vector<Interval> ans;
    int overlapping=0;
    int start = INT_MIN;
    for(int i=0;i<v.size();i++){
        if(v[i].second=='A'){
            if(start==INT_MIN) start = v[i].first;
            overlapping++;            
        }else{
            overlapping--;
            if(overlapping==0){
                ans.push_back(Interval(start,v[i].first));    
                start = INT_MIN;
            } 
        }
    }

    return ans;
}


/***************************************************************************************************************************/

// Approach 2: Sort the intervals based on increasing order of starting time

// Lets see how we check if interval 1 (a,b) intersects with interval 2 (c,d):

// Overlap case :
// a---------------------b          OR     a------b
//             c-------------------d           c------------------d

// Non overlap case :
// a--------------------b   c------------------d
// If max(a,c) > min(b,d), then the intervals do not overlap. Otherwise, they overlap.

// 1. Sort the intervals based on increasing order of starting time.
// 2. Push the first interval on to a stack.
// 3. For each interval do the following
//    a. If the current interval does not overlap with the stack top, push it.
//    b. If the current interval overlaps with stack top 
//       and ending time of current interval is more than that of stack top, update stack top with the ending  time of current interval.
// 4. At the end stack contains the merged intervals. 

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool myCmp(Interval a, Interval b) {
    return a.start<b.start;
}

vector<Interval> Solution::merge(vector<Interval> &intervals) {
    if(intervals.size()<2) return intervals;
    
    sort(intervals.begin(),intervals.end(),myCmp);
    int first = 0;
    for(int second = 1; second < intervals.size(); second++) {
        // There is overlap in intervals at first and second position.
        if(intervals[second].start <= intervals[first].end) {
            // We merge the second interval into the first one and modify the first interval to reflect it. 
            intervals[first].end = max(intervals[second].end, intervals[first].end);
        }
        else {
            // No overlap between first and second. Move forward. 
            first++;
            intervals[first].start = intervals[second].start;
            intervals[first].end = intervals[second].end;
        }
    }
    intervals.erase(intervals.begin() + first + 1, intervals.end());
    return intervals;
}
