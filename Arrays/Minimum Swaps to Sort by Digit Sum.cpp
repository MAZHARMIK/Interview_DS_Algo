/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-swaps-to-sort-by-digit-sum
*/


/*********************************************************** C++ **************************************************/
//Approach (Sort and Compare Indices and Swap)
//T.C : O(nlogn * N), N = log10(Max Number) to find digits
//S.C : O(n)
class Solution {
public:

    int getDigitSum(int num) {
        int sum = 0;

        while(num > 0) {
            sum += (num % 10);
            num /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> afterSorted(nums);

        auto lambda = [&](int num1, int num2) {
            int num1DigitSum = getDigitSum(num1); //log10(num)
            int num2DigitSum = getDigitSum(num2);

            if(num1DigitSum != num2DigitSum) {
                return num1DigitSum < num2DigitSum;
            }

            return num1 < num2;
        };

        sort(begin(afterSorted), end(afterSorted), lambda); //nlogn * N

        unordered_map<int, int> valToIdx;
        for(int i = 0; i < n; i++) { //O(n)
            valToIdx[nums[i]] = i;
        }

        
        int swapCount = 0;
        for(int i = 0; i < n; i++) { //O(n)
            int expectedVal = afterSorted[i];
            int currVal     = nums[i];

            if(expectedVal == currVal) continue;

            int idx = valToIdx[expectedVal];

            nums[i] = expectedVal;
            nums[idx] = currVal;

            valToIdx[expectedVal] = i;
            valToIdx[currVal] = idx;

            swapCount++;
        }

        return swapCount;


    }
};



/*********************************************************** JAVA **************************************************/
//Approach (Sort and Compare Indices and Swap)
//T.C : O(nlogn * N), N = log10(Max Number) to find digits
//S.C : O(n)
class Solution {

    private int getDigitSum(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    private int compareByDigitSum(int num1, int num2) {
        int num1DigitSum = getDigitSum(num1);
        int num2DigitSum = getDigitSum(num2);

        if (num1DigitSum != num2DigitSum) {
            return Integer.compare(num1DigitSum, num2DigitSum);
        }

        return Integer.compare(num1, num2);
    }

    public int minSwaps(int[] nums) {
        int n = nums.length;

        Integer[] afterSorted = new Integer[n];
        for (int i = 0; i < n; i++) {
            afterSorted[i] = nums[i];
        }

        Arrays.sort(afterSorted, this::compareByDigitSum);

        Map<Integer, Integer> valToIdx = new HashMap<>();
        for (int i = 0; i < n; i++) {
            valToIdx.put(nums[i], i);
        }

        int swapCount = 0;
        for (int i = 0; i < n; i++) {
            int expectedVal = afterSorted[i];
            int currVal = nums[i];

            if (expectedVal == currVal) continue;

            int idx = valToIdx.get(expectedVal);

            nums[i] = expectedVal;
            nums[idx] = currVal;

            valToIdx.put(expectedVal, i);
            valToIdx.put(currVal, idx);

            swapCount++;
        }

        return swapCount;
    }
}
