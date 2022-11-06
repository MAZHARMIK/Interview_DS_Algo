/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=5TNRCLbU7H4
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/orderly-queue/
*/

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k > 1) {
            sort(begin(s), end(s));
            return s;
        }
        
        string result = s;
        for(int i = 1; i<s.length(); i++) {
            string temp = s.substr(i) + s.substr(0, i);
            result = min(result, temp);
        }
        
        return result;
    }
};
