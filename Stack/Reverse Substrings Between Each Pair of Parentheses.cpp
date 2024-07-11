/*    Scroll below to see JAVA code also      */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=dUQRS4luBvA
    Company Tags                : META, AMAZON
    Leetcode Link               : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description
*/


/************************************************************ C++ ************************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openeBracket; //You can use a vector also as stack
        string result;
        for (char currentChar : s) {
            if (currentChar == '(') {
                openeBracket.push(result.length());
            } else if (currentChar == ')') {
                int start = openeBracket.top();
                openeBracket.pop();
                reverse(result.begin() + start, result.end());
            } else {
                result += currentChar;
            }
        }
        return result;
    }
};


//Approach-2 (Linear Approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> openBracket;
        vector<int> door(n);

        // First pass: Pair up parentheses
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                openBracket.push(i);
            } else if (s[i] == ')') {
                int j = openBracket.top();
                openBracket.pop();
                door[i] = j;
                door[j] = i;
            }
        }

        // Second pass: Build the result string
        string result;
        int direction = 1; //Left to Right
        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = door[i];
                direction = -direction;
            } else {
                result += s[i];
            }
        }
        return result;
    }
};


/************************************************************ JAVA ************************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(n)
class Solution {

    public String reverseParentheses(String s) {
        Stack<Integer> openBracket = new Stack<>();
        StringBuilder result = new StringBuilder();

        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                openBracket.push(result.length());
            } else if (ch == ')') {
                int start = openBracket.pop();
                reverse(result, start, result.length() - 1);
            } else {
                result.append(ch);
            }
        }

        return result.toString();
    }

    private void reverse(StringBuilder sb, int start, int end) {
        while (start < end) {
            char temp = sb.charAt(start);
            sb.setCharAt(start++, sb.charAt(end));
            sb.setCharAt(end--, temp);
        }
    }
}



//Approach-2 (Linear Approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public String reverseParentheses(String s) {
        int n = s.length();
        Stack<Integer> openBracket = new Stack<>();
        int[] door = new int[n];

        // First pass: Pair up parentheses
        for (int i = 0; i < n; ++i) {
            if (s.charAt(i) == '(') {
                openBracket.push(i);
            } else if (s.charAt(i) == ')') {
                int j = openBracket.pop();
                door[i] = j;
                door[j] = i;
            }
        }

        // Second pass: Build the result string
        StringBuilder result = new StringBuilder();
        int direction = 1; // Left to Right
        for (int i = 0; i < n; i += direction) {
            if (s.charAt(i) == '(' || s.charAt(i) == ')') {
                i = door[i];
                direction = -direction;
            } else {
                result.append(s.charAt(i));
            }
        }
        return result.toString();
    }
}
