/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=3yTnLrNdJGo
    Company Tags                : Amazon, Twitter, Facebook, Uber, Google, Bloomberg, Microsoft
    Leetcode Link               : https://leetcode.com/problems/insert-delete-getrandom-o1/
*/

/****************************************************** C++ ******************************************************/
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> vec;
    unordered_map<int, int> mp;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.find(val) != mp.end())
            return false;
        
        vec.push_back(val);
        mp[val] = vec.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) == mp.end())
            return false;
        
        int idx       = mp[val];
        int temp      = vec.back();
        vec.back()    = val;
        vec[idx]      = temp;
        mp[temp]      = idx;
        vec.pop_back();
        mp.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand()%vec.size();
        return vec[idx];
    }
};



/****************************************************** JAVA ******************************************************/
class RandomizedSet {
    private ArrayList<Integer> list;
    private HashMap<Integer, Integer> map;
    private Random random;

    /** Initialize your data structure here. */
    public RandomizedSet() {
        list = new ArrayList<>();
        map = new HashMap<>();
        random = new Random();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public boolean insert(int val) {
        if (map.containsKey(val)) {
            return false;
        }
        list.add(val);
        map.put(val, list.size() - 1);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public boolean remove(int val) {
        if (!map.containsKey(val)) {
            return false;
        }
        int idx = map.get(val);
        int lastElement = list.get(list.size() - 1);
        list.set(idx, lastElement);
        map.put(lastElement, idx);
        list.remove(list.size() - 1);
        map.remove(val);
        return true;
    }
    
    /** Get a random element from the set. */
    public int getRandom() {
        int idx = random.nextInt(list.size());
        return list.get(idx);
    }
}

