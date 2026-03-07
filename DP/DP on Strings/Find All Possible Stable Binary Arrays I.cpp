/*     Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS QN : https://www.youtube.com/watch?v=siYxju3TZdY
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/description/
*/


/****************************************************************** C++ **********************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(one * zero * limit)
//S.C : O(one * zero)
class Solution {
public:
    int M = 1e9 + 7;
    int t[201][201][2];

    int solve(int onesLeft, int zerosLeft, bool lastWasOne, int limit) {
        if(onesLeft == 0 && zerosLeft == 0) {
            return 1;
        }

        if(t[onesLeft][zerosLeft][lastWasOne] != -1) {
            return t[onesLeft][zerosLeft][lastWasOne];
        }


        int result = 0;

        if(lastWasOne == true) { //explore 0s
            for(int len = 1; len <= min(zerosLeft, limit); len++) {
                result = (result + solve(onesLeft, zerosLeft - len, false, limit)) % M;
            }
        } else { //explore 1s
            for(int len = 1; len <= min(onesLeft, limit); len++) {
                result = (result + solve(onesLeft - len, zerosLeft, true, limit)) % M;
            }
        }

        return t[onesLeft][zerosLeft][lastWasOne] = result;

    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, -1, sizeof(t));
        int startWithOne = solve(one, zero, false, limit);
        int startWithZero = solve(one, zero, true, limit);

        return (startWithOne + startWithZero) % M;

    }
};


//Approach-2 (Bottom Up)
//T.C : O(one * zero * limit)
//S.C : O(one * zero)
class Solution {
public:
    int M = 1e9 + 7;
    int t[201][201][2];

    int numberOfStableArrays(int zero, int one, int limit) {

        memset(t, 0, sizeof(t));

        // Base case: solve(0,0,lastWasOne) = 1
        t[0][0][0] = 1;
        t[0][0][1] = 1;


        for(int onesLeft = 0; onesLeft <= one; onesLeft++) {
            for(int zerosLeft = 0; zerosLeft <= zero; zerosLeft++) {

                if(onesLeft == 0 && zerosLeft == 0) continue;

                int result = 0;

                // if(lastWasOne == true) { explore 0s }
                result = 0;
                for(int len = 1; len <= min(zerosLeft, limit); len++) {
                    result = (result + t[onesLeft][zerosLeft - len][0]) % M;
                }
                t[onesLeft][zerosLeft][1] = result;

                // else { explore 1s }
                result = 0;
                for(int len = 1; len <= min(onesLeft, limit); len++) {
                    result = (result + t[onesLeft - len][zerosLeft][1]) % M;
                }
                t[onesLeft][zerosLeft][0] = result;
            }
        }

        int startWithOne  = t[one][zero][false]; //solve(one, zero, false, limit);
        int startWithZero = t[one][zero][true]; //solve(one, zero, true, limit);

        return (startWithOne + startWithZero) % M;
    }
};




/****************************************************************** JAVA **********************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(one * zero * limit)
//S.C : O(one * zero)
class Solution {
    int M = 1_000_000_007;
    int[][][] t = new int[201][201][2];

    int solve(int onesLeft, int zerosLeft, int lastWasOne, int limit) {
        if (onesLeft == 0 && zerosLeft == 0) return 1;
        if (t[onesLeft][zerosLeft][lastWasOne] != -1)
            return t[onesLeft][zerosLeft][lastWasOne];

        int result = 0;
        if (lastWasOne == 1) { // explore 0s
            for (int len = 1; len <= Math.min(zerosLeft, limit); len++) {
                result = (result + solve(onesLeft, zerosLeft - len, 0, limit)) % M;
            }
        } else { // explore 1s
            for (int len = 1; len <= Math.min(onesLeft, limit); len++) {
                result = (result + solve(onesLeft - len, zerosLeft, 1, limit)) % M;
            }
        }
        return t[onesLeft][zerosLeft][lastWasOne] = result;
    }

    public int numberOfStableArrays(int zero, int one, int limit) {
        for (int[][] a : t) for (int[] b : a) Arrays.fill(b, -1);
        int startWithOne  = solve(one, zero, 0, limit);
        int startWithZero = solve(one, zero, 1, limit);
        return (startWithOne + startWithZero) % M;
    }
}

//Approach-2 (Bottom Up)
//T.C : O(one * zero * limit)
//S.C : O(one * zero)
class Solution {
    public int numberOfStableArrays(int zero, int one, int limit) {
        int M = 1_000_000_007;
        int[][][] t = new int[one + 1][zero + 1][2];

        // Base case: solve(0,0,lastWasOne) = 1
        t[0][0][0] = 1;
        t[0][0][1] = 1;

        for (int onesLeft = 0; onesLeft <= one; onesLeft++) {
            for (int zerosLeft = 0; zerosLeft <= zero; zerosLeft++) {
                if (onesLeft == 0 && zerosLeft == 0) continue;

                // if(lastWasOne == true) { explore 0s }
                int result = 0;
                for (int len = 1; len <= Math.min(zerosLeft, limit); len++) {
                    result = (result + t[onesLeft][zerosLeft - len][0]) % M;
                }
                t[onesLeft][zerosLeft][1] = result;

                // else { explore 1s }
                result = 0;
                for (int len = 1; len <= Math.min(onesLeft, limit); len++) {
                    result = (result + t[onesLeft - len][zerosLeft][1]) % M;
                }
                t[onesLeft][zerosLeft][0] = result;
            }
        }

        int startWithOne  = t[one][zero][0]; // solve(one, zero, false, limit)
        int startWithZero = t[one][zero][1]; // solve(one, zero, true, limit)
        return (startWithOne + startWithZero) % M;
    }
}
