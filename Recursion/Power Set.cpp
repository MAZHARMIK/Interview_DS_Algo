/*                     Scroll below to see JAVA code also     */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tp9Y2AqBk6s
    Company Tags                : Snapdeal
    GFG Link                    : https://www.geeksforgeeks.org/problems/power-set4302/1
*/

/********************************************************************** C++ ***************************************************************/
//Approach-1 (Without For Loop)
//T.C : O(n * 2^n) - For ever index, we have two possibilities so 2^n and for copying each string to result, it takes O(n)
//S.C : O(n) - Recursion tree depth will be at max  = n  (NOTE : I have ignored space taken for storing result)
class Solution {
public:
    vector<string> result;

    void solve(string &curr, string &s, int idx) {
        // Base case: If the current index reaches the length of the string
        if (idx == s.length()) {
            // If the current string is not empty, add it to the result
            if (curr != "") {
                result.push_back(curr);
            }
            return;
        }

        // Include the character at the current index and proceed
        curr.push_back(s[idx]);
        solve(curr, s, idx + 1);

        // Exclude the character at the current index and proceed
        curr.pop_back();
        solve(curr, s, idx + 1);
    }

    vector<string> AllPossibleStrings(string s) {
        string curr = "";
        // Start the recursive function to generate all possible strings
        solve(curr, s, 0);

        // Sort the result lexicographically
        sort(begin(result), end(result));

        // Return the final result
        return result;
    }
};


//Approach-2 (Using for loop)
//T.C : O(n * 2^n)
//S.C : O(n)
class Solution {
public:
    vector<string> result;

    // Recursive function to generate all possible strings
    void solve(string &curr, string &s, int idx) {
        // If the current string is not empty, add it to the result
        if (curr != "") {
            result.push_back(curr);
        }

        // Iterate through the remaining characters in the string
        for (int i = idx; i < s.length(); i++) {
            // Include the character at the current index and proceed
            curr.push_back(s[i]);
            solve(curr, s, i + 1);
            curr.pop_back();  // Backtrack by removing the last character
        }
    }

    // Main function to generate all possible strings
    vector<string> AllPossibleStrings(string s) {
        string curr = "";
        solve(curr, s, 0);  // Start the recursive function
        sort(begin(result), end(result));  // Sort the result lexicographically
        return result;
    }
};



/********************************************************************** JAVA ***************************************************************/
//Approach-1 (Without For Loop)
//T.C : O(n * 2^n) - For ever index, we have two possibilities so 2^n and for copying each string to result, it takes O(n)
//S.C : O(n) - Recursion tree depth will be at max  = n  (NOTE : I have ignored space taken for storing result)
class Solution {
    private List<String> result = new ArrayList<>();

    private void solve(StringBuilder curr, String s, int idx) {
        if (idx == s.length()) {
            if (curr.length() > 0) {
                result.add(curr.toString());
            }
            return;
        }

        curr.append(s.charAt(idx));
        solve(curr, s, idx + 1);
        curr.deleteCharAt(curr.length() - 1);
        solve(curr, s, idx + 1);
    }

    public List<String> AllPossibleStrings(String s) {
        StringBuilder curr = new StringBuilder();

        solve(curr, s, 0);

        Collections.sort(result);

        return result;
    }
}


//Approach-2 (Using for loop)
//T.C : O(n * 2^n)
//S.C : O(n)
class Solution
{
    private List<String> result = new ArrayList<>();
    private void solve(StringBuilder curr, String s, int idx) {
        if (curr.length() > 0) {
            result.add(curr.toString());
        }

        for (int i = idx; i < s.length(); i++) {
            curr.append(s.charAt(i));
            solve(curr, s, i + 1);
            curr.deleteCharAt(curr.length() - 1);
        }
    }
    
    public List<String> AllPossibleStrings(String s)
    {
        StringBuilder curr = new StringBuilder();

        solve(curr, s, 0);

        Collections.sort(result);

        return result;
    }
}
