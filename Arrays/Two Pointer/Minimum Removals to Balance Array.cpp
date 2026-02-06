/*			Scroll below to see JAVA code also			*/
/*
	    MY YOUTUBE VIDEO ON THIS Qn : 
    	Company Tags  		          : Will update later
    	Leetcode Link 		          : https://leetcode.com/problems/minimum-removals-to-balance-array
*/


/*************************************************************** C++ *************************************************/
//Approach (Using sorting and two pointers)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int maxEl = nums[0];
        int minEl = nums[0];

        int L = 1;
        int i = 0;
        int j = 0;

        while(j < n) {
            maxEl = nums[j];
            minEl = nums[i];

            while(i < j && maxEl > (long long)k * minEl) {
                i++;
                minEl = nums[i];
            }

            L = max(L, j-i+1);
            j++;
        }

        return n - L;
    }
};




/*************************************************************** JAVA *************************************************/
//Approach (Using sorting and two pointers)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public int minRemoval(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);

        int i = 0;
        int maxLen = 1;

        for (int j = 0; j < n; j++) {
            long maxEl = nums[j];
            long minEl = nums[i];

            while (i < j && maxEl > (long) k * minEl) {
                i++;
                minEl = nums[i];
            }

            maxLen = Math.max(maxLen, j - i + 1);
        }

        return n - maxLen;
    }
}
