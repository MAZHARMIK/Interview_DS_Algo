/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=K2IomuIFbPg
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/patching-array/description/
*/


/************************************************** C++ **************************************************/
//Approach (Greedy observation)
//T.C : O(max(l, log(n)), l = length of nums
//S.C : O(1)
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long maxReach = 0;
        int patch     = 0;
        int i         = 0;

        while(maxReach < n) {
            if(i < nums.size() && nums[i] <= maxReach+1) {
               maxReach += nums[i];
               i++;
            } else {
               maxReach += (maxReach + 1);
               patch++;
            }
        }
        return patch;
    }
};



/************************************************** JAVA **************************************************/
//Approach (Greedy observation)
//T.C : O(max(l, log(n)), l = length of nums
//S.C : O(1)
class Solution {
    public int minPatches(int[] nums, int n) {
        long maxReach = 0;
        int patch = 0;
        int i = 0;

        while (maxReach < n) {
            if (i < nums.length && nums[i] <= maxReach + 1) {
                maxReach += nums[i];
                i++;
            } else {
                maxReach += (maxReach + 1);
                patch++;
            }
        }
        return patch;
    }
}
