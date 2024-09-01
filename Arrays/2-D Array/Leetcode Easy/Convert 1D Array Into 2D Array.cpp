/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=4jQErv8WK6o
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/convert-1d-array-into-2d-array
*/


/************************************************************ C++ ************************************************************/
//Approach-1 (Using simply simulation)
//T.C : O(m*n)
//S.C : O(1) //no including space of result
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m, vector<int>(n));
        int l = original.size();

        if(m*n != l) {
            return {};
        }

        int idx = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = original[idx];
                idx++;
            }
        }

        return result;
    }
};


//Approach-2 (Using simply math observation)
//T.C : O(m*n)
//S.C : O(1) //no including space of result
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> result(m, vector<int>(n));
        int l = original.size();

        if(m*n != l) {
            return {};
        }

        for(int i = 0; i < l; i++) {
            result[i/n][i%n] = original[i];
        }

        return result;
    }
};



/************************************************************ JAVA ************************************************************/
//Approach-1 (Using simply simulation)
//T.C : O(m*n)
//S.C : O(1) //no including space of result
class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        // Check if the product of m and n is equal to the size of the original array
        if (m * n != original.length) {
            return new int[0][0];  // Return an empty 2D array if the sizes don't match
        }

        // Initialize the result 2D array
        int[][] result = new int[m][n];

        // Index for the original array
        int idx = 0;

        // Fill the 2D array row by row
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = original[idx];
                idx++;
            }
        }

        return result;  // Return the constructed 2D array
    }
}



//Approach-2 (Using simply math observation)
//T.C : O(m*n)
//S.C : O(1) //no including space of result
class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        // Check if the total number of elements matches
        if (m * n != original.length) {
            return new int[0][0];  // Return an empty 2D array if the sizes don't match
        }

        // Initialize the result 2D array
        int[][] result = new int[m][n];
        
        // Fill the 2D array using division and modulus to calculate row and column indices
        for (int i = 0; i < original.length; i++) {
            result[i / n][i % n] = original[i];
        }

        return result;  // Return the constructed 2D array
    }
}
