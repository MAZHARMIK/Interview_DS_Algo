/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=iUM2dOAOA9s
    Company Tags                : Cisco
    Leetcode Link               : https://leetcode.com/problems/lucky-numbers-in-a-matrix
*/


/********************************************************************* C++ ****************************************************************************/
//Approach-1 (Using Simple Traversal and extra space)
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> rowMin;
        for (int row = 0; row < m; row++) {

            int rMin = INT_MAX;
            for (int col = 0; col < n; col++) {
                rMin = min(rMin, matrix[row][col]);
            }
            rowMin.push_back(rMin);
        }

        vector<int> colMax;
        for (int col = 0; col < n; col++) {

            int cMax = INT_MIN;
            for (int row = 0; row < m; row++) {
                cMax = max(cMax, matrix[row][col]);
            }
            colMax.push_back(cMax);
        }

        vector<int> result;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == rowMin[row] && matrix[row][col] == colMax[col]) {
                    result.push_back(matrix[row][col]);
                }
            }
        }

        return result;
    }
};



//Approach-2 (Only one Lucky Number is possible) - Find it Greedily
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(); //rows
        int n = matrix[0].size(); //columns

        int rMinMax = INT_MIN;
        
        for(int row = 0; row < m; row++) {

            int rMin = INT_MAX;
            for(int col = 0; col < n; col++) {
                rMin = min(rMin, matrix[row][col]);
            }

            rMinMax = max(rMinMax, rMin);

        }

        int cMaxMin = INT_MAX;
        for(int col = 0; col < n; col++) {

            int cMax = INT_MIN;
            for(int row = 0; row < m; row++) {
                cMax = max(cMax, matrix[row][col]);
            }

            cMaxMin = min(cMaxMin, cMax);

        }


        if(rMinMax == cMaxMin) {
            return {rMinMax}; //{cMaxMin}
        }

        return {};
    }
};



/********************************************************************* JAVA ****************************************************************************/
//Approach-1 (Using Simple Traversal and extra space)
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        List<Integer> rowMin = new ArrayList<>();
        for (int row = 0; row < m; row++) {
            int rMin = Integer.MAX_VALUE;
            for (int col = 0; col < n; col++) {
                rMin = Math.min(rMin, matrix[row][col]);
            }
            rowMin.add(rMin);
        }

        List<Integer> colMax = new ArrayList<>();
        for (int col = 0; col < n; col++) {
            int cMax = Integer.MIN_VALUE;
            for (int row = 0; row < m; row++) {
                cMax = Math.max(cMax, matrix[row][col]);
            }
            colMax.add(cMax);
        }

        List<Integer> result = new ArrayList<>();
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] == rowMin.get(row) && matrix[row][col] == colMax.get(col)) {
                    result.add(matrix[row][col]);
                }
            }
        }

        return result;
    }
}


//Approach-2 (Only one Lucky Number is possible) - Find it Greedily
//T.C : O(m*n)
//S.C : O(1)
class Solution {
    public List<Integer> luckyNumbers(int[][] matrix) {
        int m = matrix.length; // rows
        int n = matrix[0].length; // columns

        int rMinMax = Integer.MIN_VALUE;

        for (int row = 0; row < m; row++) {
            int rMin = Integer.MAX_VALUE;
            for (int col = 0; col < n; col++) {
                rMin = Math.min(rMin, matrix[row][col]);
            }
            rMinMax = Math.max(rMinMax, rMin);
        }

        int cMaxMin = Integer.MAX_VALUE;
        for (int col = 0; col < n; col++) {
            int cMax = Integer.MIN_VALUE;
            for (int row = 0; row < m; row++) {
                cMax = Math.max(cMax, matrix[row][col]);
            }
            cMaxMin = Math.min(cMaxMin, cMax);
        }

        List<Integer> result = new ArrayList<>();
        if (rMinMax == cMaxMin) {
            result.add(rMinMax); // {cMaxMin}
        }

        return result;
    }
}
