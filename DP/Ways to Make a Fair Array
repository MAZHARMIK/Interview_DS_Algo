/*
    Leetcode Weekly Contest-216
    Contest Link : https://leetcode.com/contest/weekly-contest-216/problems/ways-to-make-a-fair-array/
*/

class Solution {
public:
    void populateBefore(int n, vector<int>& nums, vector<int>& oddBefore, vector<int>& evenBefore) {
        int oddSum = 0;
        int evenSum = 0;
        for(int i = 0; i<n; i++) {
            oddBefore[i]  = oddSum;
            evenBefore[i] = evenSum;
            if(i%2 == 0)
                evenSum += nums[i];
            else
                oddSum += nums[i];
        }
    }
    
    void populateAfter(int n, vector<int>& nums, vector<int>& oddAfter, vector<int>& evenAfter) {
        int oddSum = 0;
        int evenSum = 0;
        for(int i = n-1; i>=0; i--) {
            oddAfter[i]  = oddSum;
            evenAfter[i] = evenSum;
            if(i%2 == 0)
                evenSum += nums[i];
            else
                oddSum += nums[i];
        }
    }
    
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        vector<int> oddBefore(n);  //oddBefore[i]  = sum of odd indexed no. before i
        vector<int> evenBefore(n); //evenBefore[i] = sum of even indexed no. before i
        
        vector<int> oddAfter(n);  //oddAfter[i]  = sum of odd indexed no. after i
        vector<int> evenAfter(n); //evenAfter[i] = sum of even indexed no. after i
        
        populateBefore(n, nums, oddBefore, evenBefore);
        populateAfter(n, nums, oddAfter, evenAfter);
        
        int result = 0;
        for(int i = 0; i<n; i++) {
            if(oddBefore[i] + evenAfter[i] == evenBefore[i]+oddAfter[i])
                result++;
        }
        return result;
    }
};
