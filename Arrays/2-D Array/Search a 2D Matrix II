/*
    Company Tags  : MentorGraphics, Yahoo
    Leetcode Link : https://leetcode.com/problems/search-a-2d-matrix-ii/
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        
        //Go from top right
        int row = 0;
        int col = n-1;
        
        while(row < m && col >= 0) {
            if(matrix[row][col] > target) {
                //We can reject that column : All the integers in each column are sorted in ascending order.
                col--;
            } else if(matrix[row][col] < target) {
                //We can reject that rwo : All the integers in each row are sorted in ascending order.
                row++;
            } else {
                return true;
            }
        }
        return false;
    }
};
