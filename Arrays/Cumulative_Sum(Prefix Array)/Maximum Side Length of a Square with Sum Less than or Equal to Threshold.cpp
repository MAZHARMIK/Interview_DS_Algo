/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn    : 
    Company Tags                   : DE Shaw
    Leetcode Link                  : https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Using 2D Prefix Sum and finding best side square)
//T.C : O(rows * cols * min(rows, cols))
//S.C : O(rows * cols)
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();
        int cols = mat[0].size();

        // Build prefix sum
        vector<vector<int>> prefix(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i][j] = mat[i][j]
                             + (i > 0 ? prefix[i - 1][j] : 0)
                             + (j > 0 ? prefix[i][j - 1] : 0)
                             - (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
            }
        }

        // Sum of square (r1,c1) -> (r2,c2)
        auto sumSquare = [&](int r1, int c1, int r2, int c2) {
            int sum = prefix[r2][c2];
            if (r1 > 0) sum -= prefix[r1 - 1][c2];
            if (c1 > 0) sum -= prefix[r2][c1 - 1];
            if (r1 > 0 && c1 > 0) sum += prefix[r1 - 1][c1 - 1];
            return sum;
        };

        // Check function
        auto check = [&](int side) {
            if (side == 0) return true;

            for (int i = 0; i + side - 1 < rows; i++) {
                for (int j = 0; j + side - 1 < cols; j++) {
                    if (sumSquare(i, j,
                                  i + side - 1,
                                  j + side - 1) <= threshold) {
                        return true;
                    }
                }
            }
            return false;
        };

        // Binary search on side length
        int lo = 0, hi = min(rows, cols);
        int ans = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};



//Approach-2 (Using 2D Prefix Sum and binarysearch the square side)
//T.C : O(rows * cols * log(min(rows, cols)))
//S.C : O(rows * cols)
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();
        int cols = mat[0].size();

        // Build prefix sum
        vector<vector<int>> prefix(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i][j] = mat[i][j]
                             + (i > 0 ? prefix[i - 1][j] : 0)
                             + (j > 0 ? prefix[i][j - 1] : 0)
                             - (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
            }
        }

        // Sum of square (r1,c1) -> (r2,c2)
        auto sumSquare = [&](int r1, int c1, int r2, int c2) {
            int sum = prefix[r2][c2];
            if (r1 > 0) sum -= prefix[r1 - 1][c2];
            if (c1 > 0) sum -= prefix[r2][c1 - 1];
            if (r1 > 0 && c1 > 0) sum += prefix[r1 - 1][c1 - 1];
            return sum;
        };

        // Check function
        auto check = [&](int side) {
            if (side == 0) return true;

            for (int i = 0; i + side - 1 < rows; i++) {
                for (int j = 0; j + side - 1 < cols; j++) {
                    if (sumSquare(i, j,
                                  i + side - 1,
                                  j + side - 1) <= threshold) {
                        return true;
                    }
                }
            }
            return false;
        };

        // Binary search on side length
        int lo = 0, hi = min(rows, cols);
        int result = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid)) {
                result = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return result;
    }
};




/************************************************************ JAVA *****************************************************/
//Approach-1 (Using 2D Prefix Sum and finding best side square)
//T.C : O(rows * cols * min(rows, cols))
//S.C : O(rows * cols)
class Solution {
    public int maxSideLength(int[][] mat, int threshold) {
        int rows = mat.length;
        int cols = mat[0].length;

        int[][] prefix = new int[rows][cols];

        // Build prefix sum
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i][j] = mat[i][j]
                        + (i > 0 ? prefix[i - 1][j] : 0)
                        + (j > 0 ? prefix[i][j - 1] : 0)
                        - (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
            }
        }

        int best = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = best; k < Math.min(rows - i, cols - j); k++) {
                    int r2 = i + k;
                    int c2 = j + k;

                    int sum = prefix[r2][c2];
                    if (i > 0) sum -= prefix[i - 1][c2];
                    if (j > 0) sum -= prefix[r2][j - 1];
                    if (i > 0 && j > 0) sum += prefix[i - 1][j - 1];

                    if (sum <= threshold) {
                        best = k + 1;
                    } else {
                        break;
                    }
                }
            }
        }

        return best;
    }
}


//Approach-2 (Using 2D Prefix Sum and binarysearch the square side)
//T.C : O(rows * cols * log(min(rows, cols)))
//S.C : O(rows * cols)
class Solution {
    private boolean check(int side, int rows, int cols,
                           int threshold, int[][] prefix) {
        if (side == 0)
            return true;

        for (int i = 0; i + side - 1 < rows; i++) {
            for (int j = 0; j + side - 1 < cols; j++) {

                int r2 = i + side - 1;
                int c2 = j + side - 1;

                int sum = prefix[r2][c2];
                if (i > 0) sum -= prefix[i - 1][c2];
                if (j > 0) sum -= prefix[r2][j - 1];
                if (i > 0 && j > 0) sum += prefix[i - 1][j - 1];

                if (sum <= threshold) {
                    return true;
                }
            }
        }
        return false;
    }

    public int maxSideLength(int[][] mat, int threshold) {
        int rows = mat.length;
        int cols = mat[0].length;

        // Prefix sum without padding
        int[][] prefix = new int[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i][j] =
                        mat[i][j]
                        + (i > 0 ? prefix[i - 1][j] : 0)
                        + (j > 0 ? prefix[i][j - 1] : 0)
                        - (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
            }
        }

        int lo = 0, hi = Math.min(rows, cols);
        int result = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid, rows, cols, threshold, prefix)) {
                result = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return result;
    }
}
