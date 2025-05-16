/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=SVTezUTAKMk
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/find-minimum-time-to-reach-last-room-ii
*/


/************************************************************ C++ ************************************************/
//Approach (Using Dijkstra's Algorithm)
//T.C : O(mn log(mn))
//S.C : O(mn)
class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    //{t, {i, j}}
    typedef pair<int, pair<int, int>> P;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq; //all cells will be inserted in it (m*n)

        result[0][0] = 0;
        pq.push({0, {0, 0}});
        //S.C : O(m*n)
        while(!pq.empty()) { //O(m*n * log(m*n))
            int currTime = pq.top().first;
            auto cell     = pq.top().second;
            int i = cell.first;
            int j = cell.second;

            pq.pop();
            if(i == m-1 && j == n-1) {
                return currTime;
            }

            for(auto &dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) {
                    int moveCost = (i_ + j_) % 2 == 0 ? 2 : 1;
                    int wait     = max(moveTime[i_][j_] - currTime, 0);
                    int arrTime  = currTime + wait + moveCost;

                    if(result[i_][j_] > arrTime) {
                        result[i_][j_] = arrTime;
                        pq.push({arrTime, {i_, j_}});
                    }
                    
                }
            }
        }

        return -1;

    }
};


/************************************************************ JAVA ************************************************/
//Approach (Using Dijkstra's Algorithm)
//T.C : O(mn log(mn))
//S.C : O(mn)
import java.util.*;

class Solution {

    private static final int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    static class Cell implements Comparable<Cell> {
        int time, row, col;

        Cell(int time, int row, int col) {
            this.time = time;
            this.row = row;
            this.col = col;
        }

        @Override
        public int compareTo(Cell other) {
            return Integer.compare(this.time, other.time);
        }
    }

    public int minTimeToReach(int[][] moveTime) {
        int m = moveTime.length;
        int n = moveTime[0].length;

        int[][] result = new int[m][n];
        for (int[] row : result) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        PriorityQueue<Cell> pq = new PriorityQueue<>();
        result[0][0] = 0;
        pq.offer(new Cell(0, 0, 0));

        while (!pq.isEmpty()) {
            Cell curr = pq.poll();

            if (curr.row == m - 1 && curr.col == n - 1) {
                return curr.time;
            }

            for (int[] dir : directions) {
                int newRow = curr.row + dir[0];
                int newCol = curr.col + dir[1];

                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    int moveCost = (newRow + newCol) % 2 == 0 ? 2 : 1;
                    int wait = Math.max(moveTime[newRow][newCol] - curr.time, 0);
                    int arrivalTime = curr.time + wait + moveCost;

                    if (result[newRow][newCol] > arrivalTime) {
                        result[newRow][newCol] = arrivalTime;
                        pq.offer(new Cell(arrivalTime, newRow, newCol));
                    }
                }
            }
        }

        return -1;
    }
}
