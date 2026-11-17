/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO LINK : 
    Company Tags          : Will update later
    Leetcode Link         : https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes
*/


/*********************************************************** C++ **************************************************/
//Approach-1 (Recursion Memoization)
//T.C : O(n^3 * div(n) + n^2 * k) ~ O(n^3)
//S.C : O(n^2) (costMemo n*n + memo n*k + recursion stack O(k))
class Solution {
public:
    int n;
    string str;

    vector<vector<int>> costMemo;
    vector<vector<int>> memo;

    int getCost(int i, int j) {
        int len = j - i + 1;

        if(costMemo[i][j] != -1) {
            return costMemo[i][j];
        }

        int minCost = INT_MAX;

        for(int d = 1; d < len; d++) {
            if(len % d != 0)
                continue;
            
            int cost = 0;
            for(int group = 0; group < d; group++) { //for d, we will have d groups
                int l = i + group;
                int r = l + (len/d - 1) * d;

                while(l < r) {
                    if(str[l] != str[r])
                        cost++;
                    
                    l += d;
                    r -= d;
                }
            }

            minCost = min(minCost, cost);
        }

        return costMemo[i][j] = minCost;
    }

    int solve(int start, int k) {
        if(k == 0) {
            if(start == n)
                return 0;
            
            return INT_MAX;
        }

        //early return
        if(start + 2*k > n)
            return INT_MAX;

        if(memo[start][k] != -1) {
            return memo[start][k];
        }
        
        int result = INT_MAX;

        for(int end = start+1; end < n; end++) {
            //start...end -> 1 piece
            int remainingCost = solve(end+1, k-1);

            if(remainingCost == INT_MAX) {
                continue;
            }

            result = min(result, getCost(start, end) + remainingCost);
        }

        return memo[start][k] = result;
    }

    int minimumChanges(string s, int k) {
        n = s.length();
        str = s;

        costMemo.assign(n+1, vector<int>(n+1, -1)); //n*n
        memo.assign(n+1, vector<int>(k+1, -1));

        return solve(0, k);
    }
};



//Approach-2 (Bottom Up)
//T.C : O(n^3 * div(n) + n^2 * k) ~ O(n^3)
//S.C : O(n^2) (costMemo n*n + memo n*k)
class Solution {
public:
    int n;
    string str;

    vector<vector<int>> costMemo;
    vector<vector<int>> memo;

    int getCost(int i, int j) {
        int len = j - i + 1;

        int minCost = INT_MAX;

        for(int d = 1; d < len; d++) {
            if(len % d != 0)
                continue;
            
            int cost = 0;
            for(int group = 0; group < d; group++) { //for d, we will have d groups
                int l = i + group;
                int r = l + (len/d - 1) * d;

                while(l < r) {
                    if(str[l] != str[r])
                        cost++;
                    
                    l += d;
                    r -= d;
                }
            }

            minCost = min(minCost, cost);
        }

        return minCost;
    }

    int minimumChanges(string s, int k) {
        n = s.length();
        str = s;

        costMemo.assign(n+1, vector<int>(n+1, INT_MAX)); //n*n
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                costMemo[i][j] = getCost(i, j);
            }
        }

        memo.assign(n+1, vector<int>(k+1, INT_MAX));

        memo[n][0] = 0;

        for(int start = n; start >= 0; start--) {
            for(int pieces = 1; pieces <= k; pieces++) {
                if(start + 2*pieces > n)
                    continue;
                
                int result = INT_MAX;

                for(int end = start+1; end < n; end++) {
                    int remainCost = memo[end+1][pieces-1];

                    if(remainCost == INT_MAX)
                        continue;
                    
                    result = min(result, costMemo[start][end] + remainCost);
                }

                memo[start][pieces] = result;
            }
        }

        return memo[0][k];
    }
};



