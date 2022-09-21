/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=pA4fX-Mvkyw
    Company Tags                : Indeed (Frequently Asked)
    Leetcode Link               : https://leetcode.com/problems/sum-of-even-numbers-after-queries/
*/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        
        int sumEven = 0;
        for(int &x : nums) {
            if(x%2 == 0) sumEven += x;
        }
        
        vector<int> result;
        
        for(int i = 0; i<q; i++) {
            int val  = queries[i][0];
            int idx  = queries[i][1];
            
            if(nums[idx] % 2 == 0) {
                sumEven -= nums[idx];
            }
            
            nums[idx] += val;
            
            if(nums[idx] % 2 == 0)
                sumEven += nums[idx];  
            
            result.push_back(sumEven);
        }
        
        return result;
    }
};
