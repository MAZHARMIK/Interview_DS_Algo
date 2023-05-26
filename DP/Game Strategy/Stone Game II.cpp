/*
      MY YOUTUBE VIDEO ON THIS Qn : <soon>
      Company Tags                : META
      Leetcode Link               : https://leetcode.com/problems/stone-game-ii/
*/

//Recursion + Memo
class Solution {
public:
    int t[2][101][101];
    int n;
    
    int solve(vector<int>& piles, int person, int i, int M) {
        if(i >= n)
            return 0;
        
        if(t[person][i][M] != -1)
            return t[person][i][M];
        
        int result;
        if(person == 0)
            result = -1;
        else
            result = 1000000;
        
        int sum = 0;
        
        for (int x = 1; x <= min(2 * M, n - i); x++) {
            sum += piles[i + x - 1];
            
            if (person == 0) {
                result = max(result, sum + solve(piles, 1, i + x, max(M, x)));
            }
            else {
                result = min(result, solve(piles, 0, i + x, max(M, x)));
            }
        }
        
        return t[person][i][M] = result;
        
    }
    
    int stoneGameII(vector<int>& piles) {
        memset(t, -1, sizeof(t));
        
        n = piles.size();
        
        return solve(piles, 0, 0, 1);
    }
};
