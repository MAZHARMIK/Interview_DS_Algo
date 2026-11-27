/*        Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO LINK : https://www.youtube.com/watch?v=2BeIDxoeY5E
    Company Tags          : Will update later
    Leetcode Link         : https://leetcode.com/problems/maximum-number-of-items-from-sale-i/description/
*/


/*************************************************************** C++ ******************************************************/
//Approach-1 (Recursion Memo)
//T.C : O(n^2 + n*budget)
//S.C : O(n + n*budget)
class Solution {
public:
    int t[1001][1501];

    int solve(int n, int budget, int minPrice, vector<vector<int>>& items, vector<int>& copies) {
        if(n == 0) {
            return budget/minPrice;
        }

        if(t[n][budget] != -1)
            return t[n][budget];

        int take = 0;
        int price = items[n-1][1];

        if(price <= budget) {
            take = 1 + copies[n-1] + solve(n-1, budget-price, minPrice, items, copies);
        }

        int skip = solve(n-1, budget, minPrice, items, copies);

        return t[n][budget] = max(take, skip);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> copies(n, 0); //copies[i] = count of copies if I buy ith item
        int minPrice = INT_MAX;

        for(int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);

            int copy = 0;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;

                if(items[j][0] % items[i][0] == 0)
                    copy++;
            }

            copies[i] = copy;
        }

        memset(t, -1, sizeof(t));
        return solve(n, budget, minPrice, items, copies);
    }
};



//Approach-2 (Bottom Up)
//T.C : O(n^2 + n*budget)
//S.C : O(n + n*budget)
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> copies(n, 0); //copies[i] = count of copies if I buy ith item
        int minPrice = INT_MAX;

        for(int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);

            int copy = 0;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;

                if(items[j][0] % items[i][0] == 0)
                    copy++;
            }

            copies[i] = copy;
        }

        vector<vector<int>> t(n + 1, vector<int>(budget + 1, 0));

        // Base case: no item types left, spend leftover on the cheapest item
        //n = 0
        for (int b = 0; b <= budget; b++)
            t[0][b] = b / minPrice;

        for (int i = 1; i <= n; i++) {
            for (int b = 0; b <= budget; b++) {
                int price = items[i - 1][1];
                int take = 0;

                if (price <= b)
                    take = 1 + copies[i - 1] + t[i - 1][b - price];

                int skip = t[i - 1][b];

                t[i][b] = max(take, skip);
            }
        }

        return t[n][budget];
    }
};




/*************************************************************** JAVA ******************************************************/
//Approach-1 (Recursion Memo)
//T.C : O(n^2 + n*budget)
//S.C : O(n + n*budget)
class Solution {
    int[][] t;

    private int solve(int n, int budget, int minPrice, int[][] items, int[] copies) {
        if (n == 0) {
            return budget / minPrice;
        }

        if (t[n][budget] != -1)
            return t[n][budget];

        int take = 0;
        int price = items[n - 1][1];

        if (price <= budget) {
            take = 1 + copies[n - 1] + solve(n - 1, budget - price, minPrice, items, copies);
        }

        int skip = solve(n - 1, budget, minPrice, items, copies);

        return t[n][budget] = Math.max(take, skip);
    }

    public int maximumSaleItems(int[][] items, int budget) {
        int n = items.length;

        int[] copies = new int[n]; //copies[i] = free copies if I buy ith item
        int minPrice = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            minPrice = Math.min(minPrice, items[i][1]);

            int copy = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                if (items[j][0] % items[i][0] == 0)
                    copy++;
            }

            copies[i] = copy;
        }

        t = new int[n + 1][budget + 1];
        for (int[] row : t)
            Arrays.fill(row, -1);

        return solve(n, budget, minPrice, items, copies);
    }
}



//Approach-2 (Bottom Up)
//T.C : O(n^2 + n*budget)
//S.C : O(n + n*budget)
class Solution {
    public int maximumSaleItems(int[][] items, int budget) {
        int n = items.length;

        int[] copies = new int[n]; //copies[i] = free copies if I buy ith item
        int minPrice = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            minPrice = Math.min(minPrice, items[i][1]);

            int copy = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                if (items[j][0] % items[i][0] == 0)
                    copy++;
            }

            copies[i] = copy;
        }

        int[][] t = new int[n + 1][budget + 1];

        // Base case: no item types left, spend leftover on the cheapest item
        // n = 0
        for (int b = 0; b <= budget; b++)
            t[0][b] = b / minPrice;

        for (int i = 1; i <= n; i++) {
            for (int b = 0; b <= budget; b++) {
                int price = items[i - 1][1];
                int take = 0;

                if (price <= b)
                    take = 1 + copies[i - 1] + t[i - 1][b - price];

                int skip = t[i - 1][b];

                t[i][b] = Math.max(take, skip);
            }
        }

        return t[n][budget];
    }
}
