/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : Adobe, Microsoft, Amazon, Citygroup, Twitch
    Leetcode Link               : https://leetcode.com/problems/lru-cache/
*/

//Approach-1 (Brute Force)
class LRUCache {
public:
    vector<vector<int>> cache;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    //O(n)
    int get(int key) {
        if(cache.size() == 0) {
            return -1;
        }
        int val = -1;
        int i = 0;
        for(; i<cache.size(); i++) {
            if(cache[i][0] == key) {
                val = cache[i][1];
                break;
            }
        }
        if(i == cache.size()) {
            return -1;
        }
        cache.erase(cache.begin()+i);
        cache.push_back({key, val});
        return val;
    }
    
    //O(n)
    void put(int key, int value) {
        if(cache.size() == 0) {
            cache.push_back({key, value});
            return;
        }
        for(int i = 0; i<cache.size(); i++) {
            if(cache[i][0] == key) {
                cache[i][1] = value;
                cache.erase(cache.begin()+i);
                cache.push_back({key, value});
                return;
            }
        }
        if(cache.size() < n) {
            cache.push_back({key, value});
            return;
        } else {
            cache.erase(cache.begin());
            cache.push_back({key, value});
        }
    }
};


//Approach-2 (Optimal)
class LRUCache {
public:
    list<int> dll; //it contains the key
    map<int, pair<list<int>::iterator, int>> cache; //key->(list_node, value)
    int capacity;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    void makeMostRecentlyUsed(int key) {
        dll.erase(cache[key].first);
        dll.push_front(key);
        cache[key].first = dll.begin();
    }
    
    int get(int key) {
        if(!cache.count(key))
            return -1;
        
        makeMostRecentlyUsed(key);
        return cache[key].second;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            cache[key].second = value;
            makeMostRecentlyUsed(key);
        } else {
            dll.push_front(key);
            cache[key] = {dll.begin(), value};
            capacity--;
        }
        
        if(capacity < 0) {
            cache.erase(dll.back());
            dll.pop_back();
            capacity++;
        }
    }
};
