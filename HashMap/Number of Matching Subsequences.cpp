/*
    Company Tags : Google
    Leecode Link : https://leetcode.com/problems/number-of-matching-subsequences/
*/

//Approach-1 (Naive approach) - TLE
class Solution {
public:
    bool isSubsequence(const string &s1, const string &s2) {
        int m = s1.length();
        int n  = s2.length();
        int i = 0, j = 0;

        while(i < m) {
            if(s1[i] == s2[j])
                j++;
            i++;
        }

        return j == n;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        map<string, int> mp; //to avoid calculating for duplicate words
        for(string &word : words) {
            mp[word]++;
        }
        
        for(auto &it : mp) {
            if(isSubsequence(s, it.first)) {
                count += it.second;
            }
        }
        
        return count;
    }
};

//Approach-2 (Important Concept) (Time : O(s.length * #words) or O(s.length + ∑words[i].length))
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char, vector<string>> mp;
        //Could also use : vector<vector<string>> mp(26, vector<string>());
        for(string &word : words) {
            mp[word.back()].push_back(word);
        }
        int n = s.length();
        int count =  0;
        for(int i = n-1; i>=0 ; i--) {
            char ch = s[i];
            if(mp.find(ch) == mp.end())
                continue;
            vector<string> candidates = mp[ch];
            mp[ch].clear();
            for(string &word : candidates) {
                word.pop_back();
                if(word.empty()) {
                    //word got completely found in s
                    count++;
                } else {
                    mp[word.back()].push_back(word);
                }
            }
        }
        return count;
    }
};

//Approach-3 (Using Binary Search)
/*
  You will find it in "Arrays/Binary Search" Section : 
  Link : https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Binary%20Search/Number%20of%20Matching%20Subsequences.cpp
*/
