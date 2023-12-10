/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ThwBsSxiPvk
    Company Tags                : Amazon, MakeMyTrip, Wipro, InfoEdge
    Leetcode Qn Link            : https://leetcode.com/problems/transpose-matrix/
    
    Note: This can be done in-place also but only for square matrix.
*/

/******************************************************************* C++ *******************************************************************/
//T.C : O(m*n)
//S.C : O(1) - Ignoring the space taken for result
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> result(n, vector<int>(m));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                result[j][i] = A[i][j];
            }
        }
        return result;
    }
};



/******************************************************************* JAVA *******************************************************************/
//T.C : O(m*n)
//S.C : O(1) - Ignoring the space taken for result
class Solution {
    public int[][] transpose(int[][] A) {
        int m = A.length;
        int n = A[0].length;
        int[][] result = new int[n][m];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[j][i] = A[i][j];
            }
        }
        
        return result;
    }
}
