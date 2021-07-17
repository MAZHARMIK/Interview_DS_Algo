/*
    Company Tags  : Adobe, Amazon, Housing.com, Moonfrog Labs, OYO Rooms, Saplabs, Walmart
    Leetcode Link : https://leetcode.com/problems/jump-game-ii/
*/

//Approach-1 (Recursion+Memoization) : Accepted
typedef unsigned long long ll;
class Solution {
public:
    ll solve(vector<int>& nums, int n, int idx, unordered_map<int, int>& mp) {
        if(idx >= n)
            return INT_MAX;
        if(mp.count(idx))
            return mp[idx];
        if(idx == n-1)
            return mp[idx] = 0;
        
        ll minS = INT_MAX;
        
        for(int i = 1; i<=nums[idx]; i++) {
            minS = min(minS, solve(nums, n, idx+i, mp));
        }
        
        return mp[idx] = minS+1;
    }
    ll jump(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        return solve(nums, n, 0, mp);
    }
};

//Approach-2 (DP) : Accepted
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, INT_MAX);
        //t[i] = minimum # jumps to reach ith position
        
        vector<int> path(n, -1);
        //path[i] = index of element from where you came to i
        
        path[0] = -1; //I came to 0th index from -1
        t[0] = 0; //I need 0 steps to reach 0th index (I start from 0 only)
        
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<i; j++) {
                //if I can reach to i from j
                if(nums[j] + j >= i) {
                    if(t[i] > t[j]+1) {
                        t[i] = t[j]+1;
                        path[i] = j;
                    }
                }
            }
        }
        
        /*
        Uncomment this to see the path
        
        cout << "Min steps Path " << endl;
        int i = n-1;
        while(i > 0) {
            cout << "You came to index " << i << " i.e. at " << nums[i] << " from index " << path[i] << " i.e " << nums[path[i]] << endl;
            i = path[i];
        }
        
        */
        
        return t[n-1];
    }
};

//Approach-3 : O(N) Accepted (Greedy)
class Solution {
public:
    int optimal(vector<int>& nums, int n) {
        int currEnd  = 0;
        int maxReach = 0;
        int jump     = 0;
        
        for(int i = 0; i<n-1; i++) {
            maxReach = max(maxReach, nums[i]+i);
            
            //Since, I reached end, I need to
            //take a jump for exploring further positions
            if(i == currEnd) {
                jump++;
                currEnd = maxReach;
            }
        }
        
        if(currEnd >= n-1)
            return jump;
        return -1;
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1)
            return 0;
     
        return optimal(nums, n);
    }
};
