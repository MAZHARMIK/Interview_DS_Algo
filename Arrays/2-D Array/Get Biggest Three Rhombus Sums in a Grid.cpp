/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=37IXS3SiI8c
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/
*/


/************************************************** C++ **************************************************/
//Approach-1 (Brute Force)
//T.C : O(m*n * min(m, n)^2)
//S.C : O(1)
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int> st;

        auto addToSet = [&](int val) {
            st.insert(val);
            if (st.size() > 3)
                st.erase(begin(st));
        };

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                addToSet(grid[r][c]);   //every cell is valid for rohmbus of side = 0

                for (int side = 1; r-side >= 0 && r+side < m && c-side >= 0 && c+side < n; side++) {

                    int sum = 0;

                    for (int k = 0; k < side; k++) {
                        sum += grid[r - side + k][c + k];   // top to right corner
                        sum += grid[r + k][c + side - k];   // right to bottom corner
                        sum += grid[r + side - k][c - k];   // bottom to left corner
                        sum += grid[r - k][c - side + k];   // left to top corner
                    }

                    addToSet(sum);
                }
            }
        }

        return vector<int>(rbegin(st), rend(st));
    }
};




//Approach-2 (Using Diagonal Prefix Sum to get rid of innermost for loop)
//T.C : O(m*n * min(m, n))
//S.C : O(1)
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        //left to right diagonals prefix
        vector<vector<int>> d1(m, vector<int>(n));

        //right to left diagonals prefix
        vector<vector<int>> d2(m, vector<int>(n));

        // building d1
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                d1[i][j] = grid[i][j];
                if(i > 0 && j > 0)
                    d1[i][j] += d1[i-1][j-1];
            }
        }

        // building d2
        for(int i = 0; i < m; i++){
            for(int j = n-1; j >= 0; j--){
                d2[i][j] = grid[i][j];
                if(i > 0 && j+1 < n)
                    d2[i][j] += d2[i-1][j+1];
            }
        }

        set<int> st;

        auto addToSet = [&](int val){
            st.insert(val);
            if(st.size() > 3)
                st.erase(st.begin());
        };

        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){

                // rhombus with side = 0
                addToSet(grid[r][c]);

                for(int side = 1; r-side >= 0 && r+side < m && c-side >= 0 && c+side < n; side++) {
                    int sum = 0;

                    int top_r = r-side, top_c = c;
                    int right_r = r, right_c = c+side;
                    int bottom_r = r+side, bottom_c = c;
                    int left_r = r, left_c = c-side;

                    // top to right corner
                    sum += d1[right_r][right_c];
                    if(top_r-1 >= 0 && top_c-1 >= 0)
                        sum -= d1[top_r-1][top_c-1];

                    // right to bottom corner
                    sum += d2[bottom_r][bottom_c];
                    if(right_r-1 >= 0 && right_c+1 < n)
                        sum -= d2[right_r-1][right_c+1];

                    // bottom to left corner
                    sum += d1[bottom_r][bottom_c];
                    if(left_r-1 >= 0 && left_c-1 >= 0)
                        sum -= d1[left_r-1][left_c-1];

                    // left to top corner
                    sum += d2[left_r][left_c];
                    if(top_r-1 >= 0 && top_c+1 < n)
                        sum -= d2[top_r-1][top_c+1];

                    // remove corners counted twice
                    sum -= grid[top_r][top_c];
                    sum -= grid[right_r][right_c];
                    sum -= grid[bottom_r][bottom_c];
                    sum -= grid[left_r][left_c];

                    addToSet(sum);
                }
            }
        }

        return vector<int>(st.rbegin(), st.rend());
    }
};



