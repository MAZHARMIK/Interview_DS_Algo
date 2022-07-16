/*
    MY YOUTUBE VIDEO LINK FOR THIS Qn : https://www.youtube.com/watch?v=f2QgmVxPiS4&list=PLpIkg8OmuX-K6A0sEPFxOSJh4_AjCGAFf&index=5
    Company Tags                      : Accolite, Adobe, Amazon, D-E-Shaw, MakeMyTrip, Microsoft, Payu
    Leetcode Link                     : https://leetcode.com/problems/trapping-rain-water/
*/

class Solution {
public:
    vector<int> getLeftMax(vector<int>& height, int n) {
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for(int i = 1; i<n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        return leftMax;
    }
    vector<int> getRightMax(vector<int>& height, int n) {
        vector<int> rightMax(n);
        rightMax[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        return rightMax;
    } 
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 1 || n == 0)
            return 0;
        vector<int> leftMax = getLeftMax(height, n);
        vector<int> rightMax = getRightMax(height, n);
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += min(leftMax[i], rightMax[i]) - height[i];
        }
        return sum;
    }
};
