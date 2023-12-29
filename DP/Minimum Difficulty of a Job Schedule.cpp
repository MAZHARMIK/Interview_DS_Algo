/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=smTnSl6UKi0
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
*/

/***************************************************************** C++ *****************************************************************/
//Approach - 1 (Recursion + Memoization)
//T.C : O(n*d) only this amount of states we will visit
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
//soon coming with a video when I return from New Year Trip

/***************************************************************** C++ *****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n*d) only this amount of states we will visit
//S.C : O(301*11) ~= O(1)
public class Solution {
    private int[][] t;

    public int minDifficulty(int[] jd, int d) {
        int n = jd.length;

        if (n < d)
            return -1;

        t = new int[n][d + 1];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        return solve(jd, n, 0, d);
    }

    private int solve(int[] jd, int n, int idx, int d) {
        // If you have only 1 day, then you will do all the remaining jobs
        // and select the max difficulty as the answer
        if (d == 1) {
            return Arrays.stream(Arrays.copyOfRange(jd, idx, n)).max().orElse(Integer.MIN_VALUE);
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
            maxDifficulty = Math.max(maxDifficulty, jd[i]);
            result = Math.min(result, maxDifficulty + solve(jd, n, i + 1, d - 1));
        }

        return t[idx][d] = result;
    }
}


//Approach - 2 (Bottom UP)
//soon coming with a video when I return from New Year Trip
