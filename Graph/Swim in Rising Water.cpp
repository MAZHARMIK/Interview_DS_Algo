/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/swim-in-rising-water/
    
    The question can be stated as follows: there are multiple paths from (0, 0) to (n - 1, n - 1),
    each path has a max value from all of the steps .
    And what is smallest of that value res in the path among all of them ?
    
    Similar Question - Leetcode : 1102 (Path With Maximum Minimum Value) (Premium Question)
*/


/**************************************************************** C++ ************************************************************************/
//Approach -1 (Binary Search + BFS) Time : O(n^2 * log(n))
//NOTE - In the paths, we have to find the maximum from the minimum path (Minimize the Maximum Hints towards Binary Search)
//T.C : O(n^2 * log(n^2)) = O(n^2 log n)
//S.C : O(n^2) for visited
class Solution {
public:
    int n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool visited[50][50];
    bool reachable(vector<vector<int>>& grid, int i, int j, int mid) {
        if(i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] > mid)
            return false;
        
        visited[i][j] = true;
        
        if(i == n-1 && j == n-1)
            return true;
        
        for(vector<int> &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            if(reachable(grid, new_i, new_j, mid))
                return true;
        }
        
        return false;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        
        int l = grid[0][0], r = n*n-1;
        int result = 0;

        while(l <= r) {
            int mid = l + (r-l)/2;
            memset(visited, 0, sizeof(visited));
            
            if(reachable(grid, 0, 0, mid)) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        
        return result;
    }
};



//Approach-2 Dijkstra's Algo (priority_queue) Time : O(n^2 * log(n))
//Single Source, Single Destination, We have to find the shortest path to reach m-1, n-1 and in the process, calculate result
//T.C : O(n^2 * log(n^2)) = O(n^2 log n) --- Because TC of Dijkstra if E*logV where E = number of edges, V = number of vertices
//S.C : O(n^2) for visited
class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    using P = pair<int, pair<int, int>>; // {time, {i, j}}

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n, vector<int>(n, INT_MAX));
        
        priority_queue<P, vector<P>, greater<P>> pq; // min-heap by time
        result[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        while (!pq.empty()) {
            int currTime = pq.top().first;
            auto cell = pq.top().second;
            int i = cell.first;
            int j = cell.second;
            pq.pop();

            // if we reached destination, return time
            if (i == n - 1 && j == n - 1)
                return currTime;

            // Skip if we’ve already found a better path
            if (currTime > result[i][j]) continue;

            for (auto& dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < n) {
                    int nextTime = max(currTime, grid[i_][j_]);

                    if (nextTime < result[i_][j_]) {
                        result[i_][j_] = nextTime;
                        pq.push({nextTime, {i_, j_}});
                    }
                }
            }
        }

        return -1; // should never reach here
    }
};




/**************************************************************** JAVA ************************************************************************/
//Approach -1 (Binary Search + DFS) Time : O(n^2 * log(n))
//NOTE - In the paths, we have to find the maximum from the minimum path (Minimize the Maximum hints towards Binary Search)
//T.C : O(n^2 * log(n^2)) = O(n^2 log n)
//S.C : O(n^2) for visited
class Solution {
    int n;
    int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    boolean[][] visited;

    private boolean reachable(int[][] grid, int i, int j, int mid) {
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] > mid)
            return false;

        visited[i][j] = true;

        if (i == n - 1 && j == n - 1)
            return true;

        for (int[] dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if (reachable(grid, new_i, new_j, mid))
                return true;
        }

        return false;
    }

    public int swimInWater(int[][] grid) {
        n = grid.length;

        int l = grid[0][0], r = n * n - 1;
        int result = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            visited = new boolean[n][n];

            if (reachable(grid, 0, 0, mid)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }
}




//Approach-2 Dijkstra's Algo (PriorityQueue) Time : O(n^2 * log(n))
//Single Source, Single Destination — find the shortest path to reach n-1, n-1
//T.C : O(n^2 * log(n^2)) = O(n^2 log n) because Dijkstra runs in O(E log V)
//S.C : O(n^2) for result + PQ
class Solution {
    int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int[][] result = new int[n][n];
        for (int[] row : result)
            Arrays.fill(row, Integer.MAX_VALUE);

        // Min-heap based on current time
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        result[0][0] = grid[0][0];
        pq.offer(new int[]{grid[0][0], 0, 0}); // {time, i, j}

        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            int currTime = curr[0];
            int i = curr[1];
            int j = curr[2];

            if (i == n - 1 && j == n - 1)
                return currTime;

            if (currTime > result[i][j])
                continue;

            for (int[] dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < n) {
                    int nextTime = Math.max(currTime, grid[i_][j_]);
                    if (nextTime < result[i_][j_]) {
                        result[i_][j_] = nextTime;
                        pq.offer(new int[]{nextTime, i_, j_});
                    }
                }
            }
        }

        return -1; // should never reach here
    }
}
