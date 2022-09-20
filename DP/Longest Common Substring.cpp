/*
    Company Tags  : Amazon, Microsoft, Morgan Stanley
    Question Link : https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1#
    Similar Leetcode Qn : Maximum Length of Repeated Subarray (https://leetcode.com/problems/maximum-length-of-repeated-subarray/)
*/

//Approach-1 (Recursion + Memoization : Top Down)
class Solution{
    public:
    unordered_map<string, int> mp;
    int solve(string S1, string S2, int n, int m, int count) {
        if(m == 0 || n == 0)
            return count;
        string key = to_string(n) + "_" + to_string(m) + "_" + to_string(count);
        if(mp.count(key)) return mp[key];
        
        int same = count;
        if(S1[n-1] == S2[m-1]) {
            same = solve(S1, S2, n-1, m-1, count+1);
        }
        
        int x = solve(S1, S2, n-1, m, 0);
        int y = solve(S1, S2, n, m-1, 0);
        
        return mp[key] = max({same, x, y});
    }
    
    int longestCommonSubstr(string S1, string S2, int n, int m) {
        mp.clear();
        return solve(S1, S2, n, m, 0);
    }
};

//Approach-2 (Bottom Up)
class Solution{
    public:
    int longestCommonSubstr (string S1, string S2, int n, int m) {
        vector<vector<int>> t(n+1, vector<int>(m+1, 0));
        //t[i][j] = Longets common Substring in S1[:i] and S2[:j]
        int maxC = 0;
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=m; j++) {
                if(S1[i-1] == S2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                    maxC = max(maxC, t[i][j]);
                } else {
                    t[i][j] = 0; //Discontinue (since we want a substring not subsequence)
                }
            }
        }
        
        return maxC;
    }
};
