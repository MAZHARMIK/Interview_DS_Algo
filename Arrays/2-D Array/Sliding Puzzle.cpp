/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Airbnb
    Leetcode Link               : https://leetcode.com/problems/sliding-puzzle/description
*/


/******************************************** C++ ********************************************/
//Approach - BFS (asking for minimum moves - and problem different states)
//T.C : O(6!) : The puzzle has 6 ! = 720 possible permutations of the board, as there are 6 tiles, including the blank tile (0). In the worst case, BFS explores all permutations.
//S.C : O(6!) All states are stored in map
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string start = "";
        
        // Convert 2D board to a string
        for (auto& row : board) {
            for (int num : row) {
                start += to_string(num);
            }
        }
        
        unordered_set<string> visited;
        vector<vector<int>> dirs = {
            {1, 3},        // 0 can swap with 1 and 3
            {0, 2, 4},     // 1 can swap with 0, 2, and 4
            {1, 5},        // 2 can swap with 1 and 5
            {0, 4},        // 3 can swap with 0 and 4
            {1, 3, 5},     // 4 can swap with 1, 3, and 5
            {2, 4}         // 5 can swap with 2 and 4
        };

        queue<string> que;
        que.push(start);
        visited.insert(start);

        int steps = 0;

        while (!que.empty()) {
            int n = que.size();
            while (n--) {
                string curr = que.front();
                que.pop();

                // Check if we reached the target state
                if (curr == target) {
                    return steps;
                }

                // Find the index of '0' and explore its neighbors
                int zeroIndex = curr.find('0');
                for (int dir : dirs[zeroIndex]) {
                    string next = curr;
                    swap(next[zeroIndex], next[dir]);
                    if (!visited.count(next)) {
                        visited.insert(next);
                        que.push(next);
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};


/************************************************************ JAVA ************************************************************/
//Approach - BFS (asking for minimum moves - and problem different states)
//T.C : O(row*col)
//S.C : O(1)
class Solution {
    public int slidingPuzzle(int[][] board) {
        String target = "123450";
        StringBuilder start = new StringBuilder();
        
        // Convert the 2D board to a string
        for (int[] row : board) {
            for (int num : row) {
                start.append(num);
            }
        }
        
        // Directions for swapping positions
        int[][] dirs = {
            {1, 3},        // 0 can swap with 1 and 3
            {0, 2, 4},     // 1 can swap with 0, 2, and 4
            {1, 5},        // 2 can swap with 1 and 5
            {0, 4},        // 3 can swap with 0 and 4
            {1, 3, 5},     // 4 can swap with 1, 3, and 5
            {2, 4}         // 5 can swap with 2 and 4
        };
        
        Set<String> visited = new HashSet<>();
        Queue<String> queue = new LinkedList<>();
        
        queue.offer(start.toString());
        visited.add(start.toString());
        
        int steps = 0;
        
        while (!queue.isEmpty()) {
            int n = queue.size();
            for (int i = 0; i < n; i++) {
                String curr = queue.poll();
                
                if (curr.equals(target)) {
                    return steps;
                }
                
                int zeroIndex = curr.indexOf('0');
                
                for (int dir : dirs[zeroIndex]) {
                    char[] next = curr.toCharArray();
                    // Swap the 0 with its adjacent position
                    char temp = next[zeroIndex];
                    next[zeroIndex] = next[dir];
                    next[dir] = temp;
                    
                    String nextStr = new String(next);
                    
                    if (!visited.contains(nextStr)) {
                        visited.add(nextStr);
                        queue.offer(nextStr);
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
}
