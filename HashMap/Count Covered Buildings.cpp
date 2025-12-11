/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/count-covered-buildings
*/


/************************************************************ C++ *****************************************************/
//Approach (storing in Map and checking)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, pair<int,int>> yToMinMaxX;
        unordered_map<int, pair<int,int>> xToMinMaxY;

        for (auto &building : buildings) {
            int x = building[0];
            int y = building[1];

            if (!yToMinMaxX.count(x))
                yToMinMaxX[x] = {INT_MAX, INT_MIN};

            if (!xToMinMaxY.count(y))
                xToMinMaxY[y] = {INT_MAX, INT_MIN};

            yToMinMaxX[x].first = min(yToMinMaxX[x].first, y);
            yToMinMaxX[x].second = max(yToMinMaxX[x].second, y);

            xToMinMaxY[y].first = min(xToMinMaxY[y].first, x);
            xToMinMaxY[y].second = max(xToMinMaxY[y].second, x);
        }

        int result = 0;

        for (auto &building : buildings) {
            int x = building[0];
            int y = building[1];


            auto &xr = xToMinMaxY[y];
            auto &yr = yToMinMaxX[x];

            if (xr.first < x && x < xr.second &&
                yr.first < y && y < yr.second) {
                result++;
            }
        }

        return result;
    }
};




/************************************************************ JAVA *****************************************************/
//Approach (storing in Map and checking)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        Map<Integer, int[]> yToMinMaxX = new HashMap<>();
        Map<Integer, int[]> xToMinMaxY = new HashMap<>();

        for (int[] building : buildings) {
            int x = building[0];
            int y = building[1];

            yToMinMaxX.putIfAbsent(x, new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE});
            xToMinMaxY.putIfAbsent(y, new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE});

            int[] yr = yToMinMaxX.get(x);
            yr[0] = Math.min(yr[0], y);
            yr[1] = Math.max(yr[1], y);

            int[] xr = xToMinMaxY.get(y);
            xr[0] = Math.min(xr[0], x);
            xr[1] = Math.max(xr[1], x);
        }

        int result = 0;

        for (int[] building : buildings) {
            int x = building[0];
            int y = building[1];

            int[] xr = xToMinMaxY.get(y);
            int[] yr = yToMinMaxX.get(x);

            if (xr[0] < x && x < xr[1] &&
                yr[0] < y && y < yr[1]) {
                result++;
            }
        }

        return result;
    }
}
