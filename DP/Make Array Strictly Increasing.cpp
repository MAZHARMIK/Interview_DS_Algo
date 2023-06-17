/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ct036xxMtT8
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/make-array-strictly-increasing/
*/

//Approach-1 (Using simple Recursion + Memoization) - O(n*n*log(n))
class Solution {
public:
    map<pair<int, int>, int> mp;
    
    int solve(int idx, vector<int>& arr1, vector<int>& arr2, int prev) {
        if(idx == arr1.size())
            return 0;
        
        int result1 = 1e9+1;
        
        if(mp.find({idx, prev}) != mp.end())
            return mp[{idx, prev}];
        
        if(arr1[idx] > prev) {
            result1 = solve(idx+1, arr1, arr2, arr1[idx]);
        }
        
        int result2 = 1e9+1;
        auto it = upper_bound(begin(arr2), end(arr2), prev);
        
        if(it != end(arr2)) {
            int i = it - begin(arr2);
            result2 = 1 + solve(idx+1, arr1, arr2, arr2[i]);
        }
        
        return mp[{idx, prev}] = min(result1, result2);
        
        
    }
    
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(begin(arr2), end(arr2));
        mp.clear();
        
        int result = solve(0, arr1, arr2, INT_MIN);
        
        if(result == 1e9+1)
            return -1;
        
        return result;
    }
};



//Approach-2 (Using Bottom Up)
//Soon
