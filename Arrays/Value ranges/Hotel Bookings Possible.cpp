// A hotel manager has to process N advance bookings of rooms for the next season. His hotel has K rooms. 
// Bookings contain an arrival date and a departure date. 
// He wants to find out whether there are enough rooms in the hotel to satisfy the demand.

// Input:
// First list for arrival time of booking.
// Second list for departure time of booking.
// Third is K which denotes count of rooms.

// Example :
// Input : 
//         Arrivals :   [1 3 5]
//         Departures : [2 6 8]
//         K : 1
// Return : False / 0 
// At day = 5, there are 2 guests in the hotel. But I have only one room. 

// Approach: MAXIMUM INTERVAL OVERLAP

// Finding MAXIMUM level of OVERLAP in the INTERVALS

// 1. Create event points for every interval start, and end. 
// 2. Sort it according to the day. 
// 3. Now, iterate over them one by one. If you encounter a start, then the number of active guests increase by one. If you encounter an end, the number of active guests decrease by one. 
// 4. If at any point, the number of active guests exceed K, we know that scheduling is not possible. 

// The idea is store arrival and departure times in an auxiliary array with an additional marker to indicate whether the time is arrival or departure. 
// Now sort the array. Process the sorted array, for every arrival increment active bookings. 
// And for every departure, decrement. Keep track of maximum active bookings. 
// If the count of active bookings at any moment is more than k, then return false. Else return true.

// GOTCHAS : What if there are multiple start and end on the same day ? How should they be ordered ?
// For this question, if arrival & departure on same day, then departure before arrival

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {

   int n = arrive.size();
    vector<pair<int,char>> v;
    for(int i=0;i<n;i++){
        v.push_back({arrive[i],'s'}); 
        v.push_back({depart[i],'e'}); // For this question, if arrival & departure on same day, then departure before arrival
    }
    sort(v.begin(),v.end());

    int active=0;
    for(int i=0;i<v.size();i++){
        if(v[i].second=='s') active++; // arrival
        else active--;
        
        if(active>K) return false;
    }
    
    return true;

}
