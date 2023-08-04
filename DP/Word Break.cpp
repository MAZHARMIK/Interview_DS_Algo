/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=oBUpyPZ08zU
    Company Tags                : Amazon, Google, IBM, MAQ Software, Microsoft, Walmart, Zoho
    Leetcode Question Link      : https://leetcode.com/problems/word-break/
    NOTE :  SCROLL DOWN TO SEE JAVA VERSION AS WELL
*/

//***********************************************   C++   ***********************************************************//
//Approach-1 (Recur + Memoiz) - 
//T.C :  O(n * 2^n) Because at each index, we eaither split it or not and substr also takes O(n)
class Solution {
public:
    unordered_set<string> st;
    int t[301];
    int n;
    
    bool solve(string &s, int idx) {
        
        if(idx == n) {
            return true;
        }

        if(st.find(s.substr( idx , n - idx )) != st.end()) {
            return true;
        }
        
        if(t[idx] != -1)
            return t[idx];
        
        for(int l = 1; l<=n; l++) {
            
            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end() && solve(s, idx+l))
                return t[idx] = true;
            
        }
        
        return t[idx] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        
        memset(t, -1, sizeof(t));
        
        for(string &word : wordDict) {
            st.insert(word);
        }
        
        return solve(s, 0);
    }
};


//Approach-2 (Bottom Up DP)
class Solution {
public:
    bool solve(string s, vector<string>& wordDict) {
        unordered_set<string> st(begin(wordDict), end(wordDict));
        int n = s.length();
        vector<bool> t(n+1, false);
        /*
            t[i] = True;
            It means that for string of length i, its possible to break
            the word such that broken words are in wordDict
        */
        
        t[0] = true; //string of length 0 is always true
        
        for(int i = 1; i<=n; i++) {
            //we choose different point (j) to break
            for(int j = 0; j<i; j++) {
                string temp = s.substr(j, i-j);
                
                if(st.count(temp) && t[j]) {
                    /*
                        It means from s[j...i] is in wordDict
                        And, t[j] = true means s[0...j] could
                        also be broken correctly
                    */
                    
                    t[i] = true;
                    break;
                }
            }
        }
        return t[n]; //length n
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s, wordDict);
    }
};


//***********************************************   JAVA   ***********************************************************//
//Approach-1 (Recur + Memoiz)
class Solution {
    private Boolean[] t;
    int n;
    public boolean wordBreak(String s, List<String> wordDict) {
        n = s.length();
        t = new Boolean[s.length()];
        return solve(s, 0, wordDict);
    }
    
    private boolean solve(String s, int idx, List<String> wordDict) {
        if (idx == n) {
            return true;
        }
        
        if (t[idx] != null) {
            return t[idx];
        }
        
        for (int endIdx = idx + 1; endIdx <= n; endIdx++) {
            
            String split = s.substring(idx, endIdx);
            
            if (wordDict.contains(split) && solve(s, endIdx, wordDict)) {
                return t[idx] = true;
            }
        }
        
        return t[idx] = false;
    }
}



//Approach-2 (Bottom Up DP)
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> wordSet = new HashSet<>();
        wordSet.addAll(wordDict);
        
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;
        for (int i = 1; i < dp.length ; i++) {
            for (int k = 1; k <= i; k++) {
                dp[i] = dp[i] || (dp[i - k] && wordSet.contains(s.substring(i - k, i)));
            }
        }
        return dp[s.length()];
    }
}
