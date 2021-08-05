/*
    Company Tags  : Google, Adobe, Amazon, Microsoft
    Leetcode Link : https://leetcode.com/problems/stone-game/
*/

//Approach-1 (Recur+Memo) O(n^2) - Standard Optimal Game Strategy Concept
class Solution {
public:
    int n;
    int t[501][501];
    int solve(vector<int>& piles, int left, int right) {
        if(left > right)
            return 0;
        
        if(left == right)
            return piles[left];
        
        if(t[left][right] != -1)
            return t[left][right];
        
        /*
            That's how optimal game strategy works. Expect your opponent to be playing optimally
            -When it's your turn, do your best
            -When it's your opponent's turn, expect the worst (that's why min() is taken below)
        */
        int choose_left  = piles[left]  + min(solve(piles, left+2, right), solve(piles, left+1, right-1));
        int choose_right = piles[right] + min(solve(piles, left, right-2), solve(piles, left+1, right-1));
        
        return t[left][right] = max(choose_left, choose_right);
    }
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        memset(t, -1, sizeof(t));
        int sum = accumulate(begin(piles), end(piles), 0);
        int alexScore = solve(piles, 0, n-1);
        
        return alexScore > sum/2;
    }
};

//Approach-2 (Coming soon)
