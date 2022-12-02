/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=KbdCp4nUDiQ
    Company Tags                : Google, Microsoft, Atlassian, Morgan Stanely, Adobe, Uber
    Leecode Link                : https://leetcode.com/problems/determine-if-two-strings-are-close/
*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        
        if(m != n)
            return false;
        
        vector<int> freq1(26);
        vector<int> freq2(26);
        
        for(int i = 0; i<m; i++) {
            char ch1 = word1[i];
            char ch2 = word2[i];
            
            int idx1 = ch1-'a';
            int idx2 = ch2-'a';
            
            freq1[idx1]++;
            freq2[idx2]++;
            
        }
        
        //1st point - jo char word1 me hai, wo char word2 me bhi hona chaie
        for(int i = 0; i<26; i++) {
            if(freq1[i] != 0 && freq2[i] != 0) continue;
            
            if(freq1[i] == 0 && freq2[i] == 0) continue;
            
            return false;
        }
        
        //2nd point = match freq
        sort(begin(freq1), end(freq1));
        sort(begin(freq2), end(freq2));
        
        return freq1 == freq2;
        
    }
};
