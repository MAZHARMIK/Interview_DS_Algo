/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=zZsnMAgM6Q0
      Company Tags                : META
      Leetcode Link               : https://leetcode.com/problems/concatenated-words/
*/


//Using DFS and Memoization - O(N*L^3)
class Solution {
public:
    int n;
    unordered_map<string, bool> mp;
    bool isConcat(string word, unordered_set<string>& st) {
        
        if(mp.find(word) != mp.end())
            return mp[word];
        
        int l = word.length();
        
        for(int i = 0; i<l; i++) {
            string prefix  = word.substr(0, i+1);
            string suffix  = word.substr(i+1);
            
            if((st.find(prefix) != st.end() && isConcat(suffix, st)) ||
               (st.find(prefix) != st.end() && st.find(suffix) != st.end()))
                return mp[word] = true;
        }
        
        
        return mp[word] = false;
        
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        n = words.size();
        mp.clear();
        vector<string> result;
        unordered_set<string> st(begin(words), end(words));
        
        for(int i = 0; i<n; i++) {
            if(isConcat(words[i], st))
                result.push_back(words[i]);
        }
        
        return result;
    }
};
