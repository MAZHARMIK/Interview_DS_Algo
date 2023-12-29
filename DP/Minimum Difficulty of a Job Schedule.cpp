/*
    MY YOUTUBE VIDEO ON THIS Qn : Recursion + Memoization - https://www.youtube.com/watch?v=smTnSl6UKi0
                                  Bottom Up - https://www.youtube.com/watch?v=TjyYTng3f5A
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
*/

/***************************************************************** C++ *****************************************************************/
//Approach - 1 (Recursion + Memoization)
//T.C : O(n^2*d)
//S.C : O(301*11) ~= O(1)
class Solution {
public:
    int t[301][11];
    int solve(vector<int>& jobDifficulty, int n, int idx, int d) {
        
        // If you have only 1 day, then you will do all the remaining jobs
        // and select the max difficulty as the answer
        if (d == 1) {
            return *max_element(begin(jobDifficulty) + idx, end(jobDifficulty));
        }
        
        if (t[idx][d] != -1)
            return t[idx][d];
    
        int Max = INT_MIN;
        int result = INT_MAX;
        
        // Try one by one with all possibilities
        /*
            Take 1 job in one day
            Take 2 jobs in one day
            Take 3 jobs in one day
            and so on
            
            Then find the optimal one among all the results
        */
        for (int i = idx; i <= n - d; i++) {
            Max = max(Max, jobDifficulty[i]);
            result = min(result, Max + solve(jobDifficulty, n, i + 1, d - 1));
        }
        
        return t[idx][d] = result;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        
        if (n < d)
            return -1;

        memset(t, -1, sizeof(t));
        
        return solve(jobDifficulty, n, 0, d);
    }
};



//Approach - 2 (Bottom UP)
//T.C : O(n^2 * d)
//S.C : O(n*d)
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();

        if (n < d)
            return -1;

        vector<vector<int>> t(n+1, vector<int>(d+1, -1));
        //t[i][j] = minimum diffculty of doing job from index i to n-1 in j days.

        // Base case: if there is only one day - Do all jobs on that day
        for (int i = 0; i < n; i++) {
            t[i][1] = *max_element(begin(jobDifficulty) + i, end(jobDifficulty));
        }

        // Build the DP table bottom-up
        for (int days = 2; days <= d; days++) {
            for (int i = 0; i <= n - days; i++) {
                int maxDifficulty = INT_MIN;
                int result        = INT_MAX;

                for (int j = i; j <= n - days; j++) {
                    maxDifficulty   = max(maxDifficulty, jobDifficulty[j]);
                    result          = min(result, maxDifficulty + t[j + 1][days - 1]);
                }

                t[i][days] = result;
            }
        }

        return t[0][d];
    }
};

/***************************************************************** JAVA *****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n^2*d)
//S.C : O(301*11) ~= O(1)
public class Solution {
    private int[][] t;

    public int minDifficulty(int[] jobDifficulty, int d) {
        int n = jobDifficulty.length;

        if (n < d)
            return -1;

        t = new int[n][d + 1];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        return solve(jobDifficulty, n, 0, d);
    }

    private int solve(int[] jobDifficulty, int n, int idx, int d) {
        // If you have only 1 day, then you will do all the remaining jobs
        // and select the max difficulty as the answer
        if (d == 1) {
            return Arrays.stream(Arrays.copyOfRange(jobDifficulty, idx, n)).max().orElse(Integer.MIN_VALUE);
        }

        if (t[idx][d] != -1)
            return t[idx][d];

        int maxDifficulty = Integer.MIN_VALUE;
        int result = Integer.MAX_VALUE;

        // Try one by one with all possibilities
        /*
         * Take 1 job in one day Take 2 jobs in one day Take 3 jobs in one day and so
         * on Then find the optimal one among all the results
         */
        for (int i = idx; i <= n - d; i++) {
            maxDifficulty = Math.max(maxDifficulty, jobDifficulty[i]);
            result = Math.min(result, maxDifficulty + solve(jobDifficulty, n, i + 1, d - 1));
        }

        return t[idx][d] = result;
    }
}


//Approach - 2 (Bottom UP)
//T.C : O(n^2 * d)
//S.C : O(n*d)
public class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {
        int n = jobDifficulty.length;

        if (n < d)
            return -1;

        int[][] t = new int[n + 1][d + 1];

        // Base case: if there is only one day - Do all jobs on that day
        for (int i = 0; i < n; i++) {
            t[i][1] = Arrays.stream(Arrays.copyOfRange(jobDifficulty, i, n)).max().orElse(Integer.MIN_VALUE);
        }

        // Build the DP table bottom-up
        for (int days = 2; days <= d; days++) {
            for (int i = 0; i <= n - days; i++) {
                int maxDifficulty = Integer.MIN_VALUE;
                int result = Integer.MAX_VALUE;

                for (int j = i; j <= n - days; j++) {
                    maxDifficulty = Math.max(maxDifficulty, jobDifficulty[j]);
                    result = Math.min(result, maxDifficulty + t[j + 1][days - 1]);
                }

                t[i][days] = result;
            }
        }

        return t[0][d];
    }
}
