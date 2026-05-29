/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=XCLN0RgwH0E
    Company Tags                : Flipkart, Morgan Stanley, Amazon, Microsoft, Snapdeal, Oracle, PayU, Visa, Directi, GreyOrange, Mobicip, NPCI
    Problem Link                : https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Bottom Up)
//T.C : O(n*W)
//S.C : O(n*W)
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        vector<vector<int>> t(n+1, vector<int>(W+1, 0));
        //t[i][j] = max profit with i items and j knapsack weight
        //return t[n][W];
        
        //Base case : if(n == 0 ) return 0; //no item
        for(int j = 0; j < W+1; j++) {
            t[0][j] = 0;
        }
        
        //Base case : if(W == 0) return 0; //knapsack full
        for(int i = 0; i < n+1; i++) {
            t[i][0] = 0;
        }
        
        
        for(int i = 1; i < n+1; i++) {
            for(int j = 1; j < W+1; j++) {
                
                int take = 0;
                int skip = 0;
                
                //take
                if(wt[i-1] <= j) {
                    take = val[i-1] + t[i-1][j - wt[i-1]];//val[i-1] + solve(i-1, j - wt[i-1], val, wt);
                }
                
                skip    = t[i-1][j]; //solve(i-1, j, val, wt);
                
                t[i][j] = max(take, skip); //return t[n][W] = max(take, skip);
                
            }
        }
        
        return t[n][W];
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach (Bottom Up)
//T.C : O(n*W)
//S.C : O(n*W)
class Solution {
    public int knapsack(int W, int val[], int wt[]) {
        int n = val.length;

        int[][] t = new int[n + 1][W + 1];
        // t[i][j] = max profit with i items and capacity j

        // Base case: first row (i = 0)
        for (int j = 0; j <= W; j++) {
            t[0][j] = 0;
        }

        // Base case: first column (j = 0)
        for (int i = 0; i <= n; i++) {
            t[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= W; j++) {

                int take = 0;
                int skip;

                // take
                if (wt[i - 1] <= j) {
                    take = val[i - 1] + t[i - 1][j - wt[i - 1]];
                }

                // skip
                skip = t[i - 1][j];

                t[i][j] = Math.max(take, skip);
            }
        }

        return t[n][W];
    }
}
