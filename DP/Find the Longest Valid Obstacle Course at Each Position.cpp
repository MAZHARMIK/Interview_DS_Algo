/*
    MY YOUTUBE VIDEO ON THIS Qn : <soon>
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/
*/

//Approach-1 (Using LIS code) - O(n^2) - TLE
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[j] <= nums[i]) {
                    t[i] = max(t[i], t[j]+1);
                    
                }
            }
        }
        
        return t;
    }
};


//Approach-2 (Using Optimised LIS - Binary Search) - O(nlog(n)) - ACCEPTED
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        
        // lis[i] records the lowest increasing sequence of length i + 1.
        vector<int> answer(n, 1), lis;
        
        for (int i = 0; i < n; ++i) {
            // Find the rightmost insertion position idx.
            int idx = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();
            if (idx == lis.size())
                lis.push_back(obstacles[i]);
            else
                lis[idx] = obstacles[i];
            answer[i] = idx + 1;
        }
        return answer;
    }
};
