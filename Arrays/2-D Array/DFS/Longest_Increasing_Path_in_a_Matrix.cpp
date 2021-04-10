/*
    Company Tags  : Google, Facebook
    Leetcode Link : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
*/

static const vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Solution {
public:
    int m   = 0;
    int n   = 0;
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& store) {
        
        //do we already have the best path starting from i,j, if yes return that
        if(store[i][j] != 0)
            return store[i][j];
        
        int maxL = 1;
        //lets find the best path moving from i,j to 4-directions and see what we get
        for(vector<int> dir:directions) {
            int _i = i+dir[0];
            int _j = j+dir[1];
            
            if(_i < 0 || _j < 0 || _i >= m || _j >= n || matrix[i][j] >= matrix[_i][_j])
                continue;
            
            //up, down, left, right (compare all results with maxL)
            int len = 1 + solve(_i, _j, matrix, store);
            maxL = max(maxL, len);
        }
        
        //store the best path from i,j at store[i][j]
        return store[i][j] = maxL;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        
        vector<vector<int>> store(m, vector<int>(n, 0));
        //store[i][j] represents longest increasing path starts from point matrix[i][j]
        
        int result = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                //find the best path from (i,j)
                int len = solve(i, j, matrix, store);
                //compare with result
                result = max(result, len);
            }
        }
        
        
        return result;
    }
};
