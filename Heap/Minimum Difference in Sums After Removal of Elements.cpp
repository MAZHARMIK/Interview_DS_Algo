/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=uURBjheosXU
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements
*/

/************************************************************ C++ ************************************************************/
//Approach (Using 2 heaps and cumulative sum)
//T.C : O(NlogN)
//S.C : O(N)
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int N = nums.size(); //3*n
        int n = N/3;

        vector<long long> leftMinSum(N, 0);
        vector<long long> rightMaxSum(N, 0);

        priority_queue<int> maxHeap;
        long long leftSum = 0;
        for(int i = 0; i < 2*n; i++) {
            maxHeap.push(nums[i]);
            leftSum += nums[i];

            if(maxHeap.size() > n) {
                leftSum -= maxHeap.top();
                maxHeap.pop();
            }

            leftMinSum[i] = leftSum;
        }


        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long rightSum = 0;
        for(int i = N-1; i >= n; i--) {
            minHeap.push(nums[i]);
            rightSum += nums[i];

            if(minHeap.size() > n) {
                rightSum -= minHeap.top();
                minHeap.pop();
            }

            rightMaxSum[i] = rightSum;
        }


        long long result = LLONG_MAX;

        for(int i = n-1; i <= 2*n-1; i++) {
            result = min(result, leftMinSum[i] - rightMaxSum[i+1]);
        }

        return result;


    }
};



/************************************************************ JAVA ************************************************************/
//Approach (Using 2 heaps and cumulative sum)
//T.C : O(NlogN)
//S.C : O(N)
class Solution {
    public long minimumDifference(int[] nums) {
        int N = nums.length; // 3*n
        int n = N / 3;
        
        long[] leftMinSum = new long[N];
        long[] rightMaxSum = new long[N];
        
        // Max heap for left side (to keep n smallest elements)
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        long leftSum = 0;
        for (int i = 0; i < 2 * n; i++) {
            maxHeap.offer(nums[i]);
            leftSum += nums[i];
            
            if (maxHeap.size() > n) {
                leftSum -= maxHeap.poll();
            }
            
            leftMinSum[i] = leftSum;
        }
        
        // Min heap for right side (to keep n largest elements)
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        long rightSum = 0;
        for (int i = N - 1; i >= n; i--) {
            minHeap.offer(nums[i]);
            rightSum += nums[i];
            
            if (minHeap.size() > n) {
                rightSum -= minHeap.poll();
            }
            
            rightMaxSum[i] = rightSum;
        }
        
        long result = Long.MAX_VALUE;
        
        for (int i = n - 1; i <= 2 * n - 1; i++) {
            result = Math.min(result, leftMinSum[i] - rightMaxSum[i + 1]);
        }
        
        return result;
    }
}
