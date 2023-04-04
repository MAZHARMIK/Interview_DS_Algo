/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=QonXo5Em5VA
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/optimal-partition-of-string/
*/

class Solution {
public:
    int partitionString(string s) {
        vector<int> lastSeen(26, -1);
        
        int count = 0;
        int substringStart = 0;

        for (int i = 0; i < s.length(); i++) {
            if (lastSeen[s[i] - 'a'] >= substringStart) {
                count++;
                substringStart = i;
            }
            lastSeen[s[i] - 'a'] = i;
        }

        return count+1;
    }
};
