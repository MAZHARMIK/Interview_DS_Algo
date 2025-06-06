/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Greedily finding the minimum character to right)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();

        vector<char> minCharToRight(n); //you can store index of those characters instead of storing characters

        minCharToRight[n-1] = s[n-1];
        for(int i = n-2; i >= 0; i--) {
            minCharToRight[i] = min(s[i], minCharToRight[i+1]);
        }


        string t = "";
        string paper = "";

        int i = 0; 
        while(i < n) {
            t.push_back(s[i]);

            char minChar = (i+1 < n) ? minCharToRight[i+1] : s[i];

            while(!t.empty() && t.back() <= minChar) {
                paper += t.back();
                t.pop_back();
            }

            i++;
        }

        //fill the remaining characters
        while(!t.empty()) {
            paper += t.back();
            t.pop_back();
        }

        return paper;
    }
};


/**************************************************************** JAVA ****************************************************************/
//Approach (Greedily finding the minimum character to right)
//T.C : O(n)
//S.C : O(n)
import java.util.*;

class Solution {
    public String robotWithString(String s) {
        int n = s.length();

        // Array to store the smallest character from index i to the end
        char[] minCharToRight = new char[n];
        minCharToRight[n - 1] = s.charAt(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            minCharToRight[i] = (char) Math.min(s.charAt(i), minCharToRight[i + 1]);
        }

        Deque<Character> stack = new ArrayDeque<>();
        StringBuilder paper = new StringBuilder();

        int i = 0;
        while (i < n) {
            stack.push(s.charAt(i));
            char minChar = (i + 1 < n) ? minCharToRight[i + 1] : s.charAt(i);

            while (!stack.isEmpty() && stack.peek() <= minChar) {
                paper.append(stack.pop());
            }

            i++;
        }

        // Empty the remaining characters from the stack
        while (!stack.isEmpty()) {
            paper.append(stack.pop());
        }

        return paper.toString();
    }
}
