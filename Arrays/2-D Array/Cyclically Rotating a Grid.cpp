/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/cyclically-rotating-a-grid
*/


/************************************************** C++ **************************************************/
//Approach - Straight forward iterate layer by layer, rotate and put
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2; //each layer require two rows and two columns

        for (int layer = 0; layer < layers; layer++) {

            vector<int> nums;

            int top = layer;
            int bottom = m - layer - 1;
            int left = layer;
            int right = n - layer - 1;

            // Top row (left -> right)
            for (int j = left; j <= right; j++) {
                nums.push_back(grid[top][j]);
            }

            // Right column (top -> bottom)
            // Skip corners because they are already included in top/bottom rows
            for (int i = top + 1; i <= bottom - 1; i++) {
                nums.push_back(grid[i][right]);
            }

            // Bottom row (right -> left)
            for (int j = right; j >= left; j--) {
                nums.push_back(grid[bottom][j]);
            }

            // Left column (bottom -> top)
            // Skip corners because they are already included in top/bottom rows
            for (int i = bottom - 1; i >= top + 1; i--) {
                nums.push_back(grid[i][left]);
            }

            int len = nums.size();

            int nomralized_k = k % len;

            rotate(begin(nums), begin(nums) + nomralized_k, end(nums));

            int idx = 0;

            for (int j = left; j <= right; j++) {
                grid[top][j] = nums[idx++];
            }

            for (int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = nums[idx++];
            }

            for (int j = right; j >= left; j--) {
                grid[bottom][j] = nums[idx++];
            }

            for (int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = nums[idx++];
            }
        }

        return grid;
    }
};




/************************************************** JAVA **************************************************/
//Approach - Straight forward iterate layer by layer, rotate and put
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
    public int[][] rotateGrid(int[][] grid, int k) {

        int m = grid.length;
        int n = grid[0].length;

        // each layer requires two rows and two columns
        int layers = Math.min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {

            List<Integer> nums = new ArrayList<>();

            int top = layer;
            int bottom = m - layer - 1;
            int left = layer;
            int right = n - layer - 1;

            // Top row (left -> right)
            for (int j = left; j <= right; j++) {
                nums.add(grid[top][j]);
            }

            // Right column (top -> bottom)
            // Skip corners because they are already included
            for (int i = top + 1; i <= bottom - 1; i++) {
                nums.add(grid[i][right]);
            }

            // Bottom row (right -> left)
            for (int j = right; j >= left; j--) {
                nums.add(grid[bottom][j]);
            }

            // Left column (bottom -> top)
            // Skip corners because they are already included
            for (int i = bottom - 1; i >= top + 1; i--) {
                nums.add(grid[i][left]);
            }

            int len = nums.size();

            int normalizedK = k % len;

            // Rotate left by normalizedK
            Collections.rotate(nums, -normalizedK);

            int idx = 0;

            // Top row
            for (int j = left; j <= right; j++) {
                grid[top][j] = nums.get(idx++);
            }

            // Right column
            for (int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = nums.get(idx++);
            }

            // Bottom row
            for (int j = right; j >= left; j--) {
                grid[bottom][j] = nums.get(idx++);
            }

            // Left column
            for (int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = nums.get(idx++);
            }
        }

        return grid;
    }
}
