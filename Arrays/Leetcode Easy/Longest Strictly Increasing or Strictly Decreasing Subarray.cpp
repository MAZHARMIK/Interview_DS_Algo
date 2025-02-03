/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray
*/

/*********************************************************** C++ **************************************************/
//Approach-1 : Brute Force
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int result = 0;
        for(int i = 0; i < n; i++) {
            int increasing = 1;
            int j = i+1;
            while(j < n && nums[j] > nums[j-1]) {
                increasing++;
                j++;
            }

            int decreasing = 1;
            j = i+1;

            while(j < n && nums[j] < nums[j-1]) {
                decreasing++;
                j++;
            }

            result = max({result, increasing, decreasing});
        }

        return result;
    }
};


//Approach-2 : Optimal
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int result = 1;
        int increasing = 1;
        int decreasing = 1;
        //{3, 2, 1}
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) {
                increasing++;
                decreasing = 1;
                result = max(result, increasing);
            } else if(nums[i] < nums[i-1]) {
                decreasing++;
                increasing = 1;
                result = max(result, decreasing);
            } else {
                increasing = 1;
                decreasing = 1;
            }
        }

        return result;
    }
};


/*********************************************************** Java **************************************************/
// Approach-1 : Brute Force
// T.C : O(n^2)
// S.C : O(1)
class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length;
        int result = 0;

        for (int i = 0; i < n; i++) {
            int increasing = 1;
            int j = i + 1;
            while (j < n && nums[j] > nums[j - 1]) {
                increasing++;
                j++;
            }

            int decreasing = 1;
            j = i + 1;
            while (j < n && nums[j] < nums[j - 1]) {
                decreasing++;
                j++;
            }

            result = Math.max(result, Math.max(increasing, decreasing));
        }

        return result;
    }
}

// Approach-2 : Optimal
// T.C : O(n)
// S.C : O(1)
class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length;
        int result = 1;
        int increasing = 1;
        int decreasing = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                increasing++;
                decreasing = 1;
                result = Math.max(result, increasing);
            } else if (nums[i] < nums[i - 1]) {
                decreasing++;
                increasing = 1;
                result = Math.max(result, decreasing);
            } else {
                increasing = 1;
                decreasing = 1;
            }
        }

        return result;
    }
}
