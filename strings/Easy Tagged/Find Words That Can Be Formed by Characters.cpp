/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=0RpZxrkLCyg
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
*/

/*************************************************************** C++ ***************************************************************/
//T.C : O(words.length())
//S.C : O(26)
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charCount(26, 0);
        
        for(char &ch : chars) {
            charCount[ch-'a']++;
        }
        
        int result = 0;
        
        for(string &word : words) {
            
            vector<int> wordCount(26, 0);
            for(char &ch : word) {
                wordCount[ch-'a']++;
            }
            
            bool ok = true;
            for(int i = 0; i < 26; i++) {
                if(wordCount[i] > charCount[i]) {
                    ok = false;
                    break;
                }
            }
            
            if(ok)
                result += word.size();
            
        }
        
        return result;
        
        
    }
};


/*************************************************************** JAVA ***************************************************************/
//T.C : O(words.length())
//S.C : O(26)
public class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] charCount = new int[26];

        for (char ch : chars.toCharArray()) {
            charCount[ch - 'a']++;
        }

        int result = 0;

        for (String word : words) {
            int[] wordCount = new int[26];
            for (char ch : word.toCharArray()) {
                wordCount[ch - 'a']++;
            }

            boolean ok = true;
            for (int i = 0; i < 26; i++) {
                if (wordCount[i] > charCount[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                result += word.length();
            }
        }

        return result;
    }

}
