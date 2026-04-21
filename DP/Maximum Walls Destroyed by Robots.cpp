/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=niOPy-UHahQ
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-walls-destroyed-by-robots/description/
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Recursion + Memoization + Binary Search)
//T.C : O(n * log(w) + nlogn + wlogw), n = robots.size(), w = walls.size()
//S.C : O(n)
class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> t;

    int countWalls(vector<int>& walls, int l, int r) {
        int left  = lower_bound(begin(walls), end(walls), l) - begin(walls);
        int right = upper_bound(begin(walls), end(walls), r) - begin(walls);

        return right - left;

    }

    int solve(vector<int>& walls, vector<P>& roboDist, vector<P>& range, int i, int prevDir) {

        if(i == roboDist.size())
            return 0;
        
        if(t[i][prevDir] != -1)
            return t[i][prevDir];

        int leftStart = range[i].first;

        if(prevDir == 1) { //prev robot fired bullet rtowards right
            leftStart = max(leftStart, range[i-1].second + 1);
        }

        int leftTake = countWalls(walls, leftStart, roboDist[i].first) 
                        + solve(walls, roboDist, range, i+1, 0);
                    
        int rightTake = countWalls(walls, roboDist[i].first, range[i].second) 
                        + solve(walls, roboDist, range, i+1, 1);

        
        return t[i][prevDir] = max(leftTake, rightTake);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();

        vector<P> roboDist(n);
        for (int i = 0; i < n; i++) {
            roboDist[i] = {robots[i], distance[i]};
        }

        sort(begin(roboDist), end(roboDist));
        sort(begin(walls), end(walls));

        //Prepare range vector for each robot
        vector<P> range(n);

        for(int i = 0; i < n; i++) {
            int pos = roboDist[i].first;
            int d   = roboDist[i].second;

            int leftLimit  = (i == 0)   ? 1   : roboDist[i-1].first+1;
            int rightLimit = (i == n-1) ? 1e9 : roboDist[i+1].first-1;

            int L = max(pos - d, leftLimit);
            int R = min(pos + d, rightLimit);

            range[i] = {L, R};
        }

        t.assign(n+1, vector<int>(2, -1));

        //prev = 0/1 (previious robot hit buttlet to left/right)
        return solve(walls, roboDist, range, 0, 0);
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach (Recursion + Memoization + Binary Search)
//T.C : O(n * log(w) + nlogn + wlogw), n = robots.size(), w = walls.size()
//S.C : O(n)
class Solution {

    int[][] t;

    // Count walls in range [L, R]
    int countWalls(int[] walls, int L, int R) {
        int left = lowerBound(walls, L);
        int right = upperBound(walls, R);
        return right - left;
    }

    // Binary search: first index >= target
    int lowerBound(int[] arr, int target) {
        int l = 0, r = arr.length;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    // Binary search: first index > target
    int upperBound(int[] arr, int target) {
        int l = 0, r = arr.length;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] > target) r = mid;
            else l = mid + 1;
        }
        return l;
    }

    int solve(int[] walls, int[][] roboDist, int[][] range, int i, int prevDir) {

        if (i == roboDist.length) return 0;

        if (t[i][prevDir] != -1) return t[i][prevDir];

        int leftStart = range[i][0];

        // If previous robot shot RIGHT
        if (prevDir == 1 && i > 0) {
            leftStart = Math.max(leftStart, range[i - 1][1] + 1);
        }

        // shoot LEFT
        int leftTake = countWalls(walls, leftStart, roboDist[i][0]) +
                       solve(walls, roboDist, range, i + 1, 0);

        // shoot RIGHT
        int rightTake = countWalls(walls, roboDist[i][0], range[i][1]) +
                        solve(walls, roboDist, range, i + 1, 1);

        return t[i][prevDir] = Math.max(leftTake, rightTake);
    }

    public int maxWalls(int[] robots, int[] distance, int[] walls) {

        int n = robots.length;

        // Combine robots + distance
        int[][] roboDist = new int[n][2];
        for (int i = 0; i < n; i++) {
            roboDist[i][0] = robots[i];
            roboDist[i][1] = distance[i];
        }

        // Sort by robot position
        Arrays.sort(roboDist, (a, b) -> a[0] - b[0]);

        Arrays.sort(walls);

        // Prepare range
        int[][] range = new int[n][2];

        for (int i = 0; i < n; i++) {
            int pos = roboDist[i][0];
            int d = roboDist[i][1];

            int leftLimit  = (i == 0) ? 1 : roboDist[i - 1][0] + 1;
            int rightLimit = (i == n - 1) ? (int)1e9 : roboDist[i + 1][0] - 1;

            int L = Math.max(pos - d, leftLimit);
            int R = Math.min(pos + d, rightLimit);

            range[i][0] = L;
            range[i][1] = R;
        }

        t = new int[n][2];
        for (int[] row : t) Arrays.fill(row, -1);

        return solve(walls, roboDist, range, 0, 0);
    }
}
