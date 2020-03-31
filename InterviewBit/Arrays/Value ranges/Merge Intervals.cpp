// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
// You may assume that the intervals were initially sorted according to their start times.

// Example 1:
// Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].
// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

// Make sure the returned intervals are also sorted.

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
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    
    vector<pair<int,char>> v; // <time,arrive/depart> OR <time,start/end>
    
    // If at same time A & D, want A first in the sorted array for this question 
    v.push_back({newInterval.start,'A'});
    v.push_back({newInterval.end,'D'});
    for(Interval i:intervals){
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

// Approach 2: Without sorting

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    int n=intervals.size();

    if(newInterval.end<newInterval.start) swap(newInterval.start,newInterval.end);
    
    // Find position where to insert newInterval
    vector<Interval> ans;
    int i;
    for(i=0;i<n;i++){
        if(newInterval.start<intervals[i].start) break;
        else if(intervals[i].start<=newInterval.start&&newInterval.start<=intervals[i].end) break;
        else ans.push_back(intervals[i]);
    }
    
    // i==n corner case
    if(i==n){
        ans.push_back(newInterval);
        return ans;
    }
    
    // Merge all the reqd intervals
    int s=min(intervals[i].start,newInterval.start); // start of merged intervals
    for(;i<n;i++){
        if(newInterval.end<intervals[i].start){
            ans.push_back(Interval(s,newInterval.end));
            break;
        } 
        if(intervals[i].start<=newInterval.end&&newInterval.end<=intervals[i].end){
            ans.push_back(Interval(s,intervals[i].end));
            i++;
            if(i==n) return ans; // i==n corner case
            break;
        } 
    }
    
    // i==n corner case
    if(i==n){
        ans.push_back(Interval(s,newInterval.end));
        return ans;
    }
    
    // Insert remaining intervals
    for(;i<n;i++){
        ans.push_back(intervals[i]);
    }
    
    return ans;
    
}
