/*
    Company Tags  : Google, LinkedIn, Netflix, Apple, Microsoft
    Leetcode Link : https://leetcode.com/problems/time-based-key-value-store/
*/

//NOTE : You can also use  - unordered_map<string, map<int, string>> mp;
class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
        pair<int, string> ref = make_pair(timestamp, "");
            
        auto lambda = [](const pair<int, string>& p1, const pair<int, string>& p2) {
            return p1.first < p2.first;
        };
        
        auto it = upper_bound(begin(mp[key]), end(mp[key]), ref, lambda);
        
        if(it == mp[key].begin())
            return "";
        
        return prev(it)->second;
    }
};

