/*
    MY YOUTUBE VIDEO ON THIS Qn : Brute Force - https://www.youtube.com/watch?v=eptC4nUL_2A
                                  Optimal     - https://www.youtube.com/watch?v=PiGYS7BbV_Q
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
*/


//Complete Brute Force using MinHeap - TIME COMPLEXITY = O(m*n*log(k)) - TLE
class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P, vector<P>> pq;
        
        int m = nums1.size();
        int n = nums2.size();
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                
                int sum = nums1[i] + nums2[j];

                if(pq.size() < k) {
                    pq.push({sum, {i, j}});
                } else if(pq.top().first > sum) {
                    pq.pop();
                    pq.push({sum, {i, j}});
                }
            }
        }
        
        vector<vector<int>> result;
        
        while(!pq.empty()) {
            auto temp = pq.top(); 
            pq.pop();
            
            int i = temp.second.first;
            int j = temp.second.second;
            result.push_back({nums1[i], nums2[j]});
        }
        
        return result;
    }
};


//Approach-2 (Improved BRUTE FORCE) 
//Complete Brute Force using MinHeap - TIME COMPLEXITY < O(m*n*log(k)) - ACCEPTED
class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P, vector<P>> pq;
        
        int m = nums1.size();
        int n = nums2.size();
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                
                int sum = nums1[i] + nums2[j];

                if(pq.size() < k) {
                    pq.push({sum, {i, j}});
                } else if(pq.top().first > sum) {
                    pq.pop();
                    pq.push({sum, {i, j}});
                } else {
                    break; //Breaking from here (slight improvement)
                }
            }
        }
        
        vector<vector<int>> result;
        
        while(!pq.empty()) {
            auto temp = pq.top(); 
            pq.pop();
            
            int i = temp.second.first;
            int j = temp.second.second;
            result.push_back({nums1[i], nums2[j]});
        }
        
        return result;
    }
};

//Approach-3 (Slight Better approach) - O(klog(k))
class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        priority_queue<P, vector<P>, greater<P>> pq; //min-heap
        
        set<pair<int, int>> visited;
        visited.insert({0, 0});
        
        int sum = nums1[0] + nums2[0];
        
        pq.push({sum, {0, 0}});
        
        vector<vector<int>> result;
        while(k-- && !pq.empty()) {
            
            auto temp = pq.top(); 
            pq.pop();
            
            int i = temp.second.first;
            int j = temp.second.second;
            result.push_back({nums1[i], nums2[j]});
            
            //Push (i, j+1) if possible
             if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }

            //Push (i+1, j) if possible
            if (i + 1 < m && visited.find({i + 1, j}) == visited.end()) {
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }
            
        }
        
        return result;
    }
};
