/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link Part I        : https://leetcode.com/problems/smallest-stable-index-i/description/
    Leetcode Link Part II       : https://leetcode.com/problems/smallest-stable-index-ii/description/
*/


/*********************************************************** C++ **************************************************/
//Approach (just keep track of maxElement and store min element in pre-processing)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> minFromIndex(n);
        int minEl = INT_MAX;
        for(int i = n-1; i >= 0; i--) {
            minEl = min(minEl, nums[i]);
            minFromIndex[i] = minEl;
        }

        int maxEl = 0;
        for(int i = 0; i < n; i++) {
            maxEl = max(maxEl, nums[i]);

            if(maxEl - minFromIndex[i] <= k)
                return i;
        }
        
        return -1;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach (just keep track of maxElement and store min element in pre-processing)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;

        int[] minFromIndex = new int[n];
        int minEl = Integer.MAX_VALUE;
        for (int i = n - 1; i >= 0; i--) {
            minEl = Math.min(minEl, nums[i]);
            minFromIndex[i] = minEl;
        }

        int maxEl = 0;
        for (int i = 0; i < n; i++) {
            maxEl = Math.max(maxEl, nums[i]);

            if (maxEl - minFromIndex[i] <= k)
                return i;
        }

        return -1;
    }
}
