/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/number-of-zigzag-arrays-i
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Recursion + Memoization) - TLE
//T.C : O(n*m*m), we have n*m*2 states and we run for loop inside the recursion
//S.C : O(n*m)
class Solution {
public:
    typedef long long ll;
    int MOD = 1e9+7;
    int N, M;

    int t[2001][2001][2];

    int solve(int i, int prevVal, bool increasing) {
        if(i == N) { //able to find N elements of zigzag array
            return 1;
        }

        if(t[i][prevVal][increasing] != -1) {
            return t[i][prevVal][increasing];
        }

        int result = 0;
        if(increasing) {
            for(int nextVal = prevVal+1; nextVal <= M; nextVal++) {
                result = (result + solve(i+1, nextVal, false)) % MOD;
            }
        } else {
            for(int nextVal = 1; nextVal < prevVal; nextVal++) {
                result = (result + solve(i+1, nextVal, true)) % MOD;
            }
        }

        return t[i][prevVal][increasing] = result;
    }

    int zigZagArrays(int n, int l, int r) {
        N = n;
        M = r-l+1;
        memset(t, -1, sizeof(t));

        ll result = 0;

        for(int startVal = 1; startVal <= M; startVal++) {
            //a < b > c < d ...
            result = (result + solve(1, startVal, true)) % MOD;

            //a > b < c > d...
            result = (result + solve(1, startVal, false)) % MOD;
        }

        return result;
    }
};



//Approach-2 (Bottom Up) - TLE
//T.C : O(n*m*m), we have n*m*2 states and we run for loop inside the recursion
//S.C : O(n*m)
class Solution {
public:
    int MOD = 1e9+7;
    typedef long long ll;

    int zigZagArrays(int n, int l, int r) {
        int N = n;
        int M = r-l+1;

        ll t[2001][2001][2];
        memset(t, 0, sizeof(t));

        //Base Case
        for(int prevVal = 1; prevVal <= M; prevVal++) {
            t[N][prevVal][0] = 1;
            t[N][prevVal][1] = 1;
        }

        for(int i = N-1; i >= 1; i--) {

            for(int prevVal = 1; prevVal <= M; prevVal++) {

                for(int nextVal = prevVal+1; nextVal <= M; nextVal++) {
                    t[i][prevVal][1] = (t[i][prevVal][1] + t[i+1][nextVal][0]) % MOD;
                }

                for(int nextVal = 1; nextVal < prevVal; nextVal++) {
                    t[i][prevVal][0] = (t[i][prevVal][0] + t[i+1][nextVal][1]) % MOD;
                }

            }
        }

        ll result = 0;

        for(int startVal = 1; startVal <= M; startVal++) {
            //a < b > c < d ...
            result = (result + t[1][startVal][1]) % MOD;

            //a > b < c > d...
            result = (result + t[1][startVal][0]) % MOD;
        }

        return result;
        
    }
};



//Approach-3 (Bottom Up + Prefix Sum) - TLE
//T.C : O(n*m)
//S.C : O(n*m)
class Solution {
public:
    int MOD = 1e9+7;
    typedef long long ll;

    int zigZagArrays(int n, int l, int r) {
        int N = n;
        int M = r-l+1;

        ll t[2001][2001][2];

        //Base Case
        for(int prevVal = 1; prevVal <= M; prevVal++) {
            t[N][prevVal][0] = 1;
            t[N][prevVal][1] = 1;
        }

        for(int i = N-1; i >= 1; i--) {

            vector<ll> prefDir0(M+1, 0);
            vector<ll> prefDir1(M+1, 0);

            for(int prevVal = 1; prevVal <= M; prevVal++) {
                
                prefDir0[prevVal] = (prefDir0[prevVal-1] + t[i+1][prevVal][0]) % MOD;

                prefDir1[prevVal] = (prefDir1[prevVal-1] + t[i+1][prevVal][1]) % MOD;

            }

            for(int prevVal = 1; prevVal <= M; prevVal++) {
                
                t[i][prevVal][1] = (prefDir0[M] - prefDir0[prevVal] + MOD) % MOD;

                t[i][prevVal][0] = prefDir1[prevVal-1];

            }
        }

        ll result = 0;

        for(int startVal = 1; startVal <= M; startVal++) {
            //a < b > c < d ...
            result = (result + t[1][startVal][1]) % MOD;

            //a > b < c > d...
            result = (result + t[1][startVal][0]) % MOD;
        }

        return result;
        
    }
};



