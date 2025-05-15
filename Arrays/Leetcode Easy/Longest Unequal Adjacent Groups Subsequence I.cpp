/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=6zb5qH4oNSY
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i
*/

/*********************************************************** C++ **************************************************/
//Approach (Counting groups)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();

        vector<string> result;
        for(int i = 0; i < n; i++) {
            if(i == 0 || groups[i] != groups[i-1]) { //new group started, so pick the first element
                result.push_back(words[i]);
            }
        }

        return result;
    }
};


/*********************************************************** JAVA **************************************************/
//Approach (Counting groups)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public List<String> getLongestSubsequence(String[] words, int[] groups) {
        int n = words.length;
        List<String> result = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (i == 0 || groups[i] != groups[i - 1]) {
                result.add(words[i]); // new group started, so pick the first element
            }
        }

        return result;
    }
}
