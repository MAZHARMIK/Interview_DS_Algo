/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/parsing-a-boolean-expression
*/


/********************************************************************** C++ **********************************************************************/
//Approach (Using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    char solveOp(char op, vector<char>& values) {
        if (op == '!') 
            return values[0] == 't' ? 'f' : 't';
    
        if (op == '&') 
            return any_of(values.begin(), values.end(), [](char ch) { return ch == 'f'; }) ? 'f' : 't';
    
        if (op == '|') 
            return any_of(values.begin(), values.end(), [](char ch) { return ch == 't'; }) ? 't' : 'f';
    
        return 't'; // Unreachable
    }

    bool parseBoolExpr(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == ',') continue;

            if (s[i] == ')') {
                vector<char> values;
                // Gather all values inside the parentheses
                while (st.top() != '(') {
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop();  // Remove '('
                char op = st.top();
                st.pop();  // Remove the operator
                st.push(solveOp(op, values));
            } else {
                st.push(s[i]);
            }
        }
        return (st.top() == 't');
    }
};



/********************************************************************** C++ **********************************************************************/
//Approach (Using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
    private char solveOp(char op, List<Character> values) {
        if (op == '!') 
            return values.get(0) == 't' ? 'f' : 't';

        if (op == '&') 
            return values.stream().anyMatch(ch -> ch == 'f') ? 'f' : 't';

        if (op == '|') 
            return values.stream().anyMatch(ch -> ch == 't') ? 't' : 'f';

        return 't'; // Unreachable
    }

    public boolean parseBoolExpr(String expression) {
        Stack<Character> stack = new Stack<>();
        int n = expression.length();
        
        for (int i = 0; i < n; i++) {
            char c = expression.charAt(i);
            if (c == ',') continue;

            if (c == ')') {
                List<Character> values = new ArrayList<>();
                // Gather all values inside the parentheses
                while (stack.peek() != '(') {
                    values.add(stack.pop());
                }
                stack.pop();  // Remove '('
                char op = stack.pop();  // Get the operator
                stack.push(solveOp(op, values));  // Push the result back
            } else {
                stack.push(c);  // Push the character onto the stack
            }
        }
        return stack.peek() == 't';
    }
}
