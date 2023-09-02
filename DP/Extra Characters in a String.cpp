/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=uQuSzPKtoVU
      Company Tags                : Will update soon
      Leetcode Link               : https://leetcode.com/problems/extra-characters-in-a-string/
*/


//Approach-1 (Recursion + Memo)
class Solution {
public:
    unordered_set<string> st;
    int n;
    
    int solve(string &s, int idx) {
        if (idx >= n) 
            return 0;
        
        string currStr = "";
        int minExtra = n;
        
        for (int i = idx; i < s.size(); i++) {
            
            currStr.push_back(s[i]);

            int currExtra = (st.find(currStr) == st.end()) ? currStr.length() : 0;
            int nextExtra = solve(s, i + 1);
            int totalExtra = currExtra + nextExtra;
            
            minExtra = min(minExtra, totalExtra);
        }
        
        return minExtra;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        
        for(string &word : dictionary) {
            st.insert(word);
        }
        
        return solve(s, 0);
    }
};

//Approach-2 (Bottom Up) - SOOON
