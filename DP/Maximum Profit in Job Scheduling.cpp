/*
    Company Tags  : Not known yet but it's worth being asked. Few people mentioned that it was asked in Google but I don't have proof yet
    Leetcode Link : https://leetcode.com/problems/maximum-profit-in-job-scheduling/
*/

//Approach-1 (Recursion + Memo + Binary Search)
class Solution {
public:
    int n;
    int t[50001];
    int getNextIndex(vector<vector<int>>& array, int index, int target) {
        int l = index, r = n-1;
        int result =n+1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(array[mid][0] >= target) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>& array, int index) {
        if(index >= n)
            return 0;
        
        if(t[index] != -1)
            return t[index];
        int next     = getNextIndex(array, index+1, array[index][1]);
        int taken    = array[index][2] + solve(array, next);
        int notTaken = solve(array, index+1);
        
        return t[index] = max(taken, notTaken);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        vector<vector<int>> array(n, vector<int>(3, 0));
        for(int i = 0; i<n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }
        
        auto comp = [&](auto& vec1, auto& vec2) {
            return vec1[0] <= vec2[0];
        };
        sort(begin(array), end(array), comp);
        memset(t, -1, sizeof(t));
        return solve(array, 0);
    }
};

//Approach-2 (Bottom UP DP) - COMING SOON (I am travelling :-) )
