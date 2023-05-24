/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=z9oUzKhEYJU
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/maximum-subsequence-score/
*/

//Approach-1 (Recursion + Memo)
class Solution {
public:
    int K;
    int n;
    unordered_map<string, int> mp;
    
    long long solve(vector<int>& nums1, vector<int>& nums2, int sum, int min_el, int i, int count) {
        if(count == K) {
            return sum * min_el;
        }
         if(i >= n) {
            return 0;
        }
        
        string key = to_string(sum) + "_" + to_string(min_el) + "_" + to_string(i) + "_" + to_string(count);
        if(mp.find(key) != mp.end())
            return mp[key];
        
        int min_now = min(min_el, nums2[i]);
        
        long take_i = solve(nums1 , nums2 , sum + nums1[i] , min_now, i+1 , count+1);
        
        long not_take_i = solve(nums1 , nums2 , sum, min_el, i+1 , count);
        
        return mp[key] = max(take_i, not_take_i);
    }
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        K = k;
        n = nums1.size();
        mp.clear();
        
        return solve(nums1 , nums2 , 0 , INT_MAX , 0 , 0);
    }
};


//Approach-2 (Using Priority Queue + Sorting)
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        
        vector<pair<int,int>> vec(n);
        
        for(int i = 0; i<n; i++) {
            vec[i] = {nums1[i], nums2[i]};
        }
        
        auto lambda = [&](auto &P1, auto &P2) {
            return P1.second > P2.second;
        };
        
        sort(begin(vec), end(vec), lambda);
        
        priority_queue<int, vector<int>, greater<int>> pq; //min_heap
        
        long long Ksum = 0;
        
        for(int i = 0; i<=k-1; i++) {
            
            Ksum += vec[i].first;
            pq.push(vec[i].first);
            
        }
        
        long long result = Ksum * vec[k-1].second;
        
        for(int i = k; i<n; i++) {
            
            //taking minimum as vec[i].second
            Ksum += vec[i].first - pq.top();
            pq.pop();
            
            pq.push(vec[i].first);
            
            result = max(result, Ksum * vec[i].second);
            
        }
        
        return result;
    }
};
