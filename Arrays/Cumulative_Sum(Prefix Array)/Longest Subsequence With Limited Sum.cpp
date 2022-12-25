/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=rRFROtG1Y94
    Company Tags                : <soon>
    Leetcode Link               : https://leetcode.com/problems/longest-subsequence-with-limited-sum/
*/


//Approach-1
//Brute Force : O(m*n)
class Solution {
public:
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        
        int m = queries.size();
        vector<int> result;
        
        for(int  &query : queries) {
            int sum = 0;
            
            for(int j = 0; j<n; j++) {
                sum += nums[j];
                if(sum > query) {
                    result.push_back(j);
                    break;
                }
                
                if(j == n-1) {
                    result.push_back(n);
                }
            }  
        }
        return result;
    }
};

//Approach-2
//Using Self Written Binary Search : O((m+n)*log(n))
class Solution {
public:
    
    int binarySearch(vector<int>& nums, int n, int target) {
        int l = 0, r = n-1;
        int mid;
        int result_idx = -1;
        
        while(l <= r) {
            mid = l + (r-l)/2;
            if(nums[mid] <= target) {
                result_idx = mid;
                l = mid+1;
            } else if(nums[mid] > target) {
                r = mid-1;
            }
        }
        return result_idx+1;
    }
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        for(int i = 1; i<n; i++) {
            nums[i] += nums[i-1];
        }
        
        int m = queries.size();
        vector<int> result(m);
        
        for(int i = 0; i<m; i++) {
            auto it = binarySearch(nums, n, queries[i]);
            
            result[i] = it;
        }
        return result;
    }
};


//Approach-3
//Using upper_bound STL in C++ : O((m+n)*log(n))
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        sort(begin(nums), end(nums));
        for(int i = 1; i<n; i++) {
            nums[i] += nums[i-1];
        }
        
        int m = queries.size();
        vector<int> result(m);
        
        for(int i = 0; i<m; i++) {
            auto it = upper_bound(begin(nums), end(nums), queries[i]) - begin(nums);
            
            result[i] = it;
        }
        return result;
    }
};
