/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=TYOnpelfejY
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/find-if-array-can-be-sorted
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Using Bubble Sort)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        bool swapped = true;

        for(int i = 0; i < n; i++) {
            swapped = false;

            for(int j = 0; j < n - i - 1; j++) { //in every pass, the max element bubbles up to right most index
                if(nums[j] <= nums[j+1]) { //no swap required
                    continue;
                } else { //pakka nums[j] > nums[j+1]
                    //swap is required
                    if(__builtin_popcount(nums[j]) == __builtin_popcount(nums[j+1])) {
                        swap(nums[j], nums[j+1]);
                        swapped = true;
                    } else {
                        //not able to swap, hence can't sort it
                        return false;
                    }
                }
            }

            if(swapped == false) { //no swapping was done in the pass, hence array was already sorted
                break; //no more passes are required
            }

        }

        return true;
    }
};



//Approach-2 (Using simple segment sorting check)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        //Current Segment
        int numOfSetBits = __builtin_popcount(nums[0]);
        int maxOfSegment = nums[0];
        int minOfSegment = nums[0];

        int maxOfPrevSegment = INT_MIN;

        for (int i = 1; i < nums.size(); i++) {
            if (__builtin_popcount(nums[i]) == numOfSetBits) { //they belong to same segment
                maxOfSegment = max(maxOfSegment, nums[i]); //find max of current segment
                minOfSegment = min(minOfSegment, nums[i]); //find min of current segment
            } else {  // Element belongs to a new segment
                
                if (minOfSegment < maxOfPrevSegment) { //ye bataya hai maine video me
                    return false;
                }

                // Update the previous segment's max
                maxOfPrevSegment = maxOfSegment;

                // new segment started now
                maxOfSegment = nums[i];
                minOfSegment = nums[i];
                numOfSetBits = __builtin_popcount(nums[i]);
            }
        }
        // Final check for proper segment arrangement
        if (minOfSegment < maxOfPrevSegment) {
            return false;
        }
        return true;
    }
};




/************************************************************ JAVA ************************************************/
//Approach-1 (Using Bubble Sort)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
    public boolean canSortArray(int[] nums) {
        int n = nums.length;
        boolean swapped = true;

        for (int i = 0; i < n; i++) {
            swapped = false;

            for (int j = 0; j < n - i - 1; j++) { // in every pass, the max element bubbles up to the rightmost index
                if (nums[j] <= nums[j + 1]) {
                    // no swap required
                    continue;
                } else {
                    // swap is required
                    if (Integer.bitCount(nums[j]) == Integer.bitCount(nums[j + 1])) {
                        // swapping nums[j] and nums[j + 1]
                        int temp = nums[j];
                        nums[j] = nums[j + 1];
                        nums[j + 1] = temp;
                        swapped = true;
                    } else {
                        // not able to swap, hence can't sort it
                        return false;
                    }
                }
            }

            if (!swapped) { // no swapping was done in the pass, hence array was already sorted
                break; // no more passes are required
            }
        }

        return true;
    }
}


//Approach-2 (Using simple segment sorting check)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public boolean canSortArray(int[] nums) {
        // Current Segment
        int numOfSetBits = Integer.bitCount(nums[0]);
        int maxOfSegment = nums[0];
        int minOfSegment = nums[0];
        int maxOfPrevSegment = Integer.MIN_VALUE;

        for (int i = 1; i < nums.length; i++) {
            if (Integer.bitCount(nums[i]) == numOfSetBits) { // they belong to the same segment
                // Find max of current segment
                maxOfSegment = Math.max(maxOfSegment, nums[i]);
                // Find min of current segment
                minOfSegment = Math.min(minOfSegment, nums[i]);
            } else { // Element belongs to a new segment

                if (minOfSegment < maxOfPrevSegment) { // condition to check proper segment arrangement
                    return false;
                }

                // Update the previous segment's max
                maxOfPrevSegment = maxOfSegment;

                // New segment starts now
                maxOfSegment = nums[i];
                minOfSegment = nums[i];
                numOfSetBits = Integer.bitCount(nums[i]);
            }
        }

        // Final check for proper segment arrangement
        if (minOfSegment < maxOfPrevSegment) {
            return false;
        }
        return true;
    }
}
