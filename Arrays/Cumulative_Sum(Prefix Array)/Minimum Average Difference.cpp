/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=odP1T58kNQY
    Company Tags                : Amazon, Paytm
    Leetcode Link               : https://leetcode.com/problems/minimum-average-difference/
*/


/*
  NOTE : Please also try Brute Force approach on your own. It's always a good thing to start with Brute Force
*/

//Using Cumulative Sum Approach : O(n) Time, O(1) Space
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        
        //Total Sum
        long long sum = 0;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
        }
        
        long long LS = 0;
        long long RS = 0;
        
        int result = INT_MAX;
        int idx    = -1;
        
        for(int i = 0; i<n; i++) {
            LS += nums[i]; //nikalte chalenge
            RS  = sum-LS; //LS+RS = sum
            
            int n1 = i+1;
            int n2  = n-n1; //n1+n2 = n
            
            long long left_avg  = LS/n1;
            long long right_avg = (i==n-1) ? 0 : RS/n2;
            
            int diff = abs(left_avg - right_avg);
            
            if(result > diff) {
                result = diff;
                idx = i;
            }
        }
        
        return idx;
    }
};
