/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=CHxya52oxCM
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves
*/



/************************************************************ C++ **************************************************/
//Approach-1 (Using complete sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        if(n <= 4) {
            return 0;
        }
        int result = INT_MAX;
        result = min(result, nums[n-4] - nums[0]);
        result = min(result, nums[n-1] - nums[3]);
        result = min(result, nums[n-3] - nums[1]);
        result = min(result, nums[n-2] - nums[2]);

        return result;
    }
};


//Approach-2 (Using Partial Sorting)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MAX;
        if(n <= 4)
            return 0;

        partial_sort(begin(nums), begin(nums) + 4, end(nums));

        nth_element(begin(nums) + 4, begin(nums) + (n - 4), end(nums));
       
        sort(begin(nums) + (n - 4), end(nums)); //4th largest element will be correct

        result = min(result, nums[n-4] - nums[0]);
        result = min(result, nums[n-1] - nums[3]);
        result = min(result, nums[n-3] - nums[1]);
        result = min(result, nums[n-2] - nums[2]);

        return result;
    }
};




/************************************************************ JAVA **************************************************/
//Approach-1 (Using complete sorting)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public int minDifference(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        if (n <= 4) {
            return 0;
        }
        int result = Integer.MAX_VALUE;
        result = Math.min(result, nums[n - 4] - nums[0]);
        result = Math.min(result, nums[n - 1] - nums[3]);
        result = Math.min(result, nums[n - 3] - nums[1]);
        result = Math.min(result, nums[n - 2] - nums[2]);

        return result;
    }
}




//Approach-2 (Using Partial Sorting)
//T.C : O(n)
//S.C : O(1)
//Please note that in Java , there is nothing like partial_sort or nth_element, hence we used heap to solve it.
public class Solution {

    public int minDifference(int[] nums) {
        int numsSize = nums.length;
        if (numsSize <= 4) {
            return 0;
        }

        // Find the four smallest elements using a fixed-size max heap
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(
            Collections.reverseOrder()
        );
        for (int num : nums) {
            maxHeap.offer(num);
            if (maxHeap.size() > 4) {
                maxHeap.poll();
            }
        }
        List<Integer> smallestFour = new ArrayList<>(maxHeap);
        Collections.sort(smallestFour);

        // Find the four largest elements using a fixed-size min heap
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int num : nums) {
            minHeap.offer(num);
            if (minHeap.size() > 4) {
                minHeap.poll();
            }
        }
        List<Integer> largestFour = new ArrayList<>(minHeap);
        Collections.sort(largestFour);

        int minDiff = Integer.MAX_VALUE;
        // Four scenarios to compute the minimum difference
        for (int i = 0; i < 4; i++) {
            minDiff = Math.min(
                minDiff,
                largestFour.get(i) - smallestFour.get(i)
            );
        }

        return minDiff;
    }
}
