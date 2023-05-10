/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=HXdCemhtrNA
    Company Tags                : Paytm, Zoho, Morgan Stanley, Accolite, Amazon, Microsoft, Snapdeal, D-E-Shaw, MakeMyTrip, Oracle, MAQ Software, nearbuy, Nagarro, BrowserStack
    Frequency                   : 64%
    Leetcode Qn Link            : https://leetcode.com/problems/spiral-matrix-ii/
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 0)
            return {};
        int m = n;
        vector<vector<int>> matrix(m, vector<int>(n));
        int top   = 0;
        int down  = m-1;
        int left  = 0;
        int right = n-1;
        
        int id = 0;
        //id
        //0   -> left  to right
        //1   -> top   to down
        //2   -> right to left
        //3   -> down  to top
        int counter = 1;
        while(top <= down && left <= right) {
            //left to right
            if(id == 0) {
                for(int i = left; i<=right; i++) {
                    matrix[top][i] = counter++;
                }
                top++;
            }
            
            //top to down
            if(id == 1) {
                for(int i = top; i<=down; i++) {
                    matrix[i][right] = counter++;
                }
                right--;
            }
            
            //right to left
            if(id == 2) {
                for(int i = right; i>=left; i--) {
                    matrix[down][i] = counter++;
                }
                down--;
            }
            
            //down to top
            if(id == 3) {
                for(int i = down; i>=top; i--) {
                    matrix[i][left] = counter++;
                }
                left++;
            }
            
            id = (id+1)%4;
        }
        return matrix;
    }
};
