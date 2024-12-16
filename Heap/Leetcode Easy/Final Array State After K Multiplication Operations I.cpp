/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=fwZcyneQvKE
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Brute Force)
//T.C : O(n * k)
//S.C : O(1)
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        for (int j = 0; j < k; j++) {

            int idx = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] < nums[idx]) {
                    idx = i;
                }
            }

            nums[idx] *= multiplier;
        }

        return nums;
    }
};


//Approach-2 (Using stl::priority_queue)
//T.C : O(nlogn + klogn)
//S.C : O(n)
class Solution {
public:
    #define P pair<int, int>
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        priority_queue<P, vector<P>, greater<P>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        while(k--) {
            pair<int, int> temp = pq.top();
            pq.pop();

            int idx = temp.second;
            int number = temp.first;

            nums[idx] = number*multiplier;

            pq.push({nums[idx], idx});
        }

        return nums;
    }
};


//Approach-3 (Using vector as heap for O(n) heapify)
//T.C : O(n + klogn)
//S.C : O(n)
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();

        vector<pair<int, int>> vec(n);
        for(int i = 0; i < n; i++) {
            vec[i] = {nums[i], i};
        }

        make_heap(begin(vec), end(vec), greater<>());

        while(k--) {
            pop_heap(begin(vec), end(vec), greater<>());
            pair<int, int> temp = vec.back();
            vec.pop_back();

            int idx = temp.second;
            int number = temp.first;

            nums[idx] = number*multiplier;

            vec.push_back({nums[idx], idx});
            push_heap(begin(vec), end(vec), greater<>());
        }

        return nums;
    }
};



/************************************************************ JAVA ************************************************/
//Approach-1 (Brute Force)
//T.C : O(n * k)
//S.C : O(1)
class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        int n = nums.length;

        for (int j = 0; j < k; j++) {
            int idx = 0;

            // Find the index of the smallest element
            for (int i = 0; i < n; i++) {
                if (nums[i] < nums[idx]) {
                    idx = i;
                }
            }

            // Multiply the smallest element by the multiplier
            nums[idx] *= multiplier;
        }

        return nums;
    }
}


//Approach-2 (Using vector as heap for O(n) heapify)
//T.C : O(n + klogn)
//S.C : O(n)
class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        // Priority queue to store pairs of (value, index) with a custom comparator
        PriorityQueue<int[]> heap = new PriorityQueue<>((a, b) -> {
            int valueComparison = Integer.compare(a[0], b[0]);
            if (valueComparison == 0) {
                return Integer.compare(a[1], b[1]);
            }
            return valueComparison;
        });

        // Initialize the heap with values and their indices
        for (int i = 0; i < nums.length; i++) {
            heap.offer(new int[] { nums[i], i });
        }

        // Perform k iterations
        while (k-- > 0) {
            // Extract the smallest element
            int[] temp = heap.poll();
            int idx = temp[1];
            int number = temp[0];

            // Update the array and reinsert the updated value into the heap
            nums[idx] = number * multiplier;
            heap.offer(new int[] { nums[idx], idx });
        }

        return nums;
    }
}
