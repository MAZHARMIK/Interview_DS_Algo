/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=GTahroSaPe0
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/count-servers-that-communicate
*/


/************************************************** C++ **************************************************/
//Approach - 1 (Brute Force)
//T.C : O((m*n) * (m+n))
//S.C : O(1)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int resultServers = 0;

        // Traverse through the grid
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {
                    bool canCommunicate = false;

                    // Check for communication in the same row
                    for (int otherCol = 0; otherCol < n; ++otherCol) {
                        if (otherCol != col && grid[row][otherCol] == 1) {
                            canCommunicate = true;
                            break;
                        }
                    }

                    // If a server was found in the same row, increment resultServers
                    if (canCommunicate) {
                        resultServers++;
                    } else {
                        // Check for communication in the same column
                        for (int otherRow = 0; otherRow < m; ++otherRow) {
                            if (otherRow != row && grid[otherRow][col] == 1) {
                                canCommunicate = true;
                                break;
                            }
                        }

                        // If a server was found in the same column, increment resultServers
                        if (canCommunicate) {
                            resultServers++;
                        }
                    }
                }
            }
        }

        return resultServers;
    }
};


//Approach - 2 (Better Approach)
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> indexColCount(n, 0);
        vector<int> indexRowCount(m, 0);
        
        //Preprocessing
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) { //found a server at grid[row][col]
                    indexColCount[col] += 1;
                    indexRowCount[row] += 1;
                }
            }
        }

        int resultServers = 0;
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1 && (indexColCount[col] > 1 || indexRowCount[row] > 1)) {
                    resultServers++;
                }
            }
        }
        return resultServers;
    }
};


//Approach - 3 (Another better Approach)
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> colServerCount(n, 0);
        vector<int> RowAkelaServerCol(m, -1);

        int resultServers = 0;

        for(int row = 0; row < m; row++) {
            int countServersRow = 0;
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) {
                    countServersRow += 1;
                    colServerCount[col]++;
                    RowAkelaServerCol[row] = col;
                }
            }

            if(countServersRow > 1) {
                resultServers += countServersRow;
                RowAkelaServerCol[row] = -1; //no akela server in this row
            }
        }

        //Check Akela servers in each row
        for(int row = 0; row < m; row++) {
            if(RowAkelaServerCol[row] != -1) {
                int col = RowAkelaServerCol[row];
                if(colServerCount[col] > 1) {
                    resultServers += 1;
                }
            }
        }

        return resultServers;
        
    }
};



// ************************************************** Java **************************************************
// Approach - 1 (Brute Force)
// T.C : O((m*n) * (m+n))
// S.C : O(1)
class Solution {
    public int countServers(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int resultServers = 0;

        // Traverse through the grid
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (grid[row][col] == 1) {
                    boolean canCommunicate = false;

                    // Check for communication in the same row
                    for (int otherCol = 0; otherCol < n; ++otherCol) {
                        if (otherCol != col && grid[row][otherCol] == 1) {
                            canCommunicate = true;
                            break;
                        }
                    }

                    // If a server was found in the same row, increment resultServers
                    if (canCommunicate) {
                        resultServers++;
                    } else {
                        // Check for communication in the same column
                        for (int otherRow = 0; otherRow < m; ++otherRow) {
                            if (otherRow != row && grid[otherRow][col] == 1) {
                                canCommunicate = true;
                                break;
                            }
                        }

                        // If a server was found in the same column, increment resultServers
                        if (canCommunicate) {
                            resultServers++;
                        }
                    }
                }
            }
        }

        return resultServers;
    }
}

// Approach - 2 (Better Approach)
// T.C : O(m*n)
// S.C : O(m+n)
class Solution {
    public int countServers(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int[] indexColCount = new int[n];
        int[] indexRowCount = new int[m];

        // Preprocessing
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) { // found a server at grid[row][col]
                    indexColCount[col]++;
                    indexRowCount[row]++;
                }
            }
        }

        int resultServers = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1 && (indexColCount[col] > 1 || indexRowCount[row] > 1)) {
                    resultServers++;
                }
            }
        }
        return resultServers;
    }
}

// Approach - 3 (Another Better Approach)
// T.C : O(m*n)
// S.C : O(m+n)
class Solution {
    public int countServers(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int[] colServerCount = new int[n];
        int[] rowAkelaServerCol = new int[m];
        Arrays.fill(rowAkelaServerCol, -1);

        int resultServers = 0;

        for (int row = 0; row < m; row++) {
            int countServersRow = 0;
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    countServersRow++;
                    colServerCount[col]++;
                    rowAkelaServerCol[row] = col;
                }
            }

            if (countServersRow > 1) {
                resultServers += countServersRow;
                rowAkelaServerCol[row] = -1; // no akela server in this row
            }
        }

        // Check Akela servers in each row
        for (int row = 0; row < m; row++) {
            if (rowAkelaServerCol[row] != -1) {
                int col = rowAkelaServerCol[row];
                if (colServerCount[col] > 1) {
                    resultServers++;
                }
            }
        }

        return resultServers;
    }
}
