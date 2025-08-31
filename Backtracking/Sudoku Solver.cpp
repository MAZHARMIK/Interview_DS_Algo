/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO LINK : 
    Company Tags          : Uber, Snapchat, Microsoft, Qualcomm
    Frequency             : 66%
    Leetcode Link         : https://leetcode.com/problems/sudoku-solver/
*/


/************************************************************ C++ ************************************************/
//Approach (Khandani Backtracking template and all possible options)
//T.C : O(1), fixed frid size
//S.C : O(1), fixed grid size
class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col, char d) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == d)
                return false;
            
            if(board[row][i] == d) {
                return false;
            }
        }

        int start_i = row/3 * 3;
        int start_j = col/3 * 3;

        for(int k = 0; k < 3; k++) {
            for(int l = 0; l < 3; l++) {
                if(board[start_i+k][start_j+l] == d) {
                    return false;
                }
            }
        }

        return true;
    }

    //2^9
    //O(9 ^ 81)
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) { //O(9)
            for(int j = 0; j < 9; j++) { //O(9)
                if(board[i][j] == '.') {

                    for(char d = '1'; d <= '9'; d++) { 

                        if(isValid(board, i, j, d)) {
                            board[i][j] = d;

                            if(solve(board) == true) {
                                return true;
                            }

                            board[i][j] = '.';
                        }

                    }

                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};



/************************************************************ JAVA ************************************************/
//Approach (Khandani Backtracking template and all possible options)
//T.C : O(1), fixed frid size
//S.C : O(1), fixed grid size
class Solution {
    
    public void solveSudoku(char[][] board) {
        solve(board);
    }

    private boolean solve(char[][] board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char d = '1'; d <= '9'; d++) {
                        if (isValid(board, i, j, d)) {
                            board[i][j] = d;

                            if (solve(board)) {
                                return true;
                            }

                            board[i][j] = '.'; // backtrack
                        }
                    }
                    return false; // no valid number found
                }
            }
        }
        return true; // sudoku solved
    }

    private boolean isValid(char[][] board, int row, int col, char d) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == d) return false; // check column
            if (board[row][i] == d) return false; // check row
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                if (board[startRow + k][startCol + l] == d) {
                    return false; // check 3x3 box
                }
            }
        }

        return true;
    }
}
