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
    void solve(int n, string &curr, vector<string> &result) {
        if (curr.length() == n) {
            result.push_back(curr);
            return;
        }
        
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch)
                continue;
            
            // Do
            curr.push_back(ch);

            // Explore
            solve(n, curr, result);

            // Undo
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> result;
        solve(n, curr, result);

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
    void solve(int n, string &curr, int &count, int k, string &result) {
        if (curr.length() == n) {
            count++;
            if (count == k) {
                result = curr;  // Store only the k-th string
            }
            return;
        }
        
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch)
                continue;
            
            // Do
            curr.push_back(ch);

            // Explore
            solve(n, curr, count, k, result);

            // If result is found, exit early
            if (!result.empty()) return;

            // Undo
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        string result = "";
        int count = 0;
        
        solve(n, curr, count, k, result);

        return result;
    }
};


/************************************************************ Java ************************************************/
// Approach-1 (Khandani Backtracking Template - storing all possible strings)
// T.C : O(n * 3 * 2^(n-1)) ~= O(n*2^n)
// S.C : O(n * 2^n), total 2^n strings each having length n
class Solution {
    public void solve(int n, StringBuilder curr, List<String> result) {
        if (curr.length() == n) {
            result.add(curr.toString());
            return;
        }
        
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (curr.length() > 0 && curr.charAt(curr.length() - 1) == ch)
                continue;
            
            // Do
            curr.append(ch);

            // Explore
            solve(n, curr, happyStrings);

            // Undo
            curr.deleteCharAt(curr.length() - 1);
        }
    }

    public String getHappyString(int n, int k) {
        StringBuilder curr = new StringBuilder();
        List<String> result = new ArrayList<>();
        solve(n, curr, result);

        if (result.size() < k) 
            return "";
        
        return result.get(k - 1);
    }
}


// Approach-2 (Khandani Backtracking Template - Without storing all possible strings)
// T.C : O(n * 3 * 2^(n-1)) ~= O(n*2^n)
// S.C : O(n) by recursion system stack
class Solution {
    public void solve(int n, StringBuilder curr, int[] count, int k, String[] result) {
        if (curr.length() == n) {
            count[0]++;
            if (count[0] == k) {
                result[0] = curr.toString();  // Store only the k-th string
            }
            return;
        }
        
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (curr.length() > 0 && curr.charAt(curr.length() - 1) == ch)
                continue;
            
            // Do
            curr.append(ch);

            // Explore
            solve(n, curr, count, k, result);

            // If result is found, exit early
            if (!result[0].isEmpty()) return;

            // Undo
            curr.deleteCharAt(curr.length() - 1);
        }
    }

    public String getHappyString(int n, int k) {
        StringBuilder curr = new StringBuilder();
        String[] result = {""}; // Using an array to pass by reference
        int[] count = {0};  // Using an array to pass count by reference
        
        solve(n, curr, count, k, result);

        return result[0];
    }
}
