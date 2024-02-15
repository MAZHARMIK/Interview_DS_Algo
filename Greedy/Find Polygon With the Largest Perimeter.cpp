/*                                       Scroll down to see JAVA code also                        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=3RUkd0SPnPk
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/
*/


/*************************************************************** C++ ***************************************************************/
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        long long perimeter = 0;
        long long cumSum    = 0;
        
        
        for(int i = 0; i < n; i++) {
            if(nums[i] < cumSum) {
                perimeter = nums[i] + cumSum;
            }
            cumSum += nums[i];
        }
        
        return perimeter == 0 ? -1 : perimeter;
        
    }
};


/*************************************************************** JAVA ***************************************************************/
//T.C : O(nlogn)
//S.C : O(1)
public class Solution {
    public long largestPerimeter(int[] nums) {
        int n = nums.length;

        Arrays.sort(nums);

        long perimeter = 0;
        long cumSum = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < cumSum) {
                perimeter = nums[i] + cumSum;
            }
            cumSum += nums[i];
        }

        return perimeter == 0 ? -1 : perimeter;
    }
}
