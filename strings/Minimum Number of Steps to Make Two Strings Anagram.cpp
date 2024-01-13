/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=dDQTlfWvzqE
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
*/

/****************************************************** C++ ******************************************************/
//Approach-1 (Using 2 counters)
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();
        
        int mp_s[26] = {0};
        int mp_t[26] = {0};
        
        for(int i = 0; i<n; i++) {
            mp_s[s[i] - 'a']++;
            mp_t[t[i] - 'a']++;
        }
        
        int result = 0;
        
        for(int i = 0; i < 26; i++) {
            int freq_in_t = mp_t[i];
            
            int freq_in_s = mp_s[i];
            
            if(freq_in_t < freq_in_s) {
                result += freq_in_s - freq_in_t;
            }
        } 
        
        return result;
    }
};


//Approach-2 (Using 1 counter)
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();
        
        int mp[26] = {0};
        
        for(int i = 0; i<n; i++) {
            mp[s[i] - 'a']++;
            mp[t[i] - 'a']--;
        }

        int result = 0;

        for(int i = 0; i < 26; i++) {
            result += max(0, mp[i]);
        } 
        
        return result;
    }
};




/****************************************************** JAVA ******************************************************/
//Approach-1 (Using 2 counters)
//T.C : O(n)
//S.C : O(26) ~ O(1)
public class Solution {
    public int minSteps(String s, String t) {
        int n = s.length();

        int[] mp_s = new int[26];
        int[] mp_t = new int[26];

        for (int i = 0; i < n; i++) {
            mp_s[s.charAt(i) - 'a']++;
            mp_t[t.charAt(i) - 'a']++;
        }

        int result = 0;

        for (int i = 0; i < 26; i++) {
            int freq_in_t = mp_t[i];
            int freq_in_s = mp_s[i];

            if (freq_in_t < freq_in_s) {
                result += freq_in_s - freq_in_t;
            }
        }

        return result;
    }
}


//Approach-2 (Using 1 counter)
//T.C : O(n)
//S.C : O(26) ~ O(1)
public class Solution {
    public int minSteps(String s, String t) {
        int n = s.length();

        int[] mp = new int[26];

        for (int i = 0; i < n; i++) {
            mp[s.charAt(i) - 'a']++;
            mp[t.charAt(i) - 'a']--;
        }

        int result = 0;

        for (int i = 0; i < 26; i++) {
            result += Math.max(0, mp[i]);
        }

        return result;
    }
}
