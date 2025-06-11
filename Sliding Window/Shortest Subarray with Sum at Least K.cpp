/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn   : https://www.youtube.com/watch?v=Z4tH40wH6JA
    Company Tags                  : Will update soon
    Leetcode Link                 : https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k
    Similar Easy Version Problem  : https://www.youtube.com/watch?v=D2MbogiFXWU

    Monotonic Data Structures Concepts Playlist - https://www.youtube.com/watch?v=yRyumGu_owg&list=PLpIkg8OmuX-IpUPXh3z8oeKSfRkKhjaTV
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Using sliding window + monotinic deque
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int K) {
        int N = nums.size();
        
        deque<int> deq;
        vector<long long> cumulativeSum(N, 0);  // This stores the cumulative sum

        int result = INT_MAX;
        int j = 0;

        // Compute cumulative sum in the cumulativeSum array using while loop
        while (j < N) {
            if (j == 0)
                cumulativeSum[j] = nums[j];
            else
                cumulativeSum[j] = cumulativeSum[j - 1] + nums[j];
            
            // If the cumulative sum from the start to j is already >= K, update result
            if (cumulativeSum[j] >= K) 
                result = min(result, j + 1);
            
            // Remove indices from the deque where the subarray sum is >= K
            while (!deq.empty() && cumulativeSum[j] - cumulativeSum[deq.front()] >= K) {
                result = min(result, j - deq.front());  // Calculate the length of the subarray
                deq.pop_front();  // Remove the front index from the deque
            }

            // Maintain the monotonic property of the deque (increasing order of cumulative sums)
            while (!deq.empty() && cumulativeSum[j] <= cumulativeSum[deq.back()]) {
                deq.pop_back();  // Remove indices that won't be useful
            }

            // Add the current index to the deque
            deq.push_back(j);

            j++;  // Increment j to move to the next index
        }

        // Return the result if we found a valid subarray, otherwise return -1
        return result == INT_MAX ? -1 : result;
    }
};




/**************************************************************** JAVA ****************************************************************/
//Approach (Using sliding window + monotinic deque
//T.C : O(n)
//S.C : O(n)
class Solution {
    public int shortestSubarray(int[] nums, int k) {
        int N = nums.length;
        
        Deque<Integer> deq = new LinkedList<>();
        long[] cumulativeSum = new long[N];  // This stores the cumulative sum
        
        int result = Integer.MAX_VALUE;
        int j = 0;

        // Compute cumulative sum in the cumulativeSum array using while loop
        while (j < N) {
            if (j == 0)
                cumulativeSum[j] = nums[j];
            else
                cumulativeSum[j] = cumulativeSum[j - 1] + nums[j];
            
            // If the cumulative sum from the start to j is already >= k, update result
            if (cumulativeSum[j] >= k) 
                result = Math.min(result, j + 1);
            
            // Remove indices from the deque where the subarray sum is >= k
            while (!deq.isEmpty() && cumulativeSum[j] - cumulativeSum[deq.peekFirst()] >= k) {
                result = Math.min(result, j - deq.peekFirst());  // Calculate the length of the subarray
                deq.pollFirst();  // Remove the front index from the deque
            }

            // Maintain the monotonic property of the deque (increasing order of cumulative sums)
            while (!deq.isEmpty() && cumulativeSum[j] <= cumulativeSum[deq.peekLast()]) {
                deq.pollLast();  // Remove indices that won't be useful
            }

            // Add the current index to the deque
            deq.offerLast(j);

            j++;  // Increment j to move to the next index
        }

        // Return the result if we found a valid subarray, otherwise return -1
        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
