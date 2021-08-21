/*
    Company Tags  : Uber, Snapchat, Microsoft, Qualcomm
    Frequency     : 66%
    Leetcode Link : https://leetcode.com/problems/sudoku-solver/
*/

class Solution {
public:
    
    bool isValid(vector<vector<char>>& board, int i, int j, char& ch) {
        //validate current row
        for(int col = 0; col<9; col++) {
            if(board[i][col] == ch) return false;
        }
        
        //validate current column
        for(int row = 0; row<9; row++) {
            if(board[row][j] == ch) return false;
        }
        
        //validate current box
        /*
            If you want to get the start index ([start_i][start_j] i.e. top left) of a box
            given i and j
            start_i = i/3 * 3;
            start_j = j/3 * 3;
            
            Now, you can check current box
        */
        
        int start_i = i/3 * 3;
        int start_j = j/3 * 3;
        for(int k = 0; k<3; k++) {
            for(int l = 0; l<3; l++) {
                if(board[start_i + k][start_j + l] == ch) return false;
            }
        }
        
        
        return true;
    }
    
    bool backtrack(vector<vector<char>>& board, int i, int j) {
        //all rows checked
        if(i == 9)
            return true;
        
        //current row over, go to next row starting from 0th column
        if(j == 9)
            return backtrack(board, i+1, 0);
        
        //if it's filled go for next column
        if(board[i][j] != '.')
            return backtrack(board, i, j+1);
        
        //else try putting '1' to '9' and see if you find the result in any
        for(char ch = '1'; ch<='9'; ch++) {
            if(isValid(board, i, j, ch)) {
                board[i][j] = ch;
                if(backtrack(board, i, j+1)) {
                    return true;
                }
                board[i][j] = '.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
};
