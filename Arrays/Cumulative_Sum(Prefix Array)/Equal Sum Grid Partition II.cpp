/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn    : https://www.youtube.com/watch?v=Q2kDj7gy9_8
    Company Tags                   : Will update later
    Leetcode Link                  : https://leetcode.com/problems/equal-sum-grid-partition-ii/description/
*/


/************************************************************ C++ *****************************************************/
//Approach (Using prefix sum)
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    typedef long long ll;
    ll total = 0;

    bool checkHorCuts(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_set<ll> st;
        ll top = 0;

        for(int i = 0; i <= m-2; i++) {

            for(int j = 0; j < n; j++) {
                st.insert(grid[i][j]);
                top += grid[i][j];
            }

            ll bottom = (total - top);
            ll diff = top - bottom;

            if (diff == 0) return true;

            if (diff == (ll)grid[0][0])   return true;
            if (diff == (ll)grid[0][n-1]) return true;
            if (diff == (ll)grid[i][0]) return true;

            if(i > 0 && n > 1 && st.count(diff)) {
                return true;
            }
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        //Horizontal cuts
        if(checkHorCuts(grid)) {
            return true;
        }

        reverse(begin(grid), end(grid));

        if(checkHorCuts(grid)) {
            return true;
        }

        reverse(begin(grid), end(grid)); //original grid  m*n

        //Vertical cuts checking but by using checkHorCuts method
        //Transpose of grid and then do checkHorCuts
        vector<vector<int>> transposeGrid(n, vector<int>(m)); //n*m

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                transposeGrid[j][i] = grid[i][j];
            }
        }

        if(checkHorCuts(transposeGrid)) {
            return true;
        }

        reverse(begin(transposeGrid), end(transposeGrid));

        if(checkHorCuts(transposeGrid)) {
            return true;
        }

        return false;

    }
};



/************************************************************ JAVA *****************************************************/
//Approach (Using prefix sum)
//T.C : O(m*n)
//S.C : O(m+n)
import java.util.*;

class Solution {

    long total = 0;

    public boolean checkHorCuts(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        HashSet<Long> set = new HashSet<>();
        long top = 0;

        for (int i = 0; i < m - 1; i++) {

            for (int j = 0; j < n; j++) {
                set.add((long)grid[i][j]);
                top += grid[i][j];
            }

            long bottom = total - top;
            long diff = top - bottom;

            if (diff == 0) return true;

            if (diff == grid[0][0]) return true;
            if (diff == grid[0][n - 1]) return true;
            if (diff == grid[i][0]) return true;

            if (i > 0 && n > 1 && set.contains(diff)) {
                return true;
            }
        }

        return false;
    }

    public boolean canPartitionGrid(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        // compute total
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        // Horizontal
        if (checkHorCuts(grid)) return true;

        reverse(grid);

        if (checkHorCuts(grid)) return true;

        reverse(grid);

        // Transpose
        int[][] transposeGrid = new int[n][m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                transposeGrid[j][i] = grid[i][j];
            }
        }

        if (checkHorCuts(transposeGrid)) return true;

        reverse(transposeGrid);

        return checkHorCuts(transposeGrid);
    }

    // Helper to reverse rows
    private void reverse(int[][] grid) {
        int top = 0, bottom = grid.length - 1;

        while (top < bottom) {
            int[] temp = grid[top];
            grid[top] = grid[bottom];
            grid[bottom] = temp;

            top++;
            bottom--;
        }
    }
}
