/*
    Company Tags : Google
    Leecode Link : https://leetcode.com/problems/number-of-matching-subsequences/
    
    //Other approach (using hash map) : Link : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/HashMap/Number%20of%20Matching%20Subsequences.cpp
*/

//Time : O(s.length() * log(n))
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char, vector<int>> mp;
        int n = s.length();
        
        for(int i = 0; i<n; i++) {
            mp[s[i]].push_back(i);
        }

        int count = 0;
        for(string &word : words) {
            int prev      = -1;
            bool found = true;

            for(char &ch : word) {
                if(mp.find(ch) == mp.end()) {
                    found = false;
                    break;
                }

                auto it = upper_bound(begin(mp[ch]), end(mp[ch]), prev); //Binary Search (O(log(n))
                
                if(it == mp[ch].end()) {
                    found = false;
                    break;
                }

                prev = *it;
            }
            if(found)
                count++;
        }
        return count;
    }
};

