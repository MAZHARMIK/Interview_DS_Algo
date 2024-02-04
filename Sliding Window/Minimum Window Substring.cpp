/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=3Bp3OVD1EGc
    Company Tags                : Google, Amazon, Microsoft, Codenation, FactSet, , Atlassian, MakeMyTrip, Streamoid Technologies, Media.net, Airbnb
    Leetcode Link               : https://leetcode.com/problems/minimum-window-substring/
*/

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

// Java code:
class Solution {
    public String minWindow(String s, String t) {
        int n = s.length();
        Map<Character, Integer> mp = new HashMap<>();
        for(char ch : t.toCharArray()) {
            mp.put(ch, mp.getOrDefault(ch, 0) + 1);
        }
        int requiredCount = t.length();
        int i = 0, j = 0;
        int minStart = 0;
        int minWindow = Integer.MAX_VALUE;
        while(j < n) {
            char ch_j = s.charAt(j);
            if(mp.getOrDefault(ch_j, 0) > 0)
                requiredCount--;
            mp.put(ch_j, mp.getOrDefault(ch_j, 0) - 1);
            while(requiredCount == 0) {
                if(minWindow > j - i + 1) {
                    minWindow = j - i + 1;
                    minStart = i;
                }
                char ch_i = s.charAt(i);
                mp.put(ch_i, mp.get(ch_i) + 1);
                if(mp.get(ch_i) > 0)
                    requiredCount++;
                i++;
            }
            j++;
        }
        return minWindow == Integer.MAX_VALUE ? "" : s.substring(minStart, minStart + minWindow);
    }
}


