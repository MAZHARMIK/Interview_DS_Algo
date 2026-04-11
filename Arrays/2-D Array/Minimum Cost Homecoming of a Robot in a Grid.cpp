/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=JIUAXtxY1mg
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid/description/
*/


/************************************************** C++ **************************************************/
//Approach - Straight forward iterate and find
//T.C : O(m+n)
//S.C : O(1)
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {
        
        int r1 = startPos[0], c1 = startPos[1];
        int r2 = homePos[0], c2 = homePos[1];
        
        int res = 0;

        //Move in rows
        if (r2 >= r1) {
            // moving DOWN
            for (int r = r1 + 1; r <= r2; r++) {
                res += rowCosts[r];
            }
        } else {
            // moving UP
            for (int r = r1 - 1; r >= r2; r--) {
                res += rowCosts[r];
            }
        }

        //Move in columns
        if (c2 >= c1) {
            // moving RIGHT
            for (int c = c1 + 1; c <= c2; c++) {
                res += colCosts[c];
            }
        } else {
            // moving LEFT
            for (int c = c1 - 1; c >= c2; c--) {
                res += colCosts[c];
            }
        }

        return res;
    }
};


/************************************************** JAVA **************************************************/
//Approach - Straight forward iterate and find
//T.C : O(m+n)
//S.C : O(1)
class Solution {
    public int minCost(int[] startPos, int[] homePos, int[] rowCosts, int[] colCosts) {
        
        int r1 = startPos[0], c1 = startPos[1];
        int r2 = homePos[0], c2 = homePos[1];
        
        int res = 0;

        //Move in rows
        if (r2 >= r1) {
            // moving DOWN
            for (int r = r1 + 1; r <= r2; r++) {
                res += rowCosts[r];
            }
        } else {
            // moving UP
            for (int r = r1 - 1; r >= r2; r--) {
                res += rowCosts[r];
            }
        }

        //Move in columns
        if (c2 >= c1) {
            // moving RIGHT
            for (int c = c1 + 1; c <= c2; c++) {
                res += colCosts[c];
            }
        } else {
            // moving LEFT
            for (int c = c1 - 1; c >= c2; c--) {
                res += colCosts[c];
            }
        }

        return res;
    }
}
