/*         Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/
*/


/********************************************************************** C++ **********************************************************************/
// Approach-1 (Using DSU)
// T.C : O(m*n * alpha(m*n))
// S.C : O(m*n)
class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) { //size of parent and size array
        parent.resize(n);
        size.resize(n);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 0; //fis count ios 0 initially for each
        }
    }

    //find the parent of x
    int find(int x) {
        if(parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]); //Path Compression
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent) { //both already in same group
            return;
        }

        if(size[x_parent] > size[y_parent]) {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        } else {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }

    void setSize(int x, int fishCount) {
        size[x] = fishCount;
    }

    int getMaxFishCount() {
        return *max_element(begin(size), end(size));
    }
};

class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int totalCells = m*n;

        DSU dsu(totalCells);
        //DSU = alpha(totalCells)

        //Initialize size array with initial fish count of each cell
        //O(m*n)
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    int idx = i*n + j;
                    dsu.setSize(idx, grid[i][j]);
                }
            }
        }
        //O(m*n * alpha(m*n))
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) {
                    int idx = i * n + j; //parent ka index milgaya
                    for(auto &dir : directions) {
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];
                        if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0) {
                            int idx_ = i_ * n + j_; //parent ka index
                            dsu.Union(idx, idx_);
                        }
                    }
                }
            }
        }

        return dsu.getMaxFishCount();

    }
};

//Approach-2 (Using BFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int bfs(int i, int j, vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        que.push({i, j});
        int fishCount = grid[i][j];
        grid[i][j] = 0;
        
        while(!que.empty()) {
            i = que.front().first;
            j = que.front().second;
            que.pop();

            for(auto &dir : directions) {
                int i_ = dir[0] + i;
                int j_ = dir[1] + j;

                if(i_ >= 0 && j_ >= 0 && i_ < m && j_ < n && grid[i_][j_] > 0) {
                    que.push({i_, j_});
                    fishCount += grid[i_][j_];
                    grid[i_][j_] = 0;
                }
            }
        }

        return fishCount;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int maxFish = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)  {
                if(grid[i][j] > 0) { //water cell found
                    maxFish = max(maxFish, bfs(i, j, grid));
                }
            }
        }

        return maxFish;
    }
};


//Approach-3 (Using DFS)
//T.C : O(m*n * alpha(m*n))
//S.C : O(m*n)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }

        int fishCount = grid[i][j];
        grid[i][j] = 0; //took the fish from this cell

        for(vector<int>& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            fishCount += dfs(i_, j_, grid);
        }

        return fishCount;

    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int maxFish = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)  {
                if(grid[i][j] > 0) { //water cell found
                    maxFish = max(maxFish, dfs(i, j, grid));
                }
            }
        }

        return maxFish;
    }
};


/********************************************************************** JAVA **********************************************************************/
// Approach-1 (Using DSU)
// T.C : O(m*n * alpha(m*n))
// S.C : O(m*n)
class DSU {
    private int[] parent;
    private int[] size;

    public DSU(int n) { // size of parent and size array
        parent = new int[n];
        size = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 0; // fish count is 0 initially for each
        }
    }

    // find the parent of x
    public int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]); // Path Compression
    }

    public void union(int x, int y) {
        int xParent = find(x);
        int yParent = find(y);

        if (xParent == yParent) { // both already in same group
            return;
        }

        if (size[xParent] > size[yParent]) {
            parent[yParent] = xParent;
            size[xParent] += size[yParent];
        } else {
            parent[xParent] = yParent;
            size[yParent] += size[xParent];
        }
    }

    public void setSize(int x, int fishCount) {
        size[x] = fishCount;
    }

    public int getMaxFishCount() {
        int maxFish = 0;
        for (int fish : size) {
            maxFish = Math.max(maxFish, fish);
        }
        return maxFish;
    }
}

class Solution {
    private final int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public int findMaxFish(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int totalCells = m * n;
        DSU dsu = new DSU(totalCells);

        // Initialize size array with initial fish count of each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    int idx = i * n + j;
                    dsu.setSize(idx, grid[i][j]);
                }
            }
        }

        // Perform union operations
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    int idx = i * n + j; // parent index
                    for (int[] dir : directions) {
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];
                        if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0) {
                            int idx_ = i_ * n + j_;
                            dsu.union(idx, idx_);
                        }
                    }
                }
            }
        }

        return dsu.getMaxFishCount();
    }
}

// Approach-2 (Using BFS)
// T.C : O(m*n)
// S.C : O(m*n)
class Solution {
    private int m, n;
    private final int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    private int bfs(int i, int j, int[][] grid) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{i, j});
        int fishCount = grid[i][j];
        grid[i][j] = 0;

        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            i = cell[0];
            j = cell[1];

            for (int[] dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if (i_ >= 0 && j_ >= 0 && i_ < m && j_ < n && grid[i_][j_] > 0) {
                    queue.offer(new int[]{i_, j_});
                    fishCount += grid[i_][j_];
                    grid[i_][j_] = 0;
                }
            }
        }

        return fishCount;
    }

    public int findMaxFish(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        int maxFish = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) { // water cell found
                    maxFish = Math.max(maxFish, bfs(i, j, grid));
                }
            }
        }

        return maxFish;
    }
}

// Approach-3 (Using DFS)
// T.C : O(m*n)
// S.C : O(1)
class Solution {
    private int m, n;
    private final int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    private int dfs(int i, int j, int[][] grid) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            return 0;
        }

        int fishCount = grid[i][j];
        grid[i][j] = 0; // Mark this cell as visited (fish collected)

        for (int[] dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            fishCount += dfs(i_, j_, grid);
        }

        return fishCount;
    }

    public int findMaxFish(int[][] grid) {
        m = grid.length;
        n = grid[0].length;

        int maxFish = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) { // Fish cell found
                    maxFish = Math.max(maxFish, dfs(i, j, grid));
                }
            }
        }

        return maxFish;
    }
}
