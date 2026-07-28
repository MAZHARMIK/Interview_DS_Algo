/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=aazI9CgH2aU
    Company Tags                : Asked by Sprinkler in Online Assessment on 27th July, 2026
    Leetcode Link               : https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Using Pref Sum)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int funct(vector<int>& prefSum, int L, int M) {
        int n = prefSum.size();
        int maxLeftSubSum = 0;
        int result = 0; //Max sum

        for(int mEnd = L + M - 1; mEnd < n; mEnd++) {
            int lEnd = mEnd - M;
            int lStartPrev = lEnd - L;

            int mBlockSum = prefSum[mEnd] - prefSum[lEnd];
            int lBlockSum = prefSum[lEnd] - (lStartPrev < 0 ? 0 : prefSum[lStartPrev]);

            maxLeftSubSum = max(maxLeftSubSum, lBlockSum);

            result = max(result, maxLeftSubSum + mBlockSum);
        }

        return result;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        int n = nums.size();

        vector<int> prefSum(n, 0);
        prefSum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i-1] + nums[i];
        }

        return max(funct(prefSum, L, M), funct(prefSum, M, L));

    }
};



//Approach-2 (Using Sliding Window)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:

    int funct(vector<int>& nums, int L, int M) {
        int n = nums.size();

        int lBlockSum = 0;
        int mBlockSum = 0;

        //starting window from index 0 to L+M-1
        for(int i = 0; i <= L+M-1; i++) {
            if(i < L) {
                lBlockSum += nums[i];
            } else {
                mBlockSum += nums[i];
            }
        }

        int maxLeftSubSum = lBlockSum;
        int result = maxLeftSubSum + mBlockSum;

        for(int mEnd = L + M; mEnd < n; mEnd++) {
            lBlockSum += nums[mEnd-M] - nums[mEnd - M - L];
            mBlockSum += nums[mEnd] - nums[mEnd - M];

            maxLeftSubSum = max(maxLeftSubSum, lBlockSum);

            result = max(result, maxLeftSubSum + mBlockSum);
        }

        return result;

    }

    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        int n = nums.size();

        return max(funct(nums, L, M), funct(nums, M, L));
    }
};



/************************************************************ JAVA *****************************************************/
//Approach-1 (Using Pref Sum)
//T.C : O(n)
//S.C : O(n)
class Solution {
    private int funct(int[] prefSum, int L, int M) {
        int n = prefSum.length;
        int maxLeftSubSum = 0;
        int result = 0; //Max sum
        for(int mEnd = L + M - 1; mEnd < n; mEnd++) {
            int lEnd       = mEnd - M;
            int lStartPrev = lEnd - L;
            int mBlockSum  = prefSum[mEnd] - prefSum[lEnd];
            int lBlockSum  = prefSum[lEnd] - (lStartPrev < 0 ? 0 : prefSum[lStartPrev]);
            maxLeftSubSum  = Math.max(maxLeftSubSum, lBlockSum);
            result         = Math.max(result, maxLeftSubSum + mBlockSum);
        }
        return result;
    }
    public int maxSumTwoNoOverlap(int[] nums, int L, int M) {
        int n = nums.length;
        int[] prefSum = new int[n];
        prefSum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i-1] + nums[i];
        }
        return Math.max(funct(prefSum, L, M), funct(prefSum, M, L));
    }
}

//Approach-2 (Using Sliding Window)
//T.C : O(n)
//S.C : O(1)
class Solution {
    private int funct(int[] nums, int L, int M) {
        int n = nums.length;
        int lBlockSum = 0;
        int mBlockSum = 0;
        //starting window from index 0 to L+M-1
        for(int i = 0; i <= L+M-1; i++) {
            if(i < L) {
                lBlockSum += nums[i];
            } else {
                mBlockSum += nums[i];
            }
        }
        int maxLeftSubSum = lBlockSum;
        int result = maxLeftSubSum + mBlockSum;
        for(int mEnd = L + M; mEnd < n; mEnd++) {
            lBlockSum += nums[mEnd-M] - nums[mEnd - M - L];
            mBlockSum += nums[mEnd] - nums[mEnd - M];
            maxLeftSubSum = Math.max(maxLeftSubSum, lBlockSum);
            result = Math.max(result, maxLeftSubSum + mBlockSum);
        }
        return result;
    }
    public int maxSumTwoNoOverlap(int[] nums, int L, int M) {
        int n = nums.length;
        return Math.max(funct(nums, L, M), funct(nums, M, L));
    }
}
