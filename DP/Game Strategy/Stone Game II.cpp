/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9f1vzDFVnGA
      Company Tags                : META
      Leetcode Link               : https://leetcode.com/problems/stone-game-ii/
*/

//Recursion + Memo
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
