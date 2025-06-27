/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Kc4eUX-heL4
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/longest-subsequence-repeated-k-times/
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Khandani Backtracking remplate - storing all possible strings)
//T.C : O(n * ((n/k)!))
//S.C : O(n/k)
class Solution {
public:
    string result = "";

    bool isSubsequence(string &s, string& sub, int k) {
        int i = 0;
        int j = 0;
        int L = sub.length();
        int n = s.length();

        while(i < n && j < k*L) {
            if(s[i] == sub[j%L])
                j++;
            
            i++;
        }

        return j == k * L;
    }

    bool backtracking(string& s, string &curr, vector<bool>& canUse, vector<int>& requiredFreq, int k, int maxLen) {
        if(curr.length() == maxLen) {
            if(isSubsequence(s, curr, k)) {
                result = curr;
                return true;
            }
            return false;
        }

        for(int i = 25; i >= 0; i--) {
            if(canUse[i] == false || requiredFreq[i] == 0)
                continue;
            
            //DO
            char ch = i + 'a';
            curr.push_back(ch);
            requiredFreq[i]--;

            //EXPLORE
            if(backtracking(s, curr, canUse, requiredFreq, k, maxLen) == true) {
                return true;
            }

            //UNDO
            curr.pop_back();
            requiredFreq[i]++;

        }

        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();

        int freq[26] = {};
        for(char &ch : s) {
            freq[ch-'a']++;
        }

        vector<bool> canUse(26, false);
        vector<int> requiredFreq(26, 0);
        for(int i = 0; i < 26; ++i) {
            if(freq[i] >= k) {
                canUse[i] = true;
                requiredFreq[i] = freq[i]/k; //atmost this can be used in a subsequence
            }
        }

        int maxLen = n / k;

        for(int len = maxLen; len >= 0; len--) {
            vector<int> tempRequiredFreq = requiredFreq;
            string curr = "";
            if(backtracking(s, curr, canUse, tempRequiredFreq, k, len) == true) {
                return result;
            }
        }

        return result;


    }
};


//Approach-2 IMPROVED BACKTRACKING : (Khandani Backtracking remplate - storing all possible strings)
//T.C : O(n * ((n/k)!))
//S.C : O(n/k)
class Solution {
public:
    string result = "";

    bool isSubsequence(string &s, string& sub, int k) {
        int i = 0;
        int j = 0;
        int L = sub.length();
        int n = s.length();

        while(i < n && j < k*L) {
            if(s[i] == sub[j%L])
                j++;
            
            i++;
        }

        return j == k * L;
    }

    void backtracking(string& s, string &curr, vector<bool>& canUse, vector<int>& requiredFreq, int k, int maxLen) {
        if(curr.length() > maxLen)
            return;
        
        if((curr.length() > result.length() || (curr.length() == result.length() && curr > result))
            && isSubsequence(s, curr, k)) {
                result = curr;
        }

        for(int i = 0; i <= 25; i++) {
            if(canUse[i] == false || requiredFreq[i] == 0)
                continue;
            
            //DO
            char ch = i + 'a';
            curr.push_back(ch);
            requiredFreq[i]--;

            //EXPLORE
            backtracking(s, curr, canUse, requiredFreq, k, maxLen);

            //UNDO
            curr.pop_back();
            requiredFreq[i]++;

        }

    }

    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.length();

        int freq[26] = {};
        for(char &ch : s) {
            freq[ch-'a']++;
        }

        vector<bool> canUse(26, false);
        vector<int> requiredFreq(26, 0);
        for(int i = 0; i < 26; ++i) {
            if(freq[i] >= k) {
                canUse[i] = true;
                requiredFreq[i] = freq[i]/k; //atmost this can be used in a subsequence
            }
        }

        int maxLen = n / k;

        string curr;
        backtracking(s, curr, canUse, requiredFreq, k, maxLen);

        return result;


    }
};


