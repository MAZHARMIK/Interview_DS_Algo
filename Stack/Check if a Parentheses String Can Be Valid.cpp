/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Xw8SkHIu2bI
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid
*/


/********************************************************************** C++ **********************************************************************/
//Approach-1 (Using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();

        if(n%2 != 0) { //odd
            return false;
        }

        stack<int> open;
        stack<int> openClose;

        for(int i = 0; i < n; i++) {
            if(locked[i] == '0') {
                openClose.push(i);
            } else if(s[i] == '(') {
                open.push(i);
            } else if(s[i] == ')') {
                if(!open.empty()) {
                    open.pop();
                } else if(!openClose.empty()) {
                    openClose.pop();
                } else {
                    return false;
                }
            }
        }

        while(!open.empty() && !openClose.empty() && open.top() < openClose.top()) {
            open.pop();
            openClose.pop();
        }


        return open.empty(); //true

    }
};


//Approach-2 (Without using stack)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();

        if(n%2 != 0) { //odd
            return false;
        }

        //L to R
        int open = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(' || locked[i] == '0') {
                open++;
            } else {
                open--;
            }

            if(open < 0) {
                return false;
            }
        }

        //R to L
        int close = 0;
        for(int i = n-1; i >= 0; i--) {
            if(s[i] == ')' || locked[i] == '0') {
                close++;
            } else {
                close--;
            }

            if(close < 0) {
                return false;
            }
        }

        return true;

    }
};






/********************************************************************** JAVA **********************************************************************/
// Approach-1 (Using stack)
// T.C : O(n)
// S.C : O(n)
class Solution {
    public boolean canBeValid(String s, String locked) {
        int n = s.length();

        if (n % 2 != 0) { // odd
            return false;
        }

        Stack<Integer> open = new Stack<>();
        Stack<Integer> openClose = new Stack<>();

        for (int i = 0; i < n; i++) {
            if (locked.charAt(i) == '0') {
                openClose.push(i);
            } else if (s.charAt(i) == '(') {
                open.push(i);
            } else if (s.charAt(i) == ')') {
                if (!open.isEmpty()) {
                    open.pop();
                } else if (!openClose.isEmpty()) {
                    openClose.pop();
                } else {
                    return false;
                }
            }
        }

        while (!open.isEmpty() && !openClose.isEmpty() && open.peek() < openClose.peek()) {
            open.pop();
            openClose.pop();
        }

        return open.isEmpty(); // true
    }
}

// Approach-2 (Without using stack)
// T.C : O(n)
// S.C : O(1)
class Solution {
    public boolean canBeValid(String s, String locked) {
        int n = s.length();

        if (n % 2 != 0) { // odd
            return false;
        }

        // L to R
        int open = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(' || locked.charAt(i) == '0') {
                open++;
            } else {
                open--;
            }

            if (open < 0) {
                return false;
            }
        }

        // R to L
        int close = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == ')' || locked.charAt(i) == '0') {
                close++;
            } else {
                close--;
            }

            if (close < 0) {
                return false;
            }
        }

        return true;
    }
}
