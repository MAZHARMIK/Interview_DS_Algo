/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=N4KEX5-Pi34
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
*/


/******************************************** C++ ********************************************/
//Approach (Rotate and check till 4 rotations)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int n;

    void rotate(vector<vector<int>>& mat) {
        //Transpose

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }

        //Reverse each row
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();

        for(int c = 1; c <= 4; c++) {
            
            bool equal = true;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(mat[i][j] != target[i][j]) {
                        equal = false;
                        break;
                    }
                }
                if(!equal)
                    break;
            }

            if(equal)
                return true;
                
            rotate(mat);
        }

        return false;
    }
};



/******************************************** JAVA ********************************************/
//Approach (Rotate and check till 4 rotations)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    int n;

    void rotate(int[][] mat) {
        //Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }

        //Reverse each row
        for(int i = 0; i < n; i++) {
            int left = 0, right = n - 1;
            while(left < right) {
                int temp = mat[i][left];
                mat[i][left] = mat[i][right];
                mat[i][right] = temp;
                left++;
                right--;
            }
        }
    }

    public boolean findRotation(int[][] mat, int[][] target) {
        n = mat.length;

        for(int c = 1; c <= 4; c++) {
            
            boolean equal = true;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(mat[i][j] != target[i][j]) {
                        equal = false;
                        break;
                    }
                }
                if(!equal)
                    break;
            }

            if(equal)
                return true;
                
            rotate(mat);
        }

        return false;
    }
}
