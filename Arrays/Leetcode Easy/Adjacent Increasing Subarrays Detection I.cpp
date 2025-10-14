/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=DB0llpjZOhs
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    bool isIncreasing(vector<int>& nums, int start, int end) {
        for (int i = start + 1; i < end; i++) {
            if (nums[i] <= nums[i - 1])
                return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for (int start = 0; start + 2 * k <= n; start++) {
            bool firstInc = isIncreasing(nums, start, start + k);
            bool secondInc = isIncreasing(nums, start + k, start + 2 * k);

            if (firstInc && secondInc)
                return true;
        }
        return false;
    }
};


//Approach-2 (Optimal : Loop and keep checking)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int currRun = 1;
        int prevRun = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                currRun++;
            } else { //increaseing order break hogaya yaha par
                prevRun = currRun;
                currRun = 1;
            }

            if(currRun >= 2*k) {
                //we can accomodate two subarrays in it length. >= k
                return true;
            }

            if(min(currRun, prevRun) >= k) {
                return true;
            }
        }

        return false;
    }
};



/*********************************************************** JAVA **************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        int n = nums.size();

        for (int start = 0; start + 2 * k <= n; start++) {
            boolean firstInc = isIncreasing(nums, start, start + k);
            boolean secondInc = isIncreasing(nums, start + k, start + 2 * k);
            if (firstInc && secondInc)
                return true;
        }
        return false;
    }

    private boolean isIncreasing(List<Integer> nums, int start, int end) {
        for (int i = start + 1; i < end; i++) {
            if (nums.get(i) <= nums.get(i - 1))
                return false;
        }
        return true;
    }
}


//Approach (Loop and keep checking)
//T.C : O(n) 
//S.C : O(1)
class Solution {
    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        int n = nums.size();

        int currRun = 1;
        int prevRun = 0;

        for (int i = 1; i < n; i++) {
            if (nums.get(i) > nums.get(i - 1)) {
                currRun++;
            } else { // increasing order breaks here
                prevRun = currRun;
                currRun = 1;
            }

            // if current run itself can fit two subarrays of length k
            if (currRun >= 2 * k) {
                return true;
            }

            // if current and previous increasing runs can fit one subarray each
            if (Math.min(currRun, prevRun) >= k) {
                return true;
            }
        }

        return false;
    }
}
