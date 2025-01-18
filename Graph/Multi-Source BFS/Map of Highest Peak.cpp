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
class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();


        vector<vector<int>> height(m, vector<int>(n, -1));

        queue<P> que;
        //Height of water cells must be 0 only
        //T.C : O(m*n)
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) { //this cell is water
                    height[i][j] = 0; //This is a source for hitting BFS
                    que.push({i, j});
                }
            }
        }

        //Apply khandani template - Multi source BFS ka
        //T.C : O(m*n)
        //S.C : O(m*n)
        while(!que.empty()) {
            int N = que.size();

            while(N--) {
                P curr = que.front();
                que.pop();

                int i = curr.first;
                int j = curr.second;

                for(auto &dir : directions) {
                    int i_ = i + dir[0];
                    int j_ = j + dir[1];

                    if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && height[i_][j_] == -1) {
                        height[i_][j_] = height[i][j] + 1;
                        que.push({i_, j_});
                    }
                }
            }
        }

        return height;


    }
};


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
