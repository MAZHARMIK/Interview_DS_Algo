/*			Scroll below to see JAVA code also			*/
/*
	    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=fZBdZ5TDKOw
    	Company Tags  		          : Will update later
    	Leetcode Link 		          : https://leetcode.com/problems/longest-balanced-subarray-i
*/


/*************************************************************** C++ *************************************************/
//Approach (try all subarrays)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();

        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            unordered_set<int> even;
            unordered_set<int> odd;

            for(int j = i; j < n; j++) {
                if(nums[j]%2 == 0)
                    even.insert(nums[j]);
                else
                    odd.insert(nums[j]);
                
                if(even.size() == odd.size())
                    maxLen = max(maxLen, j-i+1);
            }
        }

        return maxLen;
    }
};



/*************************************************************** JAVA *************************************************/
//Approach (try all subarrays)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
    public int longestBalanced(int[] nums) {
        int n = nums.length;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            Set<Integer> even = new HashSet<>();
            Set<Integer> odd = new HashSet<>();

            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    even.add(nums[j]);
                } else {
                    odd.add(nums[j]);
                }

                if (even.size() == odd.size()) {
                    maxLen = Math.max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
}
