/*        Scroll below to see JAVA code also      */
/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9f1vzDFVnGA
      Company Tags                : META
      Leetcode Link               : https://leetcode.com/problems/stone-game-ii/
*/

/******************************************************** C++ ********************************************************/
//Recursion + Memo
//T.C : O(n^3)
//S.C : O(n^3)
class Solution {
public:
    
    int n;
    int t[2][101][101]; //t[2][n+1][n+1] - 2*(n+1)*(n+1) ~n^2 * n ~ O(n^3)
    int solveForAlice(vector<int>& piles, int person, int i, int M) {
        
        if(i >= n)
            return 0;
        
        if(t[person][i][M] != -1)
            return t[person][i][M];
        
        int result = (person == 1) ? -1 : INT_MAX;
        
        int stones = 0;
        
        for(int x = 1; x <= min(2*M, n-i); x++) {
            
            stones += piles[i+x-1];
            
            if(person == 1) { //Alice
                result = max(result, stones + solveForAlice(piles, 0, i+x, max(M, x)));
            } else { //Bob
                result = min(result, solveForAlice(piles, 1, i+x, max(M, x)));
            }
            
        }
        
        return t[person][i][M] = result;
        
    }
    
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        
        memset(t, -1, sizeof(t));
        
        return solveForAlice(piles, 1, 0, 1);
    }
};


//Will soon upload more approaches as well :-)

/******************************************************** JAVA ********************************************************/
//Recursion + Memo
//T.C : O(n^3)
//S.C : O(n^3)
class Solution {
    private int n;
    private int[][][] t = new int[2][101][101]; // t[2][n+1][n+1] ~ O(n^3)
    
    private int solveForAlice(int[] piles, int person, int i, int M) {
        if (i >= n) {
            return 0;
        }
        
        if (t[person][i][M] != -1) {
            return t[person][i][M];
        }
        
        int result = (person == 1) ? -1 : Integer.MAX_VALUE;
        int stones = 0;
        
        for (int x = 1; x <= Math.min(2 * M, n - i); x++) {
            stones += piles[i + x - 1];
            
            if (person == 1) { // Alice
                result = Math.max(result, stones + solveForAlice(piles, 0, i + x, Math.max(M, x)));
            } else { // Bob
                result = Math.min(result, solveForAlice(piles, 1, i + x, Math.max(M, x)));
            }
        }
        
        return t[person][i][M] = result;
    }
    
    public int stoneGameII(int[] piles) {
        n = piles.length;
        
        for (int[][] arr2D : t) {
            for (int[] arr1D : arr2D) {
                Arrays.fill(arr1D, -1);
            }
        }
        
        return solveForAlice(piles, 1, 0, 1);
    }
}
