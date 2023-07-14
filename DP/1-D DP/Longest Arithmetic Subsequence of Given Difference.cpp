/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=OHxwaAbO1A8
    Company Tags                : AMAZON, META
    Leetcode Link               : https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
*/

//Approach-1 (Recursion + Memo with 2-D Memo) - (Memory Limit Exceeded)
class Solution {
public:
    int n;
    int D;
    
    int solve(int curr_idx, vector<int>& arr, int prev_idx, vector<vector<int>>& t) {
        if(curr_idx >= n)
            return 0;
        
        int result = 0;
        if(t[prev_idx][curr_idx] != -1)
            return t[prev_idx][curr_idx];
        
        int prevVal = arr[prev_idx];
        int currVal = arr[curr_idx];

        if (currVal - prevVal == D)
            result = max(result, 1 + solve(curr_idx+1, arr, curr_idx, t));
        else {
            result = max(result, solve(curr_idx+1, arr, prev_idx, t));
        }

        return t[prev_idx][curr_idx] = result;
    }
    
    int longestSubsequence(vector<int>& arr, int difference) {
        int result = 0;
        n = arr.size();
        D = difference;
        vector<vector<int>> t(n+1, vector<int>(n+1, -1));
        for (int i = 0; i < n; i++) {
            result = max(result, 1 + solve(i+1, arr, i, t));
        }

        return result;
    }
};


//Approach-2 (Recursion + Memo with 1-D Memo) - Time Limit Exceeded
class Solution {
public:
    int n;
    int D;
    int t[100001];
    int solve(int idx, vector<int>& arr) {
        
        if(t[idx] != -1)
            return t[idx];
        
        int result = 0;
        
        for(int i = idx+1; i < n; i++) {
            int prevVal = arr[idx];
            int currVal = arr[i];


            if (currVal - prevVal == D)
                result = max(result, 1 + solve(i, arr));
        }
        
        return t[idx] = result;
    }
    
    int longestSubsequence(vector<int>& arr, int difference) {
        int result = 0;
        n = arr.size();
        D = difference;
        
        memset(t, -1, sizeof(t));
        
        for (int i = 0; i < n; i++) {
            result = max(result, 1 + solve(i, arr));
        }

        return result;
    }
};


//Approach-3 (DP using Map) - O(n) - Accepted
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp;
        int n = arr.size();
        
        int result = 0;
        for(int i = 0; i<n; i++) {
            
            int prev            = arr[i] - difference;
            
            int lengt_till_prev = mp[prev];
            
            mp[arr[i]] = lengt_till_prev + 1;
            
            result = max(result, mp[arr[i]]);
        }
        
        return result;
    }
};
