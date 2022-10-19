/*
    MY YOUTUBE VIDEO ON THIS Qn (Approach-1) : https://www.youtube.com/watch?v=zW-8-6A2gxM
    MY YOUTUBE VIDEO ON THIS Qn (Approach-2) : <soon>
    Company Tags                             : Pocket Gems, Amazon, Bloomberg, Yelp, Uber, Microsoft, Adobe, Citrix
    Leetcode Link                            : https://leetcode.com/problems/top-k-frequent-words/
*/

//Approach-1 (Time : O(nlogn), Space : O(n))
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int, string>> vp;
        unordered_map<string, int> mp;
        
        for(string &word : words) {
            mp[word]++;
        }
        
        for(auto &it : mp) {
            vp.push_back({it.second, it.first});
        }
        
        auto lambda = [](pair<int, string>& p1, pair<int, string>& p2) {
            if(p1.first == p2.first)
                return p1.second < p2.second;
            
            return p1.first > p2.first;
        };
        
        sort(begin(vp), end(vp), lambda);
        
        int i = 0;
        vector<string> result(k);
        while(i < k) {
            result[i] = vp[i].second;
            i++;
        }
        
        return result;
    }
};

//Approach-2 (Using Heap - Time : O(nlogk), Space : O(n))
class Solution {
public:
    typedef pair<string, int> P;
    
    struct lambda {
        bool operator()(P& a, P& b){
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        }  
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<P, vector<P>, lambda> pq;
        
        unordered_map<string, int> mp;
        
        for(string &word : words) {
            mp[word]++;
        }
        
        for(auto &it : mp) {
            pq.push({it.first, it.second});
            
            if(pq.size() > k)
                pq.pop();
        }
        
        int i = k-1;
        vector<string> result(k);
        while(!pq.empty()) {
            result[i] = pq.top().first;
            pq.pop();
            i--;
        }
        
        return result;
    }
};
