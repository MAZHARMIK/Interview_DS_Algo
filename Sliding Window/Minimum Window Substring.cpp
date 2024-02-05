/*                                            Scroll below to see JAVA code also                                    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=3Bp3OVD1EGc
    Company Tags                : Google, Amazon, Microsoft, Codenation, FactSet, , Atlassian, MakeMyTrip, Streamoid Technologies, Media.net, Airbnb
    Leetcode Link               : https://leetcode.com/problems/minimum-window-substring/
*/

/***************************************************************** C++ *****************************************************************/
//T.C : O(m+n) where m = length of s and n = length of t
//S.C : O(n)
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        map<char, int> mp;
        
        for(char &ch : t) {
            mp[ch]++;
        }
        
        int requiredCount = t.length();
        int i = 0, j  = 0;
        int minStart  = 0;
        int minWindow = INT_MAX;
        while(j < n) {
            char ch_j = s[j];
            if(mp[ch_j] > 0)
                requiredCount--;
            
            mp[ch_j]--;
            
            while(requiredCount == 0) { //try to shrink the window
                if(minWindow > j-i+1) {
                    minWindow = j-i+1;
                    minStart  = i;
                }
                
                char ch_i = s[i];
                mp[ch_i]++;
                if(mp[ch_i] > 0)
                    requiredCount++;
                i++;
            }
            
            j++; //Don't ever forget this :-)
        }
        
        return minWindow == INT_MAX ? "" : s.substr(minStart, minWindow);
    }
};


/***************************************************************** JAVA *****************************************************************/
//T.C : O(m+n) where m = length of s and n = length of t
//S.C : O(n)
public class Solution {
    public String minWindow(String s, String t) {
        int n = s.length();

        if (t.length() > n)
            return "";

        Map<Character, Integer> mp = new HashMap<>();

        // store karliya
        for (char ch : t.toCharArray())
            mp.put(ch, mp.getOrDefault(ch, 0) + 1);

        int requiredCount = t.length();
        int i = 0, j = 0;

        int minWindowSize = Integer.MAX_VALUE;
        int start_i = 0;

        // story starts
        while (j < n) {
            char ch = s.charAt(j);

            if (mp.containsKey(ch) && mp.get(ch) > 0)
                requiredCount--;

            mp.put(ch, mp.getOrDefault(ch, 0) - 1);

            while (requiredCount == 0) {
                // start shrinking the window

                int currWindowSize = j - i + 1;

                if (minWindowSize > currWindowSize) {
                    minWindowSize = currWindowSize;
                    start_i = i;
                }

                char startChar = s.charAt(i);
                mp.put(startChar, mp.getOrDefault(startChar, 0) + 1);

                if (mp.containsKey(startChar) && mp.get(startChar) > 0) {
                    requiredCount++;
                }

                i++;
            }

            j++;
        }

        return minWindowSize == Integer.MAX_VALUE ? "" : s.substring(start_i, start_i + minWindowSize);
    }
}
