/*
    Company Tags  : Google, Facebook, Snapchat
    Leetcode Link : https://leetcode.com/problems/combination-sum-iv/
*/

class Solution {
public:
    //The main crux here is that you will have to start again from index 0 to consider all possible combinations
    //For example : in [1,2,3], target = 4
    //We can also have [1, 2, 1] -> I added 1 and then 2 and then again added 1 (This is possible only when we
    //restart from 0 also)
    int solve_1(vector<int>& nums, int target, int pos, vector<int>& cache) {
        if (pos == nums.size() || target <= 0) {
            return (target == 0) ? 1 : 0;
        }
        
        if (cache[target] != -1) {
            return cache[target];
        }
        
        int take = solve_1(nums, target - nums[pos], 0, cache); //restart from 0 also (This will take care of taking an element unlimited times)
        int skip = solve_1(nums, target, pos + 1, cache);
        
        return cache[target] = take + skip;
    }
    
    int solve_2(vector<int>& nums, int target, vector<int>& t) {
        if(nums.size() == 0)
            return 0;
        
        if(target == 0)
            return t[target] = 1;
        if(t[target] != -1)
            return t[target];
        
        int result = 0;
        //This for loop technique is nothin but just a top-down approach
        /*
            i.e. we have 4, it can be broken by 1, 2, or 3
            (broken by 1) -> we are now left with (4-1) = 3, now further this 3 can be broken by 1, 2, or 3 and so on.
            
            Similaryly,
            (broken by 2) -> we are now left with (4-2) = 2, now further this 2 can be broken by 1, 2, or 3 and so on.
            Similaryly,
            (broken by 3) -> we are now left with (4-3) = 1, now further this 1 can be broken by 1, 2, or 3 and so on.
            
            Until we reach to leaves of the DFS tree
        */
        for(int i = 0; i<nums.size(); i++) {
            if(target >= nums[i]) //just an optimization
                result += solve_2(nums, target-nums[i], t);
        }
        
        return t[target] = result;
        
    }
    
    int solve_3(vector<int>& nums, int target) {
        vector<unsigned long long> t(target+1, 0);
        t[0] = 1;
        
        for(unsigned long long i = 1; i<=target; i++) {
            for(unsigned long long j = 0; j<nums.size(); j++) {
                
                if(i >= nums[j])
                    t[i] = t[i] + t[i-nums[j]];
            }
        }
        
        return t[target];
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> t(target+1, -1);
        
        //return solve_1(nums, target, 0, t);
        
        //return solve_2(nums, target, t);
        
        return solve_3(nums, target);
        
        
    }
};
