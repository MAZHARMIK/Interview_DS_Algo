/*    Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS QN : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-words-you-can-type
*/

/*************************************************************************** C++ ***************************************************************************/
//Approach - simple iteration
//T.C : O(m+n), m = length of text, n = length of brokenLetters
//S.C : O(1)
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.length();

        bool mp[26];
        for(char &ch : brokenLetters) {
            mp[ch-'a'] = true;
        }

        int result        = 0;
        bool foundBroken  = false;
        for(char &ch : text) {
            if(ch == ' ') {
                if(!foundBroken) {
                    result++;
                }
                foundBroken = false;
            } else if (mp[ch - 'a']) {
                foundBroken = true; //found
            }
        }
        if(foundBroken == 0)
            result++;

        return result;
    }
};



/*************************************************************************** JAVA ***************************************************************************/
//Approach - simple iteration
//T.C : O(m+n), m = length of text, n = length of brokenLetters
//S.C : O(1)
class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        // Step 1: Create a boolean array to mark broken letters
        boolean[] broken = new boolean[26];
        for (char ch : brokenLetters.toCharArray()) {
            broken[ch - 'a'] = true;
        }

        int result = 0;
        boolean foundBroken = false;

        // Step 2: Iterate through text character by character
        for (int i = 0; i < text.length(); i++) {
            char ch = text.charAt(i);

            if (ch == ' ') { // End of a word
                if (!foundBroken) {
                    result++;
                }
                foundBroken = false; // reset for next word
            } else if (broken[ch - 'a']) {
                foundBroken = true; // found a broken letter in this word
            }
        }

        // Step 3: Check last word (no space after last word)
        if (!foundBroken) {
            result++;
        }

        return result;
    }
}
