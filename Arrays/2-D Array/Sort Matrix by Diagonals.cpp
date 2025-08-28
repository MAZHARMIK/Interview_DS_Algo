/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Up445vSkzHQ
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/sort-matrix-by-diagonals/description
*/


/************************************************** C++ **************************************************/
//Approach-1 (Without Map - Simulation)
//T.C : O(n^2 * logn)
//S.C : O(n)
class Solution {
public:
    int n;
    
    void sortDiagonal(int r, int c, vector<vector<int>>& grid, bool asc) {
        vector<int> vec; //diagonal elements starting from [r][c]

        int i = r;
        int j = c;

        while(i < n && j < n) {
            vec.push_back(grid[i][j]);
            i++;
            j++;
        }

        if(asc) {
            sort(begin(vec), end(vec));
        } else {
            sort(rbegin(vec), rend(vec));
        }

        i = r;
        j = c;
        for(int &val : vec) {
            grid[i][j] = val;
            i++;
            j++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        n = grid.size();

        //Bottom Left - Non-Increasing Order
        for(int row = 0; row < n; row++) {
            sortDiagonal(row, 0, grid, false);
        }


        //Top Right - Non-Decreasing Order
        for(int col = 1; col < n; col++) {
            sortDiagonal(0, col, grid, true);
        }

        return grid;
    }
};


//Approach-2 (Using Map - (i-j) as the key)
//T.C : O(n^2 * logn)
//S.C : O(n^2) map stores all elements
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_map<int, vector<int>> mp;
        //(i-j) -> diagonal elements

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int diag = i-j;
                mp[diag].push_back(grid[i][j]);       
            }
        }

        for(auto &it : mp) {
            if(it.first >= 0) { //Key
                sort(begin(it.second), end(it.second));
            } else {
                sort(rbegin(it.second), rend(it.second));
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int diag = i-j;
                grid[i][j] = mp[diag].back();
                mp[diag].pop_back();      
            }
        }

        return grid;
    }
};



/************************************************** JAVA **************************************************/
//Approach-1 (Without Map - Simulation)
//T.C : O(n^2 * logn)
//S.C : O(n)
class Solution {
    private int n;

    private void sortDiagonal(int r, int c, int[][] grid, boolean asc) {
        List<Integer> vec = new ArrayList<>();

        int i = r, j = c;
        while (i < n && j < n) {
            vec.add(grid[i][j]);
            i++;
            j++;
        }

        if (asc) {
            Collections.sort(vec); // ascending
        } else {
            vec.sort(Collections.reverseOrder()); // descending
        }

        i = r;
        j = c;
        for (int val : vec) {
            grid[i][j] = val;
            i++;
            j++;
        }
    }

    public int[][] sortMatrix(int[][] grid) {
        n = grid.length;

        // Bottom-left diagonals → sort in non-increasing order
        for (int row = 0; row < n; row++) {
            sortDiagonal(row, 0, grid, false);
        }

        // Top-right diagonals → sort in non-decreasing order
        for (int col = 1; col < n; col++) {
            sortDiagonal(0, col, grid, true);
        }

        return grid;
    }
}


//Approach-2 (Using Map - (i-j) as the key)
//T.C : O(n^2 * logn)
//S.C : O(n^2) map stores all elements
class Solution {
    public int[][] sortMatrix(int[][] grid) {
        int n = grid.length;

        Map<Integer, List<Integer>> mp = new HashMap<>();

        // Collect diagonal elements (i - j as the key)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int diag = i - j;
                mp.computeIfAbsent(diag, k -> new ArrayList<>()).add(grid[i][j]);
            }
        }

        // Sort diagonals: non-decreasing for diag >= 0, non-increasing for diag < 0
        for (Map.Entry<Integer, List<Integer>> entry : mp.entrySet()) {
            List<Integer> list = entry.getValue();
            if (entry.getKey() >= 0) {
                Collections.sort(list); // ascending
            } else {
                list.sort(Collections.reverseOrder()); // descending
            }
        }

        // Fill grid back using elements from the map
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int diag = i - j;
                List<Integer> list = mp.get(diag);
                grid[i][j] = list.remove(list.size() - 1); // take from back
            }
        }

        return grid;
    }
}
