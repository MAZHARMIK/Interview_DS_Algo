/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Amazon, Accolite, D-E-Shaw, FactSet, MakeMyTrip, Microsoft, Samsung
    Leetcode Qn Link            : https://leetcode.com/problems/majority-element/
*/

/********************************************** C++ **********************************************/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maj = NULL;
        
        for(int i = 0; i<n; i++) {
            if(count == 0) {
                count = 1;
                maj = nums[i];
            }
            else if(nums[i] == maj) {
                count++;
            } else {
                count--;
            }
        }
        
        //Since it is gauranteed that majority element exists, so we don't check for freq of "maj" and return
        return maj;
    }
};


/********************************************** JAVA **********************************************/
class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int count = 0;
        Integer maj = null;
        
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                count = 1;
                maj = nums[i];
            } else if (nums[i] == maj) {
                count++;
            } else {
                count--;
            }
        }
        
        // Since it is guaranteed that the majority element exists, so we don't check for the frequency of "maj" and return
        return maj;
    }
}
