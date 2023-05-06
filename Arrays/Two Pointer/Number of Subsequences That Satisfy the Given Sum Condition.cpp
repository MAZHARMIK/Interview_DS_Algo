/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
*/

//Approach-1 (Produce all subsequences, find min and max and check)
//This will give TLE


//Approach-2 (Using Sorting + Two Pointer Approach)
class Solution {
public:
    int M = 1e9+7;
    
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        int l = 0, r = n-1;
        int result = 0;
        
        vector<int> power(n);
        power[0] = 1;
        for(int i = 1; i<n; i++) {
            power[i] = (power[i-1]*2) % M;
        }
        
        while(l <= r) {
            
            if(nums[l] + nums[r] <= target) {
                result = (result%M + power[r-l])%M;
                l++;
            } else {
                r--;
            }
            
        }
        
        return result;
    }
};
