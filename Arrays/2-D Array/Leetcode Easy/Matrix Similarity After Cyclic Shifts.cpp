/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=RIRi89awC-s
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/matrix-similarity-after-cyclic-shift
*/


/******************************************** C++ ********************************************/
//Approach-1 (Simulation + extra space)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>> temp = mat;
        int m = mat.size();
        int n = mat[0].size();
        k = k%n;
        if(k == 0) { //no shifting
            return true;
        }
      
        for(int i = 0; i<m; i++) {
            if(i%2) { // odd
                rotate(rbegin(mat[i]), rbegin(mat[i]) + k, rend(mat[i]));
            } else {
                rotate(begin(mat[i]), begin(mat[i]) + k, end(mat[i]));
            }
        }

        return temp == mat;
    }
};


//Approach-2 (Without rotation and O(1) space)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k = (k%n);

        if(k == 0) { //no shifting
            return true;
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int currIdx = j;
                int finalIdx;

                if(i % 2 == 0) { //even : left shift
                    finalIdx = (j + k)%n;
                } else {
                    finalIdx = (j - k + n) % n;
                }

                if(mat[i][currIdx] != mat[i][finalIdx]) {
                    return false;
                }

            }
        }

        return true;
    }
};



/******************************************** JAVA ********************************************/
//Approach-1 (Simulation + extra space + your own rotation logic)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    public boolean areSimilar(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;

        k = k % n;
        if (k == 0) return true;

        // Copy matrix
        int[][] temp = new int[m][n];
        for (int i = 0; i < m; i++) {
            temp[i] = mat[i].clone();
        }

        for (int i = 0; i < m; i++) {
            if (i % 2 == 0) {
                // even : left shift
                rotateLeft(mat[i], k); //you can write your own logic as well
            } else {
                // odd : right shift
                rotateRight(mat[i], k); //you can write your own logic as well
            }
        }

        // Compare
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != temp[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }

    private void rotateLeft(int[] row, int k) {
        reverse(row, 0, k - 1);
        reverse(row, k, row.length - 1);
        reverse(row, 0, row.length - 1);
    }

    private void rotateRight(int[] row, int k) {
        int n = row.length;
        rotateLeft(row, n - k);
    }

    private void reverse(int[] row, int l, int r) {
        while (l < r) {
            int temp = row[l];
            row[l] = row[r];
            row[r] = temp;
            l++;
            r--;
        }
    }
}


//Approach-2 (Without rotation and O(1) space)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
    public boolean areSimilar(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;

        k = k % n;
        if (k == 0) return true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int currIdx = j;
                int finalIdx;

                if (i % 2 == 0) {
                    // even : left shift
                    finalIdx = (j + k) % n;
                } else {
                    // odd : right shift
                    finalIdx = (j - k + n) % n;
                }

                if (mat[i][currIdx] != mat[i][finalIdx]) {
                    return false;
                }
            }
        }

        return true;
    }
}
