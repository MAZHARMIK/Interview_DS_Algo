/*
    Company Tags  : Google (Variation)
    Leetcode Link : https://leetcode.com/problems/4sum/
*/

//Approach-1 (Simply breaking problem into 2Sum and 3Sum
class Solution {
public:
    vector<vector<int>> result;
    int n;
    int num1, num2;
    void twoSum(vector<int>& nums, int idx, int target) {
        int l = idx, r = n-1;
        
        while(l < r) {
            if(nums[l] + nums[r] < target)
                l++;
            else if(nums[l] + nums[r] > target)
                r--;
            else {
                while(l < r && nums[r] == nums[r-1]) r--;
                while(l < r && nums[l] == nums[l+1]) l++;
                
                result.push_back({num1, num2, nums[l], nums[r]});
                l++;
                r--;
            }
        }
    }
    
    void threeSum(vector<int>& nums, int idx, int target) {
        
        for(int i = idx; i<n-2; i++) {
            if(i > idx && nums[i] == nums[i-1]) continue;
            num2 = nums[i];
            twoSum(nums, i+1, target-nums[i]);        
        }
        
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        n = nums.size();
        if(n < 4)
            return {};
        result.clear();
        
        for(int i = 0; i<n-3; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            num1 = nums[i];
            threeSum(nums, i+1, target-nums[i]);        
        }
        
        return result;
    }
};
//Approach-2 (Similar approach using 2Sum separately)
class Solution {
public:
    void twoSum(vector<vector<int>>& result, vector<int>& nums, int i, int j, int n, int target) {
        int k = j+1, l = n-1;
        while(k<l) {
            if(nums[k] + nums[l] > target)
                l--;
            else if(nums[k] + nums[l] < target)
                k++;
            else {
                result.push_back({nums[i], nums[j], nums[k], nums[l]});
                while( k < n-1 && nums[k] == nums[k+1]) k++;
                while(l  > 0 && nums[l] == nums[l-1]) l--;
                k++;
                l--;
            }
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        if(n < 4)
            return result;
        for(int i = 0; i<n-3; i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1; j<n-2; j++) {
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                int subTarget = target-(nums[i]+nums[j]);
                twoSum(result, nums, i, j, n, subTarget);
            }
        }
        return result;
    }
};
//Approch-3 (Everything under one umbrella)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        for(int i = 0; i<n-3; i++) {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i+1; j<n-2; j++) {
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                int k = j+1, l = n-1;
                int sub_target = target-(nums[i]+nums[j]);
                while(k<l) {
                    if(nums[k] + nums[l] > sub_target)
                        l--;
                    else if(nums[k] + nums[l] < sub_target)
                        k++;
                    else {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while( k < n-1 && nums[k] == nums[k+1]) k++;
                        while(l  > 0 && nums[l] == nums[l-1]) l--;
                        k++;
                        l--;
                    }
                }
            }
        }
        return result;
    }
};
//Approach-4 (Generalised to solve kSum problem)
/*
Why (nums[idx]*k > target)  ????
//nums[idx] is the smallest number and if sum of k smallest numbers > target, there is no point in checking further because our array is sorted in increasing order.

Why (nums.back()*k < target) ???
Same goes with this also. If the sum of k largest number (nums.back() is largest) < target,
there is not point in checking further because our array is sorted in increasing order.

Also adding these two conditions reduces the runtime to 8ms. Faster than 99%

*/
class Solution {
public:
    int n;
    vector<vector<int>> twoSum(vector<int>& nums, int idx, int target) {
        int l = idx, r = n-1;
        vector<vector<int>> temp;
        while(l < r) {
            if(nums[l] + nums[r] < target)
                l++;
            else if(nums[l] + nums[r] > target)
                r--;
            else {
                while(l < r && nums[r] == nums[r-1]) r--;
                while(l < r && nums[l] == nums[l+1]) l++;
                
                temp.push_back({nums[l], nums[r]});
                l++;
                r--;
            }
        }
        return temp;
    }
    
    vector<vector<int>> kSum(vector<int>& nums, int k, int idx, int target) {
        vector<vector<int>> result;

        if(idx >= n || nums[idx]*k > target || nums.back()*k < target)
            return result;
        
        if(k == 2) {
            return twoSum(nums, idx, target);
        }
        
        for(int i = idx; i<n-k+1; i++) {
            if(i > idx && nums[i] == nums[i-1]) continue;
            
            for(vector<int> vec : kSum(nums, k-1, i+1, target-nums[i])) {
                vec.push_back(nums[i]);
                result.push_back(vec);
            }
        }
        return result;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(begin(nums), end(nums));
        n = nums.size();
        if(n < 4)
            return {};
        
        int k = 4;
        
        return kSum(nums, k, 0, target);
    }
};
