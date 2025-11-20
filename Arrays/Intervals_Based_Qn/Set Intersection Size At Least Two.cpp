/*         Scroll below to see JAVA code as well        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update later
    Leetcode Qn Link            : https://leetcode.com/problems/set-intersection-size-at-least-two
*/


/************************************************************************ C++ ************************************************************/
//Approach (Using sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();

        auto lambda = [](auto &vec1, auto &vec2) {
            if (vec1[1] != vec2[1])
                return vec1[1] < vec2[1];
            return vec1[0] > vec2[0];
        };

        sort(intervals.begin(), intervals.end(), lambda);

        int result = 0;
        int first  = -1;
        int second = -1;

        for (int i = 0; i < n; ++i) {
            int l = intervals[i][0];
            int r = intervals[i][1];


            if (l <= first)
                continue;

            if (l > second) {
                result += 2;
                second = r;
                first = r - 1;
            } else {
                result += 1;
                first = second;
                second = r;
            }
        }
        return result;
    }
};



/************************************************************************ JAVA ************************************************************/
//Approach (Using sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public int intersectionSizeTwo(int[][] intervals) {
        int n = intervals.length;

        // Sort by end ascending; if tie, by start descending
        Arrays.sort(intervals, (vec1, vec2) -> {
            if (vec1[1] != vec2[1]) 
                return vec1[1] - vec2[1];
            return vec2[0] - vec1[0];
        });

        int result = 0;
        int first = -1;
        int second = -1;

        for (int i = 0; i < n; ++i) {
            int l = intervals[i][0];
            int r = intervals[i][1];

            // both points already in the interval
            if (l <= first)
                continue;

            // if neither point is inside
            if (l > second) {
                result += 2;
                second = r;
                first = r - 1;
            } else {
                // only second is inside
                result += 1;
                first = second;
                second = r;
            }
        }

        return result;
    }
}