/************************************************************ JAVA ************************************************/
//Approach-1 (Khandani Backtracking remplate - storing all possible strings)
//T.C : O(n * ((n/k)!))
//S.C : O(n/k)
class Solution {
    String result = "";

    // Check if seq * k is a subsequence of s
    private boolean isSubsequence(String s, String sub, int k) {
        int i = 0, j = 0, len = sub.length(), n = s.length();

        while (i < n && j < k * len) {
            if (s.charAt(i) == sub.charAt(j % len)) {
                j++;
            }
            i++;
        }

        return j == k * len;
    }

    private void backtracking(String s, StringBuilder curr, boolean[] canUse, int[] requiredFreq, int k, int maxLen) {
        if (curr.length() > maxLen) return;

        String currStr = curr.toString();
        if ((curr.length() > result.length() || 
             (curr.length() == result.length() && currStr.compareTo(result) > 0)) &&
            isSubsequence(s, currStr, k)) {
            result = currStr;
        }

        for (int i = 25; i >= 0; i--) { // from 'z' to 'a' for lexicographically larger result
            if (!canUse[i] || requiredFreq[i] == 0) continue;

            curr.append((char) (i + 'a'));
            requiredFreq[i]--;

            backtracking(s, curr, canUse, requiredFreq, k, maxLen);

            curr.deleteCharAt(curr.length() - 1);
            requiredFreq[i]++;
        }
    }

    public String longestSubsequenceRepeatedK(String s, int k) {
        int n = s.length();
        int[] freq = new int[26];

        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        boolean[] canUse = new boolean[26];
        int[] requiredFreq = new int[26];

        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {
                canUse[i] = true;
                requiredFreq[i] = freq[i] / k;
            }
        }

        int maxLen = n / k;
        StringBuilder curr = new StringBuilder();
        backtracking(s, curr, canUse, requiredFreq, k, maxLen);

        return result;
    }
}

//Approach-2 IMPROVED BACKTRACKING : (Khandani Backtracking remplate - storing all possible strings)
//T.C : O(n * ((n/k)!))
//S.C : O(n/k)
class Solution {
    String result = "";

    // Checks if sub * k is a subsequence of s
    private boolean isSubsequence(String s, String sub, int k) {
        int i = 0, j = 0;
        int len = sub.length(), n = s.length();

        while (i < n && j < k * len) {
            if (s.charAt(i) == sub.charAt(j % len)) {
                j++;
            }
            i++;
        }

        return j == k * len;
    }

    // Tries to build a valid subsequence of exact length 'maxLen'
    private boolean backtracking(String s, StringBuilder curr, boolean[] canUse, int[] requiredFreq, int k, int maxLen) {
        if (curr.length() == maxLen) {
            if (isSubsequence(s, curr.toString(), k)) {
                result = curr.toString();
                return true;
            }
            return false;
        }

        for (int i = 25; i >= 0; i--) {
            if (!canUse[i] || requiredFreq[i] == 0)
                continue;

            curr.append((char) (i + 'a'));
            requiredFreq[i]--;

            if (backtracking(s, curr, canUse, requiredFreq, k, maxLen))
                return true;

            curr.deleteCharAt(curr.length() - 1);
            requiredFreq[i]++;
        }

        return false;
    }

    public String longestSubsequenceRepeatedK(String s, int k) {
        int n = s.length();
        int[] freq = new int[26];

        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        boolean[] canUse = new boolean[26];
        int[] requiredFreq = new int[26];

        for (int i = 0; i < 26; i++) {
            if (freq[i] >= k) {
                canUse[i] = true;
                requiredFreq[i] = freq[i] / k; // Max times a char can be used in a subsequence
            }
        }

        int maxLen = n / k;

        for (int len = maxLen; len >= 1; len--) {
            int[] tempRequiredFreq = requiredFreq.clone();  // Copy current state
            StringBuilder curr = new StringBuilder();

            if (backtracking(s, curr, canUse, tempRequiredFreq, k, len)) {
                return result;
            }
        }

        return result;
    }
}
