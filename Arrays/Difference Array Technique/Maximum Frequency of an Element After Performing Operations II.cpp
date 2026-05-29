/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=hSyXvam4Us4
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii
*/


/************************************************************ C++ ************************************************/
//Approach - Using Difference Array Technique
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(begin(nums), end(nums)) + k;
        map<int, int> diff; //map     
        unordered_map<int, int> freq;

        //O(nlogn)
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            int l = max(nums[i]-k, 0);
            int r = min(nums[i]+k, maxVal);

            diff[l]++;
            diff[r+1]--;

            diff[nums[i]] += 0; //Focus
        }


        int result = 1;
        int cumSum = 0;
        //O(n)
        for(auto it = diff.begin(); it != diff.end(); it++) {
            int target = it->first;
            it->second += cumSum;

            int targetFreq     = freq[target];
            int needConversion = it->second - targetFreq;

            int maxPossibleFreq = min(needConversion, numOperations);

            result = max(result, targetFreq + maxPossibleFreq);

            cumSum = it->second;
        }

        return result;
    }
};



/************************************************************ JAVA ************************************************/
//Approach - Using Difference Array Technique
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        int maxVal = Arrays.stream(nums).max().getAsInt() + k;
        TreeMap<Integer, Integer> diff = new TreeMap<>();
        HashMap<Integer, Integer> freq = new HashMap<>();

        // O(n log n)
        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);

            int l = Math.max(num - k, 0);
            int r = Math.min(num + k, maxVal);

            diff.put(l, diff.getOrDefault(l, 0) + 1);
            diff.put(r + 1, diff.getOrDefault(r + 1, 0) - 1);

            // Ensure key exists for later iteration
            diff.putIfAbsent(num, diff.getOrDefault(num, 0));
        }

        int result = 1;
        int cumSum = 0;

        // O(n)
        for (Map.Entry<Integer, Integer> entry : diff.entrySet()) {
            int target = entry.getKey();
            int val = entry.getValue();

            cumSum += val;
            int targetFreq = freq.getOrDefault(target, 0);
            int needConversion = cumSum - targetFreq;

            int maxPossibleFreq = Math.min(needConversion, numOperations);
            result = Math.max(result, targetFreq + maxPossibleFreq);
        }

        return result;
    }
}
