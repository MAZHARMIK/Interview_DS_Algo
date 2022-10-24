/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=MqMvkrkerIY
    Company Tags                : MICROSOFT'S 2020 MOST ASKED INTERVIEW QUESTION
    Leetcode Link               : https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
*/

//Approach-1 Using DP (Recur + Memo)
class Solution {
public:
    bool hasCommon(string &s1, string& s2) {
        int arr[26] = {0};
        
        for(char &ch : s1) {
            if(arr[ch-'a'] > 0)
                return true;
            arr[ch-'a']++;
        }
        
        for(char &ch : s2) {
            if(arr[ch-'a'] > 0)
                return true;
        }
        
        return false;
    }
    
    unordered_map<string, int> mp;
    
    int solve(int idx, vector<string>& arr, string temp, int n) {
        if(idx >= n)
            return temp.length();
        
        if(mp.find(temp) != mp.end())
            return mp[temp];
        
        int include = 0;
        int exclude = 0;
        if(hasCommon(arr[idx], temp)) {
            exclude = solve(idx+1, arr, temp, n);
        } else {
            exclude = solve(idx+1, arr, temp, n);
            temp += arr[idx];
            include = solve(idx+1, arr, temp, n);
        }
        
        return mp[temp] = max(include, exclude);
    }
    
    int maxLength(vector<string>& arr) {
        string temp = "";
        mp.clear();
        int n = arr.size();
        
        return solve(0, arr, temp, n);
        
    }
};

