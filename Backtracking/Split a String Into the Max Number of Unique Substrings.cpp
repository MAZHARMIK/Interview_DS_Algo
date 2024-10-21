/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=sTzh1L7BkQA
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings
*/


/************************************************************ C++ ************************************************/
//Approach (Using simple backtracking)
//T.C : O(n*2^n)
//S.C : O(n)
class Solution {
public:

    void solve(string& s, int idx, unordered_set<string>& st, int currCount, int& maxCount) {
        if(currCount + (s.length() - idx) <= maxCount) { //Pruning for slight improvement
            return;
        }

        if(idx == s.length()) {
            maxCount = max(maxCount, currCount);
        }

        for(int j = idx; j < s.length(); j++) {
            string sub = s.substr(idx, j-idx+1);
            if(st.find(sub) == st.end()) {
                st.insert(sub);
                solve(s, j+1, st, currCount+1, maxCount);
                st.erase(sub);
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int maxCount  = 0;
        int currCount = 0;
        solve(s, 0, st, currCount, maxCount);

        return maxCount;
    }
};




/************************************************************ JAVA ************************************************/
//Approach (Using simple backtracking)
//T.C : O(n*2^n)
//S.C : O(n)
class Solution {
    
    private void solve(String s, int idx, HashSet<String> st, int currCount, int[] maxCount) {
        // Pruning for slight improvement
        if(currCount + (s.length() - idx) <= maxCount[0]) {
            return;
        }

        if (idx == s.length()) {
            maxCount[0] = Math.max(maxCount[0], currCount);
            return;
        }

        for (int j = idx; j < s.length(); j++) {
            String sub = s.substring(idx, j + 1);
            if (!st.contains(sub)) {
                st.add(sub);
                solve(s, j + 1, st, currCount + 1, maxCount);
                st.remove(sub);
            }
        }
    }

    public int maxUniqueSplit(String s) {
        HashSet<String> st = new HashSet<>();
        int[] maxCount = new int[1]; // Using array to allow updates by reference
        solve(s, 0, st, 0, maxCount);
        return maxCount[0];
    }
}
