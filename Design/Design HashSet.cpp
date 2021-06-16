/*
    Company Tags  : Google
    Leetcode Link : https://leetcode.com/problems/design-hashset/
*/

//Approach-1 (High space complexity,but O(1) time)
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

//Approach-2 (COmpromising a little with time complexity and reducing space complexity using chaining)
class MyHashSet {
private:
    int getHashValue(int key) {
        return key%numBuckets;
    }
public:
    /** Initialize your data structure here. */
    int numBuckets;
    vector<list<int>> buckets;
    MyHashSet() {
        numBuckets = 15000;
        buckets = vector<list<int>>(numBuckets, list<int>{});
        //I will be using concept of chaining
    }
    
    void add(int key) {
        int index = getHashValue(key);
        if(find(buckets[index].begin(), buckets[index].end(), key) == buckets[index].end())
            buckets[index].push_back(key);
    }
    
    void remove(int key) {
        int index = getHashValue(key);
        auto itr  = find(buckets[index].begin(), buckets[index].end(), key);
        if(itr != buckets[index].end())
            buckets[index].erase(itr);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int index = getHashValue(key);
        return find(buckets[index].begin(), buckets[index].end(), key) != buckets[index].end();
    }
};
