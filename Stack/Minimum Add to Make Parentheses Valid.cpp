/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=lIdHFWyIrYE
    Company Tags                : Meta
    Leetcode Link               : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid
*/


/********************************************************************** C++ **********************************************************************/
//Approach-1 (Using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int open = 0;
        
        for(char &ch : s) {
            if(ch == '(')
                st.push(ch);
            else if(!st.empty())
                st.pop();
            else
                open++;
        }
        
        return open + st.size();
    }
};


//Approach-2 (without using stack)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int size = 0;
        int open = 0;

        for(char &ch : s) {
            if(ch == '(') {
                size++;
            } else if(size > 0) {
                size--;
            } else {
                open++;
            }
        }

        return open + size;
    }
};



/********************************************************************** JAVA **********************************************************************/
//Approach-1 (Using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int minAddToMakeValid(String s) {
        Stack<Character> stack = new Stack<>();
        int open = 0;

        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                stack.push(ch);
            } else if (!stack.isEmpty()) {
                stack.pop();
            } else {
                open++;
            }
        }

        return open + stack.size();
    }
}


//Approach-2 (without using stack)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int minAddToMakeValid(String s) {
        int size = 0; // Tracks unmatched opening parentheses '('
        int open = 0; // Tracks unmatched closing parentheses ')'

        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                size++; // Increment for each unmatched opening parenthesis
            } else if (size > 0) {
                size--; // Match an opening parenthesis if available
            } else {
                open++; // Unmatched closing parenthesis
            }
        }

        return open + size; // Sum of unmatched opening and closing parentheses
    }
}
