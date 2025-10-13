/*    Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=HK9CnjrpqlI
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
*/

//SEE MY YOUTUBE VIDEO ABOVE FOR 4 MORE WAYS TO SOLVE THIS PROBLEM

/*************************************************************************** C++ ***************************************************************************/
//Approach (simple traverse and check)
//T.C : O(n*m)
//S.C : O(1)
class Solution {
public:
    bool checkAnagram(string &s1, string& s2) {
        int arr[26] = {0};

        for(char &ch : s1) {
            arr[ch-'a']++;
        }

        for(char &ch : s2) {
            arr[ch-'a']--;
        }
        
        for(int i = 0; i < 26; i++) {
            if(arr[i] != 0)
                return false;
        }

        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();

        vector<string> result;

        result.push_back(words[0]);

        for(int i = 1; i < n; i++) {
            if(!checkAnagram(words[i], result.back())) {
                result.push_back(words[i]);
            }
        }

        return result;
    }
};




/*************************************************************************** JAVA ***************************************************************************/
//Approach (simple traverse and check)
//T.C : O(n*m)
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
