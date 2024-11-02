/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=LEc1tjoXV-A
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/delete-characters-to-make-fancy-string
*/

/****************************************** C++ ***********************************************************/
//Approach (Simple straight forward traversal)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();

        string result = "";

        result.push_back(s[0]);
        int freq = 1;

        for(int i = 1; i < n; i++) {
            if(s[i] == result.back()) {
                freq++;
                if(freq < 3) {
                    result.push_back(s[i]);
                }
            } else {
                result.push_back(s[i]);
                freq = 1;
            }
        }

        return result;
    }
};


/***************************************************** JAVA ****************************************************/
//Approach (Simple straight forward traversal)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public String makeFancyString(String s) {
        int n = s.length();
        StringBuilder result = new StringBuilder();

        // Start with the first character
        result.append(s.charAt(0));
        int freq = 1;

        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == result.charAt(result.length() - 1)) {
                freq++;
                if (freq < 3) {
                    result.append(s.charAt(i));
                }
            } else {
                result.append(s.charAt(i));
                freq = 1;
            }
        }

        return result.toString();
    }
}
