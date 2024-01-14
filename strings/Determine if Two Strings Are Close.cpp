/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=KbdCp4nUDiQ
    Company Tags                : Google, Microsoft, Atlassian, Morgan Stanely, Adobe, Uber
    Leecode Link                : https://leetcode.com/problems/determine-if-two-strings-are-close/
*/

/*************************************************************************** C++ **********************************************************************/
//T.C : O(n)
//S.C : O(26) ~ O(1)
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


/*************************************************************************** JAVA **********************************************************************/
//T.C : O(n)
//S.C : O(26) ~ O(1)
class Solution {
    public boolean closeStrings(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        
        if (m != n)
            return false;
        
        int[] freq1 = new int[26];
        int[] freq2 = new int[26];
        
        for (int i = 0; i < m; i++) {
            char ch1 = word1.charAt(i);
            char ch2 = word2.charAt(i);
            
            freq1[ch1-'a']++;
            freq2[ch2-'a']++;
        }
        
        // 1st point - jo char word1 me hai, wo char word2 me bhi hona chaie
        for (int i = 0; i < 26; i++) {
            if ((freq1[i] != 0 && freq2[i] != 0) || (freq1[i] == 0 && freq2[i] == 0))
                continue;
            
            return false;
        }
        
        // 2nd point = match freq
        Arrays.sort(freq1);
        Arrays.sort(freq2);
        
        return Arrays.equals(freq1, freq2);
    }
}
