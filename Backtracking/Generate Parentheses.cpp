/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Samsung
    Leetcode Qn Link            : https://leetcode.com/problems/generate-parentheses/
*/

/************************************************************ C++ ************************************************************/
//Approach-1 (Simple Recursion)
//T.C : O(2n* (2^(2n)) -> Removing constant -> O(n * (2^n))
//S.C : O(2*n) -> Removing constant -> O(n * (2^n)) -> recursion stack space - Max depth of recusion tree
class Solution {
public:
    bool isValid(string str) {
        int sum = 0;
        for(char ch:str) {
            if(ch == '(')
                sum++;
            else
                sum--;
            if(sum < 0)
                return false;
        }
        return sum==0;
    }
    void generate(string curr, int n, int length, vector<string>& result) {
        if(length == 2*n) {
            if(isValid(curr))
                result.push_back(curr);
            return;
        }
        
        curr.push_back('(');
        generate(curr, n, length+1, result);
        curr.pop_back();
        curr.push_back(')');
        generate(curr, n, length+1, result);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        generate("", n, 0, result);
        return result;
    }
};

//Approach-2 (Smart Recursion)
//T.C : O(2^n)
//S.C : O(2*n) -> Removing constant -> O(n * (2^n)) -> recursion stack space - Max depth of recusion tree
class Solution {
public:
    void generateAll(int n, string current, int open, int close, vector<string>& result) {
        if(current.length() == 2*n) {
            result.push_back(current);
            return;
        }
        
        if(open < n)
            generateAll(n, current+"(", open+1, close, result);
        if(close < open)
            generateAll(n, current+")", open, close+1, result);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateAll(n, "", 0, 0, result);
        return result;
    }
};


/************************************************************ JAVA ************************************************************/
// Approach-1 (Simple Recursion)
// Time Complexity: O(n * 2^n)
// Space Complexity: O(n * 2^n) - recursion stack space (Max depth of recursion tree)
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        generate("", n, 0, result);
        return result;
    }

    // Function to check if the parentheses are valid
    private boolean isValid(String str) {
        int sum = 0;
        for (char ch : str) {
            if (ch == '(')
                sum++;
            else
                sum--;
            if (sum < 0)
                return false;
        }
        return sum == 0;
    }

    // Recursive function to generate parentheses
    private void generate(String curr, int n, int length, List<String> result) {
        if (length == 2 * n) {
            if (isValid(curr))
                result.add(curr);
            return;
        }

        curr += '(';
        generate(curr, n, length + 1, result);
        curr = curr.substring(0, curr.length() - 1); // remove the last character

        curr += ')';
        generate(curr, n, length + 1, result);
    }
}


// Approach-2 (Smart Recursion)
// Time Complexity: O(2^n)
// Space Complexity: O(n * 2^n) - recursion stack space (Max depth of recursion tree)
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        generateAll(n, "", 0, 0, result);
        return result;
    }

    // Recursive function to generate all valid combinations
    private void generateAll(int n, String current, int open, int close, List<String> result) {
        if (current.length() == 2 * n) {
            result.add(current);
            return;
        }

        if (open < n)
            generateAll(n, current + '(', open + 1, close, result);
        if (close < open)
            generateAll(n, current + ')', open, close + 1, result);
    }
}
