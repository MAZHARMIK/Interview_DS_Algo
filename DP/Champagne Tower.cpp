/*
    MY YOUTUBE VIDEO ON THIS Qn : Recursion + Memo - https://www.youtube.com/watch?v=-RwOEYcsQU0
                                  Bottom Up - https://www.youtube.com/watch?v=Emv0Q2N-3n4
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/champagne-tower/
*/

/**************************************************************** C++ ****************************************************************/
//Approach-1
//Simple Recursion + Memoization
//T.C : O(query_row*query_row) - We visit each state only once
class Solution {
public:
    double t[101][101];
    double solve(int poured, int i, int j) {
        
        if(i < 0 || j > i || j < 0)
            return 0.0;
        
        if(i == 0 && j == 0)
            return t[i][j] = poured;
        
        if(t[i][j] != -1)
            return t[i][j];
        
        double up_left  = (solve(poured, i - 1, j - 1) - 1) / 2.0;
        
        double up_right = (solve(poured, i - 1, j) - 1) / 2.0;
            
         if(up_left < 0)
            up_left = 0.0;
        
        if(up_right < 0)
            up_right = 0.0;
        
        return t[i][j] = up_left + up_right;
    }
    
    double champagneTower(int poured, int query_row, int query_glass) {
        for(int i = 0; i<101; i++) {
            for(int j = 0; j<101; j++) {
                t[i][j] = -1;
            }
        }
        
        return min(1.0, solve(poured, query_row, query_glass));
    }
};

//Approach-2 (Using Bottom Up)
//T.C : O(query_row*query_row)
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> t(101, vector<double>(101, 0.0));
        t[0][0] = (double)poured;
        
        for(int row = 0; row<=query_row; row++) {
            //0th row has 0th column
            //1st row had 0th column, 1st column
            //2nd row has 0th column, 1st column, 2nd column
            //so, col = 0; col <= row
            for(int col = 0; col<=row; col++) {
                
                double excess = (t[row][col] - 1.0)/2.0;
                
                if(excess > 0) { //it means it will flow in next row (two glasses below it)
                    t[row+1][col]   += excess;
                    t[row+1][col+1] += excess;
                }
            }
        }
        
        //It may be the case that some Champagne was excess in t[query_row][query_glass]
        //So, And we need to tell how much Champagne is in there in t[query_row][query_glass]
        //Hence, we will return 1 in that case and so is the statement below
        return min(1.0, t[query_row][query_glass]);
    }
};

/**************************************************************** JAVA ****************************************************************/
//Approach-1
//Simple Recursion + Memoization
//T.C : O(query_row*query_row) - We visit each state only once
public class Solution {
    double[][] t = new double[101][101];

    public double solve(int poured, int i, int j) {
        if (i < 0 || j > i || j < 0) {
            return 0.0;
        }

        if (i == 0 && j == 0) {
            return t[i][j] = poured;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        double up_left = (solve(poured, i - 1, j - 1) - 1) / 2.0;
        double up_right = (solve(poured, i - 1, j) - 1) / 2.0;

        if (up_left < 0) {
            up_left = 0.0;
        }

        if (up_right < 0) {
            up_right = 0.0;
        }

        return t[i][j] = up_left + up_right;
    }

    public double champagneTower(int poured, int query_row, int query_glass) {
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                t[i][j] = -1;
            }
        }

        return Math.min(1.0, solve(poured, query_row, query_glass));
    }
}

//Approach-2 (Using Bottom Up)
//T.C : O(query_row*query_row)
public class Solution {
    double[][] t = new double[101][101];

    public double solve(int poured, int i, int j) {
        if (i < 0 || j > i || j < 0) {
            return 0.0;
        }

        if (i == 0 && j == 0) {
            return t[i][j] = poured;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        double up_left = (solve(poured, i - 1, j - 1) - 1) / 2.0;
        double up_right = (solve(poured, i - 1, j) - 1) / 2.0;

        if (up_left < 0) {
            up_left = 0.0;
        }

        if (up_right < 0) {
            up_right = 0.0;
        }

        return t[i][j] = up_left + up_right;
    }

    public double champagneTower(int poured, int query_row, int query_glass) {
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                t[i][j] = -1;
            }
        }

        return Math.min(1.0, solve(poured, query_row, query_glass));
    }
}
