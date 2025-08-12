/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=yA0DVkXhueg
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n*n), assuming that num can go till n in worst case (At max states = t[n][n])
//S.C : O(n*n), assuming that num can go till n in worst case (we took t[n][n])
class Solution {
public:

    int M = 1e9+7;
    int t[301][301];

    int solve(int n, int num, int x) {
        if(n == 0)
            return 1;
        
        if(n < 0)
            return 0;
        
        int currPowerValue = pow(num, x);
        if(currPowerValue > n) {
            return 0;
        }

        if(t[n][num] != -1) {
            return t[n][num];
        }

        int take = solve(n-currPowerValue, num+1, x);
        int skip = solve(n, num+1, x);

        return t[n][num] = (take+skip)%M;
    }
    int numberOfWays(int n, int x) {
        memset(t, -1, sizeof(t));
        return solve(n, 1, x);
    }
};


//Approach-2 (Bottom Up)
//Will come in 2nd half today - Little occupied today




/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n*n), assuming that num can go till n in worst case (At max states = t[n][n])
//S.C : O(n*n), assuming that num can go till n in worst case (we took t[n][n])
class Solution {
    private final int M = 1000000007; // 1e9 + 7
    private int[][] t = new int[301][301];

    private int solve(int n, int num, int x) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 0;
        }

        int currPowerValue = (int) Math.pow(num, x);
        if (currPowerValue > n) {
            return 0;
        }

        if (t[n][num] != -1) {
            return t[n][num];
        }

        int take = solve(n - currPowerValue, num + 1, x);
        int skip = solve(n, num + 1, x);

        return t[n][num] = (take + skip) % M;
    }

    public int numberOfWays(int n, int x) {
        // Fill memoization array with -1
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                t[i][j] = -1;
            }
        }
        return solve(n, 1, x);
    }
}



//Approach-2 (Bottom Up)
//Will come in 2nd half today - Little occupied today
