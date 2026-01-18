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

        vector<vector<int>> prefix(rows, vector<int>(cols, 0));

        // Build prefix sum
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i][j] = mat[i][j]
                             + (i > 0 ? prefix[i - 1][j] : 0)
                             + (j > 0 ? prefix[i][j - 1] : 0)
                             - (i > 0 && j > 0 ? prefix[i - 1][j - 1] : 0);
            }
        }

        // Helper lambda to get sum of square
        auto sumSquare = [&](int i, int j, int r2, int c2) {
            int sum = prefix[r2][c2];
                    if (i > 0) sum -= prefix[i - 1][c2];
                    if (j > 0) sum -= prefix[r2][j - 1];
                    if (i > 0 && j > 0) sum += prefix[i - 1][j - 1];
            
            return sum;
        };

        int best = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = best; k < min(rows - i, cols - j); k++) {
                    int r2 = i + k;
                    int c2 = j + k;

                    int sum = sumSquare(i, j, r2, c2);

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
};



//Approach-2 (Using 2D Prefix Sum and binarysearch the square side)
//T.C : O(rows * cols * log(min(rows, cols)))
//S.C : O(rows * cols)
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<vector<int>> prefix(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i + 1][j + 1] =
                    mat[i][j]
                    + prefix[i + 1][j]
                    + prefix[i][j + 1]
                    - prefix[i][j];
            }
        }

        // Lambda to compute square sum
        auto sumSquare = [&](int r1, int c1, int r2, int c2) {
            return prefix[r2 + 1][c2 + 1]
                 - prefix[r2 + 1][c1]
                 - prefix[r1][c2 + 1]
                 + prefix[r1][c1];
        };

        auto check = [&](int side) {
            for (int i = 0; i + side <= rows; i++) {
                for (int j = 0; j + side <= cols; j++) {
                    if (sumSquare(i, j, i + side - 1, j + side - 1) <= threshold) {
                        return true;
                    }
                }
            }
            return false;
        };

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
    public int maxSideLength(int[][] mat, int threshold) {
        int rows = mat.length;
        int cols = mat[0].length;

        // Prefix sum with +1 padding
        int[][] prefix = new int[rows + 1][cols + 1];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prefix[i + 1][j + 1] =
                        mat[i][j]
                        + prefix[i + 1][j]
                        + prefix[i][j + 1]
                        - prefix[i][j];
            }
        }

        int lo = 0, hi = Math.min(rows, cols);
        int result = 0;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (exists(mid, rows, cols, threshold, prefix)) {
                result = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return result;
    }

    private boolean exists(int side, int rows, int cols,
                           int threshold, int[][] prefix) {
        for (int i = 0; i + side <= rows; i++) {
            for (int j = 0; j + side <= cols; j++) {
                int sum =
                        prefix[i + side][j + side]
                        - prefix[i + side][j]
                        - prefix[i][j + side]
                        + prefix[i][j];

                if (sum <= threshold) {
                    return true;
                }
            }
        }
        return false;
    }
}
