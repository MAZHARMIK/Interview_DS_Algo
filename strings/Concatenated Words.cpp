/*            Scroll below to see JAVA code as well            */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=zZsnMAgM6Q0
      Company Tags                : META
      Leetcode Link               : https://leetcode.com/problems/concatenated-words/
*/


/********************************************************************** C++ ***************************************************************/
//Using DFS and Memoization
//T.C : O(n*L^3)
//S.C : O(n*L)
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



/********************************************************************** JAVA ***************************************************************/
//Using DFS and Memoization
//T.C : O(n*L^3)
//S.C : O(n*L)
class Solution {
    public boolean isConcatenated(String word, Set<String> st, Map<String, Boolean> map) {
        if(map.containsKey(word))
            return map.get(word);
        int l = word.length();
        for(int i = 0 ; i< l; i++){
            String prefix = word.substring(0, i+1);
            String suffix = word.substring(i+1, l);
            if((st.contains(prefix) && st.contains(suffix)) || (st.contains(prefix) && isConcatenated(suffix, st, map))){
                map.put(word, true);
                return true;
            }
        }
        map.put(word, false);
        return false;
    }
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        int n = words.length;
        Set<String> st = new HashSet<>();
        Map<String, Boolean> map = new HashMap<>();
        for(String s : words)
            st.add(s);
        List<String> result = new ArrayList<>();
        for(int i = 0 ; i < n; i++){
            String word = words[i];
            
            if(isConcatenated(word, st, map)){
                result.add(word);
            }
        }
        return result;
    }
}
