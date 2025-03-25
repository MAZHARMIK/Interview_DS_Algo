/*         Scroll below to see JAVA code as well        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Amazon, Google, Nutanix
    Leetcode Qn Link            : https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections
*/


/************************************************************************ C++ ************************************************************/
//Approach (Using Merge Intervals)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(begin(intervals), end(intervals));

        vector<vector<int>> result;

        result.push_back(intervals[0]);
        //{1, 5}, {5, 7}
        //{1, 7}
        for(int i = 1; i < n; i++) {
            if(intervals[i][0] < result.back()[1]) { //overlapping
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        //x-axis
        vector<vector<int>> hor;
        
        //y-aixs
        vector<vector<int>> vert;

        for(auto &coord : rectangles) {
            int x1 = coord[0];
            int y1 = coord[1];
            int x2 = coord[2];
            int y2 = coord[3];

            hor.push_back({x1, x2});
            vert.push_back({y1, y2});
        }

        vector<vector<int>> result1 = merge(hor);
        if(result1.size() >= 3)
            return true;

        vector<vector<int>> result2 = merge(vert);

        return result2.size() >= 3;
    }
};


/************************************************************************ Java ************************************************************/
// Approach (Using Merge Intervals)
// T.C : O(nlogn)
// S.C : O(n)
class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;

        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        List<int[]> result = new ArrayList<>();
        result.add(intervals[0]);

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < result.get(result.size() - 1)[1]) { // Overlapping
                result.get(result.size() - 1)[1] = Math.max(result.get(result.size() - 1)[1], intervals[i][1]);
            } else {
                result.add(intervals[i]);
            }
        }

        return result.toArray(new int[result.size()][]);
    }

    public boolean checkValidCuts(int n, int[][] rectangles) {
        List<int[]> hor = new ArrayList<>();
        List<int[]> vert = new ArrayList<>();

        for (int[] coord : rectangles) {
            int x1 = coord[0];
            int y1 = coord[1];
            int x2 = coord[2];
            int y2 = coord[3];

            hor.add(new int[]{x1, x2});
            vert.add(new int[]{y1, y2});
        }

        int[][] horArray = hor.toArray(new int[hor.size()][]);
        int[][] vertArray = vert.toArray(new int[vert.size()][]);

        int[][] result1 = merge(horArray);
        if (result1.length >= 3) {
            return true;
        }

        int[][] result2 = merge(vertArray);
        return result2.length >= 3;
    }
}
