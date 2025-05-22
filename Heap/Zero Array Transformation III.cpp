/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update later
    Leetcode Link               : https://leetcode.com/problems/zero-array-transformation-iii/
*/

/************************************************************ C++ ************************************************************/
//Approach (Using heaps)
//T.C : O(QlogQ + n * QlogQ)
//S.C : O(Q)
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // Min-heap of used queries' end indices
        priority_queue<int, vector<int>, greater<int>> past;

        // Max-heap of available queries' end indices
        priority_queue<int> maxHeap;

        // Sort queries by start index
        sort(queries.begin(), queries.end());

        int j = 0;              // Pointer to queries
        int usedCount = 0;      // Number of queries actually used

        for (int i = 0; i < n; ++i) {
            // Push all queries starting at index i into maxHeap
            while (j < queries.size() && queries[j][0] == i) {
                maxHeap.push(queries[j][1]);  // push only the end
                ++j;
            }

            // Apply effect of already-used queries
            nums[i] -= past.size();

            // Apply more queries if needed
            while (nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i) {
                int r = maxHeap.top(); maxHeap.pop();
                past.push(r);
                usedCount++;
                nums[i]--;
            }

            // If we can't reduce nums[i] to 0
            if (nums[i] > 0)
                return -1;

            // Remove expired queries
            while (!past.empty() && past.top() == i) {
                past.pop();
            }
        }

        return queries.size() - usedCount;
    }
};


/************************************************************ JAVA ************************************************************/
//Approach (Using heaps)
//T.C : O(QlogQ + n * QlogQ)
//S.C : O(Q)
class Solution {
    public int maxRemoval(int[] nums, int[][] queries) {
        int n = nums.length;

        // Min-heap for used queries (stores end indices)
        PriorityQueue<Integer> past = new PriorityQueue<>();

        // Max-heap for available queries (stores end indices)
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

        // Sort queries by start index
        Arrays.sort(queries, (a, b) -> Integer.compare(a[0], b[0]));

        int j = 0;               // Pointer to queries
        int usedCount = 0;       // Number of queries used

        for (int i = 0; i < n; i++) {
            // Push all queries starting at index i
            while (j < queries.length && queries[j][0] == i) {
                maxHeap.offer(queries[j][1]);  // Push only end index
                j++;
            }

            // Apply effect of already used queries
            nums[i] -= past.size();

            // Apply more queries if needed
            while (nums[i] > 0 && !maxHeap.isEmpty() && maxHeap.peek() >= i) {
                int r = maxHeap.poll();
                past.offer(r);
                usedCount++;
                nums[i]--;
            }

            // If we can't make nums[i] zero
            if (nums[i] > 0)
                return -1;

            // Remove expired queries
            while (!past.isEmpty() && past.peek() == i) {
                past.poll();
            }
        }

        return queries.length - usedCount;
    }
}
