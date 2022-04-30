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
private:
    int n, k;
    unordered_map<string, int> mp;
public:
    int solve(vector<int>& nums, int last_chosen_index, int curr_index) {
        if(curr_index >= n)
            return 0;
        string key = to_string(last_chosen_index) + "_" + to_string(curr_index);
        
        if(mp.find(key) != end(mp))
            return mp[key];
        int result = 0;
        if(last_chosen_index == -1) {
            //take curr_index element
            int taken = nums[curr_index] + solve(nums, curr_index, curr_index+1);
            
            //don't take curr_index element
            int not_taken = solve(nums, -1, curr_index+1);
            
            result = max(taken, not_taken);
            
        } else if(curr_index-last_chosen_index <= k) {
            //take curr_index element
            int taken     = nums[curr_index] + solve(nums, curr_index, curr_index+1);
            
            //don't take curr_index element
            int not_taken = solve(nums, last_chosen_index, curr_index+1);
            result = max(taken, not_taken);
        }
        
        
        return mp[key] = result;
    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        this->n = nums.size();
        this->k = k;
        
        int val = solve(nums, -1, 0);
        if(val == 0)
            return -1;
        return val;
    }
};

//Approach-2 (Bottom Up DP) - TLE (20 / 25 test cases passed)
/*
	NOTE : This is basically using the concept of Longest Increasing Subsequence (LIS)
	This can be further improved (from TLE) by using extra data structure. Loog for next approaches.
*/
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
            
	    //first get rid of out of range indices
            while(!deq.empty() && deq.front() < i-k)
                deq.pop_front();
            
            if(!deq.empty())
                t[i] = max(t[i], nums[i] + t[deq.front()]);
            
            //we maintain the deque in descending order
	    //So that you can get the optimum value at once from front
            while(!deq.empty() && t[i] >= t[deq.back()])
                deq.pop_back();
            
            deq.push_back(i);
            
            maxR = max(maxR, t[i]);
        }
        
        return maxR;
    }
};
