/* 			Scroll below to see JAVA code also						/*
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=dUkdAjY23p8
    Company Tags    		    : Microsoft, Google
    Leetcode Link   		    : https://leetcode.com/problems/furthest-building-you-can-reach/
    Similar Problem 		    : https://leetcode.com/problems/minimum-number-of-refueling-stops/
*/

//NOTE - For Heap Approach (Lazy Greedy) see my YouTube of the code in the Github Link below : 
//Link to Lazy Greedy Approach - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Heap/Furthest%20Building%20You%20Can%20Reach.cpp

/***************************************************************** C++ *****************************************************************/
//MEMORY LIMIT EXCEED - Not Accepted
//T.C : Without Memoization - O(2^(bricks + ladders)), With memoization - O(bricks * ladders)
//S.C : O(bricks * ladders) when we use memoization dp array
class Solution {
public:
    int n;
    vector<vector<int>> t;
    
    int solve(int idx, vector<int> &heights, int bricks, int ladders) {
        if(idx == n - 1) //we reached the last building and no need to move further
            return 0;
        
        if(t[bricks][ladders] != -1)
            return t[bricks][ladders];
        
        if(heights[idx] >= heights[idx + 1]) { //No need to use anything. Just move ahead
            t[bricks][ladders] = 1 + solve(idx+1, heights, bricks, ladders);
        } else {
            
            int byBrick  = 0;
            int byLadder = 0;
            if(bricks >= heights[idx + 1] - heights[idx])
                byBrick  = 1 + solve(idx+1, heights, bricks - (heights[idx+1] - heights[idx]), ladders);
            
            if(ladders > 0)
                byLadder = 1 + solve(idx+1, heights, bricks, ladders - 1);
            
            t[bricks][ladders] = max(byBrick, byLadder);
        }
        
        return t[bricks][ladders];
    }
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        n = heights.size(); 
        
        t = vector<vector<int>>(bricks + 1, vector<int>(ladders + 1, -1));

        return solve(0, heights, bricks, ladders);
    }
};



/***************************************************************** JAVA *****************************************************************/
//MEMORY LIMIT EXCEED - Not Accepted
//T.C : Without Memoization - O(2^(bricks + ladders)), With memoization - O(bricks * ladders)
//S.C : O(bricks * ladders) when we use memoization dp array
public class Solution {
    private int n;
    private int[][] t;

    private int solve(int idx, int[] heights, int bricks, int ladders) {
        if (idx == n - 1) // we reached the last building and no need to move further
            return 0;

        if (t[bricks][ladders] != -1)
            return t[bricks][ladders];

        if (heights[idx] >= heights[idx + 1]) { // No need to use anything. Just move ahead
            t[bricks][ladders] = 1 + solve(idx + 1, heights, bricks, ladders);
        } else {

            int byBrick = 0;
            int byLadder = 0;
            if (bricks >= heights[idx + 1] - heights[idx])
                byBrick = 1 + solve(idx + 1, heights, bricks - (heights[idx + 1] - heights[idx]), ladders);

            if (ladders > 0)
                byLadder = 1 + solve(idx + 1, heights, bricks, ladders - 1);

            t[bricks][ladders] = Math.max(byBrick, byLadder);
        }

        return t[bricks][ladders];
    }

    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        n = heights.length;

        t = new int[bricks + 1][ladders + 1];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        return solve(0, heights, bricks, ladders);
    }
}
