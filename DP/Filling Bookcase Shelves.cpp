/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=pOtAvGIW8kQ
    Company Tags                : Will soon update
    Leetcode Link               : https://leetcode.com/problems/filling-bookcase-shelves
*/


/*************************************************************** C++ *************************************************/
//Approach-1 (Using Recursion + Memo)
//T.C : O(n*shelfWidth)
//S.C : O(n*shelfWidth)
class Solution {
public:
    int n;
    int WIDTH;
    int t[1001][1001];
    int solve(vector<vector<int>>& books, int i, int remainW, int maxHt) {
        if(i >= n) {
            return maxHt;
        }

        if(t[i][remainW] != -1) {
            return t[i][remainW];
        }

        int bookW = books[i][0];
        int bookH = books[i][1];

        int keep = INT_MAX;
        int skip = INT_MAX;

        //keep
        if(bookW <= remainW) { //let's keep it here
            keep = solve(books, i+1, remainW - bookW, max(maxHt, bookH));
        }

        //skip and put in next shelf
        skip = maxHt + solve(books, i+1, WIDTH - bookW, bookH);

        return t[i][remainW] = min(keep, skip);
    }


    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(t, -1, sizeof(t));
        n = books.size();
        WIDTH = shelfWidth;

        int remainW = shelfWidth;
        return solve(books, 0, remainW, 0);
    }
};


/*************************************************************** JAVA *************************************************/
//Approach-1 (Using Recursion + Memo)
//T.C : O(n*shelfWidth)
//S.C : O(n*shelfWidth)
class Solution {
    private int n;
    private int WIDTH;
    private int[][] t;

    private int solve(int[][] books, int i, int remainW, int maxHt) {
        if (i >= n) {
            return maxHt;
        }

        if (t[i][remainW] != -1) {
            return t[i][remainW];
        }

        int bookW = books[i][0];
        int bookH = books[i][1];

        int keep = Integer.MAX_VALUE;
        int skip = Integer.MAX_VALUE;

        // keep
        if (bookW <= remainW) { // let's keep it here
            keep = solve(books, i + 1, remainW - bookW, Math.max(maxHt, bookH));
        }

        // skip and put in next shelf
        skip = maxHt + solve(books, i + 1, WIDTH - bookW, bookH);

        return t[i][remainW] = Math.min(keep, skip);
    }

    public int minHeightShelves(int[][] books, int shelfWidth) {
        n = books.length;
        WIDTH = shelfWidth;
        t = new int[1001][1001];
        for (int[] row : t) {
            Arrays.fill(row, -1);
        }

        int remainW = shelfWidth;
        return solve(books, 0, remainW, 0);
    }
}
