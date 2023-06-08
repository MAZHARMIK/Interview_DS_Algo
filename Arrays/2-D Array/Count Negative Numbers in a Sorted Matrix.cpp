/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=z2OLKbbNYQE
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
*/

//Approach-1 (Brute Force) - O(m * n)
//m = rows
//n = columns
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int result = 0;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                
                if(grid[i][j] < 0)
                    result++;
                
            }
        }
        
        return result;
    }
};


//Approach-2 (Using Binary Search - upper_bound) - SLIGHT OPTIMAL - O(m * log(n))
//m = rows
//n = columns
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int result = 0;
        
        for(auto &vec : grid) {
            
            int idx = upper_bound(begin(vec), end(vec), 0, greater<int>()) - begin(vec);
            
            result += n-idx;
            
        }
        
        return result;
    }
};


//Approach-3 (Using the sorted proprrty) - O(m+n) - OPTIMAL
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int row = m-1;
        int col = 0;
        
        int result = 0;
        while( row >= 0 && col < n) {
            
            if(grid[row][col] < 0) {
                result += n-col;
                row--;
            } else {
                col++;
            }
        }
        
        return result;
    }
};
