/*     Scroll below to see JAVA code also   */
/*
    My YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=I48Z8QlQH8c&list=PLpIkg8OmuX-K6A0sEPFxOSJh4_AjCGAFf&index=8
    Company Tags                : Amazon, DE-Shaw, Microsoft, Morgan Stanley, Paytm, Samsung, Snapdeal, Zoho
    Similar GfG Link            : https://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space1004/1
    Leetcode Link               : https://leetcode.com/problems/rotate-image/
*/


/************************************************** C++ **************************************************/
//Approach : Transpose and Reverse
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        
        //find transpose
        for(int i = 0; i<N; i++) {
            for(int j = i; j<N; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        //flip horizontally - For clock wise rotation
        for(int i = 0; i<N; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
        /*
        //flip vertically - For anticlock wise rotation
        for(int col = 0; col<N; col++) {
            int row = 0;
            int mid = n/2;
            while(row < mid) {
                swap(matrix[row][col], matrix[n-row-1][col]);
                row++;
            }
        }
        */
    }
};



/************************************************** JAVA **************************************************/
//Approach : Transpose and Reverse
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public void rotate(int[][] matrix) {
        int N = matrix.length;
        
        //find transpose
        for(int i = 0; i < N; i++) {
            for(int j = i; j < N; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        //flip horizontally - For clock wise rotation
        for(int i = 0; i < N; i++) {
            int left = 0, right = N - 1;
            while(left < right) {
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;
                left++;
                right--;
            }
        }
        
        /*
        //flip vertically - For anticlock wise rotation
        for(int col = 0; col < N; col++) {
            int row = 0;
            int mid = N/2;
            while(row < mid) {
                int temp = matrix[row][col];
                matrix[row][col] = matrix[N-row-1][col];
                matrix[N-row-1][col] = temp;
                row++;
            }
        }
        */
    }
}
