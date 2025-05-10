/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : Will update soon
    Leetcode Link               : https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros
*/


/************************************************************ C++ ************************************************/
//Approach (Using simple greedy)
//T.C : O(m+n), m = nums1.size() , n = nums2.size()
//S.C : O(1)
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0;
        long long sum2 = 0;

        long long zero1 = 0;
        long long zero2 = 0;

        for(int &num : nums1) {
            sum1 += num;
            if(num == 0) { //to get minimum sum, add smallest positive i.e. 1
                zero1 += 1;
                sum1 += 1;
            }
        }

        for(int &num : nums2) {
            sum2 += num;
            if(num == 0) { //to get minimum sum, add smallest positive i.e. 1
                zero2 += 1;
                sum2 += 1;
            }
        }

        if((sum1 < sum2 && zero1 == 0) || (sum2 < sum1 && zero2 == 0)) {
          return -1;
        }
        
        return max(sum1, sum2);
    }
};



/************************************************************ JAVA ************************************************/
//Approach (Using simple greedy)
//T.C : O(m+n), m = nums1.size() , n = nums2.size()
//S.C : O(1)
class Solution {
    public long minSum(int[] nums1, int[] nums2) {
        long sum1 = 0;
        long sum2 = 0;

        long zero1 = 0;
        long zero2 = 0;

        for (int num : nums1) {
            sum1 += num;
            if (num == 0) {
                zero1++;
                sum1 += 1; // Add 1 to simulate minimum positive value
            }
        }

        for (int num : nums2) {
            sum2 += num;
            if (num == 0) {
                zero2++;
                sum2 += 1; // Add 1 to simulate minimum positive value
            }
        }

        if ((sum1 < sum2 && zero1 == 0) || (sum2 < sum1 && zero2 == 0)) {
            return -1;
        }

        return Math.max(sum1, sum2);
    }
}
