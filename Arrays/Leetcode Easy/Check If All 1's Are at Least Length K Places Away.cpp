/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away
*/

/*********************************************************** C++ **************************************************/
//Approach - Maintain two pointers to count 0s between
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        
        int lastOne = -(k+1);

        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                if(i - lastOne - 1 < k)
                    return false;
                
                lastOne = i;
            }
        }

        return true;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach - Maintain two pointers to count 0s between
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int n = nums.length;
        int lastOne = -(k + 1);  // So the first 1 always passes the distance check

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                if (i - lastOne - 1 < k) {
                    return false;
                }
                lastOne = i;
            }
        }
        
        return true;
    }
}
