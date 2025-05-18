/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/painting-a-grid-with-three-different-colors
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Recursion + Memoization)
//T.C : O(n * S * S * m), where S = total states i.e. 3 * 2^m-1
//S.C : O((n * S) + (S * m)) where n * S is because of memoization array t, and S * m is for storing columnStates
class Solution {
public:
    vector<vector<int>> t;
    vector<string> columnStates;
    const int MOD = 1e9 + 7;

    // Recursively generate all valid column colorings of height 'rows'
    // such that no two vertically adjacent cells have the same color
    void generateColumnStates(string currentColumn, int rowsRemaining, char prevColor) {
        if (rowsRemaining == 0) {
            columnStates.push_back(currentColumn);
            return;
        }

        // Colors: 'R' = Red, 'G' = Green, 'B' = Blue
        for (char color : {'R', 'G', 'B'}) {
            if (color == prevColor) 
                continue;  // adjacent vertical cells must be different

            generateColumnStates(currentColumn + color, rowsRemaining - 1, color);
        }
    }

    int solve(int remainingCols, int prevColumnIdx, int m) {
        if (remainingCols == 0) 
            return 1;
        if (t[remainingCols][prevColumnIdx] != -1) 
            return t[remainingCols][prevColumnIdx];

        int totalWays = 0;
        string prevColumn = columnStates[prevColumnIdx];

        for (int nextColumnIdx = 0; nextColumnIdx < columnStates.size(); nextColumnIdx++) {
            string nextColumn = columnStates[nextColumnIdx];
            bool valid = true;

            // Check horizontal adjacency (no adjacent same color in same row)
            for (int r = 0; r < m; r++) {
                if (prevColumn[r] == nextColumn[r]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                totalWays = (totalWays + solve(remainingCols - 1, nextColumnIdx, m)) % MOD;
            }
        }

        return t[remainingCols][prevColumnIdx] = totalWays;
    }

    int colorTheGrid(int m, int n) {
        columnStates.clear();
        generateColumnStates("", m, '#');  // '#' indicates no previous color

        int numColumnPatterns = columnStates.size();
        t.assign(n, vector<int>(numColumnPatterns, -1));

        int result = 0;
        for (int i = 0; i < numColumnPatterns; i++) {
            result = (result + solve(n - 1, i, m)) % MOD;
        }

        return result;
    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach (Recursion + Memoization)
//T.C : O(n * S * S * m), where S = total states i.e. 3 * 2^m-1
//S.C : O((n * S) + (S * m)) where n * S is because of memoization array t, and S * m is for storing columnStates
import java.util.*;

public class Solution {
    private List<String> columnStates = new ArrayList<>();
    private int[][] t;
    private final int MOD = 1_000_000_007;

    // Recursively generate all valid column colorings of height 'm'
    // such that no two vertically adjacent cells have the same color
    private void generateColumnStates(String currentColumn, int rowsRemaining, char prevColor) {
        if (rowsRemaining == 0) {
            columnStates.add(currentColumn);
            return;
        }

        // Colors: 'R' = Red, 'G' = Green, 'B' = Blue
        for (char color : new char[]{'R', 'G', 'B'}) {
            if (color == prevColor) continue;
            generateColumnStates(currentColumn + color, rowsRemaining - 1, color);
        }
    }

    private int solve(int remainingCols, int prevColumnIdx, int m) {
        if (remainingCols == 0) return 1;
        if (t[remainingCols][prevColumnIdx] != -1) return t[remainingCols][prevColumnIdx];

        int totalWays = 0;
        String prevColumn = columnStates.get(prevColumnIdx);

        for (int nextColumnIdx = 0; nextColumnIdx < columnStates.size(); nextColumnIdx++) {
            String nextColumn = columnStates.get(nextColumnIdx);
            boolean valid = true;

            // Check horizontal adjacency (no same color in same row across adjacent columns)
            for (int r = 0; r < m; r++) {
                if (prevColumn.charAt(r) == nextColumn.charAt(r)) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                totalWays = (totalWays + solve(remainingCols - 1, nextColumnIdx, m)) % MOD;
            }
        }

        return t[remainingCols][prevColumnIdx] = totalWays;
    }

    public int colorTheGrid(int m, int n) {
        columnStates.clear();
        generateColumnStates("", m, '#'); // '#' denotes no previous color

        int numColumnPatterns = columnStates.size();
        t = new int[n][numColumnPatterns];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        int result = 0;
        for (int i = 0; i < numColumnPatterns; i++) {
            result = (result + solve(n - 1, i, m)) % MOD;
        }

        return result;
    }
}
