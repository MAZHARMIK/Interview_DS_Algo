/*
    MY YOUTUBE VIDEO ON THIS Qn : <coming soon>
    Leetcode Link               : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
    Company Tags                : Google
*/

//Approach-1 (Without Sliding Window : Brute Force)
class Solution {
public:
    unordered_map<string, int> mp;
    int totalWordsCount = 0;
    int substringSize   = 0;
    int wordLength      = 0;
    
    bool check(int index, string& s) {
        unordered_map<string, int> temp = mp;
        
        int wordsSeen = 0;
        
        for(int i = index; i<index+substringSize; i += wordLength) {
            string substring = s.substr(i, wordLength);
            
            if(temp.find(substring) != temp.end() && temp[substring] > 0) {
                temp[substring]--;
                wordsSeen++;
            } else {
                break;
            }
        }
        
        return wordsSeen==totalWordsCount;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        
        wordLength        = words[0].length();
        totalWordsCount   = words.size();
        substringSize     = totalWordsCount*wordLength;
        
        for(string &s : words)
            mp[s]++;
        
        vector<int> result;
        for(int i = 0; i<=n-substringSize; i++) {
            if(check(i, s))
                result.push_back(i);
        }
        
        return result;
    }
};


//Approach-2 (Using Sliding Window)
//Coming soon
