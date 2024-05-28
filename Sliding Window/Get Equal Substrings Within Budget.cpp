/*   Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=MF2MgJQuFhA
    Company Tags                : Will soon update
    Leetcode Link               : https://leetcode.com/problems/get-equal-substrings-within-budget
*/


/****************************************************** C++ ******************************************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        
        int maxLen = 0;
        int currCost = 0;
        
        int i = 0, j = 0;
        while(j < n) {
            currCost += abs(s[j] - t[j]);
            
            while (currCost > maxCost) {
                currCost -= abs(s[i] - t[i]);
                i++;
            }
            
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        
        return maxLen;
    }
};


/****************************************************** JAVA ******************************************************/
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int n = s.length();
        
        int maxLen = 0;
        int currCost = 0;
        
        int i = 0, j = 0;
        while (j < n) {
            currCost += Math.abs(s.charAt(j) - t.charAt(j));
            
            while (currCost > maxCost) {
                currCost -= Math.abs(s.charAt(i) - t.charAt(i));
                i++;
            }
            
            maxLen = Math.max(maxLen, j - i + 1);
            j++;
        }
        
        return maxLen;
    }
}
