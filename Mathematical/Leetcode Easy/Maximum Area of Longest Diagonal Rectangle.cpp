/*    Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn  : https://www.youtube.com/watch?v=S43R5YCvf9Q
    Company Tags                 : will update later
    Leetcode Link                : https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle
*/


/********************************************************************* C++ *********************************************************************/
//Approach (Simple and straight forward)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();

        int maxDiag = 0;
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];

            int diag = l*l + w*w;
            int area = l*w;

            if(diag > maxDiag) {
                maxDiag = diag;
                maxArea = area;
            } else if(diag == maxDiag) {
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};



/********************************************************************* JAVA *********************************************************************/
//Approach (Simple and straight forward)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        int maxDiag = 0;
        int maxArea = 0;

        for (int i = 0; i < dimensions.length; i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];

            int diag = l * l + w * w;
            int area = l * w;

            if (diag > maxDiag) {
                maxDiag = diag;
                maxArea = area;
            } else if (diag == maxDiag) {
                maxArea = Math.max(maxArea, area);
            }
        }

        return maxArea;
    }
}
