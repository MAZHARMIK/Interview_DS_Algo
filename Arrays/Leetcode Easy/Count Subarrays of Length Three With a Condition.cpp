/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=EM97x6t8BM4
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/
*/

/*********************************************************** C++ **************************************************/
//Approach (Striaght forward simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for(int i = 1; i < n-1; i++) {
            if(nums[i] == (nums[i-1] + nums[i+1])*2) {
                result++;
            }
        }

        return result;
    }

};


/*********************************************************** JAVA **************************************************/
//Approach (Striaght forward simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int countSubarrays(int[] nums) {
        int n = nums.length;
        int result = 0;

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == (nums[i - 1] + nums[i + 1])*2) {
                result++;
            }
        }

        return result;
    }
}
