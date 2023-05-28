/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : Airbnb, Microsoft
    Leetcode Link               : https://leetcode.com/problems/house-robber-ii/
*/


//Approach-1 (Recur + Memo)
class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int idx, int n) {
        if(idx > n)
            return 0;
        
        if(t[idx] != -1)
            return t[idx];
        
        int take  = nums[idx] + solve(nums, idx+2, n);
        int skip  = solve(nums, idx+1, n);
        
        return t[idx] = max(take, skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        if(n == 2)
            return max(nums[0], nums[1]);
        
        memset(t, -1, sizeof(t));
        
        int take_first_house = solve(nums, 0, n-2);
        memset(t, -1, sizeof(t));
        int skip_first_house = solve(nums, 1, n-1);
        
        
        return max(take_first_house, skip_first_house);
    }
};



//Approach-2 (Using Bottom Up similar to House Robber-1 and just taking two cases
/*
    Case-1 (Take from 1st House - Hence skip the last house)
    Case-2 (Take from 2nd House - Hence take the last house)
*/
class Solution {
public:
    int n;
    
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n == 1)
            return nums[0];
        
        vector<int> t(n+1, 0);
        //t[i] = Max money gained from i houses
        
        int result1 = 0;
        int result2 = 0;
        
        //Case-1 (Take from 1st House - Hence skip the last house)
        t[0] = 0;
        for(int i = 1; i<=n-1; i++) {
            t[i] = max(t[i-1] , nums[i-1]+ ((i-2 >= 0) ? t[i-2] : 0 ));
        }
        result1 = t[n-1];
        
        t.clear();
        //Case-2 (Take from 2nd House - Hence take the last house)
        t[0] = 0;
        t[1] = 0;
        for(int i = 2; i<=n; i++) {
            t[i] = max(t[i-1] , nums[i-1]+ ((i-2 >= 0) ? t[i-2] : 0 ));
        }
        result2 = t[n];
        
        return max(result1, result2);
        
    }
};




//Approach-3 (Converting Bottom Up to constant space)
class Solution {
public:
    
    //this function is solution of House robber I. We just use it to solve House Robber II
    int solve(vector<int>& nums, int l, int r) {
        int prev = 0, curr = 0;
        
        for(int i = l; i<=r; i++) {
            int temp = max(nums[i] + prev, curr);
            
            prev = curr;
            curr = temp;
        }
        
        return curr;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        if(n == 2)
            return max(nums[0], nums[1]);
        
        int take_first_house = solve(nums, 0, n-2);
        
        int skip_first_house = solve(nums, 1, n-1);
        
        
        return max(take_first_house, skip_first_house);
    }
};
