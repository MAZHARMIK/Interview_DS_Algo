/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/score-of-parentheses
*/


/********************************************************************** C++ **********************************************************************/
//Approach-1 (Using stack or vector as stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        vector<int> vec;

        int score = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(') {
                vec.push_back(score);
                score = 0;
            } else {
                if (s[i-1] == '(') { //we found inner most "()" -> +1 point
                    score = vec.back() + 1;
                } else {
                    // had content inside -> double it
                    score = vec.back() + (2 * score);
                }
                vec.pop_back();
            }
        }
        return score;
    }
};




//Approach-2 (Calculating from Depth)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int depth = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                depth++;
            } else {
                depth--;
                if (s[i - 1] == '(') {
                    score += (1 << depth);  // i.e. 2^depth
                }
            }
        }
        return score;
    }
};



/********************************************************************** JAVA **********************************************************************/
//Approach-1 (Using stack or vector as stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int scoreOfParentheses(String s) {
        int n = s.length();
        Deque<Integer> stack = new ArrayDeque<>();

        int score = 0;

        for (int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            if (ch == '(') {
                stack.push(score);
                score = 0;
            } else {
                if (s.charAt(i - 1) == '(') { // we found innermost "()" -> +1 point
                    score = stack.peek() + 1;
                } else {
                    // had content inside -> double it
                    score = stack.peek() + (2 * score);
                }
                stack.pop();
            }
        }
        return score;
    }
}


//Approach-2 (Calculating from Depth)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int scoreOfParentheses(String s) {
        int score = 0;
        int depth = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                depth++;
            } else {
                depth--;
                if (s.charAt(i - 1) == '(') {
                    score += (1 << depth); // i.e. 2^depth
                }
            }
        }
        return score;
    }
}
