/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=_b_QfxC56EA
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-distance-to-the-target-element
*/


/*********************************************************** C++ **************************************************/
//Approach-1 (Simple simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();

        int result = INT_MAX;

        //result = x;
        //abs(start - i) minimal

        for(int i = 0; i < n; i++) {

            if(nums[i] == target) {
                result = min(result, abs(i - start));
            }

        }

        return result;
    }
};




//Approach-2 (Loop with Early Break)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();

        int result = INT_MAX;

        //result = x;
        //abs(start - i) minimal

        for(int i = 0; i < n && result > abs(i - start); i++) {

            if(nums[i] == target) {
                result = min(result, abs(i - start));
            }

        }

        return result;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach-1 (Simple simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int n = nums.length;

        int result = Integer.MAX_VALUE;

        // result = min |i - start| where nums[i] == target
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                result = Math.min(result, Math.abs(i - start));
            }
        }

        return result;
    }
}


//Approach-2 (Loop with Early Break)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int n = nums.length;

        int result = Integer.MAX_VALUE;

        // stop early if i goes beyond possible better distance
        for (int i = 0; i < n && result > Math.abs(i - start); i++) {
            if (nums[i] == target) {
                result = Math.min(result, Math.abs(i - start));
            }
        }

        return result;
    }
}
