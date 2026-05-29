/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ztTME5yhYCw
    Company Tags                : Flipkart, Morgan Stanley, Amazon, Microsoft, Snapdeal, Oracle, PayU, Visa, Directi, GreyOrange, Mobicip, NPCI
    Problem Link                : https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Bottom Up Space Optimised)
//T.C : O(n*W)
//S.C : O(W)
class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        // prev → t[i-1][...]
        // curr → t[i][...]
        vector<int> prev(W+1, 0), curr(W+1, 0);
        
        
        for(int i = 1; i < n+1; i++) {
            
            for(int j = 1; j < W+1; j++) {
                
                int take = 0;
                int skip = 0;
                
                // take → t[i-1][j - wt[i-1]]
                if(wt[i-1] <= j) {
                    take = val[i-1] + prev[j - wt[i-1]];
                }
                
                // skip → t[i-1][j]
                skip = prev[j];
                
                // t[i][j]
                curr[j] = max(take, skip);
            }
            
            // move current row → previous row
            prev = curr;
        }
        
        return prev[W]; // same as t[n][W]
    }
};



/**************************************************************** JAVA ****************************************************************/
//Approach (Bottom Up)
//T.C : O(n*W)
//S.C : O(n*W)
class Solution {
    public int knapsack(int W, int val[], int wt[]) {
        int n = val.length;
        
        // prev → t[i-1][...]
        // curr → t[i][...]
        int[] prev = new int[W + 1];
        int[] curr = new int[W + 1];
        
        for(int i = 1; i < n + 1; i++) {
            
            for(int j = 1; j < W + 1; j++) {
                
                int take = 0;
                int skip = 0;
                
                // take → t[i-1][j - wt[i-1]]
                if(wt[i - 1] <= j) {
                    take = val[i - 1] + prev[j - wt[i - 1]];
                }
                
                // skip → t[i-1][j]
                skip = prev[j];
                
                // t[i][j]
                curr[j] = Math.max(take, skip);
            }
            
            // move current row → previous row
            prev = curr.clone();  // IMPORTANT: create new copy
        }
        
        return prev[W]; // same as t[n][W]
    }
}
