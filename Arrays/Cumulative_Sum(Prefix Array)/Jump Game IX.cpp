/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn    : https://www.youtube.com/watch?v=P5OmDG_3UPs
    Company Tags                   : Will update later
    Leetcode Link                  : https://leetcode.com/problems/jump-game-ix
*/


/************************************************************ C++ *****************************************************/
//Approach (Using prefix array)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxLeft(n); //maxLeft[i] = max element from index 0 to i
        vector<int> minRight(n); //minRight[i] = min element from i+1 to n

        maxLeft[0] = nums[0];
        minRight[n-1] = nums[n-1];

        for(int i = 1; i < n; i++) {
            maxLeft[i] = max(nums[i], maxLeft[i-1]);
        }

        for(int i = n-2; i >= 0; i--) {
            minRight[i] = min(nums[i], minRight[i+1]);
        }

        vector<int> ans(n);

        ans[n-1] = maxLeft[n-1];

        for(int i = n-2; i >= 0; i--) {
            if(maxLeft[i] <= minRight[i+1]) { //can't go to right at all
                ans[i] = maxLeft[i];
            } else {
                ans[i] = ans[i+1];
            }
        }

        return ans;
    }
};



//Approach (Using prefix array)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int[] maxValue(int[] nums) {
        
        int n = nums.length;

        int[] maxLeft = new int[n]; // maxLeft[i] = max element from index 0 to i
        int[] minRight = new int[n]; // minRight[i] = min element from i to n-1

        maxLeft[0] = nums[0];
        minRight[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++) {
            maxLeft[i] = Math.max(nums[i], maxLeft[i - 1]);
        }

        for(int i = n - 2; i >= 0; i--) {
            minRight[i] = Math.min(nums[i], minRight[i + 1]);
        }

        int[] ans = new int[n];

        ans[n - 1] = maxLeft[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            if(maxLeft[i] <= minRight[i + 1]) { // can't go to right at all
                ans[i] = maxLeft[i];
            } else {
                ans[i] = ans[i + 1];
            }
        }

        return ans;
    }
}
