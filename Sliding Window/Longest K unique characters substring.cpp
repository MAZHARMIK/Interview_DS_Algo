/*
    Company Tags : Google, Amazon, SAP Labs
    Qn Link      : https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1#
*/

//It's a Classical sliding window problem
//We traverse the string two times with i and j pointer in worst case. Time : o(n+n) = O(n)
class Solution{
    public:
    int longestKSubstr(string s, int k) {
        int n = s.length();
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        int maxLen = -1;
        while(j < n) {
            mp[s[j]]++;
  
            if(mp.size() == k) {
                maxLen = max(maxLen, j-i+1);
            } else if(mp.size() > k) {
                while(mp.size() > k) {
                    mp[s[i]]--;
                    if(mp[s[i]] <= 0)
                        mp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return maxLen;
    }
};
