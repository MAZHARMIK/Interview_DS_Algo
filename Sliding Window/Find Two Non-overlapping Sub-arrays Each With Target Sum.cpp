/*			Scroll below to see JAVA code also			*/
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tag                 : will update later
    Leetcode Link               : https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum
*/


/*************************************************************** C++ *************************************************/
//Approach (Sliding Window)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        int i = 0;
        int j = 0;

        int currSum = 0;
        vector<int> minBestLenTillIdx(n, INT_MAX);

        int bestMinLen = INT_MAX;
        int result = INT_MAX;


        while(j < n) {
            currSum += arr[j];

            while(i < j && currSum > target) {
                currSum -= arr[i++];
            }

            if(currSum == target) {
                int len = j - i + 1;

                if(i > 0 && minBestLenTillIdx[i-1] != INT_MAX) {
                    result = min(result, len + minBestLenTillIdx[i-1]);
                }

                bestMinLen = min(bestMinLen, len);
            }

            minBestLenTillIdx[j] = bestMinLen;
            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};



/*************************************************************** JAVA *************************************************/
//Approach (Sliding Window)
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int minSumOfLengths(int[] arr, int target) {
        int n = arr.length;

        int i = 0;
        int j = 0;

        int currSum = 0;
        int[] minBestLenTillIdx = new int[n];
        Arrays.fill(minBestLenTillIdx, Integer.MAX_VALUE);

        int bestMinLen = Integer.MAX_VALUE;
        int result = Integer.MAX_VALUE;

        while (j < n) {
            currSum += arr[j];

            while (i < j && currSum > target) {
                currSum -= arr[i++];
            }

            if (currSum == target) {
                int len = j - i + 1;

                if (i > 0 && minBestLenTillIdx[i - 1] != Integer.MAX_VALUE) {
                    result = Math.min(result, len + minBestLenTillIdx[i - 1]);
                }

                bestMinLen = Math.min(bestMinLen, len);
            }

            minBestLenTillIdx[j] = bestMinLen;
            j++;
        }

        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
