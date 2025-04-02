/*          Scroll down to see JAVA code also         */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i
*/


/*************************************************************** C++ ***************************************************************/
//Approach-1 (Brute Force - Trying All Possibilities)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    result = max(result, (long long)(nums[i] - nums[j])*nums[k]);
                }
            }
        }

        return result;
    }
};


//Approach-2 (Using prefix and suffix storage)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
        }
        for(int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], nums[i+1]);
        }

        long long result = 0;
        for (int j = 1; j < n - 1; j++) {
            result = max(result, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
        }
        return result;
    }
};


//Approach-3 (Keeping track of maxDif and maxi)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;

        long long maxDiff = 0;
        long long maxi = 0;

        for(int k = 0; k < n; k++) {
            result = max(result, maxDiff * nums[k]);
            maxDiff = max(maxDiff, maxi - nums[k]);
            maxi = max(maxi, (long long)nums[k]);
        }
        return result;
    }
};
