/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=cau0JE1q_ZA
    Company Tags                : Google, Meta, Netflix, Amazon, Apple, Baidu
    Leetcode Link               : https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
    Best explanation Hindi      : https://www.youtube.com/watch?v=XjLT4TaXsgw&t=337s
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        unordered_map<long, int> mp[n];
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                auto diff = (long)nums[i]-nums[j];
                auto it = mp[j].find(diff);
                
                int count_at_j = it==end(mp[j]) ? 0 : it->second;
                
                mp[i][diff] = count_at_j+1;
                result    += count_at_j;
                
            }
        }
        return result;
    }
};
