/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid
*/

//If you want, I can make a separate video on Bottom Up. Let me know in the comments



/**************************************************************** C++ ****************************************************************/
//Approach (Recursion + Memoization : DP On Grids) - If you want, I can make a separate video on Bottom Up. Let me know in the comments
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int M = 1e9 + 7;
    vector<vector<int>> t;

    //12 possible first rows
    string states[12] = {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR", "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"};

    int solve(int n, int prev) {
        if(n == 0)
            return 1;
        
        if(t[n][prev] != -1)
            return t[n][prev];

        int result = 0;
        string last = states[prev];

        for(int curr = 0; curr < 12; curr++) {
            if(curr == prev)
                continue;
            
            string currPat = states[curr];
            bool conflict = false;
            for(int col = 0; col < 3; col++) {
                if(currPat[col] == last[col]) {
                    conflict = true;
                    break;
                }
            }

            if(!conflict) {
                result = (result + solve(n-1, curr)) % M;
            }
        }

        return t[n][prev] = result;
    }

    int numOfWays(int n) {
        t.resize(n, vector<int>(12, -1)); //T.C : O(n)
        int result = 0;

        for(int i = 0; i < 12; i++) { //chossing 1st row
            //now remaining n-1 rows painting
            result = (result + solve(n-1, i)) % M;
        }

        return result;
    }
};




/**************************************************************** Java ****************************************************************/
//Approach (Recursion + Memoization : DP On Grids) - If you want, I can make a separate video on Bottom Up. Let me know in the comments
//T.C : O(n)
//S.C : O(n)
class Solution {
    int M = 1_000_000_007;
    int[][] t;

    // 12 possible row patterns
    String[] states = {
        "RYG", "RGY", "RYR", "RGR",
        "YRG", "YGR", "YGY", "YRY",
        "GRY", "GYR", "GRG", "GYG"
    };

    int solve(int n, int prev) {
        if (n == 0)
            return 1;

        if (t[n][prev] != -1)
            return t[n][prev];

        int result = 0;
        String last = states[prev];

        for (int curr = 0; curr < 12; curr++) {
            if (curr == prev)
                continue;

            String currPat = states[curr];
            boolean conflict = false;

            for (int col = 0; col < 3; col++) {
                if (currPat.charAt(col) == last.charAt(col)) {
                    conflict = true;
                    break;
                }
            }

            if (!conflict) {
                result = (result + solve(n - 1, curr)) % M;
            }
        }

        return t[n][prev] = result;
    }

    public int numOfWays(int n) {
        t = new int[n][12];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 12; j++) {
                t[i][j] = -1;
            }
        }

        int result = 0;

        // choose first row
        for (int i = 0; i < 12; i++) {
            result = (result + solve(n - 1, i)) % M;
        }

        return result;
    }
}
