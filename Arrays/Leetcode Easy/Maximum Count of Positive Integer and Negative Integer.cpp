/*         Scroll down to see JAVA code also        */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Using STL count_if())
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {

        auto lambdaP = [](int num) {
            return num > 0;
        };

        auto lambdaN = [](int num) {
            return num < 0;
        };

        int countPositive = count_if(begin(nums), end(nums), lambdaP);
        int countNegative = count_if(begin(nums), end(nums), lambdaN);

        return max(countPositive, countNegative);
    }
};


//Approach-2 (Using lowerbound)
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int firstP = lower_bound(begin(nums), end(nums), 1) - begin(nums);
        int firstN = lower_bound(begin(nums), end(nums), 0) - begin(nums);

        return max(n-firstP, firstN);
        
    }
};


/*********************************************************** C++ **************************************************/
//Approach-1 (Using stream , filter and count)
//T.C : O(n)
//S.C : O(1)
class Solution {
    public int maximumCount(int[] nums) {
        
        IntPredicate lambdaP = num -> num > 0;
        IntPredicate lambdaN = num -> num < 0;
        
        int positiveCount = (int) Arrays.stream(nums).filter(lambdaP).count();
        int negativeCount = (int) Arrays.stream(nums).filter(lambdaN).count();

        return Math.max(positiveCount, negativeCount);
        
    }
}



//Approach-2 (Using lowerbound)
//T.C : O(log(n))
//S.C : O(1)
class Solution {
    public int maximumCount(int[] nums) {
        int n = nums.length;

        int firstP = apnaLowerB(nums, 1) ; //>= 1
        int firstN = apnaLowerB(nums, 0);  //>=0

        return Math.max(n - firstP, firstN);
    }

    public int apnaLowerB(int[] nums, int target) {
        int l = 0;
        int r = nums.length-1;
        int result = nums.length;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(nums[mid] < target) {
                l = mid+1;
            } else {
                result = mid;
                r = mid-1;
            }
        }
        //nums = {0, 0, 0, 0}
        return result;
    }
}
