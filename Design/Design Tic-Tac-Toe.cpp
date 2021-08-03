/*
    Company Tags  : Facebook, Amazon, Apple, Microsoft, Google(variation)
    Leetcode Link : https://leetcode.com/problems/design-tic-tac-toe/

    It's a premium question, so I am putting the description below :
    Design a Tic-tac-toe game that is played between two players on anxngrid.
    You may assume the following rules:
    (1) A move is guaranteed to be valid and is placed on an empty block.
    (2) Once a winning condition is reached, no more moves is allowed.
    (3) A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.

Example:
Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|

Follow up:
- Could you do better than O(n^2) per move()operation?
Yes : We can take a vector<int> rows(n, 0), vector<int> cols(n, 0)
and two variables diag = 0, antiDiag = 0.
If it's player-1 turn,
we increment rows[row] and cols[col] And if (i == j) diag++, if(i+j == n) antiDiag++;
if it's player-2's turn
we decrement rows[row] and cols[col] And if (i == j) diag--, if(i+j == n) antiDiag--;
One whose count reaches n first wins.
*/

//Approach-1 [Time : O(n^2), Space : O(n^2)]
class TicTacToe {
public:
    vector<vector<int>> board;
    int n;
    TicTacToe(int n) {
        board.resize(n, vector<int>(n));
        this->n = n;
    }

    bool rowColWin(int &row, int& col, int& player) {
        bool wins = true;
        //row check
        for(int j = 0; j<n; j++) {
            if(board[row][j] != player) {
                wins = false;
                break;
            }
        }

        if(wins)
            return wins;

        //col check
        for(int i = 0; i<n; i++) {
            if(board[i][col] != player) {
                wins = false;
                    break;
            }
        }

        return wins;
    }

    bool diagWin(int& player) {
        for(int row = 0; row<n; row++) {
            if(board[row][row] != player)
                return false;
        }
        return true;
    }

    bool antiDiagWin(int& player) {
        for(int row = 0; row<n; row++) {
            if(board[row][n-row-1] != player)
                return false;
        }
        return true;
    }

    int move(int row, int col, int player) {
        if(player == 1) {
            board[row][col] = 1;
            if(rowColWin(row, col, player)) {
                return 1; //player-1 wins
            }

            if(row == col && diagWin(player)) {
                return 1; //player-1 wins
            } else if(row+col == n && antiDiagWin(player)) {
                return 1; //player-1 wins
            }
        } else {
            board[row][col] = 2;
            if(rowColWin(row, col, player)) {
                return 2; //player-2 wins
            }

            if(row == col && diagWin(player)) {
                return 2; //player-2 wins
            } else if(row+col == n-1 && antiDiagWin(player)) {
                return 2; //player-2 wins
            }
        }

        return 0;
    }
};


//Follow-up
//Approach-1 [Time : O(1), Space : O(n)]
class TicTacToe {
public:
    int n;
    vector<int> rows;
    vector<int> cols;
    int diag = 0;
    int antiDiag = 0;
    TicTacToe(int n) {
        this->n = n;
        rows.resize(n, 0);
        cols.resize(n, 0);
        diag = 0;
        antiDiag = 0;
    }

    int move(int row, int col, int player) {
        if(player == 1) {
            rows[row]++;
            cols[col]++;
            if(row == col)
                diag++;

            if(row+col == n-1)
                antiDiag++;

            if(rows[row] == n || cols[col] == n || diag == n || antiDiag == n)
                return 1; //player-1 wins
        } else {
            rows[row]--;
            cols[col]--;
            if(row == col)
                diag--;

            if(row+col == n-1)
                antiDiag--;

            if(rows[row] == -n || cols[col] == -n || diag == -n || antiDiag == -n)
                return 2; //player-2 wins
        }

        return 0;
    }
};
