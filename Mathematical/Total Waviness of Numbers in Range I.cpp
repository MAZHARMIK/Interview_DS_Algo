/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=rPbjKtn3vOg
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/total-waviness-of-numbers-in-range-i
*/

/*********************************************************** C++ **************************************************/
//Approach (Linear Scan - Iterate over range and score each number)
//T.C : O((num2 - num1) * log10(num2))  — for each number we scan its digits
//S.C : O(log10(num2))                  — space for the digit string of each number
class Solution {
public:
    int findWaiveScore(int num) {
        string s = to_string(num);

        int l = s.length();
        if (l < 3)
            return 0;

        int score = 0;
        for (int i = 1; i <= l - 2; i++) {
            // peak
            if (s[i] > s[i - 1] && s[i] > s[i + 1]) score++;

            // valley
            if (s[i] < s[i - 1] && s[i] < s[i + 1]) score++;
        }

        return score;
    }

    int totalWaviness(int num1, int num2) {
        int score = 0;

        for (int num = num1; num <= num2; num++) {
            score += findWaiveScore(num);
        }

        return score;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Linear Scan - Iterate over range and score each number)
//T.C : O((num2 - num1) * log10(num2))
//S.C : O(log10(num2))
class Solution {
    private int findWaiveScore(int num) {
        String s = Integer.toString(num);

        int l = s.length();
        if (l < 3)
            return 0;

        int score = 0;
        for (int i = 1; i <= l - 2; i++) {
            // peak
            if (s.charAt(i) > s.charAt(i - 1) && s.charAt(i) > s.charAt(i + 1)) score++;

            // valley
            if (s.charAt(i) < s.charAt(i - 1) && s.charAt(i) < s.charAt(i + 1)) score++;
        }

        return score;
    }

    public int totalWaviness(int num1, int num2) {
        int score = 0;

        for (int num = num1; num <= num2; num++) {
            score += findWaiveScore(num);
        }

        return score;
    }
}
