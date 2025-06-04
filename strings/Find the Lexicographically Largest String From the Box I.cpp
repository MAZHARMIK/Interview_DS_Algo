/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : O(n^2) - https://www.youtube.com/watch?v=P74WiyWY3Pk
                                  O(n)   - https://www.youtube.com/watch?v=4w-_rtiau_Q
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (trying at every index to find best substring)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length();
        if( numFriends == 1)
            return word;

        string result;

        int longestPossible = n - (numFriends - 1);

        for(int i = 0; i < n; i++) {
            int canTakeLength = min(longestPossible, n-i);

            result = max(result, word.substr(i, canTakeLength));
        }

        return result;
    }
};


//Approach-2 (2 Pointer)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int bestStartingPoint(string &word, int n) {
        int i = 0; //best starting point
        int j = 1; //keep moving to find the best starting point

        while(j < n) {
            int k = 0;

            //skipping equal characters
            while( j+k < n && word[i+k] == word[j+k]) {
                k++;
            }

            if(j+k < n && word[j+k] > word[i+k]) {
                i = j; //updating best starting point
                j = j+1;
            } else {
                j = j + k + 1; //skipping already checked characters
            }
        }

        return i;
    }

    string answerString(string word, int numFriends) {
        int n = word.length();

        if(numFriends == 1)
            return word;

        int i = bestStartingPoint(word, n);

        int longestPossibleLength = n - (numFriends-1);
        int canTakePossible       = min(longestPossibleLength, n-i);

        return word.substr(i, canTakePossible);

    }
};


/**************************************************************** JAVA ****************************************************************/
//Approach-1 (trying at every index to find best substring)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public String answerString(String word, int numFriends) {
        int n = word.length();
        if (numFriends == 1) {
            return word;
        }

        int longestPossible = n - (numFriends - 1);
        String result = "";

        for (int i = 0; i < n; i++) {
            int canTakeLength = Math.min(longestPossible, n - i);
            String sub = word.substring(i, i + canTakeLength);
            if (sub.compareTo(result) > 0) {
                result = sub;
            }
        }

        return result;
    }
}


//Approach-2 (2 Pointer) - Coming soon
//T.C : O(n)
//S.C : O(1)
public class Solution {

    public int bestStartingPoint(String word, int n) {
        int i = 0; // best starting point
        int j = 1; // keep moving to find the best starting point

        while (j < n) {
            int k = 0;

            // skipping equal characters
            while (j + k < n && word.charAt(i + k) == word.charAt(j + k)) {
                k++;
            }

            if (j + k < n && word.charAt(j + k) > word.charAt(i + k)) {
                i = j; // updating best starting point
                j = j + 1;
            } else {
                j = j + k + 1; // skipping already checked characters
            }
        }

        return i;
    }

    public String answerString(String word, int numFriends) {
        int n = word.length();

        if (numFriends == 1) {
            return word;
        }

        int i = bestStartingPoint(word, n);
        int longestPossibleLength = n - (numFriends - 1);
        int canTakePossible = Math.min(longestPossibleLength, n - i);

        return word.substring(i, i + canTakePossible);
    }
}
