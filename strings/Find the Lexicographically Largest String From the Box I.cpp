/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
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

//Approach-2 (2 Pointer) - Coming soon
//T.C : O(n)
//S.C : O(1)



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
