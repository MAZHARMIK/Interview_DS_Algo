/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=CTYIzzT9agE
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/maximize-score-after-n-operations/
*/

//Approach-1 (Recusion Brute Force Backtracking) - Using boolean visited array
class Solution {
public:
    int n;
    int solve(vector<int>&nums, vector<bool>&visited, int operation) { 
        
        int maxScore = 0;
        
        for (int i = 0; i < n - 1; i++) {
            if (visited[i])
                continue;
            
            for (int j = i + 1; j < n; j++) {
                if (visited[j])
                    continue;
                
                visited[i] = true;
                visited[j] = true;
                
                int currScore      = operation * __gcd(nums[i], nums[j]);
                int remainingScore = solve(nums, visited, operation + 1);
                maxScore           = max(maxScore, currScore + remainingScore);
                
                visited[i] = false;
                visited[j] = false;
            }
        }
        
        return maxScore;
    }
    int maxScore(vector<int>& nums) {
        n = nums.size();
        
        vector<bool>visited(n, false);
        
        int ans = solve(nums, visited, 1);
        
        return ans;
        
    }
};

//Approach-2 (Memoizing Approach-1 above)
class Solution {
public:
    int n;
    int solve(vector<int>&nums, vector<bool>&visited, int operation, unordered_map<vector<bool>, int>& mp) { 
        
        if(mp.find(visited) != mp.end())
            return mp[visited];
        
        int maxScore = 0;
        
        for (int i = 0; i < n - 1; i++) {
            if (visited[i])
                continue;
            
            for (int j = i + 1; j < n; j++) {
                if (visited[j])
                    continue;
                
                visited[i] = true;
                visited[j] = true;
                
                int currScore      = operation * __gcd(nums[i], nums[j]);
                int remainingScore = solve(nums, visited, operation + 1, mp);
                maxScore           = max(maxScore, currScore + remainingScore);
                
                visited[i] = false;
                visited[j] = false;
            }
        }
        
        return mp[visited] = maxScore;
    }
    int maxScore(vector<int>& nums) {
        n = nums.size();
        
        vector<bool>visited(n, false);
        
        unordered_map<vector<bool>, int> mp;
        
        int ans = solve(nums, visited, 1, mp);
        
        return ans;
        
    }
};


//Approach-3 (Recusion + Memo) - Using Bit Mask
class Solution {
public:
    int n;
    
    int solve(vector<int>& nums, int mask, int operation, vector<int>& memo) {
        if(2*operation == nums.size())
            return 0;
        
        if(memo[mask] != -1) {
            return memo[mask];
        }
        
        int maxScore = 0;
        
        for(int i = 0; i<n; i++) {
            for(int j = i+1; j<n; j++) {
                
                if(((mask >> i) & 1) == 1 || ((mask >> j) & 1) == 1)
                    continue;
                
                int newMask = mask | (1 << i) | ((1 << j));
                
                int currScore      = (operation+1) * __gcd(nums[i], nums[j]);
                
                int remainingScore = solve(nums, newMask, operation+1, memo);
                
                maxScore = max(maxScore, currScore+remainingScore);
                
            }
        }
        
        memo[mask] = maxScore;
        return maxScore;
    }
    
    int maxScore(vector<int>& nums) {
        n = nums.size();
        
        int memosize = 1<<n;
        
        vector<int> t(memosize, -1);
        
        return solve(nums, 0, 0, t);
    }
};
