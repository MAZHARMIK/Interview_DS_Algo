/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=YyuwTwXzSxY
    Company Tags                : Google, Facebook, Snapchat
    Leetcode Link               : https://leetcode.com/problems/combination-sum-iv/
*/

/*************************************************************** C++ ***************************************************************/
//Approach-1 (Using Khandaani Backtracking Template + Memoization to Pass)
/*
The main crux here is that you will have to start again from index 0 to consider all possible combinations
For example : in [1,2,3], target = 4
We can also have [1, 2, 1] -> I added 1 and then 2 and then again added 1 (This is possible only when we
restart from 0 also)
*/
//T.C : O(N*target)
class Solution {
public:
    int n;
    int t[1001][201];
    int solve(vector<int>& nums, int target, int idx) {
        if(target == 0)
            return 1;
        
        if(idx >= n || target < 0)
            return 0;
        
        if(t[target][idx] != -1)
            return t[target][idx];
        
        int take_idx    = solve(nums, target - nums[idx], 0);
        int reject_idx  = solve(nums, target, idx+1);
        
        return t[target][idx] = take_idx + reject_idx;
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        
        return solve(nums, target, 0);
    }
};

//Approach-2 (Same backtracking + but just using for loop)
//T.C : O(N*target)
class Solution {
public:
    int n;
    int t[1001][201];
    
    int solve(int idx, vector<int>& nums, int target) {
        if(target == 0)
            return 1;
        
        if(idx >= n || target < 0)
            return 0;
        
        int result = 0;
        
        if(t[target][idx] != -1)
            return t[target][idx];
        
        for(int i = idx; i<n; i++) {
            int take_i   = solve(0, nums, target-nums[i]);
            
            result += take_i;
        }
        
        return t[target][idx] = result;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, nums, target);
    }
};

//Approach-3 (In Approach-2 above, you can see that we no longer need to pass idx BECAUSE the for loop always starts from 0)
//So, remove idx from parameter
//T.C : O(N*target)
class Solution {
public:
    int n;
    int t[2001];
    
    int solve(vector<int>& nums, int target) {
        if(target == 0)
            return 1;
        
        if(target < 0)
            return 0;
        
        int result = 0;
        
        if(t[target] != -1)
            return t[target];
        
        for(int i = 0; i<n; i++) {
            int take_i   = solve(nums, target-nums[i]);
            
            result += take_i;
        }
        
        return t[target] = result;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, target);
    }
};




/*************************************************************** JAVA ***************************************************************/
//Converting Approach-3 above to JAVA
class Solution {
    int[] t;
    public int combinationSum4(int[] nums, int target) {
        t = new int[target+1];
        Arrays.fill(t,-1);
        return solve(nums,target);
    }
    public int solve(int[] nums, int target)
    {
        if(target == 0) {
            return 1;
        }
        if(target < 0) {
            return 0;
        }
        
        if(t[target] != -1) {
            return t[target];
        }
        
        int result = 0;
        for(int i = 0; i<nums.length;i++) {
            result += solve(nums, target-nums[i]);
        }
        return t[target] = result;
    }
}
