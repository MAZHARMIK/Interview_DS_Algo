/*			Scroll below to see JAVA code also			*/
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tag                 : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal
*/


/*************************************************************** C++ *************************************************/
//Approach (Sliding Window)
//T.C : O(n log x + n * k)
//S.C : O(n*k)
class Solution {
public:
    int n, x, k;

    long long minOpsSubarray[100001];
    //minOpsSubarray[i] = min operations reauired to make all elements of subarray[i...i+x-1] as equal

    long long memo[16][100001];

    long long solve(int count, int i) {
        if(count == k)
            return 0;
        
        int subArraysNeeded = k-count;
        int elementsNeeded  = subArraysNeeded*x;
        int lastIndex       = i + elementsNeeded - 1;

        if(lastIndex >= n) {
            return 1e16; //10^16
        }

        if(memo[count][i] != -1) {
            return memo[count][i];
        }

        //Took ith index as start of a subarray
        long long result = minOpsSubarray[i] + solve(count+1, i+x);


        //Skip index i
        result = min(result, solve(count, i+1));

        return memo[count][i] = result;

    }

    long long minOperations(vector<int>& nums, int x, int k) {
        this->n = nums.size();
        this->x = x;
        this->k = k;

        memset(memo, -1, sizeof(memo));

        multiset<int> left, right;
        long long leftSum = 0, rightSum = 0;

        int i = 0;
        int j = 0;

        while(j < n) {
            if(left.size() <= right.size()) {
                left.insert(nums[j]);
                leftSum += nums[j];
            } else {
                right.insert(nums[j]);
                rightSum += nums[j];
            }

            //Balancing
            if(!left.empty() && !right.empty()) {
                int maxLeft  = *left.rbegin();
                int minRight = *right.begin();

                if(maxLeft > minRight) {
                    left.erase(left.find(maxLeft));
                    right.erase(right.find(minRight));

                    left.insert(minRight);
                    right.insert(maxLeft);

                    leftSum += minRight - maxLeft;
                    rightSum += maxLeft - minRight;
                }
            }

            //If we have found the subarray of size x
            if(j-i+1 == x) {
                long long median = *left.rbegin();
                long long leftSize = left.size();
                long long rightSize = right.size();

                minOpsSubarray[i] = (leftSize * median - leftSum) + (rightSum - rightSize*median);

                if(left.find(nums[i]) != left.end()) {
                    left.erase(left.find(nums[i]));
                    leftSum -= nums[i];
                } else {
                    right.erase(right.find(nums[i]));
                    rightSum -= nums[i];
                }
                i++;
            }

            j++;
        }

        return solve(0, 0); //recursion
    }
};



/*************************************************************** JAVA *************************************************/
//Approach (Sliding Window)
//T.C : O(n log x + n * k)
//S.C : O(n*k)
class Solution {
    int n, x, k;

    long[] minOpsSubarray;
    // minOpsSubarray[i] = min operations required to make all elements of subarray[i...i+x-1] equal

    long[][] memo;

    static final long INF = (long) 1e16; // 10^16

    long solve(int count, int i) {
        if (count == k)
            return 0;

        int subArraysNeeded = k - count;
        int elementsNeeded  = subArraysNeeded * x;
        int lastIndex       = i + elementsNeeded - 1;

        if (lastIndex >= n) {
            return INF;
        }

        if (memo[count][i] != -1) {
            return memo[count][i];
        }

        // Took ith index as start of a subarray
        long result = minOpsSubarray[i] + solve(count + 1, i + x);

        // Skip index i
        result = Math.min(result, solve(count, i + 1));

        return memo[count][i] = result;
    }

    // ---- multiset helpers (TreeMap<value, frequency>) ----
    private void add(TreeMap<Integer, Integer> map, int val) {
        map.put(val, map.getOrDefault(val, 0) + 1);
    }

    private void remove(TreeMap<Integer, Integer> map, int val) {
        int freq = map.get(val);
        if (freq == 1) map.remove(val);
        else map.put(val, freq - 1);
    }

    public long minOperations(int[] nums, int x, int k) {
        this.n = nums.length;
        this.x = x;
        this.k = k;

        minOpsSubarray = new long[n + 1];
        memo = new long[k + 1][n + 1];
        for (long[] row : memo) Arrays.fill(row, -1);

        TreeMap<Integer, Integer> left = new TreeMap<>();
        TreeMap<Integer, Integer> right = new TreeMap<>();
        int leftSize = 0, rightSize = 0;          // TreeMap.size() counts distinct keys, so track sizes manually
        long leftSum = 0, rightSum = 0;

        int i = 0;
        int j = 0;

        while (j < n) {
            if (leftSize <= rightSize) {
                add(left, nums[j]);
                leftSize++;
                leftSum += nums[j];
            } else {
                add(right, nums[j]);
                rightSize++;
                rightSum += nums[j];
            }

            // Balancing
            if (leftSize > 0 && rightSize > 0) {
                int maxLeft  = left.lastKey();
                int minRight = right.firstKey();

                if (maxLeft > minRight) {
                    remove(left, maxLeft);
                    remove(right, minRight);

                    add(left, minRight);
                    add(right, maxLeft);

                    leftSum  += minRight - maxLeft;
                    rightSum += maxLeft - minRight;
                }
            }

            // If we have found the subarray of size x
            if (j - i + 1 == x) {
                long median = left.lastKey();

                minOpsSubarray[i] = (leftSize * median - leftSum) + (rightSum - rightSize * median);

                if (left.containsKey(nums[i])) {
                    remove(left, nums[i]);
                    leftSize--;
                    leftSum -= nums[i];
                } else {
                    remove(right, nums[i]);
                    rightSize--;
                    rightSum -= nums[i];
                }
                i++;
            }

            j++;
        }

        return solve(0, 0); // recursion
    }
}
