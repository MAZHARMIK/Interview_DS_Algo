/*
    Company Tags  : <Will share soon>
    Leetcode Link : https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
*/

//Approach-1 (Recur + Memo) - TLE (2 / 50 test cases passed.)
class Solution {
public: 
    int n, m;
    unordered_map<string, int> mp;
    int solve(vector<int>& nums, int i, int j, vector<int>& multi, int k) {
        if(k >= m || i > j)
            return 0;
        
        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(k);
        
        if(mp.find(key) != mp.end())
            mp[key];
        
        int choose_left  = nums[i]*multi[k];
        int choose_right = nums[j]*multi[k];
        
        return mp[key] = max(choose_left + solve(nums, i+1, j, multi, k+1),
                  choose_right + solve(nums, i, j-1, multi, k+1));
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        n = nums.size();
        m = multi.size();
        mp.clear();
        int i = 0;
        int j = n-1;
        int k = 0;
        return solve(nums, i, j, multi, k);
    }
};
    

//Approach-2 (Better Memoization) - ACCEPTED
class Solution {
public: 
    int n, m;
    int t[1001][1001];
    int solve(vector<int>& nums, int i, vector<int>& multi, int k) {
        if(k >= m)
            return 0;
        
        /*
            How to find j from i and k ?
            - Let's say we did 4 operations till now
            - 'i' is ahead by 2
            - It means, other (4-2) opeations were done from right side (jth index)
            - So, 'j' is ahead from behind (n-1) by (4-2) i.e. (k-i)
        */
        
        int j = (n-1) - (k-i);
            
        if(t[i][k] != INT_MIN)
            return t[i][k];
        
        int choose_left  = nums[i]*multi[k];
        int choose_right = nums[j]*multi[k];
        
        return t[i][k] = max(choose_left + solve(nums, i+1, multi, k+1),
                  choose_right + solve(nums, i, multi, k+1));
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        n = nums.size();
        m = multi.size();
        
        //Since memset can only set -1 and 0, so we loop here to fill the array
        /*
            Why we are filling it with INT_MIN and not -1 ?
            - A simple answer can be that our final result can be -1 as well and
            in that case memoization will not work.
            So, we used INT_MIN instead of -1
            
            More detail -> https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/discuss/1075496/C++Python-Classic-DP/1604231
        */
        for(int i = 0; i<1001; i++) {
            for(int j = 0; j<1001; j++) {
                t[i][j] = INT_MIN;
            }
        }
        
        int i = 0;
        int k = 0;
        return solve(nums, i, multi, k);
    }
};

//Approach-3 (Bottom Up DP) - Accepted (Coming soon)
