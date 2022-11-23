/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=dGZjzA9zLW8
    Company Tags  		: Google, Amazon, Microsoft, Uber, Apple, Snapchat
    Frequency     		: 80%
    Leetcode Link 		: https://leetcode.com/problems/valid-sudoku/
    Diagram Link with my explanation on DISCUSS : https://leetcode.com/problems/valid-sudoku/discuss/1416689/C%2B%2B-(3-approaches-with-diagrams)
*/

//Approach-1 (Naive and simplest using 3 iterations of the sudoku)
class Solution {
public:
    bool validSub(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
        unordered_set<char> st;
        for(int row = sr; row<=er; row++) {
            for(int col = sc; col <= ec; col++) {
                char ch = board[row][col];
                if(ch == '.') continue;
                if(st.count(ch)) return false;
                st.insert(ch);
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        //validate rows
        for(int row = 0; row<9; row++) {
            unordered_set<char> st;
            for(int col = 0; col <9; col++) {
                char ch = board[row][col];
                if(ch == '.') continue;
                if(st.count(ch)) return false;
                st.insert(ch);
            }
        }
        
        //validate columns
        for(int col = 0; col<9; col++) {
            unordered_set<char> st;
            for(int row = 0; row <9; row++) {
                char ch = board[row][col];
                if(ch == '.') continue;
                if(st.count(ch)) return false;
                st.insert(ch);
            }
        }
        
		//validate ech 3*3 box
        for(int sr = 0; sr < 9; sr+=3) {
            int er = sr+2;
            for(int sc = 0; sc < 9; sc+=3) {
                int ec = sc+2;
                if(!validSub(board, sr, er, sc, ec))
                    return false;
            }
        }
        
        return true;
    }
};

//Approach-2 (One iteration using hashmap and indexing boxes)
//see the diagrma (in the link above) to understand the indexing of the boxes
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> st;
        
        for(int i = 0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                if(board[i][j] == '.') continue;
                
                string row = string(1, board[i][j]) + "_row_" + to_string(i);
                string col = string(1, board[i][j]) + "_col_" + to_string(j);
                string box = string(1, board[i][j]) + "_box_" + to_string(i/3) + "_" + to_string(j/3);
                if(st.count(row) || st.count(col) || st.count(box)) return false;
                st.insert(row);
                st.insert(col);
                st.insert(box);
            }
        }
        
        return true;
    }
};

//Approach-3 (Assigning a number to each box)
//see the diagrma (in the link above) to understand how I have numbered the boxes
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {0};
        bool col[9][9] = {0};
        bool box[9][9] = {0};
        for(int i = 0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                if(board[i][j] == '.') continue;
                
                int digit     = board[i][j] - '0' - 1; //(-1 to avoid overflow in index)
                
                //we have numbered 9 boxes of (3*3) as 0, 1, 2, 3, 4 ... 9 (see the diagram below)
                int boxIndex  = (i/3)*3 + (j/3);
                
                if(row[i][digit] || col[j][digit] || box[boxIndex][digit]) return false;
                row[i][digit]        = true;
                col[j][digit]        = true;
                box[boxIndex][digit] = true;
                
            }
        }
        
        return true;
    }
};
