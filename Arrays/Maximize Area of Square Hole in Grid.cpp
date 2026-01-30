/*     Scroll below to see JAVA code as well    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=BfOeTE_-3l4
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/maximize-area-of-square-hole-in-grid
*/


/************************************************************ C++ *****************************************************/
//Approach (Sort and process)
//T.C : O(vlogv + hlogh), v = vBars.size(), h = hBars.size()
//S.C : O(1)
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        //1st Step : Sort the inputs
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));

        int maxConsecutiveHBars = 1; //Length of Longest consecutive horizontal bars
        int maxConsecutiveVBars = 1; //Length of Longest consecutive Vertical bars

        //First find Length of Longest consecutive horizontal bars
        int currConsecutiveHBars = 1;
        for(int i = 1; i < hBars.size(); i++) {
            if(hBars[i] - hBars[i-1] == 1) {
                currConsecutiveHBars++;
            } else {
                currConsecutiveHBars = 1;
            }
            maxConsecutiveHBars  = max(maxConsecutiveHBars, currConsecutiveHBars);
        }

        //Simialrl, find Length of Longest consecutive vertical bars
        int currConsecutiveVBars = 1;
        for(int i = 1; i < vBars.size(); i++) {
            if(vBars[i] - vBars[i-1] == 1) {
                currConsecutiveVBars++;
            } else {
                currConsecutiveVBars = 1;
            }
            maxConsecutiveVBars  = max(maxConsecutiveVBars, currConsecutiveVBars);
        }

        //Square width and height must be same. We can reduce the larger one to match the smaller one
        // So, take the minimum of them.
        int side = min(maxConsecutiveHBars, maxConsecutiveVBars)+1;
        
      return side*side;
    }
};


/************************************************************ JAVA *****************************************************/
//Approach (Sort and process)
//T.C : O(vlogv + hlogh), v = vBars.size(), h = hBars.size()
//S.C : O(1)
class Solution {
    public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        //1st Step : Sort the inputs
        Arrays.sort(hBars);
        Arrays.sort(vBars);

        int maxConsecutiveHBars = 1; //Length of Longest consecutive horizontal bars
        int maxConsecutiveVBars = 1; //Length of Longest consecutive Vertical bars

        //First find Length of Longest consecutive horizontal bars
        int currConsecutiveHBars = 1;
        for (int i = 1; i < hBars.length; i++) {
            if (hBars[i] - hBars[i - 1] == 1) {
                currConsecutiveHBars++;
            } else {
                currConsecutiveHBars = 1;
            }
            maxConsecutiveHBars = Math.max(maxConsecutiveHBars, currConsecutiveHBars);
        }

        //Simialrl, find Length of Longest consecutive vertical bars
        int currConsecutiveVBars = 1;
        for (int i = 1; i < vBars.length; i++) {
            if (vBars[i] - vBars[i - 1] == 1) {
                currConsecutiveVBars++;
            } else {
                currConsecutiveVBars = 1;
            }
            maxConsecutiveVBars = Math.max(maxConsecutiveVBars, currConsecutiveVBars);
        }

        //Square width and height must be same. We can reduce the larger one to match the smaller one
        // So, take the minimum of them.
        int side = Math.min(maxConsecutiveHBars, maxConsecutiveVBars) + 1;
        
        return side * side;
    }
}
