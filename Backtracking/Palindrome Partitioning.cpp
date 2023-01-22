/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : Google, Amazon, Microsoft, Meta
    Leetcode Link               : https://leetcode.com/problems/palindrome-partitioning/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1
*/

//Whenever a question asks for "Generating all possible" something, think about Backtracking once
class Solution {
public:
    bool isPallindrome(string& s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void solve(string s, int idx, vector<string> curr, vector<vector<string>>& result) {
        if(idx >= s.length()) {
            result.push_back(curr);
            return;
        }
        
        for(int i = idx; i<s.length(); i++) {
            if(isPallindrome(s, idx, i)) {
                curr.push_back(s.substr(idx, i-idx+1));
                solve(s, i+1, curr, result);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        solve(s, 0, curr, result);
        return result;
    }
};
