/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=-tqUs4Qt9TU
    Company Tags                : Facebook, Amazon, FactSet, Walmart
    Letcode Link                : https://leetcode.com/problems/increasing-triplet-subsequence/
*/

//Using Concept of Longest Increasing Subsequence
// Time : O(n^2), Space : O(n)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> t(n, 1);
        
        int max_val = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[j] < nums[i])
                    t[i] = max(t[i], t[j]+1);
            }
            max_val = max(max_val, t[i]);
            if(max_val >= 3)
                break;
        }
        
        return max_val>=3?true:false;
    }
};


// Time : O(n), Space : O(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        int num1 = INT_MAX;
        int num2 = INT_MAX;
        
        for(int i = 0; i<n; i++) {
            
            int num3 = nums[i];//sorry for that
            
            //first ask num1
            if(num3 <= num1) {
                num1 = num3;
            } else if(num3 <= num2) { //ask num2
                num2 = num3;
            } else { //num1 < num2 inki life set hai already
                return true;
            }
        }
        
        return false;
        
    }
};
