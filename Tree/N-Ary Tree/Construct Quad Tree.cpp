/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=tzABQFpl6Mk
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/construct-quad-tree/
*/

/*
  See the youtube video above for explanation of Time & Space Complexity
  Time  - O(n^2 * logn)
  Space - O(log(n))
*/
class Solution {
public:
    bool isAllSame(vector<vector<int>>& grid, int x, int y, int n) {
        int val = grid[x][y];
        
        for(int i = x; i < x + n; i++) {
            for(int j = y; j< y + n; j++) {
                if(grid[i][j] != val)
                    return false;
            }
        }
        
        return true;
    }
    
    Node* solve(vector<vector<int>> &grid, int x, int y, int n) {
        if(isAllSame(grid, x, y, n)) {
            return new Node(grid[x][y], true);
        } else {
            Node* root = new Node(1, false);
            
            root->topLeft = solve(grid, x, y, n/2);
            root->topRight = solve(grid, x, y+n/2, n/2);
            root->bottomLeft = solve(grid, x+n/2, y, n/2);
            root->bottomRight = solve(grid, x+n/2, y+n/2, n/2);
            
            return root;
        }
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};
