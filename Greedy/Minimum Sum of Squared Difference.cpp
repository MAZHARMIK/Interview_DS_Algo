/*         Scroll down to see JAVA code also                    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-sum-of-squared-difference/
*/


/********************************************************************* C++ ****************************************************************/
//Approach-1 (Brute Force - TLE)
//T.C : O((n + k1 + k2) * log n), k is huge
//S.C : O(n)
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        priority_queue<int> pq;
        for (int i = 0; i < n; ++i) {
            pq.push(abs(nums1[i] - nums2[i]));
        }

        int K = k1 + k2;

        while (K > 0 && pq.top() > 0) {
            int largestDiff = pq.top();
            pq.pop();
            pq.push(largestDiff - 1);
            K--;
        }

        long long result = 0;
        while (!pq.empty()) {
            long long d = pq.top();
            pq.pop();
            result += d * d;
        }

        return result;
    }
};



//Approach-2 (Using Counting Sort)
//T.C : O(n + maxDiff), maxDiff <= 10^5
//S.C : O(n)
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        vector<int> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }

        int maxDiff = *max_element(diff.begin(), diff.end());

        // countDiff[d] = conut of each diff
        vector<int> countDiff(maxDiff + 1, 0);
        for (int d : diff) {
            countDiff[d]++;
        }

        int K = k1 + k2;

        for (int currDiff = maxDiff; currDiff > 0 && K > 0; currDiff--) {
            int countOps             = min(countDiff[currDiff], K);

            countDiff[currDiff]     -= countOps;
            countDiff[currDiff - 1] += countOps;
            K                       -= countOps;
        }

        
        long long result = 0;
        for (long long d = 1; d <= maxDiff; ++d) {
            result += countDiff[d] * d * d;
        }

        return result;
    }
};




/********************************************************************* JAVA ****************************************************************/
//Approach-1 (Brute Force - TLE)
//T.C : O((n + k1 + k2) * log n), k is huge
//S.C : O(n)
class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        int n = nums1.length;

        // Max-heap: top is always the largest diff
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i < n; i++) {
            pq.offer(Math.abs(nums1[i] - nums2[i]));
        }

        long K = (long) k1 + k2;

        while (K > 0 && pq.peek() > 0) {
            int largestDiff = pq.poll();
            pq.offer(largestDiff - 1);
            K--;
        }

        long result = 0;
        while (!pq.isEmpty()) {
            long d = pq.poll();
            result += d * d;
        }

        return result;
    }
}



//Approach-2 (Using Counting Sort)
//T.C : O(n + maxDiff), maxDiff <= 10^5
//S.C : O(n)
class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        int n = nums1.length;

        int[] diff = new int[n];
        int maxDiff = 0;
        for (int i = 0; i < n; i++) {
            diff[i] = Math.abs(nums1[i] - nums2[i]);
            maxDiff = Math.max(maxDiff, diff[i]);
        }

        // countDiff[d] = count of indices with diff exactly d
        int[] countDiff = new int[maxDiff + 1];
        for (int d : diff) {
            countDiff[d]++;
        }

        long K = (long) k1 + k2;

        for (int currDiff = maxDiff; currDiff > 0 && K > 0; currDiff--) {
            int countOps = (int) Math.min(countDiff[currDiff], K);

            countDiff[currDiff]     -= countOps;
            countDiff[currDiff - 1] += countOps;
            K                       -= countOps;
        }

        long result = 0;
        for (long d = 1; d <= maxDiff; d++) {
            result += countDiff[(int) d] * d * d;
        }

        return result;
    }
}
