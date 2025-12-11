/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=trZj9w1WcdY
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

            if (!yToMinMaxX.count(y))
                yToMinMaxX[y] = {INT_MAX, INT_MIN};

            if (!xToMinMaxY.count(x))
                xToMinMaxY[x] = {INT_MAX, INT_MIN};

            yToMinMaxX[y].first  = min(yToMinMaxX[y].first, x);
            yToMinMaxX[y].second = max(yToMinMaxX[y].second, x);

            xToMinMaxY[x].first = min(xToMinMaxY[x].first, y);
            xToMinMaxY[x].second = max(xToMinMaxY[x].second, y);
        }

        int result = 0;

        for (auto &building : buildings) {
            int x = building[0];
            int y = building[1];


            auto &xr = yToMinMaxX[y];
            auto &yr = xToMinMaxY[x];

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

            yToMinMaxX.putIfAbsent(y, new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE});
            xToMinMaxY.putIfAbsent(x, new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE});

            int[] xr = yToMinMaxX.get(y);
            xr[0] = Math.min(xr[0], x);
            xr[1] = Math.max(xr[1], x);

            int[] yr = xToMinMaxY.get(x);
            yr[0] = Math.min(yr[0], y);
            yr[1] = Math.max(yr[1], y);
        }

        int result = 0;

        for (int[] building : buildings) {
            int x = building[0];
            int y = building[1];

            int[] xr = yToMinMaxX.get(y);
            int[] yr = xToMinMaxY.get(x);

            if (xr[0] < x && x < xr[1] &&
                yr[0] < y && y < yr[1]) {
                result++;
            }
        }

        return result;
    }
}
