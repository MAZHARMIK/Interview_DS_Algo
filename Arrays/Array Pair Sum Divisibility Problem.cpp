/*
    Company Tags       : Amazon, Directi, Goldman Sachs, Microsoft
    GfG Link           : https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1?page=3&curated[]=1&sortBy=submissions
    Good Video on this : https://www.youtube.com/watch?v=BvKv-118twg
*/

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int count = 0;
        if(n%2) return false;
        
        for(int i = 0; i<n; i++) {
            mp[nums[i]%k]++;
        }

        for(int i = 0; i<n; i++) {
            int remain = nums[i]%k;
            
            if(remain == 0) {
                if(mp[remain]%2) return false;
            } else if(2*remain == k) {
                if(mp[remain]%2) return false;
            } else {
            
                int findremain = k-remain;
                
                if(mp[remain] != mp[findremain])
                    return false;
            }
        }
        
        return true;
    }
};
