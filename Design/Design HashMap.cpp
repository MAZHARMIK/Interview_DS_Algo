/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=SerANdwnELI
    Company Tags                : Netflix, Google, Meta
    Leetcode Link               : https://leetcode.com/problems/design-hashmap/
*/

/************************************ C++ ************************************/

//Approach-1 : Brute Force - Using vector of size 10^6+1
//This solution is not good because we are taking huge space which might not be accepted in interviews
class MyHashMap {
public:
    vector<int> vec;
    int sz;
    
    MyHashMap() {
        sz = 1e6+1;
        
        vec.resize(sz);
        
        fill(vec.begin(), vec.end(), -1);
    }
    
    void put(int key, int value) {
       vec[key] = value; 
    }
    
    int get(int key) {
       return vec[key] ;
    }
    
    void remove(int key) {
      vec[key]  =-1;
    }
};


//Approach-2 : Using chaining approach and using less space
class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<list<pair<int, int>>> bucket;
    int size = 10000;
    MyHashMap() {
        bucket.resize(size);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int bucket_no = key%size;
        auto& chain = bucket[bucket_no];
        for(auto& it:chain) {
            if(it.first == key) {
                it.second = value;
                return;
            }
        }
        chain.emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int bucket_no = key%size;
        auto& chain = bucket[bucket_no];
        if(chain.empty())
            return -1;
        
        for(auto& it:chain) {
            if(it.first == key)
                return it.second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int bucket_no = key%size;
        auto& chain = bucket[bucket_no];
        
        /*Traditional way to remove from a list*/
        for (auto it=chain.begin(); it!=chain.end(); ) {
            if(it->first == key) {
                chain.erase(it);
                return;
            }
            it++;
        }
        
        /*Smart way to remove from a list*/
        //chain.remove_if([key](auto it) { return it.first == key; });
    }
};


/************************************ JAVA ************************************/
//Approach-1 : Brute Force - Using vector of size 10^6+1
//This solution is not good because we are taking huge space which might not be accepted in interviews
//T.C : See comments below
class MyHashMap {
    private int[] vec;
    private int sz;

    public MyHashMap() {
        sz = 1000001;
        vec = new int[sz];
        Arrays.fill(vec, -1);
    }

    public void put(int key, int value) { //O(1)
        vec[key] = value;
    }

    public int get(int key) { //O(1)
        return vec[key];
    }

    public void remove(int key) { //O(1)
        vec[key] = -1;
    }
}


//Approach-2
class MyHashMap {
    private List<Pair>[] bucket;
    private int size = 10000;

    static class Pair {
        int key;
        int value;

        Pair(int key, int value) {
            this.key = key;
            this.value = value;
        }
    }

    public MyHashMap() {
        bucket = new LinkedList[size];
        for (int i = 0; i < size; i++) {
            bucket[i] = new LinkedList<>();
        }
    }

    public void put(int key, int value) { //Worst - O(size), Ammortized O(1)
        int bucketNo = key % size;
        List<Pair> chain = bucket[bucketNo];
        for (Pair pair : chain) {
            if (pair.key == key) {
                pair.value = value;
                return;
            }
        }
        chain.add(new Pair(key, value));
    }
 
    public int get(int key) { //Worst - O(size), Ammortized O(1)
        int bucketNo = key % size;
        List<Pair> chain = bucket[bucketNo];
        for (Pair pair : chain) {
            if (pair.key == key) {
                return pair.value;
            }
        }
        return -1;
    }

    public void remove(int key) { //Worst - O(size), Ammortized O(1)
        int bucketNo = key % size;
        List<Pair> chain = bucket[bucketNo];
        for (Pair pair : chain) {
            if (pair.key == key) {
                chain.remove(pair);
                return;
            }
        }
    }
}
