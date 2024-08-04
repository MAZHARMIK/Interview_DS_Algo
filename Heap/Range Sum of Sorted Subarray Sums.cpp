/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=oMHO5iti5_c
    Company Tags                : will soon update
    Leetcode Link               : https://leetcode.com/problems/range-sum-of-sorted-subarray-sums
*/
/*        You will learn how do we find sorted subarray sums of an array using Heap in Approach-2 below      */


/************************************************************ C++ ************************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2 * logn) - we have total n^2 elements in temp
//S.C : O(n)
class Solution {
public:
    int M = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                temp.push_back(sum);
            }
        }
        
        sort(begin(temp), end(temp));

        // Find the sum of all values between left and right.
        int result = 0;
        for (int i = left - 1; i <= right - 1; i++) {
            result = (result + temp[i]) % M;
        }
        return result;
    }
};


//Approach-2 (How to find sorted subarray sums using Heap)
//T.C : O(n^2 *n logn)
//S.C : O(n)
class Solution {
public:
    typedef pair<int, int> P;
    int M = 1e9+7;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        priority_queue<P, vector<P>, greater<P>> pq;
        
        //pair<sum, i> -> (subarray sum, till index i)
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        int result = 0;

        for (int i = 1; i <= right; i++) {
            auto p = pq.top();
            pq.pop();

            // If the current index is greater than or equal to left, add the
            // value to the answer.
            if (i >= left) {
                result = (result + p.first) % M;
            }

            // If index is less than the last index, increment it and add its
            // value
            if (p.second < n - 1) {
                p.second++;
                p.first += nums[p.second];
                pq.push(p);
            }
        }
        return result;
    }
};




/************************************************************ JAVA ************************************************************/
//Approach-1 (Brute Force)
//T.C : O(n^2 * logn) - we have total n^2 elements in temp
//S.C : O(n)
class Solution {
    private static final int M = (int)1e9 + 7;

    public int rangeSum(int[] nums, int n, int left, int right) {
        List<Integer> temp = new ArrayList<>();
        
        // Generate all subarray sums
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                temp.add(sum);
            }
        }

        // Sort the list of subarray sums
        Collections.sort(temp);

        // Calculate the sum of values from 'left' to 'right'
        int result = 0;
        for (int i = left - 1; i < right; i++) {
            result = (result + temp.get(i)) % M;
        }

        return result;
    }
}



//Approach-2 (How to find sorted subarray sums using Heap)
//T.C : O(n^2 *n logn)
//S.C : O(n)
class Solution {
    private static final int M = (int)1e9 + 7;

    public int rangeSum(int[] nums, int n, int left, int right) {
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));

        // Initialize the priority queue with the initial subarray sums
        for (int i = 0; i < n; i++) {
            pq.add(new int[]{nums[i], i});
        }

        int result = 0;

        for (int i = 1; i <= right; i++) {
            int[] current = pq.poll();

            // If the current index is within the desired range, add the value to the result
            if (i >= left) {
                result = (result + current[0]) % M;
            }

            // If index is less than the last index, increment it and add the new subarray sum to the queue
            if (current[1] < n - 1) {
                pq.add(new int[]{current[0] + nums[current[1] + 1], current[1] + 1});
            }
        }
        return result;
    }
}
