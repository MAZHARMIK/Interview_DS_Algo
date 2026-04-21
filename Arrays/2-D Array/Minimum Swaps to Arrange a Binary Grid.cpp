/*     Scroll below to see JAVA code also   */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=FxOl81Rwdrk
    Company Tags                : Ajira Software
    Leetcode Link               : https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid
*/


/************************************************** C++ **************************************************/
//Approach (Siilar to Bubble Sort - Find best candidate and swap)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(); // rows == columns

        vector<int> endZeros(n, 0);
        //endZeros[i] = count of consecutive 0s from the end of ith row

        for(int i = 0; i < n; i++) {
            int j = n-1; //start from end

            int count = 0;
            while(j >= 0 && grid[i][j] == 0) {
                count++;
                j--;
            }

            endZeros[i] = count;
        }

        int steps = 0;

        for(int i = 0; i < n; i++) {
            
            int need = n - i - 1;

            int j = i;

            while(j < n && endZeros[j] < need) {
                j++;
            }

            if(j == n) {
                return -1;
            }

            steps += j-i;

            while(j > i) {
                swap(endZeros[j], endZeros[j-1]);
                j--;
            }

        }

        return steps;
        
    }
};



/************************************************** JAVA **************************************************/
//Approach (Siilar to Bubble Sort - Find best candidate and swap)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
    public int minSwaps(int[][] grid) {

        int n = grid.length; // rows == columns

        int[] endZeros = new int[n];
        // endZeros[i] = count of consecutive 0s from the end of ith row

        for (int i = 0; i < n; i++) {
            int j = n - 1; // start from end

            int count = 0;
            while (j >= 0 && grid[i][j] == 0) {
                count++;
                j--;
            }

            endZeros[i] = count;
        }

        int steps = 0;

        for (int i = 0; i < n; i++) {

            int need = n - i - 1;

            int j = i;

            while (j < n && endZeros[j] < need) {
                j++;
            }

            if (j == n) {
                return -1;
            }

            steps += (j - i);

            while (j > i) {
                int temp = endZeros[j];
                endZeros[j] = endZeros[j - 1];
                endZeros[j - 1] = temp;
                j--;
            }
        }

        return steps;
    }
}
