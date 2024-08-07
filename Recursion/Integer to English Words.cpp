/*         Scroll below to see JAVA code also         */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9FLpWWJ987w
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/integer-to-english-words
*/

/******************************************************** C++ **********************************************************************/
//Approach - Simple Recursion Story
//T.C : O(log10(num))
//S.C : O(log10(num))
class Solution {
public:

    // Unordered maps to store words for numbers less than 10, 20, and 100
    unordered_map<int, string> belowTen = { {0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"} };
    unordered_map<int, string> belowTwenty = { {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"} };
    unordered_map<int, string> belowHundred = { {1, "Ten"}, {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"} };


    string solve(int num) {
        if(num < 10) {
            return belowTen[num];
        }

        if(num < 20) {
            return belowTwenty[num];
        }

        if(num < 100) { //89 = "Eighty Nine"
            return belowHundred[num/10] + ((num%10 != 0) ? " " + belowTen[num%10] : "");
        }

        if(num < 1000) { //879/100 = 8 "Eight"
            return solve(num/100) + " Hundred" + ((num%100 != 0) ? " " + solve(num%100) : "");
        }

        if(num < 1000000) {
            return solve(num/1000) + " Thousand" + ((num%1000 != 0) ? " " + solve(num%1000) : "");
        }

        if(num < 1000000000) {
            return solve(num/1000000) + " Million" + ((num%1000000 != 0) ? " " + solve(num%1000000) : "");
        }

        return solve(num/1000000000) + " Billion" + ((num%1000000000 != 0) ? " " + solve(num%1000000000) : "");
    }

    string numberToWords(int num) {
        if(num == 0) {
            return "Zero";
        }

        return solve(num);
    }
};


/******************************************************** JAVA **********************************************************************/
//Approach - Simple Recursion Story
//T.C : O(log10(num))
//S.C : O(log10(num))
class Solution {
    private static final Map<Integer, String> belowTen = Map.of(
        0, "", 1, "One", 2, "Two", 3, "Three", 4, "Four", 5, "Five", 
        6, "Six", 7, "Seven", 8, "Eight", 9, "Nine"
    );

    private static final Map<Integer, String> belowTwenty = Map.of(
        10, "Ten", 11, "Eleven", 12, "Twelve", 13, "Thirteen", 14, "Fourteen", 
        15, "Fifteen", 16, "Sixteen", 17, "Seventeen", 18, "Eighteen", 19, "Nineteen"
    );

    private static final Map<Integer, String> belowHundred = Map.of(
        2, "Twenty", 3, "Thirty", 4, "Forty", 5, "Fifty", 
        6, "Sixty", 7, "Seventy", 8, "Eighty", 9, "Ninety"
    );

    public String solve(int num) {
        if (num < 10) {
            return belowTen.get(num);
        }

        if (num < 20) {
            return belowTwenty.get(num);
        }

        if (num < 100) { // 89 = "Eighty Nine"
            return belowHundred.get(num / 10) + (num % 10 != 0 ? " " + belowTen.get(num % 10) : "");
        }

        if (num < 1000) { // 879 / 100 = 8 "Eight"
            return solve(num / 100) + " Hundred" + (num % 100 != 0 ? " " + solve(num % 100) : "");
        }

        if (num < 1000000) {
            return solve(num / 1000) + " Thousand" + (num % 1000 != 0 ? " " + solve(num % 1000) : "");
        }

        if (num < 1000000000) {
            return solve(num / 1000000) + " Million" + (num % 1000000 != 0 ? " " + solve(num % 1000000) : "");
        }

        return solve(num / 1000000000) + " Billion" + (num % 1000000000 != 0 ? " " + solve(num % 1000000000) : "");
    }

    public String numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        return solve(num);
    }
}
