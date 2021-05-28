/*
    Leetcode Weekly Contest Qn
    Company Tag   : NIL (Let me know if you find any :-) )
    Leetcode Link : https://leetcode.com/problems/maximum-erasure-value/
*/

//Approach-1 (Smart)
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> cus(n+1, 0);
        for(int i = 0; i<n; i++)
            cus[i+1] = cus[i] + nums[i];
        
        vector<int> t(100001, -1);
        int start  = 0;
        int maxS   = 0;
        
        for(int end  = 0; end<n; end++) {
            start = max(start, t[nums[end]]+1);
            maxS  = max(maxS, cus[end+1]-cus[start]);
            t[nums[end]] = end;
        }
        
        return maxS;
    }
};


//Approach-2 (Simple and intuitive)
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        int sum = 0;
        int i = 0,  j = 0;
        unordered_map<int, int> mp;
        
        vector<int> cumS(n, 0);
        cumS[0] = nums[0];
        for(int i = 1; i<n; i++) {
            cumS[i] = cumS[i-1] + nums[i];
        }

        while(i < n) {
            if(!mp.count(nums[i])) {
                mp[nums[i]] = i;
                i++;
            } else {
                if(mp[nums[i]] >= j) {
                   int temp = cumS[i-1] - (j>0 ? cumS[j-1] : 0);
                    sum = max(sum, temp);
                    j = mp[nums[i]] + 1;
                }
                mp[nums[i]] = i;
                i++;
            }
        }
        
        
        int temp = 0;
        if(j < n) {
            temp = cumS[n-1] - (j>0 ? cumS[j-1] : 0);
        }
        
        return max(sum, temp);
    }
};
