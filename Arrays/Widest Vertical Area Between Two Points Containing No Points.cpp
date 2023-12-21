/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=QZuxYdVNoIU
      Company Tags                : GOOGLE
      Leetcode Link               : https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
*/

/************************************************************** C++ **************************************************************/
//T.C : O(nlog(n))
//S.C : O(1)
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points), end(points));
        
        int maxVal = 0;
        
        for(int i = 1; i<n; i++) {
            maxVal = max(maxVal, points[i][0] - points[i-1][0]);
        }
        
        return maxVal;
        
    }
};


/************************************************************** JAVA **************************************************************/
//T.C : O(nlog(n))
//S.C : O(1)
class Solution {
    public int maxWidthOfVerticalArea(int[][] points) {
        int n = points.length;
        Arrays.sort(points, (a, b) -> Integer.compare(a[0], b[0]));

        int maxVal = 0;

        for (int i = 1; i < n; i++) {
            maxVal = Math.max(maxVal, points[i][0] - points[i - 1][0]);
        }

        return maxVal;
    }
}
