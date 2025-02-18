/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Khandani Backtracking remplate - storing all possible strings)
//T.C : O(n * 3 * 2^(n-1)) ~= O(n*2^n)
//S.C : O(n * 2^n) , total 2^n strings eaching having length n
class Solution {
public:
    void solve(int n, string &currentString, vector<string> &happyStrings) {
        if (currentString.length() == n) {
            happyStrings.push_back(currentString);
            return;
        }
        
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!currentString.empty() && currentString.back() == ch)
                continue;
            
            // Do
            currentString.push_back(ch);

            // Explore
            solve(n, currentString, happyStrings);

            // Undo
            currentString.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string currentString = "";
        vector<string> result;
        solve(n, currentString, result);

        if (result.size() < k) 
            return "";
        
        return result[k - 1];
    }
};


//Approach-2 (Khandani Backtracking remplate - Without storing all possible strings)
//T.C : O(n * 3 * 2^(n-1)) ~= O(n*2^n)
//S.C : O(n) by recursion system stack
class Solution {
public:
    void solve(int n, string &currentString, int &count, int k, string &result) {
        if (currentString.length() == n) {
            count++;
            if (count == k) {
                result = currentString;  // Store only the k-th string
            }
            return;
        }
        
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!currentString.empty() && currentString.back() == ch)
                continue;
            
            // Do
            currentString.push_back(ch);

            // Explore
            solve(n, currentString, count, k, result);

            // If result is found, exit early
            if (!result.empty()) return;

            // Undo
            currentString.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string currentString = "";
        string result = "";
        int count = 0;
        
        solve(n, currentString, count, k, result);

        return result;
    }
};


/************************************************************ Java ************************************************/
// Approach-1 (Khandani Backtracking Template - storing all possible strings)
// T.C : O(n * 3 * 2^(n-1)) ~= O(n*2^n)
// S.C : O(n * 2^n), total 2^n strings each having length n
class Solution {
    public void solve(int n, StringBuilder currentString, List<String> happyStrings) {
        if (currentString.length() == n) {
            happyStrings.add(currentString.toString());
            return;
        }
        
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (currentString.length() > 0 && currentString.charAt(currentString.length() - 1) == ch)
                continue;
            
            // Do
            currentString.append(ch);

            // Explore
            solve(n, currentString, happyStrings);

            // Undo
            currentString.deleteCharAt(currentString.length() - 1);
        }
    }

    public String getHappyString(int n, int k) {
        StringBuilder currentString = new StringBuilder();
        List<String> result = new ArrayList<>();
        solve(n, currentString, result);

        if (result.size() < k) 
            return "";
        
        return result.get(k - 1);
    }
}


// Approach-2 (Khandani Backtracking Template - Without storing all possible strings)
// T.C : O(n * 3 * 2^(n-1)) ~= O(n*2^n)
// S.C : O(n) by recursion system stack
class Solution {
    public void solve(int n, StringBuilder currentString, int[] count, int k, String[] result) {
        if (currentString.length() == n) {
            count[0]++;
            if (count[0] == k) {
                result[0] = currentString.toString();  // Store only the k-th string
            }
            return;
        }
        
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (currentString.length() > 0 && currentString.charAt(currentString.length() - 1) == ch)
                continue;
            
            // Do
            currentString.append(ch);

            // Explore
            solve(n, currentString, count, k, result);

            // If result is found, exit early
            if (!result[0].isEmpty()) return;

            // Undo
            currentString.deleteCharAt(currentString.length() - 1);
        }
    }

    public String getHappyString(int n, int k) {
        StringBuilder currentString = new StringBuilder();
        String[] result = {""}; // Using an array to pass by reference
        int[] count = {0};  // Using an array to pass count by reference
        
        solve(n, currentString, count, k, result);

        return result[0];
    }
}
