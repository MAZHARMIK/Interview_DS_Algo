/*    Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=uxdIomeyUDs
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/valid-word
*/

/*************************************************************************** C++ ***************************************************************************/
//Approach (simple traverse and check)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3) {
            return false;
        }

        bool hasVowel     = false;
        bool hasConsonant = false;

        for(char ch : word) {
            if(isalpha(ch)) {
                ch = tolower(ch);
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            } else if(!isdigit(ch)) {
                return false;
            }
        }

        return hasVowel && hasConsonant;
    }
};



/*************************************************************************** C++ ***************************************************************************/
//Approach (simple traverse and check)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean isValid(String word) {
        if (word.length() < 3) {
            return false;
        }

        boolean hasVowel = false;
        boolean hasConsonant = false;

        for (char ch : word.toCharArray()) {
            if (Character.isLetter(ch)) {
                ch = Character.toLowerCase(ch);
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            } else if (!Character.isDigit(ch)) {
                return false;
            }
        }

        return hasVowel && hasConsonant;
    }
}
