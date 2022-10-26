/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=wmn3c1mP0pY&t=152s
    Company Tags                : Amazon, Facebook, Paytm
    Leetcode Link               : https://leetcode.com/problems/continuous-subarray-sum/
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        
        mp[0] = -1;
        
        int sum = 0;
        
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            
            int remainder = sum%k;
            
            if(mp.find(remainder) != mp.end()) {
                
                if(i - mp[remainder] >= 2)
                    return true;
                
            } else {
                mp[remainder] = i;
            }
        }
        return false;
    }
};
