/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : 
*/


/************************************************************ C++ ************************************************/
//Approach (Using Binary Search in Answer - See the problem statement : It asks to Minimize the Maximum which hints towards Binary Search On Answer)
//T.C : O(nlog(MAX)), where n = length of nums, MAX = max value in nums
//S.C : O(1)
class Solution {
public:

    bool isPossible(vector<int>& nums, int maxOps, int mid) {
        int totalOps = 0; //to bring each number <= mid

        for(int &num : nums) {
            int ops = num / mid;

            if(num % mid == 0) {
                ops -= 1;
            }

            totalOps += ops;
        }

        return totalOps <= maxOps;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(begin(nums), end(nums));
        
        int result = r; //we have to minimize this

        //O(n * log(MAX))
        while(l <= r) {
            int mid = l + (r-l)/2;

            if(isPossible(nums, maxOperations, mid) == true) {
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return result;


    }
};


/************************************************************ JAVA ************************************************/
//Approach (Using Binary Search in Answer - See the problem statement : It asks to Minimize the Maximum which hints towards Binary Search On Answer)
//T.C : O(nlog(MAX)), where n = length of nums, MAX = max value in nums
//S.C : O(1)
class Solution {
    public boolean isPossible(int[] nums, int maxOps, int mid) {
        int totalOps = 0; // To bring each number <= mid

        for (int num : nums) {
            int ops = num / mid;

            if (num % mid == 0) {
                ops -= 1;
            }

            totalOps += ops;
        }

        return totalOps <= maxOps;
    }

    public int minimumSize(int[] nums, int maxOperations) {
        int l = 1;
        int r = Arrays.stream(nums).max().getAsInt(); // Find max in nums
        
        int result = r; // We have to minimize this

        // Binary search: O(n * log(MAX))
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isPossible(nums, maxOperations, mid)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }
}
