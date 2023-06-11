/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=yEYoNCom72Q
    Company Tags                : Microsoft, Amazon
    Leetcode Link               : https://leetcode.com/problems/snapshot-array/
*/

//Approach-1 : Brute Force - Store all states of array for all snap ids
//You can write it on your own. A very simple one.


//Approach-2 : Use Own Binary Search - O(nlogn)
class SnapshotArray {
public:
    
    int snap_id;
    
    vector<vector<pair<int, int>>> vec;
    
    SnapshotArray(int length) {
        snap_id = 0;
        
        vec.resize(length);
        
        for(int i = 0; i < length; i++) {
            
            vec[i].push_back(make_pair(0, 0));
            
        }
    }
    
    void set(int index, int val) {
        
        vec[index].push_back(make_pair(snap_id, val));
        
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        
        int l = 0, r = vec[index].size()-1;
        
        int result = 0;
        while(l <= r) {
            
            int mid = l + (r-l)/2;
            
            if(vec[index][mid].first <= snap_id) {
                result = vec[index][mid].second;
                l = mid+1;
            } else {
                r = mid-1;
            }
            
        }
        
        return result;
        
    }
};


//Approach-3 : Use upper_bound - O(nlogn)
class SnapshotArray {
public:
    
    int snap_id;
    
    vector<vector<pair<int, int>>> vec;
    
    SnapshotArray(int length) {
        snap_id = 0;
        
        vec.resize(length);
        
        for(int i = 0; i < length; i++) {
            
            vec[i].push_back(make_pair(0, 0));
            
        }
    }
    
    void set(int index, int val) {
        
        vec[index].push_back(make_pair(snap_id, val));
        
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        
        auto it = upper_bound(begin(vec[index]), end(vec[index]), make_pair(snap_id, INT_MAX));
        //pair(snap_id, val)
        
        return prev(it)->second;
        
    }
};
