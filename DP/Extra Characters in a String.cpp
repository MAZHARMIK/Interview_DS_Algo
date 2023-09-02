/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=uQuSzPKtoVU
      Company Tags                : Will update soon
      Leetcode Link               : https://leetcode.com/problems/extra-characters-in-a-string/
*/


//Approach-1 (Recursion + Memo)
class Solution {
public:
    unordered_set<string> st;
    int t[51];
    
    int n;
    
    int solve(int idx, string &s) {
        
        if(idx >= n)
            return 0;
        
        if(t[idx] != -1)
            return t[idx];
        
        string currStr = "";
        int minExtra   = n;
        
        for(int i = idx; i<n; i++) {
            
            currStr.push_back(s[i]);
            
            int currExtra = (st.find(currStr) == st.end()) ? currStr.length() : 0;
            
            int nextExtra = solve(i+1, s);
            
            int totalExtra = currExtra + nextExtra;
            
            minExtra = min(minExtra, totalExtra);
            
        }
        
        return t[idx] = minExtra;
        
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        
        memset(t, -1, sizeof(t));
        
        for(string &word : dictionary)
            st.insert(word);
        
        return solve(0, s);
    }
};
//Approach-2 (Bottom Up) - SOOON
