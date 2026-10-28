/*   Scroll below to see JAVA code also  */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=JznAgCmAATo
    Company Tags                : Will udpate later
    Leetcode Link               : https://leetcode.com/problems/minimum-xor-path-in-a-grid
*/


/******************************************************* C++ *******************************************************/
//Approach (Bits Xor Property and Grid DP format)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bitset<1024>>> dp(m, vector<bitset<1024>>(n));
        //m*n
        //dp[i][j] = it stores a bitset<1024> {0, 0, 1, 1, 0, .....}

        dp[0][0][grid[0][0]] = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0)
                    continue;

                bitset<1024> up; //[i-1][j]
                bitset<1024> left; //[i][j-1]

                if(i > 0) {
                    up = dp[i-1][j];
                }
                if(j > 0) {
                    left = dp[i][j-1];
                }

                bitset<1024> combined = up | left; //OR operation

                for(int xorVal = 0; xorVal < 1024; xorVal++) {
                    if(combined[xorVal]) {
                        int resultXorVal = xorVal ^ grid[i][j];
                        dp[i][j][resultXorVal] = 1;
                    }
                }
            }
        }

        //dp[m-1][n-1]
        for(int xorVal = 0; xorVal < 1024; xorVal++) {
            if(dp[m-1][n-1][xorVal]) {
                return xorVal;
            }
        }

        return -1;

        
    }
};



/******************************************************* JAVA *******************************************************/
//Approach (Bits Xor Property and Grid DP format)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    public int minCost(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        // dp[i][j] = BitSet of size 1024, index = XOR value, bit = reachable
        BitSet[][] dp = new BitSet[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = new BitSet(1024);
            }
        }

        dp[0][0].set(grid[0][0]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                BitSet up = new BitSet(1024);    // [i-1][j]
                BitSet left = new BitSet(1024);  // [i][j-1]

                if (i > 0) {
                    up = (BitSet) dp[i - 1][j].clone();
                }
                if (j > 0) {
                    left = (BitSet) dp[i][j - 1].clone();
                }

                BitSet combined = (BitSet) up.clone();
                combined.or(left);               // OR operation

                for (int xorVal = 0; xorVal < 1024; xorVal++) {
                    if (combined.get(xorVal)) {
                        int resultXorVal = xorVal ^ grid[i][j];
                        dp[i][j].set(resultXorVal);
                    }
                }
            }
        }

        // dp[m-1][n-1]
        for (int xorVal = 0; xorVal < 1024; xorVal++) {
            if (dp[m - 1][n - 1].get(xorVal)) {
                return xorVal;
            }
        }

        return -1;
    }
}
