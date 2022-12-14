/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : Amazon, OYO Rooms, Paytm, Walmart, Google, Flipkart, LinkedIn, Airbnb
    Leetcode Link               : https://leetcode.com/problems/house-robber/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
    Also Famouse as             : Stickler Thief
*/

//Approach-1 (Recur + Memo)
class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int& n) {
        if(i >= n)
            return 0;
        
        if(t[i] != -1)
            return t[i];
        
        int take = nums[i] + solve(nums, i+2, n); //steals ith house and moves to i+2 (because we can't steal adjacent)
        int skip = solve(nums, i+1, n); //skips this house, now we can move to adjacent next house
        
        return t[i]=max(take, skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, n);
    }
};


//Approach-2 (Bottom up)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1)
            return nums[0];
        
        vector<int> t(n+1);
        //t[i] = max profit till house i
        
        t[0] = 0;
        t[1] = nums[0];
        t[2] = max(nums[0], nums[1]);
        
        for(int i = 3; i<=n; i++) {
            int curr_house = nums[i-1];
          
            t[i] = max(t[i-1],  curr_house + t[i-2]);
            /*
                If we skip this house, then we have money till previous house  =  t[i-1]
                If we steal this house, then we can't take prev profit, we need (i-2)th house profit = t[i-2]
            */
        }
        
        return t[n];
        
    }
};


//Approach-3 (Space Optimized Bottom Up - Converting Approach-2)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int curr = 0;
        int prev = 0;
        
        for(int i = 0; i<n; i++) {
            int temp = max(nums[i] + prev, curr);
            
            prev = curr;
            curr = temp;
        }
        
        return curr;
    }
};
