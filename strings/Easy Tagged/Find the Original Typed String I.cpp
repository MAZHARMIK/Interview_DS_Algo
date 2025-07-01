/*         Scroll below to see JAVA code also          */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=XpRSv1EFmhU
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/find-the-original-typed-string-i
*/

/****************************************************************** C++ ******************************************************************/
//Approach (straight forward traversal)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int possibleStringCount(string word) {
        int count = 0;

        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1])
                count++;
        }

        return count+1; //+1 for when Alice does no long press
    }
};



/****************************************************************** JAVA ******************************************************************/
//Approach (straight forward traversal)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int possibleStringCount(String word) {
        int count = 0;

        for (int i = 1; i < word.length(); i++) {
            if (word.charAt(i) == word.charAt(i - 1)) {
                count++;
            }
        }

        return count + 1; // +1 for the base case (no long presses)
    }
}
