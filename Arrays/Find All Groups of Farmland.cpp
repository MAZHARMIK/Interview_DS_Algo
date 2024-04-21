/*   Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=3ZaQTCH83fY
    Company Tags                : Amazon, Microsoft
    Leetcode Link               : https://leetcode.com/problems/find-all-groups-of-farmland/
*/

/*************************************************** C++ ********************************************/
//Approach-1 (Using DFS)
//T.C : O(m*n)
//S.C : O(1) AUxiliary space and O(m*n) system stack space because of recursion
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> result;
        
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void dfs(vector<vector<int>>& land, int i, int j, int& r2, int& c2) {
        land[i][j] = 0;
        
        r2 = max(r2, i);
        c2 = max(c2, j);
        
        for(auto &dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && land[i_][j_] == 1) {
                dfs(land, i_, j_, r2, c2);
            }
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();
        
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(land[i][j] == 1) {
                    int r1 = i;
                    int c1 = j;
                    int r2 = -1;
                    int c2 = -1;
                    
                    dfs(land, i, j, r2, c2);
                    result.push_back({r1, c1, r2, c2});
                }
                
            }
        }
        
        return result;
    }
};

//Approach-2 (Using BFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> result;
        
    vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void bfs(vector<vector<int>>& land, int i, int j, int& r2, int& c2) {
        queue<pair<int, int>> que;
        que.push({i, j});
        
        while(!que.empty()) {
            
            pair<int, int> p = que.front();
            que.pop();
            
            r2 = max(r2, p.first);
            c2 = max(c2, p.second);
            
            for(auto &dir : directions) {
                int i_ = p.first  + dir[0];
                int j_ = p.second + dir[1];
                
                if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && land[i_][j_] == 1) {
                    land[i_][j_] = 0; //visited
                    que.push({i_, j_});
                }
            }
            
        }
        
        
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m = land.size();
        n = land[0].size();
        
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(land[i][j] == 1) {
                    int r1 = i;
                    int c1 = j;
                    int r2 = -1;
                    int c2 = -1;
                    
                    bfs(land, i, j, r2, c2);
                    result.push_back({r1, c1, r2, c2});
                }
                
            }
        }
        
        return result;
    }
};

//Approach-3 (Brute Force Greedy)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        
        vector<vector<int>> result;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(land[i][j] == 0) continue;
                
                //find the right most column of the current group
                int c1 = j;
                while(c1 < n && land[i][c1] == 1) {
                    c1++;
                }
                
                //find the bottom most row of the current group
                int r1 = i;
                while(r1 < m && land[r1][j] == 1) {
                    r1++;
                }
                
                c1 = c1 == 0 ?  c1 : c1-1;
                r1 = r1 == 0 ?  r1 : r1-1;
                
                result.push_back({i, j, r1, c1});
                
                
                //mark all the inbetween 1s to 0s
                for(int k = i; k <= r1; k++) {
                    for(int l = j; l <= c1; l++) {
                        land[k][l] = 0; //visited
                    }
                }
                
                
            }
        }
        
        return result;
        
        
    }
};


/*************************************************** JAVA ********************************************/
//Approach-1 (Using DFS)
//T.C : O(m*n)
//S.C : O(1) AUxiliary space and O(m*n) system stack space because of recursion
class Solution {
    int m;
    int n;
    List<int[]> result;
        
    int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void dfs(int[][] land, int i, int j, int[] r2, int[] c2) {
        land[i][j] = 0;
        
        r2[0] = Math.max(r2[0], i);
        c2[0] = Math.max(c2[0], j);
        
        for (int[] dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            
            if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && land[i_][j_] == 1) {
                dfs(land, i_, j_, r2, c2);
            }
        }
    }
    
    public int[][] findFarmland(int[][] land) {
        m = land.length;
        n = land[0].length;
        result = new ArrayList<>();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (land[i][j] == 1) {
                    int r1 = i;
                    int c1 = j;
                    int[] r2 = {-1};
                    int[] c2 = {-1};
                    
                    dfs(land, i, j, r2, c2);
                    result.add(new int[]{r1, c1, r2[0], c2[0]});
                }
                
            }
        }
        
        int[][] resArray = new int[result.size()][4];
        for (int i = 0; i < result.size(); i++) {
            resArray[i] = result.get(i);
        }
        
        return resArray;
    }
}


//Approach-2 (Using BFS)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    int m;
    int n;
    List<List<Integer>> result;
        
    int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void bfs(int[][] land, int i, int j, int[] r2, int[] c2) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{i, j});
        
        while (!queue.isEmpty()) {
            
            int[] p = queue.poll();
            
            r2[0] = Math.max(r2[0], p[0]);
            c2[0] = Math.max(c2[0], p[1]);
            
            for (int[] dir : directions) {
                int i_ = p[0] + dir[0];
                int j_ = p[1] + dir[1];
                
                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && land[i_][j_] == 1) {
                    land[i_][j_] = 0; // Mark as visited
                    queue.offer(new int[]{i_, j_});
                }
            }
        }
    }
    
    public int[][] findFarmland(int[][] land) {
        m = land.length;
        n = land[0].length;
        result = new ArrayList<>();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (land[i][j] == 1) {
                    int r1 = i;
                    int c1 = j;
                    int[] r2 = {-1};
                    int[] c2 = {-1};
                    
                    bfs(land, i, j, r2, c2);
                    result.add(List.of(r1, c1, r2[0], c2[0]));
                }
                
            }
        }
        
        int[][] resArray = new int[result.size()][4];
        for (int i = 0; i < result.size(); i++) {
            List<Integer> resList = result.get(i);
            resArray[i] = resList.stream().mapToInt(Integer::intValue).toArray();
        }
        
        return resArray;
    }
}


//Approach-3 (Brute Force Greedy)
//T.C : O(m*n)
//S.C : O(1)
