/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i
*/

//NOTE : We have already solved this using Prefix Sum Technique
//Video - https://www.youtube.com/watch?v=CKha8fqTwBA
//Github Code - https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Arrays/Cumulative_Sum(Prefix%20Array)/Maximum%20Frequency%20of%20an%20Element%20After%20Performing%20Operations%20I.cpp


/************************************************************ C++ ************************************************/
//Approach - Using Difference Array Technique
//T.C : O(maxVal), maxVal = maximum element in nums + k
//S.C : O(maxVal), maxVal = maximum element in nums + k
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(begin(nums), end(nums)) + k;

        vector<int> diff(maxVal+2, 0);
        unordered_map<int, int> freq;

        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            int l = max(nums[i]-k, 0);
            int r = min(nums[i]+k, maxVal);

            diff[l]++;
            diff[r+1]--;
        }


        int result = 1;

        for(int target = 0; target <= maxVal; target++) {
            diff[target] += (target > 0 ? diff[target-1] : 0);

            int targetFreq     = freq[target];
            int needConversion = diff[target] - targetFreq;

            int maxPossibleFreq = min(needConversion, numOperations);

            result = max(result, targetFreq + maxPossibleFreq);
        }

        return result;
    }
};




/************************************************************ JAVA ************************************************/
//Approach - Using Difference Array Technique
//T.C : O(maxVal), maxVal = maximum element in nums + k
//S.C : O(maxVal), maxVal = maximum element in nums + k
class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        int maxVal = Arrays.stream(nums).max().getAsInt() + k;
        int[] diff = new int[maxVal + 2];
        Map<Integer, Integer> freq = new HashMap<>();

        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);

            int l = Math.max(num - k, 0);
            int r = Math.min(num + k, maxVal);

            diff[l]++;
            diff[r + 1]--;
        }

        int result = 1;

        for (int target = 0; target <= maxVal; target++) {
            if (target > 0) diff[target] += diff[target - 1];

            int targetFreq = freq.getOrDefault(target, 0);
            int needConversion = diff[target] - targetFreq;

            int maxPossibleFreq = Math.min(needConversion, numOperations);
            result = Math.max(result, targetFreq + maxPossibleFreq);
        }

        return result;
    }
}
