/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=nQe5OBs0FgQ
    Company Tags                : Google, Microsoft
    Leetcode Link               : https://leetcode.com/problems/map-of-highest-peak/description/
*/


/************************************************************ C++ ************************************************/
//Approach - Using Multi-Source BFS
//T.C : O(m * n) , We will visit all cells once
//S.C : O(m * n), in worst case queue will contain all the cells
import java.util.*;

class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int m = isWater.length;
        int n = isWater[0].length;
        int[][] height = new int[m][n];
        Queue<int[]> queue = new LinkedList<>();
        
        // Initialize the queue with all water cells and set their height to 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    queue.offer(new int[]{i, j});
                    height[i][j] = 0;
                } else {
                    height[i][j] = -1; // Mark unvisited land cells
                }
            }
        }
        
        // Define directions for moving in the grid
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Multi-Source BFS with level-based processing
        while (!queue.isEmpty()) {
            int size = queue.size(); // Number of nodes at the current level
            while (size-- > 0) {
                int[] curr = queue.poll();
                int i = curr[0];
                int j = curr[1];
                
                for (int[] dir : directions) {
                    int newI = i + dir[0];
                    int newJ = j + dir[1];
                    
                    // Check if the new cell is within bounds and unvisited
                    if (newI >= 0 && newI < m && newJ >= 0 && newJ < n && height[newI][newJ] == -1) {
                        height[newI][newJ] = height[i][j] + 1;
                        queue.offer(new int[]{newI, newJ});
                    }
                }
            }
        }
        
        return height;
    }
}


/************************************************************ JAVA ************************************************/
//Approach - Using Multi-Source BFS
//T.C : O(m * n) , We will visit all cells once
//S.C : O(m * n), in worst case queue will contain all the cells
class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int m = isWater.length;
        int n = isWater[0].length;
        int[][] height = new int[m][n];
        Queue<int[]> que = new LinkedList<>();
        
        // Initialize the queue with all water cells and set their height to 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    que.offer(new int[]{i, j});
                    height[i][j] = 0;
                } else {
                    height[i][j] = -1; // Mark unvisited land cells
                }
            }
        }
        
        //Noe perform Multi-Source BFS
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!que.isEmpty()) {
            int N = que.size();
            while(N-- > 0) {
                int[] curr = que.poll();
                int i = curr[0];
                int j = curr[1];

                for(int[] dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && height[i_][j_] == -1) {
                        height[i_][j_] = height[i][j] + 1;
                        que.offer(new int[]{i_, j_});
                    }
                }
            }
        }

        return height;       
    }
}
