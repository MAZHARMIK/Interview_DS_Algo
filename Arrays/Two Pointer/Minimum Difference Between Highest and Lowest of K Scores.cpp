/*			Scroll below to see JAVA code also			*/
/*
	    MY YOUTUBE VIDEO ON THIS Qn : 
    	Company Tags  		          : Will update later
    	Leetcode Link 		          : https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores
*/


/*************************************************************** C++ *************************************************/
//Approach (Using sorting and two pointers)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int minDiff = INT_MAX;

        int i = 0;
        int j = i+k-1;
        while(j < n) {
            int minElement = nums[i];
            int maxElement = nums[j];

            minDiff = min(minDiff, maxElement - minElement);
            i++;
            j++;
        }

        return minDiff;
    }
};



/*************************************************************** JAVA *************************************************/
//Approach (Using sorting and two pointers)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public int minimumDifference(int[] nums, int k) {
        int n = nums.length;

        Arrays.sort(nums);

        int minDiff = Integer.MAX_VALUE;

        int i = 0;
        int j = i+k-1;

        while(j < n) {
            int minElement = nums[i];
            int maxElement = nums[j];

            minDiff = Math.min(minDiff, maxElement - minElement);

            i++;
            j++;
        }

        return minDiff;
    }
}
