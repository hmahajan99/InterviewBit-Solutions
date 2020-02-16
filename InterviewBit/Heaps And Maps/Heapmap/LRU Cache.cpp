// Approach 1: Brute force
// Keep an array of Nodes , Node => (key,value,timestamp) . Size of the array will be equal to the given capacity of cache.
// (a) For get(int key): We can simply iterate over the array and compare the key of each node with the given key and return the value stored in the node for that key. If we don’t find any such node, return simply -1.
// Time Complexity: O(n)
// (b) For set(int key, int value): If the array if full, we have to delete one node from the array. To find the LRU node, we will iterate through the array and find the node with least timeStamp value. We will simply insert the new node (with new key and value) at the place of the LRU node.
// If the array is not full, we can simply insert a new node in the array at the last current index of the array.
// Time Complexity: O(n)

/***************************************************************************************************************************/

// Approach 2: Hashmap + Set + Timestamp
// get,set => O(logn)

set<pair<int,int>> s; // timestamp key
unordered_map<int,pair<int,int>> m;  // key => timestamp value
int t; // time
int c; // capacity

LRUCache::LRUCache(int capacity) {
    s.clear();
    m.clear();
    t=0;
    c=capacity;
}

void eraseKey(int key){
    s.erase(s.find(make_pair(m[key].first,key)));
    m.erase(key);
}

void insertKeyValue(int key,int value){
    m[key] = make_pair(t,value);
    s.insert(make_pair(t,key));
    t++; // Increment time
}

int LRUCache::get(int key) {
    if(!m.count(key)) return -1;
    
    // Update timestamp of key
    int value = m[key].second;
    eraseKey(key);
    insertKeyValue(key,value);
    return value;
}

void LRUCache::set(int key, int value) {

    if(m.count(key)){
        // key already present => update operation
        // remove key first, since want to update timestamp
        eraseKey(key);
    }

    if(c==m.size()){
        // Capacity full, remove least recently used item (i.e smallest timestamp)
        int LRUkey = s.begin()->second;
        eraseKey(LRUkey);
    }
    
    insertKeyValue(key,value);    
}

/***************************************************************************************************************************/

// Approach 3: Doubly Linked List + Hashing
// get,set => O(1)
// IMP NOTE: Doubly Linked List + Hashing used in many questions (similar to indexing concept)

// We need a data structure which at any given instance can give me the least recently used objects in order. Lets see if we can maintain a linked list to do it. We try to keep the list ordered by the order in which they are used. So whenever, a get operation happens, we would need to move that object from a certain position in the list to the front of the list. Which means a delete followed by insert at the beginning.
// Insert at the beginning of the list is trivial. How do we achieve erase of the object from a random position in least time possible ?
// How about we maintain another map which stores the pointer to the corresponding linked list node.
// Ok, now when we know the node, we would need to know its previous and next node in the list to enable the deletion of the node from the list. We can get the next in the list from next pointer ? What about the previous node ? To encounter that, we make the list doubly linked list.

#include<list>

typedef pair<int,list<int>::iterator> pii;
typedef unordered_map<int,pii> hipii;

list<int> used; // DLL, stores keys ordered by access time (MRU at front, LRU at back)
hipii cache; // key -> (value,iterator i.e position int the list, like Node*)
int cacheCapacity;

void access(int key){
    used.erase(cache[key].second); // list.erase(iterator)
    used.push_front(key);
    cache[key].second=used.begin();
}

LRUCache::LRUCache(int capacity) {
    cacheCapacity=capacity;
    cache.clear();
    used.clear();
}

int LRUCache::get(int key) {
    if(cache.count(key)==0) return -1;
    access(key);
    return cache[key].first;
}

void LRUCache::set(int key, int value) {
    if(cache.count(key)>0){
        // Key already present, update
        access(key);
    }else{
        // Insert Key
        
        // Check if cache full
        if(cache.size()==cacheCapacity){
            cache.erase(used.back());
            used.pop_back();
        }
        
        used.push_front(key);
    }
    
    cache[key] = {value,used.begin()}; 
}
