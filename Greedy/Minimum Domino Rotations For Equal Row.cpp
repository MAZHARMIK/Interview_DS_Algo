/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
*/


/************************************************************ C++ ************************************************/
//Approach (Greedy)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:

    int find(vector<int>& tops, vector<int>& bottoms, int val) {
        int n = tops.size();

        int swapTop = 0;
        int swapBottom = 0;

        for(int i = 0; i < n; i++) {
            if(tops[i] != val && bottoms[i] != val) {
                return -1;
            } else if(tops[i] != val) {
                swapTop++;
            } else if(bottoms[i] != val) {
                swapBottom++;
            }
        }

        return min(swapTop, swapBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = INT_MAX;

        for(int val = 1; val <= 6; val++) {
            int swaps = find(tops, bottoms, val);

            if(swaps != -1) {
                result = min(result, swaps);
            }
        }

        return result == INT_MAX ? -1 : result;
    }
};



/************************************************************ JAVA ************************************************/
//Approach (Greedy)
//T.C : O(n)
//S.C : O(1)
class Solution {
    private int find(int[] tops, int[] bottoms, int val) {
        int swapTop = 0;
        int swapBottom = 0;
        int n = tops.length;
        for (int i = 0; i < n; i++) {
            if (tops[i] != val && bottoms[i] != val) {
                return -1;
            } else if (tops[i] != val) {
                swapTop++; // swap top
            } else if (bottoms[i] != val) {
                swapBottom++; // swap bottom
            }
        }
        return Math.min(swapTop, swapBottom);
    }

    public int minDominoRotations(int[] tops, int[] bottoms) {
        int result = Integer.MAX_VALUE;

        for (int val = 1; val <= 6; val++) {
            int swaps = find(tops, bottoms, val);
            if (swaps != -1) {
                result = Math.min(result, swaps);
            }
        }

        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