/************************************************** Java **************************************************/
//Approach-1 (Brute Force)
//T.C : O(m*n * min(m, n)^2)
//S.C : O(1)
class Solution {
    public int[] getBiggestThree(int[][] grid) {

        int m = grid.length;
        int n = grid[0].length;

        TreeSet<Integer> st = new TreeSet<>();

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                addToSet(st, grid[r][c]); // every cell is valid for rhombus of side = 0

                for (int side = 1; r-side >= 0 && r+side < m && c-side >= 0 && c+side < n; side++) {

                    int sum = 0;

                    for (int k = 0; k < side; k++) {
                        sum += grid[r - side + k][c + k];   // top to right corner
                        sum += grid[r + k][c + side - k];   // right to bottom corner
                        sum += grid[r + side - k][c - k];   // bottom to left corner
                        sum += grid[r - k][c - side + k];   // left to top corner
                    }

                    addToSet(st, sum);
                }
            }
        }

        return buildAnswer(st);
    }

    private void addToSet(TreeSet<Integer> st, int val) {
        st.add(val);
        if (st.size() > 3)
            st.pollFirst();
    }

    private int[] buildAnswer(TreeSet<Integer> st) {
        int[] res = new int[st.size()];
        int idx = 0;

        Iterator<Integer> it = st.descendingIterator();
        while (it.hasNext())
            res[idx++] = it.next();

        return res;
    }
}




//Approach-2 (Using Diagonal Prefix Sum to get rid of innermost for loop)
//T.C : O(m*n * min(m, n))
//S.C : O(m*n)
class Solution {
    public int[] getBiggestThree(int[][] grid) {

        int m = grid.length;
        int n = grid[0].length;

        // left to right diagonals prefix
        int[][] d1 = new int[m][n];

        // right to left diagonals prefix
        int[][] d2 = new int[m][n];

        // building d1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                d1[i][j] = grid[i][j];
                if (i > 0 && j > 0)
                    d1[i][j] += d1[i-1][j-1];
            }
        }

        // building d2
        for (int i = 0; i < m; i++) {
            for (int j = n-1; j >= 0; j--) {
                d2[i][j] = grid[i][j];
                if (i > 0 && j+1 < n)
                    d2[i][j] += d2[i-1][j+1];
            }
        }

        TreeSet<Integer> st = new TreeSet<>();

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                // rhombus with side = 0
                addToSet(st, grid[r][c]);

                for (int side = 1; r-side >= 0 && r+side < m && c-side >= 0 && c+side < n; side++) {

                    int sum = 0;

                    int top_r = r-side, top_c = c;
                    int right_r = r, right_c = c+side;
                    int bottom_r = r+side, bottom_c = c;
                    int left_r = r, left_c = c-side;

                    // top to right corner
                    sum += d1[right_r][right_c];
                    if (top_r-1 >= 0 && top_c-1 >= 0)
                        sum -= d1[top_r-1][top_c-1];

                    // right to bottom corner
                    sum += d2[bottom_r][bottom_c];
                    if (right_r-1 >= 0 && right_c+1 < n)
                        sum -= d2[right_r-1][right_c+1];

                    // bottom to left corner
                    sum += d1[bottom_r][bottom_c];
                    if (left_r-1 >= 0 && left_c-1 >= 0)
                        sum -= d1[left_r-1][left_c-1];

                    // left to top corner
                    sum += d2[left_r][left_c];
                    if (top_r-1 >= 0 && top_c+1 < n)
                        sum -= d2[top_r-1][top_c+1];

                    // remove corners counted twice
                    sum -= grid[top_r][top_c];
                    sum -= grid[right_r][right_c];
                    sum -= grid[bottom_r][bottom_c];
                    sum -= grid[left_r][left_c];

                    addToSet(st, sum);
                }
            }
        }

        return buildAnswer(st);
    }

    private void addToSet(TreeSet<Integer> st, int val) {
        st.add(val);
        if (st.size() > 3)
            st.pollFirst();
    }

    private int[] buildAnswer(TreeSet<Integer> st) {
        int[] res = new int[st.size()];
        int idx = 0;

        Iterator<Integer> it = st.descendingIterator();
        while (it.hasNext())
            res[idx++] = it.next();

        return res;
    }
}
