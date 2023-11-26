/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Cs-xXLHG1BY
    Company Tags                : GOOGLE, Directi
    Leetcode Link               : https://leetcode.com/problems/largest-submatrix-with-rearrangements/
*/


/*************************************************************** C++ ***************************************************************/
//Approach-1 (Using sorting)
//T.C : (m * nlogn)
//S.C : O(m*n)
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        
        for(int row = 0; row < m; row++) {
            
            for(int col = 0; col < n; col++) {
                
                if(matrix[row][col] == 1 && row > 0) {
                    matrix[row][col] += matrix[row-1][col];
                }
                
            }
            
            
            vector<int> currRow = matrix[row];
            sort(begin(currRow), end(currRow), greater<int>());
            for(int col = 0; col < n; col++) {
                int base   = (col+1); //iske peeche k columns me >= currRow[col] to hoga hi 1s
                int height = currRow[col];
                
                result = max(result, base*height);
            }
            
        }
        
        return result;
    }
};


//Approach-2 (Without modifying the given input)
//T.C : (m * nlogn)
//S.C : O(m*n)
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prevRow(n, 0);
        int result = 0;
        
        for(int row = 0; row < m; row++) {
            vector<int> currRow = matrix[row];
            
            for(int col = 0; col < n; col++) {
                
                if(currRow[col] == 1) {
                    currRow[col] += prevRow[col];
                }
                
            }
            
            
            vector<int> sortedRow = currRow;
            sort(begin(sortedRow), end(sortedRow), greater<int>());
            
            for(int col = 0; col < n; col++) {
                int base   = (col+1); //iske peeche k columns me >= currRow[col] to hoga hi 1s
                int height = sortedRow[col];
                
                result = max(result, base*height);
            }
            
            prevRow = currRow;
            
        }
        
        return result;
    }
};



//Approach-3 (Without sorting)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> prevHeights;
        int result = 0;

        for (int row = 0; row < m; row++) {
            vector<pair<int,int>> heights;
            vector<bool> seen = vector<bool>(n, false);

            for (auto [height, col] : prevHeights) {
                if (matrix[row][col] == 1) {
                    heights.push_back({height + 1, col});
                    seen[col] = true;
                }
            }

            for (int col = 0; col < n; col++) {
                if (seen[col] == false && matrix[row][col] == 1) {
                    heights.push_back({1, col});
                }
            }

            for (int i = 0; i < heights.size(); i++) {
                int base   = (i+1);
                int height = heights[i].first;
                result = max(result, base*height);
            }

            prevHeights = heights;
        }

        return result;
    }
};



/*************************************************************** JAVA ***************************************************************/
//Approach-1 (Using sorting)
//T.C : (m * nlogn)
//S.C : O(m*n)
class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int result = 0;
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (matrix[row][col] != 0 && row > 0) {
                    matrix[row][col] += matrix[row - 1][col];
                }
            }
            
            int[] currRow = matrix[row].clone();
            Arrays.sort(currRow);
            for (int col = 0; col < n; col++) {
                int base = (n - col);
                int height = currRow[col];
                result = Math.max(result, base*height);
            }
        }
        
        return result;
    }
}



//Approach-2 (Without modifying the given input)
//T.C : (m * nlogn)
//S.C : O(m*n)
class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[] prevRow = new int[n];
        int result = 0;

        for (int row = 0; row < m; row++) {
            int[] currRow = matrix[row].clone();
            for (int col = 0; col < n; col++) {
                if (currRow[col] != 0) {
                    currRow[col] += prevRow[col];
                }
            }

            int[] sortedRow = currRow.clone();
            Arrays.sort(sortedRow);
            for (int i = 0; i < n; i++) {
                int base   = (n - i);
                int height = sortedRow[i];
                result = Math.max(result, base*height);
            }

            prevRow = currRow;
        }

        return result;
    }
}



//Approach-3 (Without sorting)
//T.C : O(m*n)
//S.C : O(m*n)

class Solution {
    public int largestSubmatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        List<Pair<Integer, Integer>> prevHeights = new ArrayList<>();
        int result = 0;

        for (int row = 0; row < m; row++) {
            List<Pair<Integer, Integer>> heights = new ArrayList<>();
            boolean[] seen = new boolean[n];

            for (Pair<Integer, Integer> entry : prevHeights) {
                int height = entry.getKey();
                int col = entry.getValue();
                if (matrix[row][col] == 1) {
                    heights.add(new Pair<>(height + 1, col));
                    seen[col] = true;
                }
            }

            for (int col = 0; col < n; col++) {
                if (!seen[col] && matrix[row][col] == 1) {
                    heights.add(new Pair<>(1, col));
                }
            }

            for (int i = 0; i < heights.size(); i++) {
                int base = i + 1;
                int height = heights.get(i).getKey();
                result = Math.max(result, base * height);
            }

            prevHeights = heights;
        }

        return result;
    }
    
}
