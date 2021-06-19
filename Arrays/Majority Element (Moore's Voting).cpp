/*
    Company Tags     : Amazon, Accolite, D-E-Shaw, FactSet, MakeMyTrip, Microsoft, Samsung
    Leetcode Qn Link : https://leetcode.com/problems/majority-element/
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int maj = nums[0];
        
        for(int i = 1; i<n; i++) {
            if(nums[i] == maj) {
                count++;
            } else {
                count--;
            }
            
            if(count == 0) {
                count = 1;
                maj = nums[i];
            }
        }
        
        //Since it is gauranteen that majority element exists, so we don't check for freq of "maj" and return
        return maj;
    }
};
