/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ZoSVDi7lk-4
    Company Tags  : META
    Leetcode Link : https://leetcode.com/problems/number-of-longest-increasing-subsequence/
*/

//Using same code of LIS - (T.C : O(n^2))
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> t(n, 1);
        vector<int> count(n, 1);
        
        for(int i = 0; i<n; i++) {
            
            for(int j = 0; j<i; j++) {
                
                if(nums[j] < nums[i]) {
                    
                    if(t[i] == t[j] + 1)
                        count[i] += count[j];
                    else if(t[i] < t[j] + 1){
                        t[i] = t[j] + 1;
                        count[i] = count[j];
                    }
                    
                }
                
            }
            
        }
        
        int maxVal = *max_element(begin(t), end(t));
        
        int result = 0;
        for(int i = 0; i<n; i++) {
            if(t[i] == maxVal) {
                result += count[i];
            }
        }
        
        return result;
    }
};
