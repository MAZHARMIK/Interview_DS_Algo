/*			Scroll below to see JAVA code also			*/
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tag                 : will update later
    Leetcode Link               : https://leetcode.com/problems/count-non-decreasing-subarrays-after-k-operations/
*/


/*************************************************************** C++ *************************************************/
//Approach (Sliding Window with Monotonic Deque + NGR + Cumulative Sum)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    typedef long long ll;

    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<ll> cumSum(n);
        cumSum[0] = nums[0];
        for(int i = 1; i < n; i++) {
            cumSum[i] = nums[i] + cumSum[i-1];
        }

        //Range Sum
        auto rangeSum = [&](int i, int j) -> long long {
            if(i > j)
                return 0;

            return cumSum[j] - ((i > 0) ? cumSum[i-1] : 0);
        };

        //NGR[i] = n
        vector<int> NGR(n, n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] < nums[i]) {
                NGR[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        //Operations[i] = total operns to make [i...n-1] non-decreasing
        vector<ll> Operations(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            int m = NGR[i];

            //i to m-1 segment
            ll segmentOprns = (1LL * nums[i] * (m-i)) - rangeSum(i, m-1);
            Operations[i] = segmentOprns + Operations[m];
        }


        //Ready for Sliding Window Maximum
        deque<int> deq;
        ll result = 0;
        int i = 0;
        int j = 0;

        while(j < n) {

            while(!deq.empty() && nums[deq.back()] < nums[j]) { //decreasing order maintained - monotonic ds
                deq.pop_back();
            }

            deq.push_back(j);

            //Shrink if required
            while(i <= j) {
                int m = deq.front(); //fayda hai sliding window maximum

                //i...j
                ll oprnsCount = (Operations[i] - Operations[m]) + (1LL * nums[m] * (j-m+1)) - rangeSum(m, j);

                if(oprnsCount <= k)
                    break;
                
                i++;
                if(deq.front() < i) {
                    deq.pop_front();
                }
            }

            result += (j-i+1);
            j++;
        }

        return result;
    }
};



/*************************************************************** JAVA *************************************************/
//Approach (Sliding Window with Monotonic Deque + NGR + Cumulative Sum)
//T.C : O(n)
//S.C : O(n)
class Solution {

    private long[] cumSum;

    // Range Sum of nums[i..j], inclusive (0 if i > j)
    private long rangeSum(int i, int j) {
        if (i > j)
            return 0;

        return cumSum[j] - ((i > 0) ? cumSum[i - 1] : 0);
    }

    public long countNonDecreasingSubarrays(int[] nums, int k) {
        int n = nums.length;

        cumSum = new long[n];
        cumSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            cumSum[i] = nums[i] + cumSum[i - 1];
        }

        // NGR[i] = index of next strictly greater element, or n if none
        int[] NGR = new int[n];
        java.util.Arrays.fill(NGR, n);
        Deque<Integer> st = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            while (!st.isEmpty() && nums[st.peek()] < nums[i]) {
                NGR[st.pop()] = i;
            }
            st.push(i);
        }

        // Operations[i] = total operations to make [i...n-1] non-decreasing
        long[] Operations = new long[n + 1];
        for (int i = n - 1; i >= 0; i--) {
            int m = NGR[i];

            // i to m-1 segment
            long segmentOprns = (1L * nums[i] * (m - i)) - rangeSum(i, m - 1);
            Operations[i] = segmentOprns + Operations[m];
        }

        // Ready for Sliding Window Maximum
        Deque<Integer> deq = new ArrayDeque<>();
        long result = 0;
        int i = 0;
        int j = 0;

        while (j < n) {

            // decreasing order maintained - monotonic deque
            while (!deq.isEmpty() && nums[deq.peekLast()] < nums[j]) {
                deq.pollLast();
            }

            deq.addLast(j);

            // Shrink if required
            while (i <= j) {
                int m = deq.peekFirst(); // index of window maximum

                // cost of [i...j]
                long oprnsCount = (Operations[i] - Operations[m])
                                + (1L * nums[m] * (j - m + 1))
                                - rangeSum(m, j);

                if (oprnsCount <= k)
                    break;

                i++;
                if (deq.peekFirst() < i) {
                    deq.pollFirst();
                }
            }

            result += (j - i + 1);
            j++;
        }

        return result;
    }
}
