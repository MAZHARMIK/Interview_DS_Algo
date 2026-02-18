/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=FUPP7bHG9Dw
    Company Tags                : Amazon, Microsoft, Goldman Sachs, Directi
    GfG Leetcode Link           : https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1
*/

/***************************************************************** C++ ***************************************************************************/
//Approach-1 (Try all possible pairs)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int n = nums.size();

        // Mark pairs as used to avoid repetition
        vector<bool> used(n, false);
    
        for (int i = 0; i < n; i++) {
            if (used[i]) {
                continue; // Skip if this element is already used in a pair
            }
    
            bool foundPair = false;
    
            for (int j = i + 1; j < n; j++) {
                if (!used[j] && (nums[i] + nums[j]) % k == 0) {
                    used[i] = true;
                    used[j] = true;
                    foundPair = true;
                    break;
                }
            }
    
            if (!foundPair) {
                return false; // No pair found for the current element
            }
        }
        
        return true;
    }
};



//Approach-2 (Using hashmap)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool canPair(vector<int> nums, int k) {
        int n = nums.size();
        if (n % 2 != 0) return false;

        unordered_map<int, int> remainderCount;
        
        // Count the remainders
        for (int num : nums) {
            int remainder = num % k;
            remainderCount[remainder]++;
        }

        // Check pairs
        for (auto& entry : remainderCount) {
            int remainder = entry.first;
            int count = entry.second;

            if (remainder == 0) {
                // For remainder 0, count must be even
                if (count % 2 != 0) return false;
            } else {
                // For other remainders, count must match with k - remainder
                if (remainderCount[remainder] != remainderCount[k - remainder]) return false;
            }
        }

        return true;
    }
};




/***************************************************************** JAVA ***************************************************************************/
//Approach-1 (Try all possible pairs)
//T.C : O(n^2)
//S.C : O(n)
public class Solution {
    public boolean canPair(int[] nums, int k) {
        int n = nums.length;

        // Mark pairs as used to avoid repetition
        boolean[] used = new boolean[n];
        Arrays.fill(used, false);

        for (int i = 0; i < n; i++) {
            if (used[i]) {
                continue; // Skip if this element is already used in a pair
            }

            boolean foundPair = false;

            for (int j = i + 1; j < n; j++) {
                if (!used[j] && (nums[i] + nums[j]) % k == 0) {
                    used[i] = true;
                    used[j] = true;
                    foundPair = true;
                    break;
                }
            }

            if (!foundPair) {
                return false; // No pair found for the current element
            }
        }

        return true;
    }
}

//Approach-2 (Using hashset)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public boolean canPair(int[] nums, int k) {
        int n = nums.length;
        if (n % 2 != 0) return false;

        Map<Integer, Integer> remainderCount = new HashMap<>();
        
        // Count the remainders
        for (int num : nums) {
            int remainder = num % k;
            remainderCount.put(remainder, remainderCount.getOrDefault(remainder, 0) + 1);
        }

        // Check pairs
        for (Map.Entry<Integer, Integer> entry : remainderCount.entrySet()) {
            int remainder = entry.getKey();
            int count = entry.getValue();

            if (remainder == 0) {
                // For remainder 0, count must be even
                if (count % 2 != 0) return false;
            } else {
                // For other remainders, count must match with k - remainder
                if (!remainderCount.getOrDefault(k - remainder, 0).equals(count)) return false;
            }
        }

        return true;
    }
}
