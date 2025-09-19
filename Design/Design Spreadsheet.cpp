/*        Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO IN THIS QN : https://www.youtube.com/watch?v=gWZaQtwM388
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/design-spreadsheet
*/


/***************************************************************** C++ *****************************************************************/
//Approach (Simple simulation)
// T.C. : Constructor → O(rows), setCell / resetCell → O(1), getValue → O(L) for substr where L = length of formula
// S.C. : O(1)
class Spreadsheet {
public:
    vector<vector<int>> sheet;

    Spreadsheet(int rows) {
        sheet.assign(rows, vector<int>(26, 0));    
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;

        sheet[row][col] = value;

    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        sheet[row][col] = 0;
    }
    
    int solve(string &s) {
        if(isdigit(s[0])) {
            return stoi(s);
        }

        int col = s[0] - 'A';
        int row = stoi(s.substr(1)) - 1;

        return sheet[row][col];
    }

    int getValue(string formula) {
        //Example : "=X+Y"
        string s = formula.substr(1); //remove =
        int plusIdx = s.find('+');

        string left = s.substr(0, plusIdx);
        string right = s.substr(plusIdx+1);


        return solve(left) + solve(right);
    }
};



/***************************************************************** JAVA *****************************************************************/
//Approach (Simple simulation)
// T.C. : Constructor → O(rows), setCell / resetCell → O(1), getValue → O(L) for substr where L = length of formula
// S.C. : O(1)
import java.util.*;

class Spreadsheet {
    private int[][] sheet;

    public Spreadsheet(int rows) {
        sheet = new int[rows][26]; // rows x 26 (A-Z)
    }

    public void setCell(String cell, int value) {
        int col = cell.charAt(0) - 'A';
        int row = Integer.parseInt(cell.substring(1)) - 1;
        sheet[row][col] = value;
    }

    public void resetCell(String cell) {
        int col = cell.charAt(0) - 'A';
        int row = Integer.parseInt(cell.substring(1)) - 1;
        sheet[row][col] = 0;
    }

    private int solve(String s) {
        if (Character.isDigit(s.charAt(0))) {
            return Integer.parseInt(s);
        }
        int col = s.charAt(0) - 'A';
        int row = Integer.parseInt(s.substring(1)) - 1;
        return sheet[row][col];
    }

    public int getValue(String formula) {
        // Example: "=A1+B2"
        String s = formula.substring(1); // remove '='
        int plusIdx = s.indexOf('+');

        String left = s.substring(0, plusIdx);
        String right = s.substring(plusIdx + 1);

        return solve(left) + solve(right);
    }
}
