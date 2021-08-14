/*
    Company Tags  : HyperVerge
    Leetcode Link : https://leetcode.com/problems/constrained-subsequence-sum/
    
    Please also see "Leetcode - 239 Sliding Window Maximum"  Both are similar to a great extent and this is the hard version.
*/

//Approach-1 (Recursion+Memo) - TLE (18 / 25 test cases passed)
/*
	You should always start from an approach like this for 
	any DP problem.
*/
class Solution {
public:
    int k, n;
    unordered_map<string, int> mp;
    int solve(vector<int>& nums, int idx, int lastIdx) {
        if(idx >= n) return 0;
        string key = to_string(idx) + "_" + to_string(lastIdx);
        if(mp.count(key))
            return mp[key];
        
        if(lastIdx == -1) {
            int taken    = nums[idx] + solve(nums, idx+1, idx);
            int notTaken = solve(nums, idx+1, lastIdx);
            return mp[key] = max(taken, notTaken);
        } else if(idx-lastIdx <= k) {
            int taken    = nums[idx] + solve(nums, idx+1, idx);
            int notTaken = solve(nums, idx+1, lastIdx);
            return mp[key] = max(taken, notTaken);
        }
        
        return mp[key] = 0;
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        this->n = nums.size();
        this->k = k;
        int val = solve(nums, 0, -1);
        mp.clear();
        
        if(val == 0)
            return *max_element(begin(nums), end(nums));
        return val;
    }
};

//Approach-2 (Bottom Up DP) - TLE (20 / 25 test cases passed)
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> t(n, 0);
        for(int i = 0; i<n; i++)
            t[i] = nums[i];
        
        int maxR = t[0];
        
        for(int i = 1; i<n; i++) {
            for(int j = i-1; i-j <= k && j >= 0; j--) {
                t[i] = max(t[i], nums[i] + t[j]);
            }
            
            maxR = max(maxR, t[i]);
        }
        
        
        return maxR;
    }
};

//Approach-3 (Using Priority_queue) Accepted
/*
	Basically in approach-2, you want the maximum value in the range of [i, i-k]
	Why not store them in max heap and access them in one go
*/

class Solution {
public:
    typedef pair<int, int> P;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> t(n, 0);
        t = nums;
        priority_queue<P, vector<P>> pq;
        pq.push({t[0], 0});
        
        int maxR = t[0];
        
        for(int i = 1; i<n; i++) {
            
            while(!pq.empty() && pq.top().second < i - k)
                pq.pop();
            
            t[i] = max(t[i], nums[i] + pq.top().first);
            pq.push({t[i], i});
            
            maxR = max(maxR, t[i]);
        }
        
        
        return maxR;
    }
};

//Approach-4 (Using monotonic decreasing deque) Accepted
/*
		This is similar to approach-3 it's just we maintain decreasing order.
		NOTE : Approach-3 and Approach-4 are used to solve "Sliding Window Maximum" also with similar approach (Leetcode-239)
		Link : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Sliding%20Window/Sliding%20Window%20Maximum.cpp
*/

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> deq;
        vector<int> t(nums);
        int maxR = t[0];
        
        for(int i = 0; i<n; i++) {
            
            while(!deq.empty() && deq.front() < i-k)
                deq.pop_front();
            
            if(!deq.empty())
                t[i] = max(t[i], nums[i] + t[deq.front()]);
            
            //we maintain the deque in descending order
            while(!deq.empty() && t[i] >= t[deq.back()])
                deq.pop_back();
            
            deq.push_back(i);
            
            maxR = max(maxR, t[i]);
        }
        
        return maxR;
    }
};
