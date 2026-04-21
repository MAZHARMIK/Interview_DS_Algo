/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=-IksRuiJXW0
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/description/
*/


/************************************************** C++ **************************************************/
//Approach - Iterate and check all k*k matrices
//T.C : O(O((m−k)×(n−k)×k^2×logk)
//S.C : O(k^2)
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> result(m-k+1, vector<int>(n-k+1, 0));
        
        for (int i = 0; i <= m-k; i++) {
            for (int j = 0; j <= n-k; j++) {
                
                // Set for distinct + sorted
                set<int> vals;
                
                for (int r = i; r <= i + k - 1; r++) {
                    for (int c = j; c <= j + k - 1; c++) {
                        vals.insert(grid[r][c]);
                    }
                }
                
                // If all elements were same, set has only 1 element
                if (vals.size() == 1) {
                    continue;
                }
                
                int minAbsDiff = INT_MAX;
                auto prev = vals.begin();
                auto curr = next(prev);
                
                while (curr != vals.end()) {
                    minAbsDiff = min(minAbsDiff, *curr - *prev);
                    prev = curr;
                    curr++;
                }
                
                result[i][j] = minAbsDiff;
            }
        }
        
        return result;
    }
};




/************************************************** JAVA **************************************************/
//Approach - Iterate and check all k*k matrices
//T.C : O(O((m−k)×(n−k)×k^2×logk)
//S.C : O(k^2)
class Solution {
    public int[][] minAbsDiff(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;

        int[][] result = new int[m - k + 1][n - k + 1];

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                // TreeSet for sorted + distinct elements
                TreeSet<Integer> vals = new TreeSet<>();

                for (int r = i; r <= i + k - 1; r++) {
                    for (int c = j; c <= j + k - 1; c++) {
                        vals.add(grid[r][c]);
                    }
                }

                // If all elements are same
                if (vals.size() == 1) {
                    continue;
                }

                int minAbsDiff = Integer.MAX_VALUE;

                Integer prev = null;
                for (int val : vals) {
                    if (prev != null) {
                        minAbsDiff = Math.min(minAbsDiff, val - prev);
                    }
                    prev = val;
                }

                result[i][j] = minAbsDiff;
            }
        }

        return result;
    }
}
