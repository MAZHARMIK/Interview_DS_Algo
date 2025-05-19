/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=X9uqA9KhID8
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/type-of-triangle
*/

/*********************************************************** C++ **************************************************/
//Approach (Simply checking triangle properties)
//T.C : O(1) 
//S.C : O(1)
class Solution {
public:
    string triangleType(vector<int>& nums) {
        bool valid = (nums[0] + nums[1] > nums[2]) &&
                     (nums[0] + nums[2] > nums[1]) &&
                     (nums[1] + nums[2] > nums[0]);

        if(!valid) {
            return "none";
        }

        if(nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        } else if(nums[0] != nums[1] && nums[0] != nums[2] && nums[1] != nums[2]) {
            return "scalene";
        }

        return "isosceles";
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Simply checking triangle properties)
//T.C : O(1) 
//S.C : O(1)
class Solution {
    public String triangleType(int[] nums) {
        boolean valid = (nums[0] + nums[1] > nums[2]) &&
                        (nums[0] + nums[2] > nums[1]) &&
                        (nums[1] + nums[2] > nums[0]);

        if (!valid) {
            return "none";
        }

        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        } else if (nums[0] != nums[1] && nums[0] != nums[2] && nums[1] != nums[2]) {
            return "scalene";
        }

        return "isosceles";
    }
}
