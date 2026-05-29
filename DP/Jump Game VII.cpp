/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=LQjehUy3AnM
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/jump-game-vii/
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n * (maxJump - minJump))
//S.C : O(n)
class Solution {
public:
    int n;
    int solve(int idx, string& s, int minJump, int maxJump, vector<int>& t) {
        // reached last index
        if (idx == n - 1) {
            return true;
        }
        if (t[idx] != -1) {
            return t[idx];
        }
        // try every possible jump
        for (int jump = minJump; jump <= maxJump; jump++) {
            int j = idx + jump;
            // out of bounds
            if (j >= n) {
                break;
            }
            // can only jump on '0'
            if (s[j] == '0') {
                if (solve(j, s, minJump, maxJump, t)) {
                    return t[idx] = true;
                }
            }
        }
        return t[idx] = false;
    }

    bool canReach(string s, int minJump, int maxJump) {
        n = s.length();
        vector<int> t(n, -1);
        return solve(0, s, minJump, maxJump, t);
    }
};


//Approach-2 (Bottom Up DP)
//T.C : O(n * (maxJump - minJump))
//S.C : O(n)
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<int> t(n, false);
        // base case
        t[n - 1] = true;
        // fill from back to front
        for (int i = n - 2; i >= 0; i--) {
            // try every possible jump
            for (int jump = minJump; jump <= maxJump; jump++) {
                int j = i + jump;
                // out of bounds
                if (j >= n) {
                    break;
                }
                // can only jump on '0'
                if (s[j] == '0') {
                    // if recursive call was true
                    if (t[j]) {
                        t[i] = true;
                        break;
                    }
                }
            }
        }
        return t[0];
    }
};


//Approach-3 (Sliding Window + Bottom Up)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();

        vector<int> t(n, 0);
        //t[i] > 0 : possible to reach i
        // == 0 : not possible to reach i

        t[0] = 1;
        int count = 0;

        for(int j = 1; j <= n-1; j++) {
            if(j - minJump >= 0) {
                count += t[j - minJump];
            }

            if(j - maxJump - 1 >= 0) {
                count -= t[j - maxJump - 1];
            }

            if(count > 0 && s[j] == '0') {
                t[j] = 1;
            }
        }

        return t[n-1] > 0;
    }
};

/*********************************************************** JAVA **************************************************/

//Approach-1 (Recursion + Memoization)
//T.C : O(n * (maxJump - minJump))
//S.C : O(n)
class Solution {
    int n;
    int[] t;

    int solve(int idx, String s, int minJump, int maxJump) {
        // reached last index
        if (idx == n - 1) {
            return 1;
        }
        if (t[idx] != -1) {
            return t[idx];
        }
        // try every possible jump
        for (int jump = minJump; jump <= maxJump; jump++) {
            int j = idx + jump;
            // out of bounds
            if (j >= n) {
                break;
            }
            // can only jump on '0'
            if (s.charAt(j) == '0') {
                if (solve(j, s, minJump, maxJump) == 1) {
                    return t[idx] = 1;
                }
            }
        }
        return t[idx] = 0;
    }

    public boolean canReach(String s, int minJump, int maxJump) {
        n = s.length();
        t = new int[n];
        Arrays.fill(t, -1);
        return solve(0, s, minJump, maxJump) == 1;
    }
}


//Approach-2 (Bottom Up DP)
//T.C : O(n * (maxJump - minJump))
//S.C : O(n)
class Solution {
    public boolean canReach(String s, int minJump, int maxJump) {
        int n = s.length();
        boolean[] t = new boolean[n];
        // base case
        t[n - 1] = true;
        // fill from back to front
        for (int i = n - 2; i >= 0; i--) {
            // try every possible jump
            for (int jump = minJump; jump <= maxJump; jump++) {
                int j = i + jump;
                // out of bounds
                if (j >= n) {
                    break;
                }
                // can only jump on '0'
                if (s.charAt(j) == '0') {
                    // if dp cell was true
                    if (t[j]) {
                        t[i] = true;
                        break;
                    }
                }
            }
        }
        return t[0];
    }
}



//Approach-3 (Sliding Window + Bottom Up)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public boolean canReach(String s, int minJump, int maxJump) {
        int n = s.length();

        int[] t = new int[n];
        //t[i] > 0 : possible to reach i
        // == 0 : not possible to reach i

        t[0] = 1;
        int count = 0;

        for (int j = 1; j <= n - 1; j++) {
            if (j - minJump >= 0) {
                count += t[j - minJump];
            }

            if (j - maxJump - 1 >= 0) {
                count -= t[j - maxJump - 1];
            }

            if (count > 0 && s.charAt(j) == '0') {
                t[j] = 1;
            }
        }

        return t[n - 1] > 0;
    }
}
