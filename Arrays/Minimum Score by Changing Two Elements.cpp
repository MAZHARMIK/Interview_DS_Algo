/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=yZof-4Kh4nQ
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-score-by-changing-two-elements
*/


/*********************************************************** C++ **************************************************/
//Approach (Sort and minimize low and high)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        
        //sort
        sort(begin(nums), end(nums));

        // low score = 0, bas high ko minimize karna hai
        return min({
            nums[n-3] - nums[0], // do sabse bade hatao
            nums[n-1] - nums[2], // do sabse chhote hatao
            nums[n-2] - nums[1]  // ek bada + ek chhota hatao
        });
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Sort and minimize low and high)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public int minimizeSum(int[] nums) {
        int n = nums.length;

        // sort
        Arrays.sort(nums);

        // low score = 0, bas high ko minimize karna hai
        int option1 = nums[n - 3] - nums[0];   
        int option2 = nums[n - 1] - nums[2];   
        int option3 = nums[n - 2] - nums[1];   

        return Math.min(option1, Math.min(option2, option3));
    }
}
