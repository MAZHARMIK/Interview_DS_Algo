/*
    Company Tags  : Amazon, Google
    Leetcode Link : https://leetcode.com/problems/word-subsets/
*/

class Solution {
public:
    bool subset(vector<int>& temp, vector<int>& B_Freq) {
        for(int i = 0; i<26; i++) {
            if(temp[i] < B_Freq[i])
                return false;
        }
        
        return true;
    }
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> result;
        
        vector<int> B_Freq(26);
        
        for(string str:B) {
            vector<int> temp(26);
            
            for(char ch:str) {
                int idx = ch-'a';
                temp[idx]++;
                B_Freq[idx] = max(B_Freq[idx], temp[idx]);
            }
        }
        
        for(string str:A) {
            vector<int> temp(26);
            
            for(char ch:str) {
                temp[ch-'a']++;
            }
            
            if(subset(temp, B_Freq))
                result.push_back(str);
        }
        
        return result;
    }
};
