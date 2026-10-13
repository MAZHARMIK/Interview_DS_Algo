/*          Scroll down to see JAVA code also         */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update soon
    Leetcode Link               : https://leetcode.com/problems/maximum-alternating-sum-of-squares
*/


/*************************************************************** C++ ***************************************************************/
//Approach-1 (Square and sort and pick larger and smaller)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++ ){
            nums[i] = nums[i]*nums[i];
        }

        sort(begin(nums), end(nums));

        long long largeHalf = accumulate(begin(nums)+n/2, end(nums), 0LL);
        long long smallHalf = accumulate(begin(nums), begin(nums)+n/2, 0LL);

        return largeHalf - smallHalf;
    }
};


//Approach-2 (Square and partial-sort and pick larger and smaller)
//T.C : Average O(n) because of nth_element
//S.C : O(1)
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++ ){
            nums[i] = nums[i]*nums[i];
        }

        nth_element(begin(nums), begin(nums)+n/2, end(nums));

        long long largeHalf = accumulate(begin(nums)+n/2, end(nums), 0LL);
        long long smallHalf = accumulate(begin(nums), begin(nums)+n/2, 0LL);

        return largeHalf - smallHalf;
    }
};




/*************************************************************** JAVA ***************************************************************/
//Approach (Square and sort and pick larger and smaller)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
    public long maxAlternatingSum(int[] nums) {
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }

        Arrays.sort(nums);

        long small = Arrays.stream(nums, 0, n / 2).asLongStream().sum();
        long large = Arrays.stream(nums, n / 2, n).asLongStream().sum();

        return large - small;
    }
}


//Note : Java doesn't have nth_element equivalent. You can implement custom quickselect for it. I will upload a separate video on Quick Sort where I will teach this.
