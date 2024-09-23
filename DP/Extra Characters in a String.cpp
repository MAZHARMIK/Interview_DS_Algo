/*           Scroll below to see JAVA code also            */
/*
      MY YOUTUBE VIDEO ON THIS Qn : Recursion + Memo             - https://www.youtube.com/watch?v=uQuSzPKtoVU
                                    Recursion + Memo & Bottom Up - 
      Company Tags                : GOOGLE
      Leetcode Link               : https://leetcode.com/problems/extra-characters-in-a-string/
*/

/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion + Memo)
//T.C : O(n^3)
//S.C : O(total numberof characters in dictionary words + n for memoization array)
class Solution {
public:
    int t[51];
    int solve(int i, string& s, unordered_set<string>& st, int &n) {
        if(i >= n) {
            return 0;
        }

        if(t[i] != -1) {
            return t[i];
        }

        int result = 1 + solve(i+1, s, st, n);

        for(int j = i; j < n; j++) {
            string curr = s.substr(i, j-i+1);
            if(st.count(curr)) {
                //valid substring
                result = min(result, solve(j+1, s, st, n));
            }
        }

        return t[i] = result;
    }

    int minExtraChar(string s, vector<string>& dict) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        unordered_set<string> st(begin(dict), end(dict));

        return solve(0, s, st, n);
    }
};

//Approach-2 (Bottom Up)
//T.C : O(n^3)
//S.C : O(n)
class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.length();
        unordered_set<string> st(begin(dict), end(dict));

        vector<int> t(n+1, 0);
        //t[i] = min extra characters in s from index = i to index = n-1
        //return t[0]

        for(int i = n-1; i >=0 ; i--) {
            t[i] = 1 + t[i+1]; //skipping the ith character 1 + (solve(i+1));

            for(int j = i; j < n; j++) {
                string curr = s.substr(i, j-i+1);
                if(st.count(curr)) {
                    t[i] = min(t[i], t[j+1]); //solve(j+1)
                }
            }
        }

        return t[0];
    }
};



************************************************************ JAVA ************************************************************
//Approach-1 (Recursion + Memo)
//T.C : O(n^3)
//S.C : O(total numberof characters in dictionary words + n for memoization array)
// Approach-1 (Recursion + Memoization)
// T.C : O(n^3)
// S.C : O(total number of characters in dictionary words + n for memoization array)
import java.util.*;

class Solution {

    int[] t = new int[51];

    public int solve(int i, String s, Set<String> st, int n) {
        if (i >= n) {
            return 0;
        }

        if (t[i] != -1) {
            return t[i];
        }

        int result = 1 + solve(i + 1, s, st, n); // skipping the ith character

        for (int j = i; j < n; j++) {
            String curr = s.substring(i, j + 1);
            if (st.contains(curr)) {
                // valid substring
                result = Math.min(result, solve(j + 1, s, st, n));
            }
        }

        return t[i] = result;
    }

    public int minExtraChar(String s, List<String> dict) {
        int n = s.length();
        Arrays.fill(t, -1);
        Set<String> st = new HashSet<>(dict);

        return solve(0, s, st, n);
    }
}


//Approach-2 (Bottom Up)
//T.C : O(n^3)
//S.C : O(n)
// Approach-2 (Bottom-Up)
// T.C : O(n^3)
// S.C : O(n)
import java.util.*;

class Solution {

    public int minExtraChar(String s, List<String> dict) {
        int n = s.length();
        Set<String> st = new HashSet<>(dict);

        int[] t = new int[n + 1]; // DP array
        // t[i] = min extra characters in s from index i to index n-1
        // we want to return t[0]

        for (int i = n - 1; i >= 0; i--) {
            t[i] = 1 + t[i + 1]; // skipping the ith character

            for (int j = i; j < n; j++) {
                String curr = s.substring(i, j + 1);
                if (st.contains(curr)) {
                    t[i] = Math.min(t[i], t[j + 1]); // solve(j+1)
                }
            }
        }

        return t[0];
    }
}
