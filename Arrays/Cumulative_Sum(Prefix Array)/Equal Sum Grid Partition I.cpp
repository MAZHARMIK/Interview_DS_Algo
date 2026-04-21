/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn    : https://www.youtube.com/watch?v=rO4Bm_GxvGk
    Company Tags                   : Will update later
    Leetcode Link                  : https://leetcode.com/problems/equal-sum-grid-partition-i/description
*/


/************************************************************ C++ *****************************************************/
//Approach (Using prefix sum)
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<ll> rowSum(m, 0);
        vector<ll> colSum(n, 0);

        ll total = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                total += grid[i][j];
                //row = i
                rowSum[i] += grid[i][j];
                //col = j
                colSum[j] += grid[i][j];
            }
        }

        if(total % 2 != 0) {
            return false;
        }

        //Horizontal split
        ll upper = 0;
        for(int i = 0; i < m-1; i++) {
            upper += rowSum[i];
            if(upper == total - upper) {
                return true;
            }
        }

        //Vertical split
        ll left = 0;
        for(int j = 0; j < n-1; j++) {
            left += colSum[j];
            if(left == total - left) {
                return true;
            }
        }

        return false;

    }
};




/************************************************************ JAVA *****************************************************/
//Approach (Using prefix sum)
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
    public boolean canPartitionGrid(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        long[] rowSum = new long[m];
        long[] colSum = new long[n];

        long total = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }

        if (total % 2 != 0) {
            return false;
        }

        // Horizontal split
        long upper = 0;
        for (int i = 0; i < m - 1; i++) {
            upper += rowSum[i];
            if (upper == total - upper) {
                return true;
            }
        }

        // Vertical split
        long left = 0;
        for (int j = 0; j < n - 1; j++) {
            left += colSum[j];
            if (left == total - left) {
                return true;
            }
        }

        return false;
    }
}
