/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=6fBEjFKQhhs
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-total-distance-traveled/description/
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    typedef long long ll;

    ll solve(int ri, int fi, vector<int>& robot, vector<int>& positions, vector<vector<ll>>& t) {
        if(ri >= robot.size()) {
            return 0; //no more distance to be covered
        }

        if(fi >= positions.size()) {
            return 1e12;
        }

        if(t[ri][fi] != -1) {
            return t[ri][fi];
        }

        ll take_current_factory = abs(robot[ri] - positions[fi]) + solve(ri+1, fi+1, robot, positions, t);
        ll skip = solve(ri, fi+1, robot, positions, t);

        return t[ri][fi] = min(take_current_factory, skip);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        //Step-1
        sort(begin(robot), end(robot));
        sort(begin(factory), end(factory));

        int m = robot.size();
        
        //Step-2 (Expand factory positions to avoid tracking of limit and easy recursion)
        vector<int> positions;
        for(int i = 0; i < factory.size(); i++) {
            int limit = factory[i][1];
            int pos   = factory[i][0];

            for(int j = 0; j < limit; j++) {
                positions.push_back(pos);
            }
        }
        int n = positions.size();
        vector<vector<ll>> t(m+1, vector<ll>(n+1, -1));

        //step-3 (solve)
        return solve(0, 0, robot, positions, t);

    }
};


//Approach-2 (Bottom Up) - Soon I will updload
/********Coming soon**********/


/**************************************************************** JAVA ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
    private long solve(int ri, int fi, List<Integer> robot, List<Integer> positions, long[][] memo) {
        if (ri >= robot.size()) {
            return 0; // No more distance to be covered
        }
        
        if (fi >= positions.size()) {
            return (long) 1e12; // Large value representing an infeasible solution
        }

        if (memo[ri][fi] != -1) {
            return memo[ri][fi];
        }

        long takeCurrentFactory = Math.abs(robot.get(ri) - positions.get(fi)) + solve(ri + 1, fi + 1, robot, positions, memo);
        long skip = solve(ri, fi + 1, robot, positions, memo);

        return memo[ri][fi] = Math.min(takeCurrentFactory, skip);
    }

    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        // Step 1: Sort robot and factory arrays
        Collections.sort(robot);
        Arrays.sort(factory, Comparator.comparingInt(a -> a[0]));

        int m = robot.size();

        // Step 2: Expand factory positions to avoid tracking of limit and easy recursion
        List<Integer> positions = new ArrayList<>();
        for (int[] f : factory) {
            int pos = f[0];
            int limit = f[1];
            for (int j = 0; j < limit; j++) {
                positions.add(pos);
            }
        }

        int n = positions.size();
        long[][] memo = new long[m + 1][n + 1];
        for (long[] row : memo) {
            Arrays.fill(row, -1);
        }

        // Step 3: Solve the problem
        return solve(0, 0, robot, positions, memo);
    }
}
