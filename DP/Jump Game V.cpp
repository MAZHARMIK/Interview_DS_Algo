/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=y0akfzqlxc8
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/jump-game-v/
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n*d)
//S.C : O(n)
class Solution {
public:
    int n;
    vector<int> t;

    int solve(vector<int>& arr, int d, int i) {
        if (t[i] != -1)
            return t[i];

        int result = 1; // count current index also

        // move left
        for (int j = i - 1; j >= max(0, i - d); j--) {
            // can't jump further once taller/equal element appears
            if (arr[j] >= arr[i])
                break;
            result = max(result, 1 + solve(arr, d, j));
        }

        // move right
        for (int j = i + 1; j <= min(n - 1, i + d); j++) {
            // can't jump further once taller/equal element appears
            if (arr[j] >= arr[i])
                break;
            result = max(result, 1 + solve(arr, d, j));
        }

        return t[i] = result;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        t.resize(n, -1);

        int maxJump = 1;
        // We need to try from every index
        for (int i = 0; i < n; i++) {
            maxJump = max(maxJump, solve(arr, d, i));
        }

        return maxJump;
    }
};


//Approach-2 (Bottom-Up DP using Sorting)
//T.C : O(n*d)
//S.C : O(n)
class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        // t[i] = maximum jumps starting from index i
        vector<int> t(n, 1);

        /*
            In recursion + memoization:
            solve(i) depends on smaller elements only.
            So in bottom-up, process smaller values first.
        */
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({arr[i], i});
        }
        sort(begin(vec), end(vec));

        for (auto& it : vec) {
            int val = it.first;
            int i   = it.second;

            // move left
            for (int j = i - 1; j >= max(0, i - d); j--) {
                // same breaking condition
                if (arr[j] >= arr[i])
                    break;
                t[i] = max(t[i], 1 + t[j]);
            }

            // move right
            for (int j = i + 1; j <= min(n - 1, i + d); j++) {
                // same breaking condition
                if (arr[j] >= arr[i])
                    break;
                t[i] = max(t[i], 1 + t[j]);
            }
        }

        return *max_element(begin(t), end(t));
    }
};

/*********************************************************** JAVA **************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n*d)
//S.C : O(n)
class Solution {
    int n;
    int[] t;

    private int solve(int[] arr, int d, int i) {
        if (t[i] != -1)
            return t[i];

        int result = 1; // count current index also

        // move left
        for (int j = i - 1; j >= Math.max(0, i - d); j--) {
            // can't jump further once taller/equal element appears
            if (arr[j] >= arr[i])
                break;
            result = Math.max(result, 1 + solve(arr, d, j));
        }

        // move right
        for (int j = i + 1; j <= Math.min(n - 1, i + d); j++) {
            // can't jump further once taller/equal element appears
            if (arr[j] >= arr[i])
                break;
            result = Math.max(result, 1 + solve(arr, d, j));
        }

        return t[i] = result;
    }

    public int maxJumps(int[] arr, int d) {
        n = arr.length;
        t = new int[n];
        Arrays.fill(t, -1);

        int maxJump = 1;
        // We need to try from every index
        for (int i = 0; i < n; i++) {
            maxJump = Math.max(maxJump, solve(arr, d, i));
        }

        return maxJump;
    }
}


//Approach-2 (Bottom-Up DP using Sorting)
//T.C : O(n*d)
//S.C : O(n)
class Solution {
    public int maxJumps(int[] arr, int d) {
        int n = arr.length;
        // t[i] = maximum jumps starting from index i
        int[] t = new int[n];
        Arrays.fill(t, 1);

        /*
            In recursion + memoization:
            solve(i) depends on smaller elements only.
            So in bottom-up, process smaller values first.
        */
        int[][] vec = new int[n][2];
        for (int i = 0; i < n; i++) {
            vec[i][0] = arr[i];
            vec[i][1] = i;
        }
        Arrays.sort(vec, (a, b) -> a[0] - b[0]);

        for (int[] it : vec) {
            int i = it[1];

            // move left
            for (int j = i - 1; j >= Math.max(0, i - d); j--) {
                // same breaking condition
                if (arr[j] >= arr[i])
                    break;
                t[i] = Math.max(t[i], 1 + t[j]);
            }

            // move right
            for (int j = i + 1; j <= Math.min(n - 1, i + d); j++) {
                // same breaking condition
                if (arr[j] >= arr[i])
                    break;
                t[i] = Math.max(t[i], 1 + t[j]);
            }
        }

        return Arrays.stream(t).max().getAsInt();
    }
}
