/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Pno2hATcwHA
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/valid-parenthesis-string/
*/

/*************************************************************** C++ ***************************************************************/
//Approach-1 (Using Recrusion + Memoization) -> Why DP ? (See my video above)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public:
    
    int t[101][101];
    bool solve(int idx, int open, string& s, int n) {
        if(idx == n) {
            return open == 0;
        }
        
        if(t[idx][open] != -1) {
            return t[idx][open] == 1 ? true : false;
        }
        
        bool isValid = false;
        
        if(s[idx] == '*') {
            if(open > 0)
                isValid |= solve(idx+1, open-1, s, n); //Treating * as )
            
            isValid |= solve(idx+1, open+1, s, n); //Treating * as (
            
            isValid |= solve(idx+1, open, s, n);   //Treating * as ''
        } else if(s[idx] == '(') {
            isValid |= solve(idx+1, open+1, s, n);
        } else if(open > 0) {
            isValid |= solve(idx+1, open-1, s, n);
        }
        
        return t[idx][open] = isValid;
    }
    
    bool checkValidString(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        return solve(0, 0, s, n);
        
    }
};

//Approach-2 (Using Bottom Up)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
public: 
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<bool>> t(n + 1, vector<bool>(n + 1, false));
        //State Definition :
        //t[i][j] = if the string from index i to n-1 is valid or not having j open brackets
        t[n][0] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int open = 0; open <= n; open++) {
                bool isValid = false;

                if (s[i] == '*') {
                    isValid |= t[i + 1][open + 1]; //Treating * as ( --> solve(i+1, open+1)
                    if (open > 0) {
                        isValid |= t[i + 1][open - 1]; //Treating * as ) --> solve(i+1, open-1)
                    }
                    isValid |= t[i + 1][open]; //Treating * as empty --> solve(i+1, open)
                } else {
                    if (s[i] == '(') {
                        isValid |= t[i + 1][open + 1]; //solve(i+1, open+1)
                    } else if (open > 0) {
                        isValid |= t[i + 1][open - 1]; //solve(i+1, open=-1)
                    }
                }
                t[i][open] = isValid;
            }
        }

        return t[0][0];
    }
};



//Approach-3 (Using two Stacks) - No DP required
//T.C : O(n)
//S.C : O(n)
class Solution {
public: 
    bool checkValidString(string s) {
        stack<int> openSt;
        stack<int> asterisksSt;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(') {
                openSt.push(i);
            } else if (ch == '*') {
                asterisksSt.push(i);
            } else {
                if (!openSt.empty()) {
                    openSt.pop();
                } else if (!asterisksSt.empty()) {
                    asterisksSt.pop();
                } else {
                    return false;
                }
            }
        }

        //This post processing will be required for cases like - "*(())(*"
        while (!openSt.empty() && !asterisksSt.empty()) {
            if (openSt.top() > asterisksSt.top()) {
                return false;
            }
            openSt.pop();
            asterisksSt.pop();
        }

        return openSt.empty();
    }
};


//Approach-4 (Constant Space)
//T.C : O(n)
//S.C :O(1)
//NOTE : You can easily combine both for loops in just a single for loop. I have written them separately for sake of simplicity and understanding
class Solution {
public:
    bool checkValidString(string s) {
        int open = 0;
        int close = 0;
        int n = s.length();
        
        //Left to Right - Check Open Brackets
        for (int i = 0; i < n; i++) {

            if (s[i] == '(' || s[i] == '*') {
                open++;
            } else {
                open--;
            }
                
            if (open < 0) {
                return false;
            }
        }

        //Right to Left - Check CLose Brackets
        for (int i = n - 1; i >= 0; i--) {
            
            if (s[i] == ')' || s[i] == '*') {
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
};


/*************************************************************** JAVA ***************************************************************/
//Approach-1 (Using Recrusion + Memoization) -> Why DP ? (See my video above)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
    public boolean checkValidString(String s) {
        int n = s.length();
        int[][] t = new int[n][n];
        for (int[] row: t) {
            Arrays.fill(row, -1);
        }
        return isValidString(0, 0, s, t);
    }

    private boolean isValidString(int idx, int open, String str, int[][] t) {
        if (idx == str.length()) {
            return (open == 0);
        }
        if (t[idx][open] != -1) {
            return t[idx][open] == 1;
        }
        boolean isValid = false;
        if (str.charAt(idx) == '*') {
            isValid |= isValidString(idx + 1, open + 1, str, t);
            if (open > 0) {
                isValid |= isValidString(idx + 1, open - 1, str, t);
            }
            isValid |= isValidString(idx + 1, open, str, t);
        } else {
            if (str.charAt(idx) == '(') {
                isValid = isValidString(idx + 1, open + 1, str, t);
            } else if (open > 0) {
                isValid = isValidString(idx + 1, open - 1, str, t);
            }
        }
        t[idx][open] = isValid ? 1 : 0;
        return isValid;
    }
}



//Approach-2 (Using Bottom Up)
//T.C : O(n*n)
//S.C : O(n*n)
class Solution {
    public boolean checkValidString(String s) {
        int n = s.length();
        boolean[][] t = new boolean[n + 1][n + 1];
        t[n][0] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int open = 0; open < n; open++) {
                boolean isValid = false;

                if (s.charAt(i) == '*') {
                    isValid |= t[i + 1][open + 1];
                    if (open > 0) {
                        isValid |= t[i + 1][open - 1];
                    }
                    isValid |= t[i + 1][open];
                } else {
                    if (s.charAt(i) == '(') {
                        isValid |= t[i + 1][open + 1];
                    } else if (open > 0) {
                        isValid |= t[i + 1][open - 1];
                    }
                }
                t[i][open] = isValid;
            }
        }

        return t[0][0];
    }
}


//Approach-3 (Using two Stacks) - No DP required
//T.C : O(n)
//S.C : O(n)
class Solution {
    public boolean checkValidString(String s) {
        Stack<Integer> openSt = new Stack<>();
        Stack<Integer> asterisksSt = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if (ch == '(') {
                openSt.push(i);
            } else if (ch == '*') {
                asterisksSt.push(i);
            } else {
                if (!openSt.isEmpty()) {
                    openSt.pop();
                } else if (!asterisksSt.isEmpty()) {
                    asterisksSt.pop();
                } else {
                    return false;
                }
            }
        }

        // This post processing will be required for cases like - "*(())(*"
        while (!openSt.isEmpty() && !asterisksSt.isEmpty()) {
            if (openSt.peek() > asterisksSt.peek()) {
                return false;
            }
            openSt.pop();
            asterisksSt.pop();
        }

        return openSt.isEmpty();
    }
}


//Approach-4 (Constant Space)
//T.C : O(n)
//S.C :O(1)
//NOTE : You can easily combine both for loops in just a single for loop. I have written them separately for sake of simplicity and understanding
class Solution {
    public boolean checkValidString(String s) {
        int open = 0;
        int close = 0;
        int n = s.length();
        
        // Left to Right - Check Open Brackets
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(' || s.charAt(i) == '*') {
                open++;
            } else {
                open--;
            }
                
            if (open < 0) {
                return false;
            }
        }

        // Right to Left - Check Close Brackets
        for (int i = n - 1; i >= 0; i--) {
            if (s.charAt(i) == ')' || s.charAt(i) == '*') {
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