/*********************************************************** JAVA **************************************************/
//Approach-1 (Recursion Memoization)
//T.C : O(n^3 * div(n) + n^2 * k) ~ O(n^3)
//S.C : O(n^2) (costMemo n*n + memo n*k + recursion stack O(k))
class Solution {
    int n;
    String str;
    int[][] costMemo;
    int[][] memo;

    private int getCost(int i, int j) {
        int len = j - i + 1;

        if (costMemo[i][j] != -1) {
            return costMemo[i][j];
        }

        int minCost = Integer.MAX_VALUE;

        for (int d = 1; d < len; d++) {
            if (len % d != 0)
                continue;

            int cost = 0;
            for (int group = 0; group < d; group++) { // for d, we will have d groups
                int l = i + group;
                int r = l + (len / d - 1) * d;

                while (l < r) {
                    if (str.charAt(l) != str.charAt(r))
                        cost++;

                    l += d;
                    r -= d;
                }
            }

            minCost = Math.min(minCost, cost);
        }

        return costMemo[i][j] = minCost;
    }

    private int solve(int start, int k) {
        if (k == 0) {
            if (start == n)
                return 0;

            return Integer.MAX_VALUE;
        }

        // early return
        if (start + 2 * k > n)
            return Integer.MAX_VALUE;

        if (memo[start][k] != -1) {
            return memo[start][k];
        }

        int result = Integer.MAX_VALUE;

        for (int end = start + 1; end < n; end++) {
            // start...end -> 1 piece
            int remainingCost = solve(end + 1, k - 1);

            if (remainingCost == Integer.MAX_VALUE) {
                continue;
            }

            result = Math.min(result, getCost(start, end) + remainingCost);
        }

        return memo[start][k] = result;
    }

    public int minimumChanges(String s, int k) {
        n = s.length();
        str = s;

        costMemo = new int[n + 1][n + 1];
        for (int[] row : costMemo)
            Arrays.fill(row, -1);

        memo = new int[n + 1][k + 1];
        for (int[] row : memo)
            Arrays.fill(row, -1);

        return solve(0, k);
    }
}


//Approach-2 (Bottom Up)
//T.C : O(n^3 * div(n) + n^2 * k) ~ O(n^3)
//S.C : O(n^2) (costMemo n*n + memo n*k)
class Solution {
    int n;
    String str;
    int[][] costMemo;
    int[][] memo;

    private int getCost(int i, int j) {
        int len = j - i + 1;

        int minCost = Integer.MAX_VALUE;

        for (int d = 1; d < len; d++) {
            if (len % d != 0)
                continue;

            int cost = 0;
            for (int group = 0; group < d; group++) { // for d, we will have d groups
                int l = i + group;
                int r = l + (len / d - 1) * d;

                while (l < r) {
                    if (str.charAt(l) != str.charAt(r))
                        cost++;

                    l += d;
                    r -= d;
                }
            }

            minCost = Math.min(minCost, cost);
        }

        return minCost;
    }

    public int minimumChanges(String s, int k) {
        n = s.length();
        str = s;

        costMemo = new int[n][n];
        for (int[] row : costMemo)
            Arrays.fill(row, Integer.MAX_VALUE);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                costMemo[i][j] = getCost(i, j);
            }
        }

        memo = new int[n + 1][k + 1];
        for (int[] row : memo)
            Arrays.fill(row, Integer.MAX_VALUE); // MAX_VALUE = impossible

        memo[n][0] = 0;

        for (int start = n; start >= 0; start--) {
            for (int pieces = 1; pieces <= k; pieces++) {
                if (start + 2 * pieces > n)
                    continue;

                int result = Integer.MAX_VALUE;

                for (int end = start + 1; end < n; end++) {
                    int remainCost = memo[end + 1][pieces - 1];

                    if (remainCost == Integer.MAX_VALUE)
                        continue;

                    result = Math.min(result, costMemo[start][end] + remainCost);
                }

                memo[start][pieces] = result;
            }
        }

        return memo[0][k];
    }
}
