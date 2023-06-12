/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=PyYZCJRAMmY
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/summary-ranges/
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return {};
        
        vector<string> result;
        
        for(int i = 0; i<n; i++) {
            
            int start = nums[i];
            
            while(i+1 < n && nums[i]+1 == nums[i+1]) {
                i++;
            }
            
            if(start != nums[i]) {
                result.push_back(to_string(start) + "->" + to_string(nums[i]));
            } else {
                result.push_back(to_string(start));
            }
            
        }
        
        return result;
        
    }
};
