/*
    Company Tags          : Samsung, Google, Snapchat
    Leetcode Link         : https://leetcode.com/problems/burst-balloons/
    Similar Tough Problem : Remove Boxes (Leetcode-546)
*/

class Solution {
public:
    int solve_memoized(vector<int>& nums, int left, int right, vector<vector<int>>& t) {
        if(left+1 == right)
            return 0;
        
        if(t[left][right] != -1)
            return t[left][right];
        int maxS = 0;
        for(int i = left+1; i<right; i++) {
            maxS = max(maxS, nums[left]*nums[i]*nums[right]+solve_memoized(nums, left, i, t)+solve_memoized(nums, i, right, t));
            //I am selecting which balloon (nums[i]) produces max result (where i is in between left and right)
        }
        return t[left][right] = maxS;
    }
    
    int solve_topDown(vector<int>& nums) {
        int n = nums.size();
        vector<int> new_nums(n+2);
        new_nums[0] = 1;
        new_nums[n+1] = 1;
        for(int i = 0; i<n; i++) {
            new_nums[i+1] = nums[i];
        }
        vector<vector<int>> t(n+2, vector<int>(n+2, 0));
        for(int L = 1; L<=n; L++) {
            for(int i = 1; i<=n-L+1; i++) {
                int j = i+L-1;
                
                for(int k = i; k<=j; k++) {
                    t[i][j] = max(t[i][j], t[i][k-1]+(new_nums[i-1]*new_nums[k]*new_nums[j+1])+t[k+1][j]);
                }
            }
        }
        return t[1][n];
    }
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> new_nums(n+2);
        new_nums[0] = 1;
        new_nums[n+1] = 1;
        for(int i = 0; i<n; i++) {
            new_nums[i+1] = nums[i];
        }
        vector<vector<int>> t(n+3, vector<int>(n+3, -1));
        
        //return solve_memoized(new_nums, 0, n+1, t);
        return solve_topDown(nums);
    }
};
