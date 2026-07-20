/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=JcoYAYFEX-w
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/rotate-array/description/
*/


/*********************************************************** C++ **************************************************/
//Approach (Reverse Trick)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k % n;
        if (k == 0) 
            return;

        auto reverse = [&](int i, int j) {
            while (i < j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        };

        reverse(0, n - 1);
        reverse(0, k - 1);
        reverse(k, n - 1);
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Reverse Trick)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n;
        if (k == 0)
            return;

        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

    private void reverse(int[] nums, int i, int j) {
        while (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
}
