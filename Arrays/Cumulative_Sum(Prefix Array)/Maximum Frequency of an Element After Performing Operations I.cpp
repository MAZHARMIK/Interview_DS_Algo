/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn    : https://www.youtube.com/watch?v=CKha8fqTwBA
    Company Tags                   : Google
    Leetcode Link                  : https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i
*/


/************************************************************ C++ *****************************************************/
//Approach - Using Cumulative Sum of Frequencies and trying all possible targets in nums
//T.C : O(maxVal), maxVal = maximum element in nums + k
//S.C : O(maxVal), maxVal = maximum element in nums + k
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEl = *max_element(begin(nums), end(nums)) + k;

        vector<int> freq(maxEl + 1, 0);

        for(int &num : nums) {
            freq[num]++;
        }

        //cumulative sum of frequenceis
        for(int i = 1; i <= maxEl; i++) {
            freq[i] += freq[i-1];
        }

        int result = 0;
        for(int target = 0; target <= maxEl; target++) {
            if(freq[target] == 0)
                continue;
            
            int leftNum  = max(0, target-k); //l
            int rightNum = min(maxEl, target+k); //r

            int totalCount  = freq[rightNum] - (leftNum > 0 ? freq[leftNum-1] : 0);

            int targetCount = freq[target] - (target > 0 ? freq[target-1] : 0);

            int needConversion = totalCount - targetCount;

            int maxPossibleFreq = targetCount + min(needConversion, numOperations);

            result = max(result, maxPossibleFreq);
        }

        return result;
    }
};




/************************************************************ JAVA *****************************************************/
//Approach - Using Cumulative Sum of Frequencies and trying all possible targets in nums
//T.C : O(maxVal), maxVal = maximum element in nums + k
//S.C : O(maxVal), maxVal = maximum element in nums + k
class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        int maxEl = Arrays.stream(nums).max().getAsInt() + k;

        int[] freq = new int[maxEl + 1];
        for (int num : nums) {
            freq[num]++;
        }

        // cumulative sum of frequencies
        for (int i = 1; i <= maxEl; i++) {
            freq[i] += freq[i - 1];
        }

        int result = 0;
        for (int target = 0; target <= maxEl; target++) {
            if (freq[target] == 0)
                continue;

            int leftNum = Math.max(0, target - k);
            int rightNum = Math.min(maxEl, target + k);

            int totalCount = freq[rightNum] - (leftNum > 0 ? freq[leftNum - 1] : 0);
            int targetCount = freq[target] - (target > 0 ? freq[target - 1] : 0);

            int needConversion = totalCount - targetCount;
            int maxPossibleFreq = targetCount + Math.min(needConversion, numOperations);

            result = Math.max(result, maxPossibleFreq);
        }

        return result;
    }
}