/*********************************************************** JAVA **************************************************/
//Approach-1 (Recursion + Memoization) - TLE
//T.C : O(n*m*m), we have n*m*2 states and we run for loop inside the recursion
//S.C : O(n*m)
class Solution {
    int MOD = 1_000_000_007;
    int N, M;
    int[][][] t;

    public int zigZagArrays(int n, int l, int r) {
        N = n;
        M = r - l + 1;
        t = new int[N + 1][M + 1][2];
        for (int[][] a : t)
            for (int[] b : a)
                Arrays.fill(b, -1);

        long result = 0;
        for (int startVal = 1; startVal <= M; startVal++) {
            //a < b > c < d ...
            result = (result + solve(1, startVal, true)) % MOD;
            //a > b < c > d...
            result = (result + solve(1, startVal, false)) % MOD;
        }
        return (int) result;
    }

    private int solve(int i, int prevVal, boolean increasing) {
        if (i == N) { //able to find N elements of zigzag array
            return 1;
        }

        int dir = increasing ? 1 : 0;
        if (t[i][prevVal][dir] != -1) {
            return t[i][prevVal][dir];
        }

        int result = 0;
        if (increasing) {
            for (int nextVal = prevVal + 1; nextVal <= M; nextVal++) {
                result = (result + solve(i + 1, nextVal, false)) % MOD;
            }
        } else {
            for (int nextVal = 1; nextVal < prevVal; nextVal++) {
                result = (result + solve(i + 1, nextVal, true)) % MOD;
            }
        }

        return t[i][prevVal][dir] = result;
    }
}


//Approach-2 (Bottom Up) - TLE
//T.C : O(n*m*m), we have n*m*2 states and we run for loop inside the recursion
//S.C : O(n*m)
class Solution {
    int MOD = 1_000_000_007;

    public int zigZagArrays(int n, int l, int r) {
        int N = n;
        int M = r - l + 1;

        long[][][] t = new long[N + 1][M + 1][2];

        //Base Case
        for (int prevVal = 1; prevVal <= M; prevVal++) {
            t[N][prevVal][0] = 1;
            t[N][prevVal][1] = 1;
        }

        for (int i = N - 1; i >= 1; i--) {
            for (int prevVal = 1; prevVal <= M; prevVal++) {

                for (int nextVal = prevVal + 1; nextVal <= M; nextVal++) {
                    t[i][prevVal][1] = (t[i][prevVal][1] + t[i + 1][nextVal][0]) % MOD;
                }

                for (int nextVal = 1; nextVal < prevVal; nextVal++) {
                    t[i][prevVal][0] = (t[i][prevVal][0] + t[i + 1][nextVal][1]) % MOD;
                }
            }
        }

        long result = 0;
        for (int startVal = 1; startVal <= M; startVal++) {
            //a < b > c < d ...
            result = (result + t[1][startVal][1]) % MOD;
            //a > b < c > d...
            result = (result + t[1][startVal][0]) % MOD;
        }
        return (int) result;
    }
}


//Approach-3 (Bottom Up + Prefix Sum) - TLE
//T.C : O(n*m)
//S.C : O(n*m)
class Solution {
    int MOD = 1_000_000_007;

    public int zigZagArrays(int n, int l, int r) {
        int N = n;
        int M = r - l + 1;

        long[][][] t = new long[N + 1][M + 1][2];

        //Base Case
        for (int prevVal = 1; prevVal <= M; prevVal++) {
            t[N][prevVal][0] = 1;
            t[N][prevVal][1] = 1;
        }

        for (int i = N - 1; i >= 1; i--) {

            long[] prefDir0 = new long[M + 1];
            long[] prefDir1 = new long[M + 1];

            for (int prevVal = 1; prevVal <= M; prevVal++) {
                prefDir0[prevVal] = (prefDir0[prevVal - 1] + t[i + 1][prevVal][0]) % MOD;
                prefDir1[prevVal] = (prefDir1[prevVal - 1] + t[i + 1][prevVal][1]) % MOD;
            }

            for (int prevVal = 1; prevVal <= M; prevVal++) {
                t[i][prevVal][1] = (prefDir0[M] - prefDir0[prevVal] + MOD) % MOD;
                t[i][prevVal][0] = prefDir1[prevVal - 1];
            }
        }

        long result = 0;
        for (int startVal = 1; startVal <= M; startVal++) {
            //a < b > c < d ...
            result = (result + t[1][startVal][1]) % MOD;
            //a > b < c > d...
            result = (result + t[1][startVal][0]) % MOD;
        }
        return (int) result;
    }
}
