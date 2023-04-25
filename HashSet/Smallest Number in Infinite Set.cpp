/*
     MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=qiSjBraBzLM
     Company Tags                : Microsoft
     Leetcode Link               : https://leetcode.com/problems/smallest-number-in-infinite-set/
*/

//Approach-1 (Using vector<bool> of size 1000 (after seeing the constraints)
class SmallestInfiniteSet {
public:
    vector<bool> nums;
    int i;
    
    SmallestInfiniteSet() {
        nums = vector<bool>(1001, true);
        i = 1;
    }
    
    int popSmallest() {
        
        int result = i;
        
        nums[i] = false;
        for(int j = i + 1; j < 1001; j++) {
            if(nums[j] == true) {
                i = j;
                break;
            }
        }
        
        return result;
        
    }
    
    void addBack(int num) {
        nums[num] = true;
        if(num < i) {
            i = num;
        }
    }
};


//Approach-2 (Using map + priority+queue + a variable to point to smallest num)
class SmallestInfiniteSet {
public:
    
    int currSmallest;
    unordered_set<int> st;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    SmallestInfiniteSet() {
        currSmallest = 1;
    }
    
    int popSmallest() {
        int result;
        
        if(!pq.empty()) {
            result = pq.top();
            pq.pop();
            st.erase(result);
        } else {
            result = currSmallest;
            currSmallest += 1;
        }
        
        return result;
    }
    
    void addBack(int num) {
        if(num >= currSmallest || st.find(num) != st.end())
            return;
        
        st.insert(num);
        pq.push(num);
    }
};


//Approach-3 (Using only ordered_set and a variable to point to smallest num)
class SmallestInfiniteSet {
public:
    set<int> st;
    
    int currSmallest;
    
    SmallestInfiniteSet() {
        currSmallest = 1;
    }
    
    int popSmallest() {
        int result;
        
        if(!st.empty()) {
            result = *st.begin();
            st.erase(st.begin()); //or, st.erase(result) also works
        } else {
            result = currSmallest;
            currSmallest += 1;
        }
        
        return result;
    }
    
    void addBack(int num) {
        if(num >= currSmallest || st.find(num) != st.end())
            return;
        
        st.insert(num);
    }
};
