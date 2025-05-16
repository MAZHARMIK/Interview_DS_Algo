/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=geXrFFZXQTc
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/
    Leetcode 2900 Video Link    : https://www.youtube.com/watch?v=6zb5qH4oNSY
    LIS Printing Pattern Video  : https://youtu.be/rYuLUjRSTeo?si=Dm--R2jBXZmM8WtZ
*/


/**************************************************************** C++ ****************************************************************/
//Approach -  Using LIS Pattern
//T.C : (n^2 * L), where L = max length of a string in the words
//S.C : O(n)
class Solution {
public:

    bool checkhammingDistanceOne(string &s1, string &s2) {
        int diff = 0;

        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] != s2[i]) {
                diff++;
            }

            if(diff > 1) {
                return false; //early exit
            }
        }

        return diff == 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<int> dp(n, 1); //dp[i] = longest subsequence length ending at index i
        vector<int> parent(n, -1);
        int longestSub = 1;
        int longestSubIdx = 0;

        //T.C : O(n^2 * L)

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i-1; j++) {
                if(groups[j] != groups[i] && words[i].length() == words[j].length() &&
                    checkhammingDistanceOne(words[i], words[j])) {
                        
                        if(dp[j] + 1 > dp[i]) {
                            dp[i] = dp[j] + 1;
                            parent[i] = j;

                            if(longestSub < dp[i]) {
                                longestSub = dp[i];
                                longestSubIdx = i;
                            }

                        }

                }
            }
        }

        vector<string> result;
        while(longestSubIdx != -1) { //O(n)
            result.push_back(words[longestSubIdx]);
            longestSubIdx = parent[longestSubIdx];
        }

        reverse(begin(result), end(result)); //O(n)
        return result;

    }
};


/**************************************************************** JAVA ****************************************************************/
//Approach -  Using LIS Pattern
//T.C : (n^2 * L), where L = max length of a string in the words
//S.C : O(n)
class Solution {
    public List<String> getWordsInLongestSubsequence(String[] words, int[] groups) {
        int n = words.length;
        int[] dp = new int[n]; // dp[i] = longest subsequence ending at i
        int[] parent = new int[n]; // backtrack path
        Arrays.fill(dp, 1);
        Arrays.fill(parent, -1);

        int longestSub = 1;
        int longestSubIdx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j]
                        && words[i].length() == words[j].length()
                        && hammingDistanceOne(words[i], words[j])) {

                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;

                        if (dp[i] > longestSub) {
                            longestSub = dp[i];
                            longestSubIdx = i;
                        }
                    }
                }
            }
        }

        List<String> result = new ArrayList<>();
        while (longestSubIdx != -1) {
            result.add(words[longestSubIdx]);
            longestSubIdx = parent[longestSubIdx];
        }

        Collections.reverse(result);
        return result;
    }

    private boolean hammingDistanceOne(String s1, String s2) {
        int diff = 0;

        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                diff++;
                if (diff > 1) return false;
            }
        }

        return diff == 1;
    }
}
