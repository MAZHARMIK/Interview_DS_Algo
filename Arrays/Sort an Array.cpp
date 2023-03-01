/*
    MY YUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=PnyxRdn-N9U
    Company Tags               : Microsoft, Goldman Sachs, Cisco
    Leetcode Link              : https://leetcode.com/problems/sort-an-array/
*/

//solving using Counting Sort (O(n+k))
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int minE = *min_element(begin(nums), end(nums));
        int maxE = *max_element(begin(nums), end(nums));
        
        unordered_map<int, int> mp;
        
        for(int &num : nums)
            mp[num]++;
        
        int i = 0;
        
        for(int num = minE; num <= maxE; num++) {
            
            while(mp[num] > 0) {
                nums[i] = num;
                i++;
                mp[num]--;
            }
            
        }
        
        return nums;
    }
};
