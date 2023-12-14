/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=evSUv26z4Wk
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/special-positions-in-a-binary-matrix/
*/


/******************************************** C++ ********************************************/
//Approach-1 (Brute Force)
//T.C : O((m*n) (m+n))
//S.C : O(1)
class Solution {
public:

    int numSpecial(vector<vector<int>>& mat) {
        int result = 0;
        int m = mat.size();
        int n = mat[0].size();
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 0) {
                    continue;
                }
                
                bool good = true;
                //Check Row
                for (int r = 0; r < m; r++) {
                    if (r != row && mat[r][col] == 1) {
                        good = false;
                        break;
                    }
                }
                
                //Check Col
                for (int c = 0; c < n; c++) {
                    if (c != col && mat[row][c] == 1) {
                        good = false;
                        break;
                    }
                }
                
                if (good) {
                    result++;
                }
            }
        }
        
        return result;
    }
};


//Approach-2(Storing count of 1s in rows and cols)
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 1) {
                    rowCount[row]++;
                    colCount[col]++;
                }
            }
        }
        
        int result = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 1) {
                    if (rowCount[row] == 1 && colCount[col] == 1) {
                        result++;
                    }
                }
            }
        }
        
        return result;
    }
};



/******************************************** JAVA ********************************************/
//Approach-1 (Brute Force)
//T.C : O((m*n) (m+n))
//S.C : O(1)
class Solution {
    public int numSpecial(int[][] mat) {
        int result = 0;
        int m = mat.length;
        int n = mat[0].length;
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 0) {
                    continue;
                }
                
                boolean good = true;
                for (int r = 0; r < m; r++) {
                    if (r != row && mat[r][col] == 1) {
                        good = false;
                        break;
                    }
                }
                
                for (int c = 0; c < n; c++) {
                    if (c != col && mat[row][c] == 1) {
                        good = false;
                        break;
                    }
                }
                
                if (good) {
                    result++;
                }
            }
        }
        
        return result;
    }
}


//Approach-2(Storing count of 1s in rows and cols)
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
    public int numSpecial(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int[] rowCount = new int[m];
        int[] colCount = new int[n];
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 1) {
                    rowCount[row]++;
                    colCount[col]++;
                }
            }
        }
        
        int result = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 1) {
                    if (rowCount[row] == 1 && colCount[col] == 1) {
                        result++;
                    }
                }
            }
        }
        
        return result;
    }
}
