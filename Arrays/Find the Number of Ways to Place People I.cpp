/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];   // candidate for upper-left

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                int x2 = points[j][0];
                int y2 = points[j][1];   // candidate for lower-right

                // Condition: (x1, y1) must be upper-left of (x2, y2)
                if (x1 <= x2 && y1 >= y2) {
                    bool hasPointInside = false;

                    // Check if some point lies inside or on the rectangle
                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) continue;

                        int x3 = points[k][0];
                        int y3 = points[k][1];

                        if (x3 >= x1 && x3 <= x2 &&
                            y3 <= y1 && y3 >= y2) {
                            hasPointInside = true;
                            break;
                        }
                    }

                    if (!hasPointInside) {
                        result++;
                    }
                }
            }
        }

        return result;
    }
};




//Approach-2 (Using Sorting)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        // Sort: x ascending, if x same then sort as y descending
        auto lambda = [](vector<int>& point1, vector<int>& point2) {
            if (point1[0] == point2[0]) {
                return point1[1] > point2[1];
            }
            return point1[0] < point2[0];
        };

        sort(points.begin(), points.end(), lambda);

        int result = 0;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];   // upper left

            int bestY = INT_MIN;

            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];   // lower right

                // Condition: (x2, y2) must be above (x1, y1)
                if (y2 > y1) { //not lower right
                    continue;
                }

                if (y2 > bestY) {
                    result++;
                    bestY = y2;
                }
            }
        }

        return result;
    }
};
