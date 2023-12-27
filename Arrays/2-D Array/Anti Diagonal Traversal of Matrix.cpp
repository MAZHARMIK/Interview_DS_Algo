/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=05FQV0T6YlI
    Company Tags                : Amazon, Microsoft, Meta (onsite)
    GfG Link                    : https://www.geeksforgeeks.org/problems/print-diagonally1623/1
*/


/****************************************************************** C++ ************************************************************************/
//Approach - Simple traversal
//T.C : O(n^2)
//S.C : O(1) (excluding space taken for result)
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) {
        vector<int> result;
        int n = matrix.size();
    
        // Traverse the top row
        for (int j = 0; j < n; ++j) {
            int row = 0;
            int col = j;
            
            // Traverse the anti-diagonal
            while (row < n && col >= 0) {
                result.push_back(matrix[row][col]);
                ++row;
                --col;
            }
        }
    
        // Traverse the rightmost column (excluding the first element)
        for (int i = 1; i < n; ++i) {
            int row = i;
            int col = n - 1;
    
            // Traverse the anti-diagonal
            while (row < n && col >= 0) {
                result.push_back(matrix[row][col]);
                ++row;
                --col;
            }

        }
    
        return result;
    }
};


/****************************************************************** JAVA ************************************************************************/
//Approach - Simple traversal
//T.C : O(n^2)
//S.C : O(1) (excluding space taken for result)
class Solution
{
    public int[] antiDiagonalPattern(int[][] matrix) {
        int n = matrix.length;
        int[] result = new int[n * n];
        int idx = 0;

        // Traverse the top row
        for (int j = 0; j < n; ++j) {
            int row = 0;
            int col = j;
            
            // Traverse the anti-diagonal
            while (row < n && col >= 0) {
                result[idx++] = matrix[row][col];
                ++row;
                --col;
            }
        }

        // Traverse the rightmost column (excluding the first element)
        for (int i = 1; i < n; ++i) {
            int row = i;
            int col = n - 1;
            
            // Traverse the anti-diagonal
            while (row < n && col >= 0) {
                result[idx++] = matrix[row][col];
                ++row;
                --col;
            }

        }

        return result;

    }
}
