/*     Scroll below to see JAVA code also    */
/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/minimum-moves-to-make-array-complementary
    Pre-Requisite               : https://www.youtube.com/watch?v=ZHNVmtm08WY&list=PLpIkg8OmuX-Kqkb8DqDe_4-Tiav6ilS_L (Difference Array Technique)
*/


/************************************************************ C++ ************************************************/
//Approach - Using Difference Array Technique
//T.C : O(n)
//S.C : O(limit)
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> diff(2 * limit + 2, 0);

        for(int i = 0; i < n/2; i++) {

            int a = nums[i];
            int b = nums[n-1-i];

            int minVal = min(a, b) + 1;
            int maxVal = max(a, b) + limit;

            diff[2] += 2;
            diff[2*limit+1] -= 2;

            //for moves = 1
            diff[minVal]   += (-1);
            diff[maxVal+1] -= (-1);

            //for moves = 0 [a+b, a+b]
            diff[a+b]   += (-1);
            diff[a+b+1] -= (-1);
        }

        int result = INT_MAX;

        for(int sum = 2; sum <= 2*limit; sum++) {
            diff[sum] += diff[sum-1];

            result = min(result, diff[sum]);
        }

        return result;
    }
};




/************************************************************ JAVA ************************************************/
//Approach - Using Difference Array Technique
//T.C : O(n)
//S.C : O(limit)
class Solution {
    public int minMoves(int[] nums, int limit) {
        
        int n = nums.length;

        int[] diff = new int[2 * limit + 2];

        for(int i = 0; i < n/2; i++) {

            int a = nums[i];
            int b = nums[n-1-i];

            int minVal = Math.min(a, b) + 1;
            int maxVal = Math.max(a, b) + limit;

            diff[2] += 2;
            diff[2*limit+1] -= 2;

            //for moves = 1
            diff[minVal]   += (-1);
            diff[maxVal+1] -= (-1);

            //for moves = 0 [a+b, a+b]
            diff[a+b]   += (-1);
            diff[a+b+1] -= (-1);
        }

        int result = Integer.MAX_VALUE;

        for(int sum = 2; sum <= 2*limit; sum++) {
            diff[sum] += diff[sum-1];

            result = Math.min(result, diff[sum]);
        }

        return result;
    }
}
