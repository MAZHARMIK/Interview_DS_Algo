/*                                                        SCROLL DOWN FOR JAVA CODE ALSO                                   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=BM-bu4tJz7U
    Company Tags                : Apple, Microsoft, Flipkart, Amazon, LinkedIn
    Leetcode Link               : https://leetcode.com/problems/evaluate-reverse-polish-notation/
*/

/********************************************************************* C++ ************************************************************************/
2-line recall (CodeStoryWithMIK approach – whole code):

Loop through each token: if it is a number, push(stoi(token)); otherwise, pop b first, then a, call operate(a, b, token) (or mp[token](a,b)), and push the computed result back onto the stack.
operate() handles +, -, *, / (preserving operand order as a op b); after all tokens are processed, st.top() is the final answer because every operator reduces two operands into one result.
2-line recall (CodeStoryWithMIK approach) whole code approach 2

Approach 2 (Map + Lambda) – 2-line recall (CodeStoryWithMIK approach):

Create an unordered_map<string, function<int(int,int)>> that maps each operator (+, -, *, /) to its corresponding lambda; while traversing tokens, push numbers, otherwise pop b, then a, compute mp[token](a, b), and push the result.
The map replaces the separate operate() function, but the stack logic remains identical—each operator reduces two operands into one, and after all tokens are processed, st.top() is the final answer (O(n) time, O(n) space).
//Approach-1 (Basic stack approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int operate(int &a, int &b, const string &s) {
        if(s == "+")
            return a+b;
        
        if(s == "-")
            return a-b;
        
        if(s == "*")
            return (long)a*(long)b;
        
        if(s == "/")
            return a/b;
        
        return -1;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result = 0;
        for(const string& s:tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                result = operate(a, b, s);
                st.push(result);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};


/*
    Using fancy Lambda on unordered_map
    For my fancy STL collection with easy exlanation with examples, see the link below -
    https://github.com/MAZHARMIK/Cpp-STL-Quick-Help/blob/main/README.md
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int result = 0;
        
        unordered_map<string, function<int (int, int)> > mp = {
            {"+", [](int a, int b) {return a + b; } },
            {"-", [](int a, int b) {return a - b; } },
            {"*", [](int a, int b) {return (long)a * (long)b; } },
            {"/", [](int a, int b) {return a / b; } },
        };
        
        for(const string& s:tokens) {
            if(s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                
                result = mp[s](a, b);
                st.push(result);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};



/********************************************************************* JAVA ************************************************************************/
//Approach-1 (Basic stack approach)
//T.C : O(n)
//S.C : O(n)
public class Solution {
    public int operate(int a, int b, String s) {
        if (s.equals("+"))
            return a + b;

        if (s.equals("-"))
            return a - b;

        if (s.equals("*"))
            return (int) ((long) a * (long) b);

        if (s.equals("/"))
            return a / b;

        return -1;
    }

    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();
        int result = 0;

        for (String s : tokens) {
            if (s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/")) {
                int b = st.pop();
                int a = st.pop();

                result = operate(a, b, s);
                st.push(result);
            } else {
                st.push(Integer.parseInt(s));
            }
        }

        return st.pop();
    }
}

/*
    Using fancy Lambda on unordered_map
    For my fancy STL collection with easy exlanation with examples, see the link below -
    https://github.com/MAZHARMIK/Cpp-STL-Quick-Help/blob/main/README.md
*/
//Approach-2 (Using map and lambda)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();
        int result = 0;

        Map<String, BiFunction<Integer, Integer, Integer>> mp = new HashMap<>();
        mp.put("+", (a, b) -> a + b);
        mp.put("-", (a, b) -> a - b);
        mp.put("*", (a, b) -> (int)((long)a * (long)b));
        mp.put("/", (a, b) -> a / b);

        for (String s : tokens) {
            if (mp.containsKey(s)) {
                int b = st.pop();
                int a = st.pop();

                result = mp.get(s).apply(a, b);
                st.push(result);
            } else {
                st.push(Integer.parseInt(s));
            }
        }
        return st.pop();
    }
}
