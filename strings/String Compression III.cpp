/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=cbo80sOKci4
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/string-compression-iii
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Simple Simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string compressedString(string word) {
        string comp = "";

        int n = word.length();
        int i = 0;

        while(i < n) {
            int count = 0;
            char ch   = word[i];

            while(i < n && count < 9 && word[i] == ch) {
                count++;
                i++;
            }

            comp += to_string(count) + ch;
        }

        return comp;
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach (Simple Simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public String compressedString(String word) {
        StringBuilder comp = new StringBuilder();
        int n = word.length();
        int i = 0;

        while (i < n) {
            int count = 0;
            char ch = word.charAt(i);

            while (i < n && count < 9 && word.charAt(i) == ch) {
                count++;
                i++;
            }

            comp.append(count).append(ch);
        }

        return comp.toString();
    }
}
