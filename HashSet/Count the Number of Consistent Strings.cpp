/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=QEIKg95HKzg
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/count-the-number-of-consistent-strings
*/


/*************************************************************************** C++ ******************************************************************************************/
//Approach-1 (using hashset)
//T.C : O(m + n*k)
//S.C : O(m)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st(begin(allowed), end(allowed));

        int count = 0;
        for(string &word : words) {
            bool allChar = true;

            for(char &ch : word) {
                if(!st.count(ch)) {
                    allChar = false;
                    break;
                }
            }

            count += allChar;
        }

        return count;
    }
};


//Approach-2 (using boolean array)
//T.C : O(m + n*k)
//S.C : O(m)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> isAllowed(26, false);
        for(char &ch : allowed) {
            isAllowed[ch - 'a'] = true;
        }

        int count = 0;
        for(string &word : words) {
            bool allChar = true;

            for(char &ch : word) {
                if(!isAllowed[ch-'a']) {
                    allChar = false;
                    break;
                }
            }

            count += allChar;
        }

        return count;
    }
};


//Approach-3 (using bit magic)
//T.C : O(m + n*k)
//S.C : O(1)
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;

        //create mask
        for (char &ch : allowed) {
            mask |= 1 << (ch - 'a');
        }

        int count = 0;

        for (string& word : words) {
            bool allChar = true;

            // Check each character in the word
            for (int i = 0; i < word.length(); i++) {

                //check if the bit is set
                if (((mask >> (word[i] - 'a')) & 1) == 0) {
                    allChar = false;
                    break;
                }
            }

            if (allChar) {
                count++;
            }
        }

        return count;
    }
};


/*************************************************************************** JAVA ******************************************************************************************/
import java.util.HashSet;

class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        // Create a set of allowed characters
        HashSet<Character> allowedSet = new HashSet<>();
        for (char ch : allowed.toCharArray()) {
            allowedSet.add(ch);
        }

        int count = 0;

        // Iterate over each word in words
        for (String word : words) {
            boolean allCharAllowed = true;

            // Check if every character in the word is in the allowedSet
            for (char ch : word.toCharArray()) {
                if (!allowedSet.contains(ch)) {
                    allCharAllowed = false;
                    break;
                }
            }

            // Increment count if all characters are allowed
            if (allCharAllowed) {
                count++;
            }
        }

        return count;
    }
}

//Approach-2 (using boolean array)
//T.C : O(m + n*k)
//S.C : O(m)
class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        // Boolean array to track allowed characters
        boolean[] isAllowed = new boolean[26];
        
        // Mark allowed characters as true
        for (char ch : allowed.toCharArray()) {
            isAllowed[ch - 'a'] = true;
        }

        int count = 0;

        // Iterate over each word in words
        for (String word : words) {
            boolean allCharAllowed = true;

            // Check each character in the word
            for (char ch : word.toCharArray()) {
                if (!isAllowed[ch - 'a']) {
                    allCharAllowed = false;
                    break;
                }
            }

            // Increment count if all characters are allowed
            if (allCharAllowed) {
                count++;
            }
        }

        return count;
    }
}


//Approach-3 (using bit magic)
//T.C : O(m + n*k)
//S.C : O(1)
class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        int mask = 0;

        // Create mask
        for (char ch : allowed.toCharArray()) {
            mask |= 1 << (ch - 'a');
        }

        int count = 0;

        // Iterate over words
        for (String word : words) {
            boolean allCharAllowed = true;

            // Check each character in the word
            for (int i = 0; i < word.length(); i++) {
                char ch = word.charAt(i);
                // Check if the bit corresponding to this character is set in the mask
                if (((mask >> (ch - 'a')) & 1) == 0) {
                    allCharAllowed = false;
                    break;
                }
            }

            if (allCharAllowed) {
                count++;
            }
        }

        return count;
    }
}
