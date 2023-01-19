/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=7Xeorb721LQ
    Company Tags                : Amazon, Microsoft, Paytm
    Leetcode Qn Link            : https://leetcode.com/problems/subarray-sums-divisible-by-k/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/sub-array-sum-divisible-by-k2617/1
*/

//Approach-1 (O(n^3))
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n       = nums.size();
        int count   = 0;
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                int sum = accumulate(begin(nums)+i, begin(nums)+j+1, 0);
                if(sum%k == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};

//Approach-1 (O(n^2))
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n       = nums.size();
        int count   = 0;
        for(int i = 1; i<n; i++) {
            nums[i] += nums[i-1];
        }
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                int sum = (i==0) ? nums[j] : nums[j] - nums[i-1];

                if(sum%k == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};

//Approach-3 (Time : O(n), Space : O(n))
/*
    Concept behind this method
    K
    
    a  b  c  d   e   f   g    h
    -----s1-------
    -----------------s2--------
    
    Lets say, 
    s1%k = x
    s2%k = x
    s1 = k*n + x
    s2 = k*m + x
    subarraySum = s2-s1
                = k*(m-n)
                Which proves that the subarray is divisible by k
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        int sum = 0;
        
        mp[0] = 1;
        
        int result = 0;
        
        for(int i = 0; i<n; i++) {
            sum += nums[i];
            
            int rem = sum%k;
            
            if(rem < 0) {
                rem += k;
            }
            
            if(mp.find(rem) != mp.end()) {
                result += mp[rem];
            }
            
            mp[rem]++;
            
        }
        
        return result;
        
    }
};
