/*
    MY YOUTUBE VIDEO IN THIS QN : https://www.youtube.com/watch?v=Ts9JHEaApfM
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/design-hashset/
*/

//Approach-1 (High space complexity,but O(1) time) - Not a very good approach
class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<bool> vec;
    MyHashSet() {
        vec.resize(1000001, false);
    }
    
    void add(int key) {
        vec[key] = true;
    }
    
    void remove(int key) {
        vec[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return vec[key] == true;
    }
};

class MyHashSet {
public:
    int numBuckets;
    vector<list<int>> buckets;
    int getHashValue(int key) {
        return key%numBuckets;
    }
    
    MyHashSet() {
        numBuckets = 15000;
        buckets = vector<list<int>>(numBuckets, list<int>{});
    }
    
    void add(int key) {
        int index = getHashValue(key);
        auto itr  = find(buckets[index].begin(), buckets[index].end(), key);
        
        if(itr == buckets[index].end())
            buckets[index].push_back(key);
    }
    
    void remove(int key) {
        int index = getHashValue(key);
        
        auto itr  = find(buckets[index].begin(), buckets[index].end(), key);
        
        if(itr != buckets[index].end())
            buckets[index].erase(itr);
    }
    
    bool contains(int key) {
        int index = getHashValue(key);
        
        auto itr  = find(buckets[index].begin(), buckets[index].end(), key);
        
        return itr != buckets[index].end();
    }
};


//NOTE:
/*
You can use the information of load factor to resize the hashset if the Load Factor crosses 0.75
int n = No. of elements inserted till now
int b = Total Number of Buckets

Load Factor = (n/b);
*/
