/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=ak3DkeUBo-c
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/predict-the-winner/
*/

//Recursion + Memo - I
//Approach-1 (Using same as Optimal Code Strategy)
class Solution {
public:
    int n;
    int t[23][23];
    int solve(vector<int>& nums, int l, int r) {
        
        if(l > r)
            return 0;
        
        if(l == r)
            return nums[l];
        
        if(t[l][r] != -1)
            return t[l][r];
        
        int take_left  = nums[l] + min(solve(nums, l+2, r), solve(nums, l+1, r-1));
        
        int take_right = nums[r] + min(solve(nums, l, r-2), solve(nums, l+1, r-1));
        
        
        return t[l][r] = max(take_left, take_right);
        
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        
        memset(t, -1, sizeof(t));
        
        n = nums.size();
        
        
        int total = accumulate(begin(nums), end(nums), 0);
        
        int player1 = solve(nums, 0, n-1);
        int player2 = total - player1;
        
        return player1 >= player2;
    }
};


//Recursion + Memo - II
//Approach-2 (Using diff of score between players)
class Solution {
public:
    int n;
    int t[23][23];
    
    //Player1 - Player2
    int maxDiff(vector<int>& nums, int l, int r) {
        
        if(l == r)
            return nums[l];
        
        if(t[l][r] != -1)
            return t[l][r];
        
        int take_left  = nums[l] - maxDiff(nums, l+1, r);
        int take_right = nums[r] - maxDiff(nums, l, r-1);
        
        return t[l][r] = max(take_left, take_right);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return maxDiff(nums, 0, n-1) >= 0;
            
    }
};


//Bottom Up - Soon
