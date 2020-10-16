/*
    Company Tags    : MentorGraphics, Yahoo
    Leetcode Link   : https://leetcode.com/problems/search-a-2d-matrix/
    Time Complexity : O(log(m*n))
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        int l = 0;
        int h = (m*n)-1;
        while(l<=h) {
            int mid = (l+h)/2;
            int row = mid/n; //divide by column
            int col = mid%n; //modulo by column
            
            if(matrix[row][col] == target)
                return true;
            if(matrix[row][col] > target)
                h = mid-1;
            else
                l = mid+1;
        }
        return false;
    }
};
