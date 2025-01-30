/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=SOI-ZzYemoc
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows
*/


/******************************************** C++ ********************************************/
//Approach-1 (Brute Force)
//T.C : O(row^2 * col)
//S.C : O(col)
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int maxRows = 0;

        for (auto& currRow : matrix) {

            vector<int> inverted(n);
            int count = 0;

            
            for (int col = 0; col < n; col++) {
                inverted[col] = currRow[col] == 0 ? 1 : 0;
            }

            for (auto& row : matrix) {

                if (row == currRow || row == inverted) {
                    count++;
                }
            }

            maxRows = max(maxRows, count);
        }

        return maxRows;
    }
};


//Approach-2 (Using hashmap to store patterns)
//T.C : O(row * col)
//S.C : O(row*col)
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<string, int> mp; //O(m*n)

        for(auto &row : matrix) { //O(m)
            string rowKaNature = "";

            int firstVal = row[0];
            for(int col = 0; col < n; col++) { //O(n)
                rowKaNature += (row[col] == firstVal) ? "S" : "B";
            }

            mp[rowKaNature]++;
        }

        int maxRows = 0;
        for(auto &it : mp) {
            maxRows = max(maxRows, it.second);
        }

        return maxRows;
    }
};



/******************************************** JAVA ********************************************/
//Approach-1 (Brute Force)
//T.C : O(row^2 * col)
//S.C : O(col)
class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int n = matrix[0].length;
        int maxRows = 0;

        for (int[] currRow : matrix) {
            int[] inverted = new int[n];
            int count = 0;

            // Generate the inverted row
            for (int col = 0; col < n; col++) {
                inverted[col] = currRow[col] == 0 ? 1 : 0;
            }

            // Count matching rows (either equal to currRow or inverted)
            for (int[] row : matrix) {
                if (Arrays.equals(row, currRow) || Arrays.equals(row, inverted)) {
                    count++;
                }
            }

            maxRows = Math.max(maxRows, count);
        }

        return maxRows;
    }
}


//Approach-2 (Using hashmap to store patterns)
//T.C : O(row * col)
//S.C : O(row*col)
class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        Map<String, Integer> rowPatterns = new HashMap<>(); // To store row patterns and their frequencies

        for (int[] row : matrix) { // Loop over each row
            StringBuilder rowPattern = new StringBuilder();
            int firstVal = row[0];

            // Generate the pattern for the current row
            for (int col = 0; col < n; col++) {
                rowPattern.append(row[col] == firstVal ? "S" : "B");
            }

            // Increment the frequency of the row pattern
            rowPatterns.put(rowPattern.toString(), rowPatterns.getOrDefault(rowPattern.toString(), 0) + 1);
        }

        int maxRows = 0;

        // Find the maximum frequency of any row pattern
        for (int count : rowPatterns.values()) {
            maxRows = Math.max(maxRows, count);
        }

        return maxRows;
    }
}
