/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Fx96uB9EIDQ
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/scramble-string/
*/


//Appoach-1 (Recursion + Memo)
class Solution {
public:
    unordered_map<string, bool> mp;
    bool solve(string s1, string s2) {

        if(s1 == s2) //both string empty covered here too
            return true;
        if(s1.length() != s2.length())
            return false;

        string key = s1 + "_" + s2;
        if(mp.find(key) != mp.end())
            return mp[key];

        bool result = false;
        int n = s1.length();
        for(int i = 1; i<n; i++) {
            /*
            Example : "great"  "eatgr"
            if swapped at i = 2
            we compare s1.substr(0, i) i.e "gr"  with s2.substr(n-i, i) i.e. "gr"
            && s1.substr(i, n-i) i.e "eat"  with s2.substr(0, n-i) i.e. "eat"
            */

            bool swapped = solve(s1.substr(0, i), s2.substr(n-i, i)) &&
                           solve(s1.substr(i, n-i), s2.substr(0, n-i));
            if(swapped) { //if we find they are scrambled, we don't need to check further
                result = true;
                break;
            }
            /*
            Example : "great"  "great"
            if not swapped at i = 2
            we compare s1.substr(0, i) i.e "gr"  with s2.substr(0, i) i.e. "gr"
            && s1.substr(i, n-i) i.e "eat"  with s2.substr(i, n-i) i.e. "eat"
            */

            bool not_swapped = solve(s1.substr(0, i), s2.substr(0, i)) &&
                               solve(s1.substr(i, n-i), s2.substr(i, n-i));
            if(not_swapped) { //if we find they are scrambled, we don't need to check further
                result = true;
                break;
            }

        }

        return mp[key] = result;
    }
    bool isScramble(string &s1, string &s2) {
        mp.clear();
        return solve(s1, s2);
    }
};
