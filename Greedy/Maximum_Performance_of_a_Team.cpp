/*
    Company Tags  : Let me know when you get it. It's a tough question
    Leetcode Link : https://leetcode.com/problems/maximum-performance-of-a-team/
*/

class Solution {
public:
    int M = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> emp(n);
        for(int i = 0; i<n; i++) {
            emp[i].first  = speed[i];
            emp[i].second = efficiency[i];
        }
        
        auto lambda_sort = [&](pair<int, int>& p1, pair<int, int>& p2) {
            return p1.second > p2.second;
        };
        
        sort(begin(emp), end(emp), lambda_sort);
        
        
        priority_queue<int, vector<int>, greater<int>> pq; //min heap
        
        long result = 0;
        long speed_sum = 0;
        for(int i = 0; i<n; i++) {
            speed_sum += emp[i].first;
            pq.push(emp[i].first);
            if(pq.size() > k) {
                speed_sum -= pq.top();
                pq.pop();
            }
            
            result = max(result, speed_sum*emp[i].second);
        }
        
        return result % M;
    }
};
