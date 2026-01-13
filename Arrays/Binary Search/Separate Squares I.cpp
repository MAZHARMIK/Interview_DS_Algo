/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/separate-squares-i/description/
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Binary search on answer)
//T.C : O(n * log(range)), range = max (y+side) value - min y value
//S.C : O(1)
class Solution {
public:
    bool check(vector<vector<int>>& squares, double mid_y, double total) {
        double bot_area = 0;

        for(auto &square : squares) {
            double y = square[1];
            double l = square[2];

            double boty = y;
            double topy = y + l;

            if (mid_y >= topy) {
                //full square below
                bot_area += l * l;
            } else if (mid_y > boty) {
                //partial area below
                bot_area += (mid_y - boty) * l;
            }
        }

        return bot_area >= total/2.0; //Is bottom area more than above ?
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low   = INT_MAX;
        double high  = INT_MIN;
        double total = 0.00000;

        for(auto &square : squares) {
            double x = square[0];
            double y = square[1];
            double l = square[2];
            total   += l*l;

            low  = min(low, y);
            high = max(high, y+l);
        }

        double result_y = 0.00000;

        while(high-low > 1e-5) {
            double mid_y = low + (high-low)/2;
            
            result_y = mid_y;

            if (check(squares, mid_y, total) == true) { //bottom area is greater
                //shift mid_y down side to balance area
                high = mid_y;
            } else {
                low = mid_y;
            }
        }

        return result_y;
    }
};



/****************************************************************** JAVA ******************************************************************/
//Approach (Binary search on answer)
//T.C : O(n * log(range)), range = max (y+side) value - min y value
//S.C : O(1)
class Solution {

    private boolean check(int[][] squares, double midY, double total) {
        double bottomArea = 0.0;

        for (int[] square : squares) {
            double y = square[1];
            double l = square[2];

            double bottomY = y;
            double topY = y + l;

            if (midY >= topY) {
                // full square below
                bottomArea += l * l;
            } else if (midY > bottomY) {
                // partial square below
                bottomArea += (midY - bottomY) * l;
            }
        }

        return bottomArea >= total / 2.0; //Is bottom area more than above ?
    }

    public double separateSquares(int[][] squares) {
        double low = Double.MAX_VALUE;
        double high = -Double.MAX_VALUE;
        double total = 0.0;

        for (int[] square : squares) {
            double y = square[1];
            double l = square[2];

            total += l * l;
            low = Math.min(low, y);
            high = Math.max(high, y + l);
        }

        double resultY = 0.0;

        while (high - low > 1e-5) {
            double midY = low + (high - low) / 2.0;
            resultY = midY;

            if (check(squares, midY, total)) {
                // bottom area is more than half, move down
                high = midY;
            } else {
                low = midY;
            }
        }

        return resultY;
    }
}
