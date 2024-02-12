/*                                    Scroll below to see JAVA code also                                */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=Q6L5SoS-fTo
    Company Tags                : Amazon, Accolite, D-E-Shaw, FactSet, MakeMyTrip, Microsoft, Samsung
    Leetcode Qn Link            : https://leetcode.com/problems/majority-element/
*/

/********************************************** C++ **********************************************/
//Approach-1
//T.C : O(n)
//S.C : O(1)
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

//////OR you can also code it like this (Eaxct similar to Majority Element-II)
//Approach-2
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maj = NULL;

        for(int i = 0; i<n; i++) {
            if(nums[i] == maj) {
                count++;
            } else if(count == 0) {
                maj = nums[i];
                count = 1;
            } else {
                count--;
            }

        }

        return maj;
    }
};

/********************************************** JAVA **********************************************/
//Approach-1
//T.C : O(n)
//S.C : O(1)
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


//////OR you can also code it like this (Eaxct similar to Majority Element-II)
//Approach-2
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int count = 0;
        Integer maj = null;

        for (int i = 0; i < n; i++) {
            if (maj != null && nums[i] == maj) {
                count++;
            } else if (count == 0) {
                maj = nums[i];
                count = 1;
            } else {
                count--;
            }
        }

        return maj;
    }
}
